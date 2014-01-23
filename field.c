#include "field.h"

#include <amlib.h>
#include "export.h"
#include "math.h"


#define FPS							60
#define FIELD_UPDATE_INTERVAL		4
#define FIELD_ADD_BLOCK_INTERVAL	120
#define FIELD_EXPOSE_TIME			120

#define FIELD_STATE_EXPOSE	0
#define FIELD_STATE_FALL	1

FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];	


void fieldInit()
{
	int i, j, k;

	for (k = 0; k < 2; k++) {
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				field[k][i][j].kind = FIELD_KIND_NONE;
				field[k][i][j].hp = 5;
			}
		}

		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = FIELD_SIZE_HEIGHT - 2; j < FIELD_SIZE_HEIGHT; j++) {
				field[k][i][j].kind = rand() % 3 + 1;
				field[k][i][j].hp = 5;
				field[k][i][j].state = FIELD_STATE_FALL;
			}
		}
	}
	
}

void fieldFunc()
{
	static int count = 0;
	int i, j, k;

	for (k = 0; k < 2; k++) {
		if (count % FIELD_UPDATE_INTERVAL == 0) {
			// ブロックを下に落とす
			for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
				for (j = FIELD_SIZE_HEIGHT-2; j >= 0; j--) {
					if (field[k][i][j].kind != FIELD_KIND_NONE && field[k][i][j].state == FIELD_STATE_FALL) {
						if (field[k][i][j+1].kind == FIELD_KIND_NONE) {
							field[k][i][j+1].kind = field[k][i][j].kind;
							field[k][i][j+1].hp = field[k][i][j].hp;
							field[k][i][j+1].state = field[k][i][j].state;
							field[k][i][j].kind = FIELD_KIND_NONE;
						}
					}
				}
			}
		}

		if (count % FIELD_ADD_BLOCK_INTERVAL == 0) {
			// 新たにブロックを生成する
			int x = rand()%FIELD_SIZE_WIDTH;
			if (field[k][x][0].kind == FIELD_KIND_NONE) {
				field[k][x][0].kind = rand() % 4 + 1;
				field[k][x][0].hp = 5;
				field[k][x][0].state = FIELD_STATE_EXPOSE;
				field[k][x][0].counter = 0;
			}
		}

		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			if (field[k][i][0].state == FIELD_STATE_EXPOSE) {
				if (field[k][i][0].counter >= FIELD_EXPOSE_TIME) {
					field[k][i][0].state = FIELD_STATE_FALL;
				} else {
					field[k][i][0].counter++;
				}
			}
		}
	}

	count++;
}


void fieldDraw(void* DBuf)
{
	int i, j, k;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	for (k = 0; k < 2; k++) {
		int fieldX;
		if (k == 0) {
			fieldX = FIELD_ORIGIN1_X;
		} else {
			fieldX = FIELD_ORIGIN2_X;
		}

		

		// フィールドの背景
		agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( _DBuf, AG_CG_STAGE_BG, 0, NULL, NULL );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(fieldX - FIELD_BLOCK_SIZE), x4(FIELD_ORIGIN_Y), x4(fieldX - FIELD_BLOCK_SIZE + FIELD_BLOCK_SIZE * (FIELD_SIZE_WIDTH + 2)), x4(FIELD_ORIGIN_Y + FIELD_BLOCK_SIZE * (FIELD_SIZE_HEIGHT + 2)));

		// フィールドの描画
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				int isTexture = FALSE;

				switch (field[k][i][j].kind) {
					case FIELD_KIND_NONE:
					default:
						// agDrawSETFCOLOR(_DBuf, ARGB(255, 255, 255, 255));
						// agDrawSETDBMODE( _DBuf, 0xff, 0, 0, 1 );
						break;

					case FIELD_KIND_RED:
						isTexture = TRUE;
						agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( _DBuf, AG_CG_BLOCK_RED, 0, NULL, NULL );
						agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
						break;

					case FIELD_KIND_GREEN:
						isTexture = TRUE;
						agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( _DBuf, AG_CG_BLOCK_GREEN, 0, NULL, NULL );
						agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
						break;

					case FIELD_KIND_BLUE:
						isTexture = TRUE;
						agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( _DBuf, AG_CG_BLOCK_BLUE, 0, NULL, NULL );
						agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
						break;

					case FIELD_KIND_NEEDLE:
						isTexture = TRUE;
						agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
						ageTransferAAC( _DBuf, AG_CG_BLOCK_NEEDLE, 0, NULL, NULL );
						agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
						break;
				}
				
				agDrawSPRITE( _DBuf, isTexture, x4(fieldX + i * FIELD_BLOCK_SIZE), x4(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE), x4(fieldX + i * FIELD_BLOCK_SIZE) + x4(FIELD_BLOCK_SIZE), x4(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE) + x4(FIELD_BLOCK_SIZE) );
			}
		}
	}
}