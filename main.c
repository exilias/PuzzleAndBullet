#include <amlib.h>
#include <agdraw.h>
#include <agetool.h>
#include <agtransfer.h>
#include <agesndmgr.h>
#include <vdpreg.h>
#include <aggl.h>

#include "game.h"
#include "export.h"



void _rtl_exit(void)
{
    _dprintf("_rtl_exit()\n");
    while(1)
        ;
}

void drawNumberGraph(int number ,int x, int y, int size_x, int size_y , int order ,AGDrawBuffer* DBuf) {
	int i, n;
	int draw_x;
	int id[10] = {	AG_CG_NUMBER_0, 
					AG_CG_NUMBER_1, 
					AG_CG_NUMBER_2,
					AG_CG_NUMBER_3,
					AG_CG_NUMBER_4,
					AG_CG_NUMBER_5,
					AG_CG_NUMBER_6,
					AG_CG_NUMBER_7,
					AG_CG_NUMBER_8,
					AG_CG_NUMBER_9};
					
	draw_x = x + (order-1)*size_x;

	for(i=0;i<order;i++) {
		n = number%10;
		agDrawSETFCOLOR( DBuf, ARGB( 255, 255, 0, 0 ) );
		ageTransferAAC( DBuf, id[n], 0, NULL, NULL );
		agDrawSETDBMODE( DBuf, 0xff, 0, 2, 1 );
		agDrawSPRITE( DBuf, 1, draw_x, y, draw_x+size_x, y+size_y );
		number /= 10;
		draw_x -= size_x;
	}
}



static u32 DrawBuffer[ 4096*10 ];

void  main( void )  
{
	AGDrawBuffer DBuf;



	agpDisableCpuInterrupts();
	aglInitialize();
	agpEnableCpuInterrupts();

	_dprintf( ">> [Super Puzzle Platformer] start.\n" );

	gameInit();

	//agglInitialize();
    //agglDisplaySize( FB_WIDTH , FB_HEIGHT );

	while( 1 ) {

		gameFunc();

		// ディスプレイリストの作成
		agDrawBufferInit( &DBuf , DrawBuffer );

		// VRAM_FB設定
		agDrawSETDAVR( &DBuf , 0 , 0 , aglGetDrawFrame() , 0 , 0 );
		agDrawSETDAVF( &DBuf, 0, 0, FB_WIDTH<<2, FB_HEIGHT<<2 );

		// 背景
		agDrawSETFCOLOR( &DBuf, ARGB( 128, 255, 255, 255 ) );
		agDrawSETDBMODE( &DBuf, 0xff, 0, 0, 1 );
		agDrawSPRITE( &DBuf, 0, 0, 0, FB_WIDTH<<2, FB_HEIGHT<<2 );

		// ゲーム画面の描画
		gameDraw(&DBuf);

		// GUIの描画
		// FPS
		// drawNumberGraph(aglGetReg(AG_REG_SYSMNTR) /*表示させたい数字(int)*/, 10<<2 表示させたいX座標, 10<<2 /*表示させたいY座標*/, 10<<2/*1つの文字の幅*/, 10<<2/*1つの文字の高さ*/, 10/*桁数*/, &DBuf);

		// ディスプレイリスト生成終了
		agDrawEODL( &DBuf );

		// ディスプレイリストを転送して描画終了を待つ
		agTransferDrawDMA( &DBuf );

		aglWaitVSync();
		aglSwap();
	};
}
