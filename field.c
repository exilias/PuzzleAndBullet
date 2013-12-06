#include "field.h"


int field[FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];	

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
			field[i][j] = rand() % 3 + 1;
		}
	}
}

void fieldFunc()
{
	
}