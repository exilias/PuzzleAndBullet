#include "game.h"

#include <math.h>
#include <ax51401.h>
#include "pad.h"
#include "field.h"
#include "player.h"

#define BS(a) ((a) << 2)


extern int field[FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];
extern PlayerData playerData;

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
}


void gameFunc(void)
{
	fieldFunc();
	playerFunc();
}


void gameDraw(AGDrawBuffer *DBuf)
{
	int i, j;

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			switch (field[i][j]) {
				case FIELD_KIND_NONE:
				default:
					agDrawSETFCOLOR(DBuf, ARGB(255, 40, 40, 40));
					break;

				case FIELD_KIND_RED:
					agDrawSETFCOLOR(DBuf, ARGB(255, 255, 40, 40));
					break;

				case FIELD_KIND_GREEN:
					agDrawSETFCOLOR(DBuf, ARGB(255, 40, 255, 40));
					break;

				case FIELD_KIND_BLUE:
					agDrawSETFCOLOR(DBuf, ARGB(255, 40, 40, 255));
					break;
			}

			agDrawSETDBMODE( DBuf, 0xff, 0, 0, 1 );
			agDrawSPRITE( DBuf, FALSE, BS(FIELD_ORIGIN_X + i * FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_X + i * FIELD_BLOCK_SIZE) + BS(FIELD_BLOCK_SIZE), BS(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE) + BS(FIELD_BLOCK_SIZE) );
		}
	}
}