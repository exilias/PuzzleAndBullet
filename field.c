#include "field.h"

#define FPS					60
#define UPDATE_INTERVAL		40
#define ADD_BLOCK_INTERVAL	300

int field[FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];	


int getRandomBlock()
{
	return rand() % 3 + 1;
}

void fieldInit()
{
	int i, j;

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			field[i][j] = 0;
		}
	}

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = FIELD_SIZE_HEIGHT - 2; j < FIELD_SIZE_HEIGHT; j++) {
			field[i][j] = getRandomBlock();
		}
	}
}

void fieldFunc()
{
	static int count = 0;

	if (count % UPDATE_INTERVAL == 0) {
		int i, j;

		// ブロックを下に落とす
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
			for (j = FIELD_SIZE_HEIGHT-2; j >= 0; j--) {
				if (field[i][j] != FIELD_KIND_NONE) {
					if (field[i][j+1] == FIELD_KIND_NONE) {
						field[i][j+1] = field[i][j];
						field[i][j] = FIELD_KIND_NONE;
					}
				}
			}
		}
	}

	if (count % ADD_BLOCK_INTERVAL == 0) {
		// 新たにブロックを生成する
		field[rand()%FIELD_SIZE_WIDTH][0] = getRandomBlock();
	}

	count++;
}