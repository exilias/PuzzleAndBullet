#include "field.h"

#define FPS					60
#define UPDATE_INTERVAL		100
#define ADD_BLOCK_INTERVAL	500

FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];	


void fieldInit()
{
	int i, j, k;

	for (k = 0; k < 2; k++) {
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				field[k][i][j].kind = 0;
				field[k][i][j].hp = 5;
			}
		}

		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = FIELD_SIZE_HEIGHT - 2; j < FIELD_SIZE_HEIGHT; j++) {
				field[k][i][j].kind = rand() % 3 + 1;
				field[k][i][j].hp = 5;
			}
		}
	}
	
}

void fieldFunc()
{
	static int count = 0;
	int k;

	for (k = 0; k < 2; k++) {
		if (count % UPDATE_INTERVAL == 0) {
			int i, j;

			// ブロックを下に落とす
			for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
				for (j = FIELD_SIZE_HEIGHT-2; j >= 0; j--) {
					if (field[k][i][j].kind != FIELD_KIND_NONE) {
						if (field[k][i][j+1].kind == FIELD_KIND_NONE) {
							field[k][i][j+1].kind = field[k][i][j].kind;
							field[k][i][j+1].hp = field[k][i][j].hp;
							field[k][i][j].kind = FIELD_KIND_NONE;
						}
					}
				}
			}
		}

		if (count % ADD_BLOCK_INTERVAL == 0) {
			int i, j;

			// 新たにブロックを生成する
			int x = rand()%FIELD_SIZE_WIDTH;
			field[k][x][0].kind = rand() % 4 + 1;
			field[k][x][0].hp = 5;
		}
	}

	count++;
}