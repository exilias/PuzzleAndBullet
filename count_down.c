
#include "count_down.h"

#include <amlib.h>
#include <agesndmgr.h>
#include "export.h"
#include "cutin.h"


#define COUNT_DOWN_INTERVAL			60
#define COUNT_DOWN_CUTIN_DURATION	48

#define COUNT_DOWN_STATE_3			0
#define COUNT_DOWN_STATE_2			1
#define COUNT_DOWN_STATE_1			2
#define COUNT_DOWN_STATE_START		3
#define COUNT_DOWN_STATE_COMPLETED	4


#define COUNT_DOWN_NUMBER_WIDTH		300
#define COUNT_DOWN_NUMBER_HEIGHT	300

typedef struct countDownData {
	int state;
	int counter;
	int isFire;
}CountDown;



CountDown countDown;


void countDownInit()
{
	countDown.state  = COUNT_DOWN_STATE_3;
	countDown.counter = 0;
	countDown.isFire = FALSE;
}


void countDownFunc()
{
	if (!countDown.isFire) {
		return;
	}

	cutinFunc();

	switch (countDown.state) {
		case COUNT_DOWN_STATE_3:
			if (countDown.counter >= COUNT_DOWN_INTERVAL) {
				countDown.state = COUNT_DOWN_STATE_2;
				countDown.counter = 0;
				createCutinWithDurationAndSize(COUNT_DOWN_CUTIN_DURATION, COUNT_DOWN_NUMBER_WIDTH, COUNT_DOWN_NUMBER_HEIGHT, AG_CG_COUNT_DOWN_NUMBER_2);
			}
			break;

		case COUNT_DOWN_STATE_2:
			if (countDown.counter >= COUNT_DOWN_INTERVAL) {
				countDown.state = COUNT_DOWN_STATE_1;
				countDown.counter = 0;
				createCutinWithDurationAndSize(COUNT_DOWN_CUTIN_DURATION, COUNT_DOWN_NUMBER_WIDTH, COUNT_DOWN_NUMBER_HEIGHT, AG_CG_COUNT_DOWN_NUMBER_1);
			}
			break;

		case COUNT_DOWN_STATE_1:
			if (countDown.counter >= COUNT_DOWN_INTERVAL) {
				countDown.state = COUNT_DOWN_STATE_START;
				countDown.counter = 0;
				ageSndMgrPlayOneshot( AS_SND_SYSTEM_GAME_START, 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
			}
			break;

		case COUNT_DOWN_STATE_START:
			if (countDown.counter >= COUNT_DOWN_INTERVAL) {
				countDown.state = COUNT_DOWN_STATE_COMPLETED;
				countDown.counter = 0;
				countDown.isFire = FALSE;
			}
			break;

	}

	countDown.counter++;
}


void countDownDraw(void *DBuf)
{
	int fileId;
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;

	if (!countDown.isFire) {
		return;
	}

	cutinDraw(_DBuf);
}

void fireCountDown()
{
	countDown.state  = COUNT_DOWN_STATE_3;
	countDown.counter = 0;
	countDown.isFire = TRUE;
	createCutinWithDurationAndSize(COUNT_DOWN_CUTIN_DURATION, COUNT_DOWN_NUMBER_WIDTH, COUNT_DOWN_NUMBER_HEIGHT, AG_CG_COUNT_DOWN_NUMBER_3);
	ageSndMgrPlayOneshot( AS_SND_SYSTEM_COUNT_DOWN, 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
}

int isCountDownCompleted()
{
	return (countDown.state == COUNT_DOWN_STATE_COMPLETED);
}
