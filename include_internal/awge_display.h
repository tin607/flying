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
 * \brief 
 *
 * \internal
 * \par Modification history
 * - 1.00 18-06-23  win, first implementation.
 * \endinternal
 */


#ifndef __AWGE_DISPLAY_H
#define __AWGE_DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

struct awge_display {
    bool_t mode_changed;
};

aw_err_t awge_display_init (struct awge_display *p_dispaly);

void awge_display_mode_save (struct awge_display *p_display);
void awge_display_mode_reset ();
bool_t awge_display_mode_change (int width, int height);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_DISPLAY_H */

/* end of file */
