/*******************************************************************************
*                                 AWorks
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2019 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief 
 *
 * \internal
 * \par Modification history
 * - 1.00 19-04-07  win, first implementation.
 * \endinternal
 */


#ifndef __AWGE_UTIL_H
#define __AWGE_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief integer transfer to string
 * \note don't support
 */
char *awge_util_int_to_string (int i);

/**
 * \brief get bevel speed
 *
 * \param[in] start
 * \param[in] dest
 * \param[in] speed
 * \param[in] ratio_x
 * \param[in] ratio_y
 */
void awge_bevel_speed_get (awge_point_t   start,
                           awge_point_t   dest,
                           int            speed,
                           int           *p_ratio_x,
                           int           *p_ratio_y);

/**
 * \brief get random number
 */
void awge_random_get (int range, int *p_array);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_UTIL_H */

/* end of file */
