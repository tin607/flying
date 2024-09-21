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
 * \brief ������Сָ�����εĿ�͸�
 * \note �ھ��ε����������dx,�ھ��ε���������dy�� dx��dy�������ɷ���ֵ���������ӿ�͸ߣ�������С��
 */
bool_t awge_gui_rect_inflate (awge_engine_rect_t *p_rect, int dx, int dy);

/**
 * \brief �жϿؼ��Ƿ���ѡ��������
 */
int awge_gui_intersect_rect (awge_engine_rect_t dst,
                             awge_engine_rect_t src1,
                             awge_engine_rect_t src2);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_GUI_HAL_H */

/* end of file */
