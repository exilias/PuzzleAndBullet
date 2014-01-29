#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0, 1024,  764,  512,  6,      34456, NULL },		/* AG_CG_GAME_BG */
	{       4307,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_BLUE_1 */
	{       4447,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_BLOCK_BLUE_2 */
	{       4647,          0,   50,   50,   32,  8,       1888, NULL },		/* AG_CG_BLOCK_BLUE_3 */
	{       4883,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_GREEN_1 */
	{       5023,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_BLOCK_GREEN_2 */
	{       5223,          0,   50,   50,   32,  8,       1856, NULL },		/* AG_CG_BLOCK_GREEN_3 */
	{       5455,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_BLOCK_RED_1 */
	{       5595,          0,   50,   50,   32,  8,       1664, NULL },		/* AG_CG_BLOCK_RED_2 */
	{       5803,          0,   50,   50,   32,  8,       1920, NULL },		/* AG_CG_BLOCK_RED_3 */
	{       6043,          0,   50,   50,   32,  8,       2240, NULL },		/* AG_CG_BLOCK_NEEDLE */
	{       6323,          0,   80,  530,   40,  8,       6208, NULL },		/* AG_CG_GAUGE_BG */
	{       7099,          0,  450,  550,  232,  8,      49952, NULL },		/* AG_CG_GAME_BG_STAGE_BACK_LEMI */
	{      13343,          0,  450,  550,  232,  8,      44960, NULL },		/* AG_CG_GAME_BG_STAGE_BACK_MAKO */
	{      18963,          0,  450,  550,  232,  8,       8704, NULL },		/* AG_CG_GAME_BG_STAGE_FRONT */
	{      22730,          0,   12,   12,   12,  3,        168, NULL },		/* AG_CG_MAKO_BULLET_LEFT */
	{      22751,          0,   12,   12,   12,  3,        176, NULL },		/* AG_CG_MAKO_BULLET_RIGHT */
	{      25176,          0, 1024,  300,  512,  8,       8832, NULL },		/* AG_CG_MAKO_CUT_IN */
	{      26280,          0, 1024,  300,  512,  8,     108640, NULL },		/* AG_CG_CUTIN_LEMI */
	{      39860,          0,  410,   90,  208,  8,       1664, NULL },		/* AG_CG_SCORE_BG */
	{      40068,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_0 */
	{      40216,          0,   45,   50,   24,  8,        736, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_1 */
	{      40308,          0,   45,   50,   24,  8,       1152, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_2 */
	{      40452,          0,   45,   50,   24,  8,       1184, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_3 */
	{      40600,          0,   45,   50,   24,  8,       1024, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_4 */
	{      40728,          0,   45,   50,   24,  8,       1120, NULL },		/* AG_CG_WEAPON_GRADE_NUMBER_5 */
	{      40868,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_0 */
	{      41108,          0,   50,   60,   32,  8,       1280, NULL },		/* AG_CG_SCORE_NUMBER_1 */
	{      41268,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_2 */
	{      41508,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_3 */
	{      41748,          0,   50,   60,   32,  8,       1824, NULL },		/* AG_CG_SCORE_NUMBER_4 */
	{      41976,          0,   50,   60,   32,  8,       1888, NULL },		/* AG_CG_SCORE_NUMBER_5 */
	{      42212,          0,   50,   60,   32,  8,       1920, NULL },		/* AG_CG_SCORE_NUMBER_6 */
	{      42452,          0,   50,   60,   32,  8,       1728, NULL },		/* AG_CG_SCORE_NUMBER_7 */
	{      42668,          0,   50,   60,   32,  8,       2016, NULL },		/* AG_CG_SCORE_NUMBER_8 */
	{      42920,          0,   50,   60,   32,  8,       1952, NULL },		/* AG_CG_SCORE_NUMBER_9 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_MAKO_IDLE */
	     20071,     20227,     20383,     20539,     20699,     20859,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_MAKO_RUN */
	     21040,     21188,     21344,     21492,     21644,     21800,     21948,     22096,
	     22244,     22400,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_MAKO_JUMP */
	     22573,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_LEMI_IDLE */
	     22793,     22921,     23049,     23177,     23313,     23449,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_LEMI_RUN */
	     23606,     23742,     23882,     24022,     24162,     24302,     24438,     24578,
	     24718,     24858,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_LEMI_JUMP */
	     25023,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_EFFECT_BOMB */
	     43184,     43344,     43520,     43712,     43952,     44208,     44484,     44768,
	     45060,     45336,     45592,     45824,     46016,     46176,     46320,     46416,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_EFFECT_SUNRISE */
	     46481,     46741,     47041,     47385,     47761,     48245,     48729,     49209,
	     49673,     50129,     50573,     50985,     51389,     51745,     51929,     52085,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_EFFECT_GRADE_MAX */
	     52222,     52422,     52666,     52926,     53206,     53522,     53854,     54194,
	     54534,     54830,     55034,     55222,     55386,     55566,     55722,     55870,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_EFFECT_LEVEL_UP */
	     55995,     56139,     56267,     56375,     56475,     56571,     56659,     56739,
	     56815,     56891,     56963,     57027,     57091,     57155,     57219,     57283,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{      20051,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_MAKO_IDLE */
	{      21020,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_MAKO_RUN */
	{      22553,   40,   40,   7680,      1, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_MAKO_JUMP */
	{      22773,   40,   40,   7680,      6, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_LEMI_IDLE */
	{      23586,   40,   40,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_LEMI_RUN */
	{      25003,   40,   40,   7680,      1, 2, 1, ageRM3Offsets0005, NULL        },		/* AG_RP_LEMI_JUMP */
	{      43164,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_EFFECT_BOMB */
	{      46461,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_EFFECT_SUNRISE */
	{      52202,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_EFFECT_GRADE_MAX */
	{      55975,  128,  128,   7680,     16, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_EFFECT_LEVEL_UP */
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
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };
