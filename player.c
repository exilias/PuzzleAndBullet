
#include <amlib.h>
#include <agGamePad.h>

#include "export.h"
#include "player.h"
#include "field.h"
#include "cutin.h"
#include "math.h"


#define PLAYER_COLLISION_MARGIN	10
#define PLAYER_CHARACTER_MAKO	0
#define PLAYER_CHARACTER_LEMI	1



PlayerData playerData[2];
extern FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];

const static u16 MotionMap[2][9] = {
	{
		AG_RP_MAKO_STAND,
		AG_RP_MAKO_RUN,
		AG_RP_MAKO_RUN,
		AG_RP_MAKO_RUN,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_STAND
	},
	{
		AG_RP_LEMI_STAND,
		AG_RP_LEMI_RUN,
		AG_RP_LEMI_RUN,
		AG_RP_LEMI_RUN,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_JUMP,
		AG_RP_MAKO_JUMP,
		AG_RP_LEMI_STAND
	}
};

const static s16 JumpPattern[] = {
	50, 30, 22, 19, 15, 13, 10, 8 , 7 , 6 , 5 , 4 , 2 , 2 , 1, 1, 0, 0,
};


int movePlayer(int dx, int dy, int moveFlag, int playerId);
int calcPlayer(int playerId);
int isGameOver(int playerId);
void checkPlayerInput(int playerId);



void playerInit()
{
	int i;

	for (i = 0; i < 2; i++) {
		playerData[i].direction = 1;
		playerData[i].count = 0;
		playerData[i].mode = PLAYER_MODE_WAIT;
		playerData[i].jumpCount = 0;
		playerData[i].isDead = FALSE;
		playerData[i].weaponCount = 0;
		playerData[i].x = (i == 0 ? FIELD_ORIGIN1_X : FIELD_ORIGIN2_X) + 200;
		playerData[i].y = FIELD_ORIGIN_Y + 200;
		playerData[i].characterId = PLAYER_CHARACTER_MAKO;
	}
}


void playerFunc()
{
	int i;

	for (i = 0; i < 2; i++) {
		calcPlayer(i);
		if (!playerData[i].isDead) {
			playerData[i].isDead = isGameOver(i);
			checkPlayerInput(i);
		}
	}
}


void playerDraw(void* DBuf)
{
	int i;
	int w, h;
	int pat;

	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	for (i = 0; i < 2; i++) {
		if ((playerData[i].count >> 1) >= ageRM3[MotionMap[playerData[i].characterId][playerData[i].mode]].Frames) {
			playerData[i].count = 0;
		}

		agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
		pat = playerData[i].count >> 1;

		ageTransferAAC_RM3( _DBuf, MotionMap[playerData[i].characterId][playerData[i].mode] , 0, &w, &h , pat);
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );

		if (playerData[i].direction) {
			agDrawSPRITE_UV( _DBuf, x4(playerData[i].x), x4(playerData[i].y), 0x1000 , 0, x4(playerData[i].x + PLAYER_WIDTH), x4(playerData[i].y + PLAYER_HEIGHT), 0, 0x1000);
		} else {
			agDrawSPRITE(_DBuf, TRUE, x4(playerData[i].x), x4(playerData[i].y), x4(playerData[i].x + PLAYER_WIDTH), x4(playerData[i].y + PLAYER_HEIGHT));
		}
	}
}

// プレイヤーを動かす
// 戻り値は当たり判定の結果
int movePlayer(int dx, int dy, int moveFlag, int playerId)
{
	int i, j, k;

	int isHit;
	int nextX = playerData[playerId].x + dx;
	int nextY = playerData[playerId].y + dy;
	int fieldOriginX;

	if (playerId == 0) {
		fieldOriginX = FIELD_ORIGIN1_X;
	} else {
		fieldOriginX = FIELD_ORIGIN2_X;
	}

	if (playerData[playerId].isDead == TRUE) {
		return FALSE;
	}

	// ここで当たり判定
	isHit = FALSE;
	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			int fieldX, fieldY;
			fieldX = fieldOriginX + i * FIELD_BLOCK_SIZE;
			fieldY = FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE;

			switch (field[playerId][i][j].kind) {
				case FIELD_KIND_NONE:
				default:
					break;

				case FIELD_KIND_RED:
				case FIELD_KIND_GREEN:
				case FIELD_KIND_BLUE:
				case FIELD_KIND_NEEDLE:
					if( ( nextX + PLAYER_COLLISION_MARGIN < fieldX + FIELD_BLOCK_SIZE ) &&
					    ( fieldX < nextX + PLAYER_WIDTH - PLAYER_COLLISION_MARGIN ) &&
					    ( nextY < fieldY + FIELD_BLOCK_SIZE ) &&
					    ( fieldY < nextY + PLAYER_HEIGHT ) ) {
						isHit = TRUE;
					}

					if (field[playerId][i][j].kind == FIELD_KIND_NEEDLE && isHit) {
						// 針を踏んでる時は当たり判定を無効化する
						if ((playerData[playerId].x + PLAYER_COLLISION_MARGIN < fieldX + FIELD_BLOCK_SIZE) &&
							(fieldX < playerData[playerId].x + PLAYER_WIDTH - PLAYER_COLLISION_MARGIN) &&
							(nextY + PLAYER_HEIGHT < fieldY + FIELD_BLOCK_SIZE) &&
							(fieldY < nextY + PLAYER_HEIGHT)) {
							isHit = FALSE;
						}
					}
					break;
			}
		}
	}

	// 壁判定
	if ((nextX < fieldOriginX) || (nextX + PLAYER_WIDTH > fieldOriginX + FIELD_BLOCK_SIZE * FIELD_SIZE_WIDTH) || (nextY < FIELD_ORIGIN_Y)) {
		isHit = TRUE;
	}
	

	if (moveFlag && !isHit) {
		playerData[playerId].x = nextX;
		playerData[playerId].y = nextY;
	}

	return isHit;
}

