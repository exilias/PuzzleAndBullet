
#include "gauge.h"

#include <amlib.h>
#include "export.h"
#include "field.h"


#define GAUGE_BG_WIDTH			80
#define GAUGE_BG_HEIGHT			530
#define GAUGE_BG_MARGIN_X		5
#define GAUGE_BG_MARGIN_Y		5			
#define GAUGE_BG_ORIGIN1_X		432
#define GAUGE_BG_ORIGIN2_X		GAUGE_BG_ORIGIN1_X + GAUGE_BG_WIDTH + 5
#define GAUGE_BG_ORIGIN_Y		(FIELD_ORIGIN_Y - 10)



void gaugeInit()
{

}


void gaugeFunc()
{

}


void gaugeDraw(void* DBuf)
{
	AGDrawBuffer *_DBuf = (AGDrawBuffer *)DBuf;


	// ゲージの背景
	agDrawSETFCOLOR( _DBuf, ARGB( 255, 255, 0, 0 ) );
	ageTransferAAC( _DBuf, AG_CG_GAUGE_BG, 0, NULL, NULL );
	agDrawSETDBMODE( _DBuf, 0xff, 0, 2, 1 );
	agDrawSPRITE(_DBuf, TRUE, x4(GAUGE_BG_ORIGIN1_X), x4(GAUGE_BG_ORIGIN_Y), x4(GAUGE_BG_ORIGIN1_X + GAUGE_BG_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_HEIGHT));

	agDrawSPRITE(_DBuf, TRUE, x4(GAUGE_BG_ORIGIN2_X), x4(GAUGE_BG_ORIGIN_Y), x4(GAUGE_BG_ORIGIN2_X + GAUGE_BG_WIDTH), x4(GAUGE_BG_ORIGIN_Y + GAUGE_BG_HEIGHT));

	
}