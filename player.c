
#include <amlib.h>
#include "player.h"
#include "pad.h"
#include "field.h"


PlayerData playerData;
extern int field[FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];

int movePlayer(int dx, int dy, int moveFlag);
int calcPlayer(int flag);

void playerInit()
{
	PadInit();

	playerData.direction = 1;
	playerData.count = 0;
	playerData.mode = PLAYER_MODE_WAIT;
	playerData.jumpCount = 0;
	playerData.x = FIELD_ORIGIN_X;
	playerData.y = FIELD_ORIGIN_Y;
}


void playerFunc()
{
	PadRun();
	calcPlayer(1);
}


// プレイヤーを動かす
// 戻り値は当たり判定の結果
int movePlayer(int dx, int dy, int moveFlag)
{
	int i, j, k;

	int isHit;
	int nextX = playerData.x + dx;
	int nextY = playerData.y + dy;

	// ここで当たり判定
	isHit = FALSE;
	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			int fieldX, fieldY;
			fieldX = FIELD_ORIGIN_X + i * FIELD_BLOCK_SIZE;
			fieldY = FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE;

			switch (field[i][j]) {
				case FIELD_KIND_NONE:
				default:
					break;

				case FIELD_KIND_RED:
				case FIELD_KIND_GREEN:
				case FIELD_KIND_BLUE:
					if( ( nextX < fieldX + FIELD_BLOCK_SIZE ) &&
					    ( fieldX < nextX + PLAYER_WIDTH ) &&
					    ( nextY < fieldY + FIELD_BLOCK_SIZE ) &&
					    ( fieldY < nextY + PLAYER_HEIGHT ) ) {
						isHit = TRUE;
						_dprintf("hit\n");
					}
					break;
			}
		}
	}

	if (moveFlag && !isHit) {
		playerData.x = nextX;
		playerData.y = nextY;
	}

	return isHit;
}

const static s16 JumpPattern[] = {
	50, 30, 22, 19, 15, 13, 10, 8 , 7 , 6 , 5 , 4 , 2 , 2 , 1, 1, 0, 0,
};

int calcPlayer(int flag)
{
	switch (playerData.mode) {
		// 地面にいる場合
		case PLAYER_MODE_WAIT:
		case PLAYER_MODE_RUNSTART:
		case PLAYER_MODE_RUN:
		case PLAYER_MODE_RUNEND:
			if (playerData.y < (FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * FIELD_SIZE_HEIGHT) && !movePlayer(0, 10, 0)) {
				// 一番下
				playerData.mode = PLAYER_MODE_FALL;
			}
			else if (PadTrg()&PAD_B){	// ボタンが押された場合はジャンプモード
				playerData.mode = PLAYER_MODE_JUMPSTART;
				playerData.count = 0;
				// ジャンプの効果音
			}
			else if (PadLvl()&PAD_RIGHT || PadLvl()&PAD_LEFT) {
				if (PadLvl()&PAD_RIGHT) {
					playerData.direction = 0;
					movePlayer(PLAYER_RUN_SPEED, 0, 1);
				}
				else {
					playerData.direction = 1;
					movePlayer(-PLAYER_RUN_SPEED, 0, 1);
				}

				if (playerData.mode == PLAYER_MODE_WAIT) {
					// 止まっていたら走りはじめる
					playerData.mode = PLAYER_MODE_RUNSTART;
					playerData.count = 0;
				}
				else if (playerData.mode == PLAYER_MODE_RUNEND) {
					// 止まりかけだったなら走る
					playerData.mode = PLAYER_MODE_RUN;
					playerData.count = 0;
				}
				else {
					playerData.count++;

					// 移動モーションの変更部分

					if (playerData.mode == PLAYER_MODE_RUNSTART) {	// 走り始めが終わったら走りモードへ
						playerData.mode = PLAYER_MODE_RUN;
					}
				}
			}
			else {	// キー入力なし
				if (playerData.mode == PLAYER_MODE_RUNSTART) {	// 走り始めは停止へ
					playerData.mode = PLAYER_MODE_WAIT;
					playerData.count = 0;
				}
				else if (playerData.mode == PLAYER_MODE_RUN) {	// 走ってたら走り終りへ
					playerData.mode = PLAYER_MODE_RUNEND;
				}
				else {	// 止まってるか走り終わり
					playerData.count++;

					// 移動モーションの変更部分

					if (playerData.mode == PLAYER_MODE_RUNEND) {
						playerData.mode = PLAYER_MODE_WAIT;
					}
				}
			}
			break;

		case PLAYER_MODE_JUMPSTART:
			if (PadLvl()&PAD_RIGHT) {
				playerData.direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1);
			}
			if (PadLvl()&PAD_LEFT) {
				playerData.direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1);
			}

			if (PadLvl()&PAD_B) {	// ボタンが押されている場合
				playerData.count++;

				if (playerData.count > 5) {
					playerData.count = 0;
					playerData.mode = PLAYER_MODE_JUMP;
					playerData.jumpCount = 0;
				}
			}
			else {	// ボタンが離された（ジャンプ直前なので停止へ以降
				playerData.mode = PLAYER_MODE_WAIT;
				playerData.count = 0;
			}
			break;

		case PLAYER_MODE_JUMP :
			if (PadLvl()&PAD_RIGHT) {
				playerData.direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1);
			}
			if (PadLvl()&PAD_LEFT) {
				playerData.direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1);
			}

			if (PadLvl()&PAD_B) {	// ボタンが押されている場合
				movePlayer(0, -JumpPattern[playerData.jumpCount], 1);
				playerData.jumpCount++;

				if (playerData.jumpCount >= sizeof(JumpPattern)/sizeof(JumpPattern[0])) {
					playerData.mode = PLAYER_MODE_FALL;
				}

				playerData.count++;

				// キャラクターアニメーション
			
			}
			else {	// ボタンが離されたので落ちモードへ
				playerData.mode = PLAYER_MODE_FALL;
			}
			break;

		case PLAYER_MODE_FALL:
			if (PadLvl()&PAD_RIGHT) {
				playerData.direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1);
			}
			if (PadLvl()&PAD_LEFT) {
				playerData.direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1);
			}

			if (movePlayer(0, 8, 1)) {
				playerData.mode = PLAYER_MODE_JUMPEND;
				playerData.count = 0;
			}
			else if (playerData.y >= (FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * FIELD_SIZE_HEIGHT)) {
				playerData.y = (FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * FIELD_SIZE_HEIGHT);
				playerData.mode = PLAYER_MODE_JUMPEND;
				playerData.count = 0;
			}
			else {
				playerData.count++;

				// アニメーション

			}
			break;

		case PLAYER_MODE_JUMPEND:
			if (PadLvl()&PAD_RIGHT) {
				playerData.direction = 0;
				movePlayer(PLAYER_RUN_SPEED, 0, 1);
			}
			if (PadLvl()&PAD_LEFT) {
				playerData.direction = 1;
				movePlayer(-PLAYER_RUN_SPEED, 0, 1);
			}

			playerData.count++;

			if (playerData.count > 1) {
				playerData.count = 0;
				playerData.mode = PLAYER_MODE_WAIT;
			}
			break;

		default:
			break;
	}

	_dprintf("mode %d\n", playerData.mode);

	return 0;
}