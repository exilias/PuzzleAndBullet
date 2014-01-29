#ifndef __AG_EXPORT__
#define __AG_EXPORT__

#include <agexport.h>
#include <ag3d.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************/
/*                       FrameBuffer                           */
/***************************************************************/
#define AGE_FB_WIDTH	(1024)
#define AGE_FB_HEIGHT	(768)
#define AGE_DISP_WIDTH	(1024)
#define AGE_DISP_HEIGHT	(768)
#define AGE_FB_ADDR0	(7602176)
#define AGE_FB_ADDR1	(6815744)
#define AGE_ZB_ADDR	(6815744)
#define AGE_ZB_DEPTH	(4)
#define AGE_ZMD	(1)
#define AGE_AAC_ADDR	(13631488)
#define AGE_AAC_SIZE	(13631488)
#define AGE_SOUND_ROM_OFFSET	(0x400000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_GAME_BG	(0)
#define AG_CG_BLOCK_BLUE_1	(1)
#define AG_CG_BLOCK_BLUE_2	(2)
#define AG_CG_BLOCK_BLUE_3	(3)
#define AG_CG_BLOCK_GREEN_1	(4)
#define AG_CG_BLOCK_GREEN_2	(5)
#define AG_CG_BLOCK_GREEN_3	(6)
#define AG_CG_BLOCK_RED_1	(7)
#define AG_CG_BLOCK_RED_2	(8)
#define AG_CG_BLOCK_RED_3	(9)
#define AG_CG_BLOCK_NEEDLE	(10)
#define AG_CG_GAUGE_BG	(11)
#define AG_CG_GAME_BG_STAGE_BACK_LEMI	(12)
#define AG_CG_GAME_BG_STAGE_BACK_MAKO	(13)
#define AG_CG_GAME_BG_STAGE_FRONT	(14)
#define AG_CG_MAKO_BULLET_LEFT	(15)
#define AG_CG_MAKO_BULLET_RIGHT	(16)
#define AG_CG_MAKO_CUT_IN	(17)
#define AG_CG_CUTIN_LEMI	(18)
#define AG_CG_SCORE_BG	(19)
#define AG_CG_WEAPON_GRADE_NUMBER_0	(20)
#define AG_CG_WEAPON_GRADE_NUMBER_1	(21)
#define AG_CG_WEAPON_GRADE_NUMBER_2	(22)
#define AG_CG_WEAPON_GRADE_NUMBER_3	(23)
#define AG_CG_WEAPON_GRADE_NUMBER_4	(24)
#define AG_CG_WEAPON_GRADE_NUMBER_5	(25)
#define AG_CG_SCORE_NUMBER_0	(26)
#define AG_CG_SCORE_NUMBER_1	(27)
#define AG_CG_SCORE_NUMBER_2	(28)
#define AG_CG_SCORE_NUMBER_3	(29)
#define AG_CG_SCORE_NUMBER_4	(30)
#define AG_CG_SCORE_NUMBER_5	(31)
#define AG_CG_SCORE_NUMBER_6	(32)
#define AG_CG_SCORE_NUMBER_7	(33)
#define AG_CG_SCORE_NUMBER_8	(34)
#define AG_CG_SCORE_NUMBER_9	(35)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_MAKO_IDLE	(0)
#define AG_RP_MAKO_RUN	(1)
#define AG_RP_MAKO_JUMP	(2)
#define AG_RP_LEMI_IDLE	(3)
#define AG_RP_LEMI_RUN	(4)
#define AG_RP_LEMI_JUMP	(5)
#define AG_RP_EFFECT_BOMB	(6)
#define AG_RP_EFFECT_SUNRISE	(7)
#define AG_RP_EFFECT_GRADE_MAX	(8)
#define AG_RP_EFFECT_LEVEL_UP	(9)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                       Sound Member Symbol                   */
/***************************************************************/
#define AS_SND_MAKO_GRADE_MAX	(0)
#define AS_SND_MAKO_JUMP	(1)
#define AS_SND_MAKO_LEVEL_UP	(2)
#define AS_SND_MAKO_LOSE	(3)
#define AS_SND_MAKO_SELECTED_CHARACTER	(4)
#define AS_SND_MAKO_SKILL_1	(5)
#define AS_SND_MAKO_SKILL_2	(6)
#define AS_SND_MAKO_WIN	(7)
#define AS_SND_LEMI_GRADE_MAX	(8)
#define AS_SND_LEMI_JUMP	(9)
#define AS_SND_LEMI_LEVEL_UP	(10)
#define AS_SND_LEMI_LOSE	(11)
#define AS_SND_LEMI_SELECTED_CHARACTER	(12)
#define AS_SND_LEMI_SKILL_1	(13)
#define AS_SND_LEMI_SKILL_2	(14)
#define AS_SND_LEMI_WIN	(15)
#define AS_SND_GAME_BGM	(16)
#define AS_SND_SE_MAKO_WEAPON	(17)
#define AS_SND_SE_USE_SKILL	(18)
#define AS_SND_SE_LEMI_WEAPON	(19)
#define AS_SND_SE_JUMP	(20)
#define AS_SND_SE_BLOCK_CRASH	(21)
#define AS_SND_SE_LEVEL_MAX	(22)
#define AS_SND_SE_LEMI_SKILL	(23)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[36];
extern const AGERM3Member ageRM3[10];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[24];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
