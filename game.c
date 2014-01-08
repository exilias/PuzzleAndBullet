#include "game.h"

#include <math.h>
#include <ax51401.h>
#include "field.h"
#include "player.h"
#include "weapon.h"
#include "pad.h"
#include "export.h"


#define BS(a) ((a) << 2)


extern FieldData field[FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];
extern PlayerData playerData;
extern WeaponData weapon[WEAPON_MAX_COUNT];

// 乱数の初期化
void setSrand()
{
	srand(aglGetReg(AG_REG_SYSMNTR));
}


void gameInit(void)
{
	setSrand();

	fieldInit();
	playerInit();
	weaponInit();
}


void gameFunc(void)
{
	fieldFunc();
	playerFunc();
	weaponFunc();

	if (PadTrg()&PAD_X) {
		gameInit();
	}
}


void gameDraw(AGDrawBuffer *DBuf)
{
	int i, j;
	int isTexture;

	if (playerData.isDead) { 
		return;
	}

	// フィールドの描画
	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			isTexture = FALSE;

			switch (field[i][j].kind) {
				case FIELD_KIND_NONE:
				default:
					agDrawSETFCOLOR(DBuf, ARGB(255, 255, 255, 255));
					agDrawSETDBMODE( DBuf, 0xff, 0, 0, 1 );
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
	
			agDrawSPRITE( DBuf, isTexture, BS(FIELD_ORIGIN_X + i * FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_X + i * FIELD_BLOCK_SIZE) + BS(FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE) + BS(FIELD_BLOCK_SIZE) );
		}
	}

	// キャラクターの描画
	agDrawSETFCOLOR(DBuf, ARGB(255, 255, 255, 40));
	agDrawSETDBMODE( DBuf, 0xff, 0, 0, 1 );
	agDrawSPRITE(DBuf, FALSE, BS(playerData.x), BS(playerData.y), BS(playerData.x + PLAYER_WIDTH), BS(playerData.y + PLAYER_HEIGHT));

	// 武器の描画
	for (i = 0; i < WEAPON_MAX_COUNT; i++) {
		if (weapon[i].isActive) {
			agDrawSETFCOLOR(DBuf, ARGB(255, 255, 255, 255));
			agDrawSETDBMODE( DBuf, 0xff, 0, 0, 1 );
			agDrawSPRITE(DBuf, FALSE, BS(weapon[i].x), BS(weapon[i].y), BS(weapon[i].x + WEAPON_BLOCK_SIZE), BS(weapon[i].y + WEAPON_BLOCK_SIZE));
		}
	}
	
}