#include "bgm_manager.h"

#include <agesndmgr.h>


static SNDHANDLE handle;

void setCurrentBGMHandle(int rom_index,int loop)
{
	handle=ageSndMgrAlloc(rom_index, 0, loop, AGE_SNDMGR_PANMODE_LR12, 0);
	
	// ボリューム設定(フェードターゲットボリューム)
	ageSndMgrSetVolume( handle , 75 );

	// パン設定.
	ageSndMgrSetPan( handle , 128 );
}

void playCurrentBGM()
{
	ageSndMgrPlay(handle);
}

void releaseCurrentBGMHandle()
{
	ageSndMgrRelease(handle);
}

void stopCurrentBGM()
{
	ageSndMgrStop(handle);
}

void playBgm(int rom_index){
	stopCurrentBGM();
	releaseCurrentBGMHandle();
	setCurrentBGMHandle(rom_index,1);
	playCurrentBGM();
}