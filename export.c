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
	{     329213,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_BLUE */
	{     330463,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_GREEN */
	{     331713,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{     332963,          0,   50,   50,   50,  0,      10000, NULL },		/* AG_CG_BLOCK_RED */
	{     334213,          0,   40,   40,   40,  0,       6400, NULL },		/* AG_CG_MAKO_LEFT */
	{     335013,          0,   40,   40,   40,  0,       6400, NULL },		/* AG_CG_MAKO_RIGHT */
	{     335813,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET_LEFT */
	{     335885,          0,   12,   12,   12,  0,        576, NULL },		/* AG_CG_MAKO_BULLET_RIGHT */
	{     335957,          0,  500,  550,  500,  0,    1100000, NULL },		/* AG_CG_STAGE_BG */
	{     473457,          0, 1024,  300, 1024,  0,    1228800, NULL },		/* AG_CG_MAKO_CUT_IN */
	{     627057,          0, 1024,  768, 1024,  0,    3145728, NULL },		/* AG_CG_GAME_BG */
	{    1020273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{    1021273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{    1022273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{    1023273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{    1024273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{    1025273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{    1026273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{    1027273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{    1028273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{    1029273,          0,   40,   50,   40,  0,       8000, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_RUN */
	    327700,    327848,    328004,    328152,    328304,    328460,    328608,    328756,
	    328904,    329060,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{     327680,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_RUN */
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
