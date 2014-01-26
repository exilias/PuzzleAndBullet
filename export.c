#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,   50,   50,   32,  6,        888, NULL },		/* AG_CG_BLOCK_BLUE */
	{        111,          0,   50,   50,   32,  6,        952, NULL },		/* AG_CG_BLOCK_GREEN */
	{        230,          0,   50,   50,   32,  6,        856, NULL },		/* AG_CG_BLOCK_RED */
	{        337,          0,   50,   50,   32,  8,       1280, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{        497,          0, 1024,  768,  512,  6,      14584, NULL },		/* AG_CG_GAME_BG */
	{       2320,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{       3096,          0,  450,  550,  232,  8,      39840, NULL },		/* AG_CG_GAME_BG_STAGE_BACK_MAKO */
	{       8076,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      11843,          0,   12,   12,   12,  3,        168, NULL },		/* AG_CG_MAKO_BULLET_LEFT */
	{      11864,          0,   12,   12,   12,  3,        176, NULL },		/* AG_CG_MAKO_BULLET_RIGHT */
	{      14289,          0, 1024,  300,  512,  8,       8832, NULL },		/* AG_CG_MAKO_CUT_IN */
	{      15393,          0,   40,   50,   24,  8,       1472, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      15577,          0,   40,   50,   24,  8,        992, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      15701,          0,   40,   50,   24,  8,       1504, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      15889,          0,   40,   50,   24,  8,       1568, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      16085,          0,   40,   50,   24,  8,       1312, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      16249,          0,   40,   50,   24,  8,       1440, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      16429,          0,   40,   50,   24,  8,       1472, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      16613,          0,   40,   50,   24,  8,       1344, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      16781,          0,   40,   50,   24,  8,       1568, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      16977,          0,   40,   50,   24,  8,       1504, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	      9184,      9340,      9496,      9652,      9812,      9972,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_RUN */
	     10153,     10301,     10457,     10605,     10757,     10913,     11061,     11209,
	     11357,     11513,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_JUMP */
	     11686,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     11906,     12034,     12162,     12290,     12426,     12562,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     12719,     12855,     12995,     13135,     13275,     13415,     13551,     13691,
	     13831,     13971,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     14136,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{       9164,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      10133,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_RUN */
	{      11666,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_JUMP */
	{      11886,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      12699,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      14116,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
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
