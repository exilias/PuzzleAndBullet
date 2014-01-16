
#include "weapon.h"

#include <amlib.h>
#include "player.h"
#include "field.h"

#define WEAPON_SPEED	5


WeaponData weapon[WEAPON_MAX_COUNT];
extern FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];

void blockDestroy(int x, int y, int playerNo);

void weaponInit()
{
	int i;

	for (i = 0; i < WEAPON_MAX_COUNT; i++) {
		weapon[i].isActive = FALSE;
	}
}

void weaponFunc()
{
	int i, j, k, l;

	for (l = 0; l < 2; l++) {
		for (i = 0; i < WEAPON_MAX_COUNT; i++) {
			if (weapon[i].isActive) {
				weapon[i].x += weapon[i].direction == 0 ? WEAPON_SPEED : -WEAPON_SPEED;

				if (weapon[i].x < FIELD_ORIGIN_X || weapon[i].x > FIELD_ORIGIN_X * FIELD_SIZE_WIDTH) {
					weapon[i].isActive = FALSE;
				}
			}
		}

		// 当たり判定
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) { 
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				int fieldX, fieldY;
				fieldX = FIELD_ORIGIN_X + i * FIELD_BLOCK_SIZE;
				fieldY = FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE;

				switch (field[l][i][j].kind) {
					case FIELD_KIND_NONE:
					default:
						break;

					case FIELD_KIND_RED:
					case FIELD_KIND_GREEN:
					case FIELD_KIND_BLUE:
						for (k = 0; k < WEAPON_MAX_COUNT; k++) {
							if (weapon[k].isActive) {
								if( ( weapon[k].x < fieldX + FIELD_BLOCK_SIZE ) &&
						    ( fieldX < weapon[k].x + WEAPON_BLOCK_SIZE ) &&
						    ( weapon[k].y < fieldY + FIELD_BLOCK_SIZE ) &&
							    ( fieldY < weapon[k].y + WEAPON_BLOCK_SIZE ) ) {
									weapon[k].isActive = FALSE;
									//　ダメージ処理
									field[l][i][j].hp -= weapon[k].attackPoint;
									_dprintf("attack %d %d\n", field[l][i][j].hp, weapon[k].attackPoint);
									if (field[l][i][j].hp <= 0) {
										_dprintf("delete\n");
										blockDestroy(i, j, l);
									} 
								}
							}
						}
						
						break;
				}
			}
		}
	}
}

void blockDestroy(int x, int y, int playerNo)
{
	int fieldKind = field[playerNo][x][y].kind;
	if (field[playerNo][x][y].kind == FIELD_KIND_NONE) {
		return;
	}

	field[playerNo][x][y].kind = FIELD_KIND_NONE;

	if (x-1 >= 0 && field[playerNo][x-1][y].kind == fieldKind) {
		blockDestroy(x-1, y, playerNo);
	}
	if (x+1 < FIELD_SIZE_WIDTH && field[playerNo][x+1][y].kind == fieldKind) {
		blockDestroy(x+1, y, playerNo);
	}
	if (y-1 >= 0 && field[playerNo][x][y-1].kind == fieldKind) {
		blockDestroy(x, y-1, playerNo);
	}
	if (y+1 < FIELD_SIZE_HEIGHT && field[playerNo][x][y+1].kind == fieldKind) {
		blockDestroy(x, y+1, playerNo);
	}

	return;
}

void addWeapon(void* playerData)
{
	int i;
	PlayerData *_playerData = (PlayerData *)playerData;

	for (i = 0; i < WEAPON_MAX_COUNT; i++) {
		if (!weapon[i].isActive) {
			weapon[i].isActive = TRUE;
			weapon[i].x = _playerData->x + 15;
			weapon[i].y = _playerData->y + 23;
			weapon[i].direction = _playerData->direction;
			weapon[i].attackPoint = 1;
			break;
		}
	}
}

