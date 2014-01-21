#include "game.h"

#include <math.h>
#include <ax51401.h>
#include <agGamePad.h>

#include "field.h"
#include "player.h"
#include "weapon.h"
#include "cutin.h"
#include "export.h"


#define BS(a) ((a) << 2)


extern FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];
extern PlayerData playerData[2];
extern WeaponData weapon[2][WEAPON_MAX_COUNT];
extern CutinData cutinData;

static int deadCount;

// 乱数の初期化
void setSrand()
{
	srand(aglGetReg(AG_REG_SYSMNTR));
}

void pushedStartButton(void)
{
	u32 pad;

	pad = agGamePadGetData(0);

	if (pad & GAMEPAD_START) {
		gameInit();
	}
}


void gameInit(void)
{
	setSrand();

	fieldInit();
	playerInit();
	weaponInit();
	cutinInit();

	deadCount = 0;
}


void gameFunc(void)
{
	fieldFunc();
	playerFunc();
	weaponFunc();
	cutinFunc();

	pushedStartButton();
}


void gameDraw(AGDrawBuffer *DBuf)
{
	int i, j, k;
	int isTexture;

	// 背景
	ageTransferAAC( DBuf, AG_CG_GAME_BG, 0, NULL, NULL );
	agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(DBuf, TRUE, 0, 0, BS(FB_WIDTH), BS(FB_HEIGHT));

	for (k = 0; k < 2; k++) {
		int fieldX;
		if (k == 0) {
			fieldX = FIELD_ORIGIN1_X;
		} else {
			fieldX = FIELD_ORIGIN2_X;
		}

		if (playerData[0].isDead) {
			if (deadCount > 60) {
				return;
			} else {
				deadCount++;
			}
		}

		// フィールドの背景
		agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( DBuf, AG_CG_STAGE_BG, 0, NULL, NULL );
		agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(DBuf, TRUE, BS(fieldX - FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y), BS(fieldX - FIELD_BLOCK_SIZE + FIELD_BLOCK_SIZE * (FIELD_SIZE_WIDTH + 2)), BS(FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * (FIELD_SIZE_HEIGHT + 2)));

		// フィールドの描画
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				isTexture = FALSE;

				switch (field[k][i][j].kind) {
					case FIELD_KIND_NONE:
					default:
						// agDrawSETFCOLOR(DBuf, ARGB(255, 255, 255, 255));
						// agDrawSETDBMODE( DBuf, 0xff, 0, 0, 1 );
						break;

					case FIELD_KIND_RED:
						isTexture = TRUE;
						agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( DBuf, AG_CG_BLOCK_RED, 0, NULL, NULL );
						agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
						break;

					case FIELD_KIND_GREEN:
						isTexture = TRUE;
						agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( DBuf, AG_CG_BLOCK_GREEN, 0, NULL, NULL );
						agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
						break;

					case FIELD_KIND_BLUE:
						isTexture = TRUE;
						agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( DBuf, AG_CG_BLOCK_BLUE, 0, NULL, NULL );
						agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
						break;

					case FIELD_KIND_NEEDLE:
						isTexture = TRUE;
						agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( DBuf, AG_CG_BLOCK_NEEDLE, 0, NULL, NULL );
						agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
						break;
				}
				
				agDrawSPRITE( DBuf, isTexture, BS(fieldX + i * FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE), BS(fieldX + i * FIELD_BLOCK_SIZE) + BS(FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE) + BS(FIELD_BLOCK_SIZE) );
			}
		}

		// 武器の描画
		for (i = 0; i < WEAPON_MAX_COUNT; i++) {
			if (weapon[k][i].isActive) {
				agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
				if (weapon[k][i].direction) {
					ageTransferAAC( DBuf, AG_CG_MAKO_BULLET_LEFT, 0, NULL, NULL );
				} else {
					ageTransferAAC( DBuf, AG_CG_MAKO_BULLET_RIGHT, 0, NULL, NULL );
				}
				agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
				agDrawSPRITE(DBuf, TRUE, BS(weapon[k][i].x), BS(weapon[k][i].y), BS(weapon[k][i].x + WEAPON_BLOCK_SIZE), BS(weapon[k][i].y + WEAPON_BLOCK_SIZE));
			}
		}

		// キャラクターの描画
		agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
		if (playerData[k].direction) {
			ageTransferAAC( DBuf, AG_CG_MAKO_LEFT, 0, NULL, NULL );
		} else {
			ageTransferAAC( DBuf, AG_CG_MAKO_RIGHT, 0, NULL, NULL );
		}
		agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(DBuf, TRUE, BS(playerData[k].x), BS(playerData[k].y), BS(playerData[k].x + PLAYER_WIDTH), BS(playerData[k].y + PLAYER_HEIGHT));
	}

	// カットイン
	if (isCutinShowing()) {
		agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( DBuf, cutinData.imageFile, 0, NULL, NULL );
		agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(DBuf, TRUE, BS(cutinData.x), BS(cutinData.y), BS(cutinData.x + cutinData.width), BS(cutinData.y + cutinData.height));
	}
}