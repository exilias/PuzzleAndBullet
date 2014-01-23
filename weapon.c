
#include "weapon.h"

#include <amlib.h>
#include "export.h"
#include "player.h"
#include "field.h"
#include "score.h"
#include "math.h"

#define WEAPON_SPEED	5



WeaponData weapon[2][WEAPON_MAX_COUNT];
extern FieldData field[2][FIELD_SIZE_WIDTH][FIELD_SIZE_HEIGHT];

void blockDestroy(int x, int y, int count, int playerId);
void blockDamaging(int x, int y, int playerId);



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
					case FIELD_KIND_NEEDLE:
						for (k = 0; k < WEAPON_MAX_COUNT; k++) {
							if (weapon[l][k].isActive) {
								if( ( weapon[l][k].x < fieldX + FIELD_BLOCK_SIZE ) && ( fieldX < weapon[l][k].x + WEAPON_BLOCK_SIZE ) && ( weapon[l][k].y < fieldY + FIELD_BLOCK_SIZE ) && ( fieldY < weapon[l][k].y + WEAPON_BLOCK_SIZE ) ) {
									weapon[l][k].isActive = FALSE;

									if (field[l][i][j].kind != FIELD_KIND_NEEDLE) {
										//　通常ブロックにはダメージ処理
										field[l][i][j].hp -= weapon[l][k].attackPoint;
										blockDamaging(i, j, l);
										_dprintf("attack %d %d\n", field[l][i][j].hp, weapon[l][k].attackPoint);
										if (field[l][i][j].hp <= 0) {
											_dprintf("delete\n");
											blockDestroy(i, j, 0, l);
										} 
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


void weaponDraw(void* DBuf)
{
	int i, j;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < WEAPON_MAX_COUNT; j++) {
			if (weapon[i][j].isActive) {
				agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
				if (weapon[i][j].direction) {
					ageTransferAAC( _DBuf, AG_CG_MAKO_BULLET_LEFT, 0, NULL, NULL );
				} else {
					ageTransferAAC( _DBuf, AG_CG_MAKO_BULLET_RIGHT, 0, NULL, NULL );
				}
				agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
				agDrawSPRITE(_DBuf, TRUE, x4(weapon[i][j].x), x4(weapon[i][j].y), x4(weapon[i][j].x + WEAPON_BLOCK_SIZE), x4(weapon[i][j].y + WEAPON_BLOCK_SIZE));
			}
		}
	}
}

void blockDestroy(int x, int y, int count, int playerId)
{
	int fieldKind = field[playerId][x][y].kind;
	if (field[playerId][x][y].kind == FIELD_KIND_NONE) {
		return;
	}

	field[playerId][x][y].kind = FIELD_KIND_NONE;

	addScore(SCORE_ADD_STANDARD_VALUE + SCORE_ADD_BONUS_VALUE * count, playerId);
	addWeaponGauge(PLAYER_WEAPON_GAUGE_ADD_STANDARD_VALUE + PLAYER_WEAPON_GAUGE_ADD_BONUS_VALUE * count, playerId);

	if (x-1 >= 0 && (field[playerId][x-1][y].kind == fieldKind || field[playerId][x-1][y].kind == FIELD_KIND_NEEDLE)) {
		blockDestroy(x-1, y, ++count, playerId);
	}
	if (x+1 < FIELD_SIZE_WIDTH && (field[playerId][x+1][y].kind == fieldKind || field[playerId][x+1][y].kind == FIELD_KIND_NEEDLE)) {
		blockDestroy(x+1, y, ++count, playerId);
	}
	if (y-1 >= 0 && (field[playerId][x][y-1].kind == fieldKind || field[playerId][x][y-1].kind == FIELD_KIND_NEEDLE)) {
		blockDestroy(x, y-1, ++count, playerId);
	}
	if (y+1 < FIELD_SIZE_HEIGHT && (field[playerId][x][y+1].kind == fieldKind || field[playerId][x][y+1].kind == FIELD_KIND_NEEDLE)) {
		blockDestroy(x, y+1, ++count, playerId);
	}

	return;
}

void blockDamaging(int x, int y, int playerId)
{
	int fieldKind = field[playerId][x][y].kind;
	if (field[playerId][x][y].damagingEffectCount == FIELD_DAMAGING_EFFECT_FRAME) {
		return;
	}

	field[playerId][x][y].damagingEffectCount = FIELD_DAMAGING_EFFECT_FRAME;

	if (x-1 >= 0 && (field[playerId][x-1][y].kind == fieldKind || field[playerId][x-1][y].kind == FIELD_KIND_NEEDLE)) {
		blockDamaging(x-1, y, playerId);
	}
	if (x+1 < FIELD_SIZE_WIDTH && (field[playerId][x+1][y].kind == fieldKind || field[playerId][x+1][y].kind == FIELD_KIND_NEEDLE)) {
		blockDamaging(x+1, y, playerId);
	}
	if (y-1 >= 0 && (field[playerId][x][y-1].kind == fieldKind || field[playerId][x][y-1].kind == FIELD_KIND_NEEDLE)) {
		blockDamaging(x, y-1, playerId);
	}
	if (y+1 < FIELD_SIZE_HEIGHT && (field[playerId][x][y+1].kind == fieldKind || field[playerId][x][y+1].kind == FIELD_KIND_NEEDLE)) {
		blockDamaging(x, y+1, playerId);
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