int isGameOver(int playerId)
{
	int i, j;
	int isGameOver;

	isGameOver = FALSE;

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			int fieldX, fieldY;
			if (playerId == 0) {
				fieldX = FIELD_ORIGIN1_X + i * FIELD_BLOCK_SIZE;
			} else {
				fieldX = FIELD_ORIGIN2_X + i * FIELD_BLOCK_SIZE;
			}
			fieldY = FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE;

			// 潰され判定
			switch (field[playerId][i][j].kind) {
				case FIELD_KIND_NONE:
				default:
					break;

				case FIELD_KIND_RED:
				case FIELD_KIND_GREEN:
				case FIELD_KIND_BLUE:
				case FIELD_KIND_NEEDLE:
					if( ( playerData[playerId].x + PLAYER_COLLISION_MARGIN < fieldX + FIELD_BLOCK_SIZE ) &&
					    ( fieldX < playerData[playerId].x + PLAYER_WIDTH - PLAYER_COLLISION_MARGIN ) &&
					    ( playerData[playerId].y < fieldY + FIELD_BLOCK_SIZE ) &&
					    ( fieldY < playerData[playerId].y + PLAYER_HEIGHT ) ) {
						isGameOver = TRUE;
						_dprintf("player:%d dead\n", playerId);
					}
					break;
			}
		}
	}

	return isGameOver;
}

