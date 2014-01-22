#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_0 */
	{      32768,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_1 */
	{      65536,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_2 */
	{      98304,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_3 */
	{     131072,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_4 */
	{     163840,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_5 */
	{     196608,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_6 */
	{     229376,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_7 */
	{     262144,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_8 */
	{     294912,          0,  256,  256,  256,  0,     262144, NULL },		/* AG_CG_NUMBER_9 */
	{     327680,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_BLUE */
	{     328930,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_GREEN */
	{     330180,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{     331430,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_RED */
	{     334571,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET_LEFT */
	{     334643,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET_RIGHT */
	{     334715,          0,  500,  550,  500,  0,    1100000, NULL },		/* AG_CG_STAGE_BG */
	{     472215,          0, 1024,  300, 1024,  0,    1228800, NULL },		/* AG_CG_MAKO_CUT_IN */
	{     625815,          0, 1024,  768, 1024,  0,    3145728, NULL },		/* AG_CG_GAME_BG */
	{    1019031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{    1020031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{    1021031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{    1022031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{    1023031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{    1024031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{    1025031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{    1026031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{    1027031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{    1028031,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_STAND */
	    332700,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_RUN */
	    332881,    333029,    333185,    333333,    333485,    333641,    333789,    333937,
	    334085,    334241,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_JUMP */
	    334414,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{     332680,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_STAND */
	{     332861,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_RUN */
	{     334394,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_JUMP */
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
