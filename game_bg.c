
#include "game_bg.h"

#include <amlib.h>
#include "export.h"
#include "math.h"


#define GAME_BG_OBJECT_MAX	2

typedef struct gameBgObject
{
	int x, y;
	int dx, dy;
	int interval;
	int counter;
	int fileId;
}GameBgObject;


GameBgObject gameBgObject[GAME_BG_OBJECT_MAX];


void gameBgInit()
{
	// 雲（大）
	gameBgObject[0].x = 100;
	gameBgObject[0].y = 20;
	gameBgObject[0].dx = 1;
	gameBgObject[0].dy = 0;
	gameBgObject[0].interval = 3;
	gameBgObject[0].counter = 0;
	gameBgObject[0].fileId = AG_CG_GAME_BG_CLOUD_BIG;

	// 雲（小）
	gameBgObject[1].x = 400;
	gameBgObject[1].y = 200;
	gameBgObject[1].dx = 1;
	gameBgObject[1].dy = 0;
	gameBgObject[1].interval = 10;
	gameBgObject[1].counter = 0;
	gameBgObject[1].fileId = AG_CG_GAME_BG_CLOUD_SMALL;
}


void gameBgFunc()
{
	int i;

	for (i = 0; i < GAME_BG_OBJECT_MAX; i++) {
		if (gameBgObject[i].counter >= gameBgObject[i].interval) {
			gameBgObject[i].x += gameBgObject[i].dx;
			gameBgObject[i].y += gameBgObject[i].dy;
			gameBgObject[i].counter = 0;
		}
		gameBgObject[i].counter++;
	}
}


void gameBgDraw(void* DBuf)
{
	int i;
	int w, h;

	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;


	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );

	ageTransferAAC( _DBuf, AG_CG_GAME_BG_SKY, 0, &w, &h );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, 0, 0, x4(w), x4(h));

	for (i = 0; i < GAME_BG_OBJECT_MAX; i++) {
		ageTransferAAC( _DBuf, gameBgObject[i].fileId, 0, &w, &h );
		agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE(_DBuf, TRUE, x4(gameBgObject[i].x), x4(gameBgObject[i].y), x4(gameBgObject[i].x + w), x4(gameBgObject[i].y + h));

		if (gameBgObject[i].x >= 1024) {
				gameBgObject[i].x = -w;
			}
	}
}


