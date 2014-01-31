#include <amlib.h>
#include <agdraw.h>
#include <agetool.h>
#include <agtransfer.h>
#include <agesndmgr.h>
#include <vdpreg.h>
#include <aggl.h>
#include <agGamePad.h>

#include "title.h"
#include "game.h"
#include "export.h"
#include "draw_number.h"



#define MAIN_STATE_TITLE	0
#define MAIN_STATE_GAME		1


typedef struct mainData
{
	int state;
}MainData;


void _rtl_exit(void)
{
    _dprintf("_rtl_exit()\n");
    while(1)
        ;
}


static u32 DrawBuffer[ 4096*10 ];
AGESoundManagerData SndMgr;
static volatile u32 _SystemVSyncCount = 0;
MainData mainData;


void  main( void )  
{
	int i;
	AGDrawBuffer DBuf;
	u32 skip;
    u32 v;



	agpDisableCpuInterrupts();
	aglInitialize();
	agpEnableCpuInterrupts();

	mainData.state = MAIN_STATE_TITLE;

	// 初期化.
	ageSndMgrInit(&SndMgr, AGE_SOUND_ROM_OFFSET);

	// マスターボリュームの設定
	for( i=0 ; i<AG_SND_MAX_MASTERVOLUME ; i++ ) {
		ageSndMgrSetMasterVolume( i , 0x94 );
	};

	// チャンネルボリュームの設定
	for( i=0 ; i<AG_SND_MAX_CHANNEL ; i++ ) {
		ageSndMgrSetChannelVolume( i , 0xc0 );
	};


	_dprintf( ">> [Puzzle & Bullet] start.\n" );

	titleInit();

	skip = 0;
	agGamePadSyncInit( &_SystemVSyncCount, 60);
	v = _SystemVSyncCount;

	_dprintf( "Sync Wait\n");

	while( 1 ) {

		agGamePadSync();
		ageSndMgrRun();

		switch (mainData.state) {
			case MAIN_STATE_TITLE:
			{
				if (isTitleEnd()) {
					mainData.state = MAIN_STATE_GAME;
					gameInit();
				}
				titleFunc();
			}
				break;

			case MAIN_STATE_GAME:
				if (isGameEnd()) {
					mainData.state = MAIN_STATE_TITLE;
					titleInit();
				}
				gameFunc();
				break;
		}
		

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
		switch (mainData.state) {
			case MAIN_STATE_TITLE:
				titleDraw(&DBuf);
				break;

			case MAIN_STATE_GAME:
				gameDraw(&DBuf);
				break;
		}

		// ディスプレイリスト生成終了
		agDrawEODL( &DBuf );

		// ディスプレイリストを転送して描画終了を待つ
		agTransferDrawDMA( &DBuf );

		aglWaitVSync();
		aglSwap();
	};
}
