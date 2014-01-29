#include "field.h"

#include <amlib.h>
#include "export.h"
#include "math.h"
#include "cutin.h"


#define FIELD_BG_WIDTH				450
#define FIELD_BG_HEIGHT				550
#define FIELD_BG_MARGIN_X			27
#define FIELD_BG_MARGIN_Y			23

#define FIELD_UPDATE_INTERVAL		2
#define FIELD_ADD_BLOCK_INTERVAL	60
#define FIELD_EXPOSE_TIME			60
#define FIELD_SKILL_EXPOSE_TIME		90

#define FIELD_STATE_EXPOSE			0
#define FIELD_STATE_FALL			1
#define FIELD_STATE_USING_SKILL		2



int getBlockNo(int hp);

FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];



const int FIELD_STAGE_BG_ID[] = {
		AG_CG_GAME_BG_STAGE_BACK_MAKO,
		AG_CG_GAME_BG_STAGE_BACK_LEMI
	};	

const int FIELD_BLOCK_BLUE_ID[] = {
		AG_CG_BLOCK_BLUE_1,
		AG_CG_BLOCK_BLUE_2,
		AG_CG_BLOCK_BLUE_3
	};

const int FIELD_BLOCK_RED_ID[] = {
		AG_CG_BLOCK_RED_1,
		AG_CG_BLOCK_RED_2,
		AG_CG_BLOCK_RED_3
	};	

const int FIELD_BLOCK_GREEN_ID[] = {
		AG_CG_BLOCK_GREEN_1,
		AG_CG_BLOCK_GREEN_2,
		AG_CG_BLOCK_GREEN_3
	};




void fieldInit()
{
	int i, j, k;

	for (k = 0; k < 2; k++) {
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				field[k][i][j].kind = FIELD_KIND_NONE;
				field[k][i][j].hp = FIELD_BLOCK_HP;
				field[k][i][j].damagingEffectCount = 0;
				field[k][i][j].counter = 0;
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
							field[k][i][j+1].damagingEffectCount = field[k][i][j].damagingEffectCount;
							field[k][i][j].kind = FIELD_KIND_NONE;
						}
					}
				}
			}
		}

		if ((count % FIELD_ADD_BLOCK_INTERVAL == 0)) {
			// 新たにブロックを生成する
			int x = rand()%FIELD_SIZE_WIDTH;
			if (field[k][x][0].kind == FIELD_KIND_NONE) {
				field[k][x][0].kind = rand() % 4 + 1;
				field[k][x][0].hp = 5;
				field[k][x][0].state = FIELD_STATE_EXPOSE;
				field[k][x][0].counter = 0;
				field[k][x][0].damagingEffectCount = 0;
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

		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				if (field[k][i][j].state == FIELD_STATE_USING_SKILL) {
					if (field[k][i][j].damagingEffectCount <= 0) {
						if ((field[k][i][j].counter % (FIELD_DAMAGING_EFFECT_FRAME)) == 0 ) {
							field[k][i][j].damagingEffectCount = FIELD_DAMAGING_EFFECT_FRAME;
						}
						field[k][i][j].counter++;
					}

					if (field[k][i][j].counter >= FIELD_SKILL_EXPOSE_TIME) {
						field[k][i][j].kind = FIELD_KIND_NONE;
					}
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
		ageTransferAAC( _DBuf, FIELD_STAGE_BG_ID[k], 0, NULL, NULL );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(fieldX - FIELD_BG_MARGIN_X), x4(FIELD_ORIGIN_Y - FIELD_BG_MARGIN_Y), x4(fieldX - FIELD_BG_MARGIN_X + FIELD_BG_WIDTH), x4(FIELD_ORIGIN_Y - FIELD_BG_MARGIN_Y + FIELD_BG_HEIGHT));

		// フィールドの描画
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				int isTexture = FALSE;
				int isDraw = TRUE;
				int imageFile;

				switch (field[k][i][j].kind) {
					case FIELD_KIND_NONE:
					default:
						isDraw = FALSE;
						break;

					case FIELD_KIND_RED:
						isTexture = TRUE;
						imageFile = FIELD_BLOCK_RED_ID[getBlockNo(field[k][i][j].hp)];
						break;

					case FIELD_KIND_GREEN:
						isTexture = TRUE;
						imageFile = FIELD_BLOCK_GREEN_ID[getBlockNo(field[k][i][j].hp)];
						break;

					case FIELD_KIND_BLUE:
						isTexture = TRUE;
						imageFile = FIELD_BLOCK_BLUE_ID[getBlockNo(field[k][i][j].hp)];
						break;

					case FIELD_KIND_NEEDLE:
						isTexture = TRUE;
						imageFile = AG_CG_BLOCK_NEEDLE;
						break;
				}
				
				if (isDraw) {
					if (field[k][i][j].damagingEffectCount > 0) {
						agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 255, 255 ) );
						agDrawSETDBMODE( _DBuf, 0xff, 0, 0, 1 );
						isTexture = FALSE;
						field[k][i][j].damagingEffectCount--;
					} else {
						ageTransferAAC( _DBuf, imageFile, 0, NULL, NULL );
						agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
					}	
					agDrawSPRITE( _DBuf, isTexture, x4(fieldX + i * FIELD_BLOCK_SIZE), x4(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE), x4(fieldX + i * FIELD_BLOCK_SIZE) + x4(FIELD_BLOCK_SIZE), x4(FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE) + x4(FIELD_BLOCK_SIZE) );
				}
			}
		}

		// フィールドの背景
		agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( _DBuf, AG_CG_GAME_BG_STAGE_FRONT, 0, NULL, NULL );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(fieldX - FIELD_BG_MARGIN_X), x4(FIELD_ORIGIN_Y - FIELD_BG_MARGIN_Y), x4(fieldX - FIELD_BG_MARGIN_X + FIELD_BG_WIDTH), x4(FIELD_ORIGIN_Y - FIELD_BG_MARGIN_Y + FIELD_BG_HEIGHT));
	}
}


