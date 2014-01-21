
#include "weapon.h"

#include <amlib.h>
#include "player.h"
#include "field.h"

#define WEAPON_SPEED	5



WeaponData weapon[2][WEAPON_MAX_COUNT];
extern FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];

void blockDestroy(int x, int y, int playerId);



void weaponInit()
{
	int i, j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < WEAPON_MAX_COUNT; j++) {
			weapon[i][j].isActive = FALSE;
		}
	}
}

void weaponFunc()
{
	int i, j, k, l;

	for (l = 0; l < 2; l++) {
		int fieldOriginX;
		fieldOriginX = l == 0 ? FIELD_ORIGIN1_X : FIELD_ORIGIN2_X;

		for (i = 0; i < WEAPON_MAX_COUNT; i++) {
			if (weapon[l][i].isActive) {
				weapon[l][i].x += weapon[l][i].direction == 0 ? WEAPON_SPEED : -WEAPON_SPEED;

				if (weapon[l][i].x < fieldOriginX || weapon[l][i].x > fieldOriginX + FIELD_BLOCK_SIZE * FIELD_SIZE_WIDTH) {
					weapon[l][i].isActive = FALSE;
				}
			}
		}

		// 当たり判定
		for (i = 0; i < FIELD_SIZE_WIDTH; i++) { 
			for (j = 0; j < FIELD_SIZE_HEIGHT; j++) {
				int fieldX, fieldY;
				fieldX = fieldOriginX + i * FIELD_BLOCK_SIZE;
				fieldY = FIELD_ORIGIN_Y + j * FIELD_BLOCK_SIZE;

				switch (field[l][i][j].kind) {
					case FIELD_KIND_NONE:
					default:
						break;

					case FIELD_KIND_RED:
					case FIELD_KIND_GREEN:
					case FIELD_KIND_BLUE:
						for (k = 0; k < WEAPON_MAX_COUNT; k++) {
							if (weapon[l][k].isActive) {
								if( ( weapon[l][k].x < fieldX + FIELD_BLOCK_SIZE ) &&
						    ( fieldX < weapon[l][k].x + WEAPON_BLOCK_SIZE ) &&
						    ( weapon[l][k].y < fieldY + FIELD_BLOCK_SIZE ) &&
							    ( fieldY < weapon[l][k].y + WEAPON_BLOCK_SIZE ) ) {
									weapon[l][k].isActive = FALSE;
									//　ダメージ処理
									field[l][i][j].hp -= weapon[l][k].attackPoint;
									_dprintf("attack %d %d\n", field[l][i][j].hp, weapon[l][k].attackPoint);
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

void blockDestroy(int x, int y, int playerId)
{
	int fieldKind = field[playerId][x][y].kind;
	if (field[playerId][x][y].kind == FIELD_KIND_NONE) {
		return;
	}

	field[playerId][x][y].kind = FIELD_KIND_NONE;

	if (x-1 >= 0 && field[playerId][x-1][y].kind == fieldKind) {
		blockDestroy(x-1, y, playerId);
	}
	if (x+1 < FIELD_SIZE_WIDTH && field[playerId][x+1][y].kind == fieldKind) {
		blockDestroy(x+1, y, playerId);
	}
	if (y-1 >= 0 && field[playerId][x][y-1].kind == fieldKind) {
		blockDestroy(x, y-1, playerId);
	}
	if (y+1 < FIELD_SIZE_HEIGHT && field[playerId][x][y+1].kind == fieldKind) {
		blockDestroy(x, y+1, playerId);
	}

	return;
}

void addWeapon(void* playerData, int playerId)
{
	int i;
	PlayerData *_playerData = (PlayerData *)playerData;

	for (i = 0; i < WEAPON_MAX_COUNT; i++) {
		if (!weapon[playerId][i].isActive) {
			weapon[playerId][i].isActive = TRUE;
			weapon[playerId][i].x = _playerData->x + 15;
			weapon[playerId][i].y = _playerData->y + 23;
			weapon[playerId][i].direction = _playerData->direction;
			weapon[playerId][i].attackPoint = 1;
			break;
		}
	}
}

