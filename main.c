#include <amlib.h>
#include <agdraw.h>
#include <agetool.h>
#include <agtransfer.h>
#include <agesndmgr.h>
#include <vdpreg.h>
#include <aggl.h>

#include "game.h"



void _rtl_exit(void)
{
    _dprintf("_rtl_exit()\n");
    while(1)
        ;
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

		// ディスプレイリスト生成終了
		agDrawEODL( &DBuf );

		// ディスプレイリストを転送して描画終了を待つ
		agTransferDrawDMA( &DBuf );

		aglWaitVSync();
		aglSwap();
	};
}
