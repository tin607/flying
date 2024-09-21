/*******************************************************************************
*                                 AWorks
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      ametal.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief Ƕ��ʽ��Ϸ����
 *
 * \internal
 * \par Modification history
 * - 1.00 18-06-23  win, first implementation.
 * \endinternal
 */


#ifndef __AWGE_ENGINE_H
#define __AWGE_ENGINE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief �ṹ����������ϽǺ����½ǵ�����
 */
typedef struct {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
} awge_engine_rect_t;

/**
 * \brief ����
 */
struct awge_engine {

    /** \brief ���ڱ��� */
    const char *p_wnd_title;

    int wnd_width;
    int wnd_height;
    int scrn_width;
    int scrn_height;

    bool_t fullscreen;

    awge_engine_rect_t rc_old;

    int32_t style;
    int32_t ex_style;

    struct awge_display *p_display;

    int    interval_time;
    bool_t is_sleep;

    bool_t keys[256];
    int    game_state;
};

/**
 * \brief ��ʼ����Ϸ����
 */
aw_err_t awge_engine_init (struct awge_engine *p_engine);

/**
 * \brief ��Ϸ���ڳ�ʼ��
 */
bool_t awge_engine_wnd_init (struct awge_engine *p_engine);


typedef enum {
    AWGE_ENGINE_WA_ACTIVE,
    AWGE_ENGINE_WA_CLICK_ACTIVE,
    AWGE_ENGINE_WA_TOUCH_ACTIVE,
    AWGE_ENGINE_WA_INACTIVE,
} awge_engine_wa_t;

/**
 * \brief ��Ϸ�¼�
 */
aw_err_t awge_engine_event (struct awge_engine *p_engine,
                            uint32_t            msg,
                            awge_engine_wa_t    wa_param,
                            void               *p_arg);

/**
 * \brief ������Ϸ����
 */
aw_err_t awge_engine_start (struct awge_engine *p_engine);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_ENGINE_H */

/* end of file */