int getBlockNo(int hp)
{
	if (hp >= FIELD_BLOCK_HP*0.7) {
		return 0;
	} else if (hp >= FIELD_BLOCK_HP * 0.3) {
		return 1;
	} else {
		return 2;
	}
}


void useMakoSkill(int applyPlayerId)
{
	int i;
	int index = rand() % FIELD_SIZE_WIDTH;

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		if (field[applyPlayerId][i][0].kind != FIELD_KIND_NONE) {
			if (index == i) {
				index = i + 1;
			}
		}
	}
	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		if (i != index) {
			field[applyPlayerId][i][0].kind = rand() % 3 + 1;
			field[applyPlayerId][i][0].hp = 5;
			field[applyPlayerId][i][0].state = FIELD_STATE_EXPOSE;
			field[applyPlayerId][i][0].counter = 0;
			field[applyPlayerId][i][0].damagingEffectCount = 0;
		}
	}
}


void useLemiSkill(int applyPlayerId)
{
	int i, j;
	int deleteTable[FIELD_SIZE_WIDTH];

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		if (i < 4) {
			deleteTable[i] = TRUE;
		} else {
			deleteTable[i] = FALSE;
		}
	}

	for (i = 0; i < 10; i++) {
		int swapIndexA = rand() % FIELD_SIZE_WIDTH;
		int swapIndexB = rand() % FIELD_SIZE_WIDTH;
		int buf;

		buf = deleteTable[swapIndexA];
		deleteTable[swapIndexA] = deleteTable[swapIndexB];
		deleteTable[swapIndexB] = buf;
	}

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			if (deleteTable[i]) {
				field[applyPlayerId][i][j].state = FIELD_STATE_USING_SKILL;
				field[applyPlayerId][i][j].damagingEffectCount = 0;
	 			field[applyPlayerId][i][j].counter = 0;
			}
		}
	}

	// int i, j;
	// int isFound = FALSE;
	// for (i = 1; i < FIELD_SIZE_HEIGHT; i++) {
	// 	for (j = 0; j < FIELD_SIZE_WIDTH; j++) {
	// 		if (!isFound) {
	// 			if ((field[applyPlayerId][j][i].kind == FIELD_KIND_RED) ||
	// 				(field[applyPlayerId][j][i].kind == FIELD_KIND_GREEN) ||
	// 				(field[applyPlayerId][j][i].kind == FIELD_KIND_BLUE)) {
	// 				isFound = TRUE;
	// 				break;
	// 			}
	// 		} else {
	// 			if (field[applyPlayerId][j][i].kind != FIELD_KIND_NONE) {
	// 				field[applyPlayerId][j][i].state = FIELD_STATE_USING_SKILL;
	// 				field[applyPlayerId][j][i].damagingEffectCount = 0;
	//  				field[applyPlayerId][j][i].counter = 0;
	// 			}
	// 		}
			
	// 	}
	// }


	// for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
	// 	for (j = FIELD_SIZE_HEIGHT-1; j >= 0; j--) {
	// 		if (field[applyPlayerId][i][j].kind != FIELD_KIND_NONE) {
	// 			if (field[applyPlayerId][i][j-1].kind != FIELD_KIND_NONE) {
	// 				field[applyPlayerId][i][j].state = FIELD_STATE_USING_SKILL;
	// 				field[applyPlayerId][i][j].damagingEffectCount = 0;
	// 				field[applyPlayerId][i][j].counter = 0;
	// 			}
	// 		}
	// 	}
	// }
}