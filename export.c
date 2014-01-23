#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_BLUE */
	{       1250,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_GREEN */
	{       2500,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_RED */
	{       3750,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{       7679,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET_LEFT */
	{       7751,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET_RIGHT */
	{      10226,          0,  500,  550,  500,  0,    1100000, NULL },		/* AG_CG_STAGE_BG */
	{     147726,          0, 1024,  300, 1024,  0,    1228800, NULL },		/* AG_CG_MAKO_CUT_IN */
	{     301326,          0, 1024,  768, 1024,  0,    3145728, NULL },		/* AG_CG_GAME_BG */
	{     694542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{     695542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{     696542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{     697542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{     698542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{     699542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{     700542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{     701542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{     702542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{     703542,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	      5020,      5176,      5332,      5488,      5648,      5808,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_RUN */
	      5989,      6137,      6293,      6441,      6593,      6749,      6897,      7045,
	      7193,      7349,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_JUMP */
	      7522,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	      7843,      7971,      8099,      8227,      8363,      8499,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	      8656,      8792,      8932,      9072,      9212,      9352,      9488,      9628,
	      9768,      9908,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     10073,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{       5000,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{       5969,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_RUN */
	{       7502,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_JUMP */
	{       7823,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{       8636,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      10053,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
};

/***************************************************************/
/*                     Reserve Member Lists                    */
/***************************************************************/
const u32 ageReserve[1] = { 0 }; /* No Reserve Member */

/***************************************************************/
/*                      User Member Lists                      */
/***************************************************************/
const u32 ageUser[1] = { 0 }; /* No User Member */

/***************************************************************/
/*                      Vram Group Lists                       */
/***************************************************************/
const AGEVramGroup ageVG[] = { { 0, NULL } };
const s16 ageVGCnt = 0;

const u8* ageMotCommon[] = { NULL };
const AGEMotion ageMot[] = {
	{ 0, 0, 0, NULL, },
};
/***************************************************************/
/*                   Sound Rom Member Lists                    */
/***************************************************************/
const AGESoundRomMember ageSRM[] = { { 0, 0 } };
/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };
