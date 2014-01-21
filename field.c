#include "field.h"

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
			field[k][x][0].kind = rand() % 4 + 1;
			field[k][x][0].hp = 5;
			field[k][x][0].state = FIELD_STATE_EXPOSE;
			field[k][x][0].counter = 0;
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