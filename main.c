#include <amlib.h>
#include <agdraw.h>
#include <agetool.h>
#include <agtransfer.h>
#include <agesndmgr.h>
#include <vdpreg.h>
#include <aggl.h>
#include <agGamePad.h>

#include "game.h"
#include "export.h"
#include "draw_number.h"



void _rtl_exit(void)
{
    _dprintf("_rtl_exit()\n");
    while(1)
        ;
}


static u32 DrawBuffer[ 4096*10 ];
static volatile u32 _SystemVSyncCount = 0;

void  main( void )  
{
	AGDrawBuffer DBuf;
	u32 skip;
    u32 v;



	agpDisableCpuInterrupts();
	aglInitialize();
	agpEnableCpuInterrupts();

	_dprintf( ">> [Super Puzzle Platformer] start.\n" );

	gameInit();

	skip = 0;
	agGamePadSyncInit( &_SystemVSyncCount, 60);
	v = _SystemVSyncCount;

	_dprintf( "Sync Wait\n");

	//agglInitialize();
    //agglDisplaySize( FB_WIDTH , FB_HEIGHT );

	while( 1 ) {

		agGamePadSync();

		gameFunc();
		fieldFunc();

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


		// ディスプレイリスト生成終了
		agDrawEODL( &DBuf );

		// ディスプレイリストを転送して描画終了を待つ
		agTransferDrawDMA( &DBuf );

		aglWaitVSync();
		aglSwap();
	};
}
