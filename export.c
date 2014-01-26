#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0, 1024,  768,  512,  6,      22648, NULL },		/* AG_CG_GAME_BG */
	{       2831,          0,   50,   50,   32,  6,        888, NULL },		/* AG_CG_BLOCK_BLUE */
	{       2942,          0,   50,   50,   32,  6,        952, NULL },		/* AG_CG_BLOCK_GREEN */
	{       3061,          0,   50,   50,   32,  6,        856, NULL },		/* AG_CG_BLOCK_RED */
	{       3168,          0,   50,   50,   32,  8,       1280, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{       3328,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{       4104,          0,  450,  550,  232,  8,      39840, NULL },		/* AG_CG_GAME_BG_STAGE_BACK_MAKO */
	{       9084,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      12851,          0,   12,   12,   12,  3,        168, NULL },		/* AG_CG_MAKO_BULLET_LEFT */
	{      12872,          0,   12,   12,   12,  3,        176, NULL },		/* AG_CG_MAKO_BULLET_RIGHT */
	{      15297,          0, 1024,  300,  512,  8,       8832, NULL },		/* AG_CG_MAKO_CUT_IN */
	{      16401,          0, 1024,  300,  512,  8,      31520, NULL },		/* AG_CG_CUTIN_LEMI */
	{      20341,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      20489,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      20581,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      20725,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      20873,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      21001,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      21141,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      21381,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      21541,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      21781,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      22021,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      22249,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      22485,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      22725,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      22941,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      23193,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     10192,     10348,     10504,     10660,     10820,     10980,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_RUN */
	     11161,     11309,     11465,     11613,     11765,     11921,     12069,     12217,
	     12365,     12521,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_JUMP */
	     12694,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     12914,     13042,     13170,     13298,     13434,     13570,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     13727,     13863,     14003,     14143,     14283,     14423,     14559,     14699,
	     14839,     14979,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     15144,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      10172,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      11141,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_RUN */
	{      12674,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_JUMP */
	{      12894,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      13707,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      15124,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
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