int calcPlayer(int playerId)
{
	u32 pad;

	pad = agGamePadGetData(playerId);

	switch (playerData[playerId].mode) {
		// 地面にいる場合
		case PLAYER_MODE_WAIT:
		case PLAYER_MODE_RUNSTART:
		case PLAYER_MODE_RUN:
		case PLAYER_MODE_RUNEND:
			if (playerData[playerId].y < (FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * FIELD_SIZE_HEIGHT) && !movePlayer(0, 10, 0, playerId)) {
				// 一番下
				playerData[playerId].mode = PLAYER_MODE_FALL;
			}
			else if (pad & GAMEPAD_B){	// ボタンが押された場合はジャンプモード
				playerData[playerId].mode = PLAYER_MODE_JUMPSTART;
				playerData[playerId].count = 0;
				// ジャンプの効果音
			}
			else if (pad & GAMEPAD_A) {
				playerData[playerId].mode = PLAYER_MODE_ATTACK;
				playerData[playerId].count = 0;
				addWeapon(&playerData[playerId], playerId);
			}
			else if (pad & GAMEPAD_R || pad & GAMEPAD_L) {
				if (pad & GAMEPAD_R) {
					playerData[playerId].direction = 0;
					movePlayer(PLAYER_RUN_SPEED, 0, 1, playerId);
				}
				else {
					playerData[playerId].direction = 1;
					movePlayer(-PLAYER_RUN_SPEED, 0, 1, playerId);
				}

				if (playerData[playerId].mode == PLAYER_MODE_WAIT) {
					// 止まっていたら走りはじめる
					playerData[playerId].mode = PLAYER_MODE_RUNSTART;
					playerData[playerId].count = 0;
				}
				else if (playerData[playerId].mode == PLAYER_MODE_RUNEND) {
					// 止まりかけだったなら走る
					playerData[playerId].mode = PLAYER_MODE_RUN;
					playerData[playerId].count = 0;
				}
				else {
					playerData[playerId].count++;

					if (playerData[playerId].mode == PLAYER_MODE_RUNSTART) {	// 走り始めが終わったら走りモードへ
						playerData[playerId].mode = PLAYER_MODE_RUN;
					}
				}
			}
			else {	// キー入力なし
				if (playerData[playerId].mode == PLAYER_MODE_RUNSTART) {	// 走り始めは停止へ
					playerData[playerId].mode = PLAYER_MODE_WAIT;
					playerData[playerId].count = 0;
				}
				else if (playerData[playerId].mode == PLAYER_MODE_RUN) {	// 走ってたら走り終りへ
					playerData[playerId].mode = PLAYER_MODE_RUNEND;
				}
				else {	// 止まってるか走り終わり
					playerData[playerId].count++;

					if (playerData[playerId].mode == PLAYER_MODE_RUNEND) {
						playerData[playerId].mode = PLAYER_MODE_WAIT;
					}
				}
			}
			break;

		case PLAYER_MODE_JUMPSTART:
			if (pad & GAMEPAD_R) {
				playerData[playerId].direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1, playerId);
			}
			if (pad & GAMEPAD_L) {
				playerData[playerId].direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1, playerId);
			}

			if (pad & GAMEPAD_B) {	// ボタンが押されている場合
				playerData[playerId].count++;

				if ((playerData[playerId].count >> 1) >= ageRM3[MotionMap[playerData[playerId].characterId][playerData[playerId].mode]].Frames) {
					playerData[playerId].count = 0;
					playerData[playerId].mode = PLAYER_MODE_JUMP;
					playerData[playerId].jumpCount = 0;
				}
			}
			else {	// ボタンが離された（ジャンプ直前なので停止へ以降
				playerData[playerId].mode = PLAYER_MODE_WAIT;
				playerData[playerId].count = 0;
			}
			break;

		case PLAYER_MODE_JUMP :
			if (pad & GAMEPAD_R) {
				playerData[playerId].direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1, playerId);
			}
			if (pad & GAMEPAD_L) {
				playerData[playerId].direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1, playerId);
			}

			if (pad & GAMEPAD_B) {	// ボタンが押されている場合
				movePlayer(0, -JumpPattern[playerData[playerId].jumpCount], 1, playerId);
				playerData[playerId].jumpCount++;

				if (playerData[playerId].jumpCount >= sizeof(JumpPattern)/sizeof(JumpPattern[0])) {
					playerData[playerId].mode = PLAYER_MODE_FALL;
				}

				playerData[playerId].count++;
			}
			else {	// ボタンが離されたので落ちモードへ
				playerData[playerId].mode = PLAYER_MODE_FALL;
			}
			break;

		case PLAYER_MODE_FALL:
			if (pad & GAMEPAD_R) {
				playerData[playerId].direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1, playerId);
			}
			if (pad & GAMEPAD_L) {
				playerData[playerId].direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1, playerId);
			}

			if (movePlayer(0, 8, 1, playerId)) {
				playerData[playerId].mode = PLAYER_MODE_JUMPEND;
				playerData[playerId].count = 0;
			}
			else if (playerData[playerId].y >= (FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * FIELD_SIZE_HEIGHT)) {
				playerData[playerId].y = (FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * FIELD_SIZE_HEIGHT);
				playerData[playerId].mode = PLAYER_MODE_JUMPEND;
				playerData[playerId].count = 0;
				playerData[playerId].isDead = TRUE;
			}
			else {
				playerData[playerId].count++;
			}
			break;

		case PLAYER_MODE_JUMPEND:
			if (pad & GAMEPAD_R) {
				playerData[playerId].direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1, playerId);
			}
			if (pad & GAMEPAD_L) {
				playerData[playerId].direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1, playerId);
			}

			playerData[playerId].count++;

			if ((playerData[playerId].count >> 1) >= ageRM3[MotionMap[playerData[playerId].characterId][playerData[playerId].mode]].Frames) {
				playerData[playerId].count = 0;
				playerData[playerId].mode = PLAYER_MODE_WAIT;
			}
			break;

		case PLAYER_MODE_ATTACK:
			playerData[playerId].count++;
			playerData[playerId].weaponCount++;

			if (playerData[playerId].weaponCount > PLAYER_WEAPON_INTERVAL) {
				playerData[playerId].count = 0;
				playerData[playerId].weaponCount = 0;
				playerData[playerId].mode = PLAYER_MODE_WAIT;
			}
			break;


		default:
			break;
	}

	return 0;
}


void checkPlayerInput(int playerId)
{
	u32 pad;

	pad = agGamePadGetData(playerId);

	if (pad & GAMEPAD_Y) {
		if (!isCutinShowing()) {
			createCutin(AG_CG_MAKO_CUT_IN);
		}
	}
}