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
#define AGE_SOUND_ROM_OFFSET	(0x800000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_NUMBER_0	(0)
#define AG_CG_NUMBER_1	(1)
#define AG_CG_NUMBER_2	(2)
#define AG_CG_NUMBER_3	(3)
#define AG_CG_NUMBER_4	(4)
#define AG_CG_NUMBER_5	(5)
#define AG_CG_NUMBER_6	(6)
#define AG_CG_NUMBER_7	(7)
#define AG_CG_NUMBER_8	(8)
#define AG_CG_NUMBER_9	(9)
#define AG_CG_BLOCK_BLUE	(10)
#define AG_CG_BLOCK_GREEN	(11)
#define AG_CG_BLOCK_NEEDLE	(12)
#define AG_CG_BLOCK_RED	(13)
#define AG_CG_MAKO_BULLET_LEFT	(14)
#define AG_CG_MAKO_BULLET_RIGHT	(15)
#define AG_CG_STAGE_BG	(16)
#define AG_CG_MAKO_CUT_IN	(17)
#define AG_CG_GAME_BG	(18)
#define AG_CG_SCORE_NUMBER_0	(19)
#define AG_CG_SCORE_NUMBER_1	(20)
#define AG_CG_SCORE_NUMBER_2	(21)
#define AG_CG_SCORE_NUMBER_3	(22)
#define AG_CG_SCORE_NUMBER_4	(23)
#define AG_CG_SCORE_NUMBER_5	(24)
#define AG_CG_SCORE_NUMBER_6	(25)
#define AG_CG_SCORE_NUMBER_7	(26)
#define AG_CG_SCORE_NUMBER_8	(27)
#define AG_CG_SCORE_NUMBER_9	(28)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_MAKO_STAND	(0)
#define AG_RP_MAKO_RUN	(1)
#define AG_RP_MAKO_JUMP	(2)
#define AG_RP_LEMI_STAND	(3)
#define AG_RP_LEMI_RUN	(4)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[29];
extern const AGERM3Member ageRM3[5];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
