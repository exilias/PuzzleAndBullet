#include "field.h"

#define FPS					60
#define UPDATE_INTERVAL		100
#define ADD_BLOCK_INTERVAL	500

FieldData field[FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];	


void createRandomBlock(int x, int y)
{
	field[x][y].kind = rand() % 4 + 1;
	field[x][y].hp = 5;

	return;
}

void fieldInit()
{
	int i, j;

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
			field[i][j].kind = 0;
			field[i][j].hp = 5;
		}
	}

	for (i = 0; i < FIELD_SIZE_WIDTH; i++) {
		for (j = FIELD_SIZE_HEIGHT - 2; j < FIELD_SIZE_HEIGHT; j++) {
			createRandomBlock(i, j);
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
				if (field[i][j].kind != FIELD_KIND_NONE) {
					if (field[i][j+1].kind == FIELD_KIND_NONE) {
						field[i][j+1].kind = field[i][j].kind;
						field[i][j+1].hp = field[i][j].hp;
						field[i][j].kind = FIELD_KIND_NONE;
					}
				}
			}
		}
	}

	if (count % ADD_BLOCK_INTERVAL == 0) {
		// 新たにブロックを生成する
		createRandomBlock(rand()%FIELD_SIZE_WIDTH, 0);
	}

	count++;
}