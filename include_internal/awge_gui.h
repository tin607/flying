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
 * - 1.00 18-07-21  win, first implementation.
 * \endinternal
 */


#ifndef __AWGE_GUI_HAL_H
#define __AWGE_GUI_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

/**
 * \brief 增大或减小指定矩形的宽和高
 * \note 在矩形的左和右增加dx,在矩形的上下增加dy。 dx和dy参数是由符号值。正数增加宽和高，负数减小。
 */
bool_t awge_gui_rect_inflate (awge_engine_rect_t *p_rect, int dx, int dy);

/**
 * \brief 判断控件是否在选择区域中
 */
int awge_gui_intersect_rect (awge_engine_rect_t dst,
                             awge_engine_rect_t src1,
                             awge_engine_rect_t src2);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_GUI_HAL_H */

/* end of file */
