#include "game.h"

#include <math.h>
#include <ax51401.h>
#include <agGamePad.h>

#include "export.h"
#include "field.h"
#include "player.h"
#include "weapon.h"
#include "cutin.h"
#include "draw_number.h"
#include "score.h"



#define BS(a) ((a) << 2)


extern FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];
extern PlayerData playerData[2];
extern WeaponData weapon[2][WEAPON_MAX_COUNT];
extern CutinData cutinData;

int deadCount;

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
	scoreInit();

	deadCount = 0;
}


void gameFunc(void)
{
	fieldFunc();
	playerFunc();
	weaponFunc();
	cutinFunc();
	scoreFunc();

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

		
	}

	// 武器の描画
	weaponDraw(DBuf);
	
	// プレイヤー描画
	playerDraw(DBuf);

	// カットイン
	if (isCutinShowing()) {
		agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( DBuf, cutinData.imageFile, 0, NULL, NULL );
		agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(DBuf, TRUE, BS(cutinData.x), BS(cutinData.y), BS(cutinData.x + cutinData.width), BS(cutinData.y + cutinData.height));
	}

	// GUI
	for (i = 0; i < 2; i++) {
		// Score
		drawNumberGraph(getScore(i) /*表示させたい数字(int)*/, BS(i == 0 ? 100 : 600) /*表示させたいX座標*/, BS(20) /*表示させたいY座標*/, BS(40)/*1つの文字の幅*/, BS(50)/*1つの文字の高さ*/, 6/*桁数*/, DBuf);
	}
	
}