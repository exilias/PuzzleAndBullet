#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_BLUE_1 */
	{        140,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_BLOCK_BLUE_2 */
	{        340,          0,   50,   50,   32,  8,       1888, NULL },		/* AG_CG_BLOCK_BLUE_3 */
	{        576,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_GREEN_1 */
	{        716,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_BLOCK_GREEN_2 */
	{        916,          0,   50,   50,   32,  8,       1856, NULL },		/* AG_CG_BLOCK_GREEN_3 */
	{       1148,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_RED_1 */
	{       1288,          0,   50,   50,   32,  8,       1664, NULL },		/* AG_CG_BLOCK_RED_2 */
	{       1496,          0,   50,   50,   32,  8,       1920, NULL },		/* AG_CG_BLOCK_RED_3 */
	{       1736,          0,   50,   50,   32,  8,       2240, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{       2016,          0,  450,  550,  232,  8,      19584, NULL },		/* AG_CG_GAME_BG_STAGE_BACK */
	{       4464,          0,  350,  150,  176,  8,       5376, NULL },		/* AG_CG_GAME_BG_CLOUD_BIG */
	{       5136,          0,  200,   80,  104,  8,       2656, NULL },		/* AG_CG_GAME_BG_CLOUD_SMALL */
	{       5468,          0, 1024,  120,  512,  8,       6624, NULL },		/* AG_CG_GAME_BG_SAND */
	{       6296,          0, 1024,  768,  512,  8,      23424, NULL },		/* AG_CG_GAME_BG_SKY */
	{       9224,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{      10000,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      16170,          0,   12,   12,   12,  3,        256, NULL },		/* AG_CG_LEMI_BULLET */
	{      16202,          0,   12,   12,   12,  3,        176, NULL },		/* AG_CG_MAKO_BULLET */
	{      16224,          0, 1024,  300,  512,  8,      78272, NULL },		/* AG_CG_CUTIN_LEMI */
	{      26008,          0, 1024,  300,  512,  8,      81696, NULL },		/* AG_CG_CUTIN_MAKO */
	{      36220,          0,  410,   90,  208,  8,       1664, NULL },		/* AG_CG_SCORE_BG */
	{      36428,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      36576,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      36668,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      36812,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      36960,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      37088,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      37228,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      37468,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      37628,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      37868,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      38108,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      38336,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      38572,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      38812,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      39028,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      39280,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     11108,     11264,     11420,     11576,     11736,     11896,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_RUN */
	     12077,     12225,     12381,     12529,     12681,     12837,     12985,     13133,
	     13281,     13437,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_JUMP */
	     13610,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     13787,     13915,     14043,     14171,     14307,     14443,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     14600,     14736,     14876,     15016,     15156,     15296,     15432,     15572,
	     15712,     15852,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     16017,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_EFFECT_BOMB */
	     39544,     39704,     39880,     40072,     40312,     40568,     40844,     41128,
	     41420,     41696,     41952,     42184,     42376,     42536,     42680,     42776,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     42841,     43101,     43401,     43745,     44121,     44605,     45089,     45569,
	     46033,     46489,     46933,     47345,     47749,     48105,     48289,     48445,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     48582,     48782,     49026,     49286,     49566,     49882,     50214,     50554,
	     50894,     51190,     51394,     51582,     51746,     51926,     52082,     52230,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     52355,     52499,     52627,     52735,     52835,     52931,     53019,     53099,
	     53175,     53251,     53323,     53387,     53451,     53515,     53579,     53643,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      11088,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      12057,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_RUN */
	{      13590,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_JUMP */
	{      13767,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      14580,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      15997,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      39524,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      42821,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      48562,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      52335,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
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
const AGESoundRomMember ageSRM[] = {
	/* Ch, Length */
	{ 1,      857 },		/* AS_SND_MAKO_GRADE_MAX */
	{ 1,      347 },		/* AS_SND_MAKO_JUMP */
	{ 1,     1526 },		/* AS_SND_MAKO_LEVEL_UP */
	{ 1,     1678 },		/* AS_SND_MAKO_LOSE */
	{ 1,     1221 },		/* AS_SND_MAKO_SELECTED_CHARACTER */
	{ 1,     2409 },		/* AS_SND_MAKO_SKILL_1 */
	{ 1,     1873 },		/* AS_SND_MAKO_SKILL_2 */
	{ 1,     1736 },		/* AS_SND_MAKO_WIN */
	{ 1,     1417 },		/* AS_SND_LEMI_GRADE_MAX */
	{ 1,      277 },		/* AS_SND_LEMI_JUMP */
	{ 1,     1741 },		/* AS_SND_LEMI_LEVEL_UP */
	{ 1,     1246 },		/* AS_SND_LEMI_LOSE */
	{ 1,     1718 },		/* AS_SND_LEMI_SELECTED_CHARACTER */
	{ 1,     1607 },		/* AS_SND_LEMI_SKILL_1 */
	{ 1,      937 },		/* AS_SND_LEMI_SKILL_2 */
	{ 1,     1720 },		/* AS_SND_LEMI_WIN */
	{ 2,    51850 },		/* AS_SND_GAME_BGM */
	{ 2,     1282 },		/* AS_SND_SE_MAKO_WEAPON */
	{ 1,      855 },		/* AS_SND_SE_USE_SKILL */
	{ 2,      391 },		/* AS_SND_SE_LEMI_WEAPON */
	{ 2,      208 },		/* AS_SND_SE_JUMP */
	{ 1,     1529 },		/* AS_SND_SE_BLOCK_CRASH */
	{ 2,     4048 },		/* AS_SND_SE_LEVEL_MAX */
	{ 2,     4336 },		/* AS_SND_SE_LEMI_SKILL */
	{ 2,      835 },		/* AS_SND_SE_TOUCH_NEEDLE */
	{ 2,      653 },		/* AS_SND_SE_LEVEL_UP */
	{ 2,     1619 },		/* AS_SND_SE_MAKO_SKILL */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };
