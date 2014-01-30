#ifndef __GAME__
#define __GAME__

#include <amlib.h>
#include <agdraw.h>
#include <vdpreg.h>


/*-- game.c --*/
void gameInit(void);
void gameFunc(void);
void gameDraw(AGDrawBuffer *DBuf);

int isGameEnd();

#endif /* __GAME__ */