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

#include "awge_internal.h"

char *awge_util_int_to_string (int i)
{
    char *p_str = aw_mem_alloc(20 * sizeof(char));

    if (p_str == NULL) {
        return NULL;
    }

    aw_snprintf(p_str, 20, L"%d ", i);
    return p_str;
}

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
                           int           *p_ratio_y)
{
    float a_x, b_y;

    if (dest.x > start.x) {
        a_x = (float)(dest.x - start.x);
    } else {
        a_x = (float)(start.x - dest.x);
    }

    if (dest.y > start.y) {
        b_y = (float)(dest.y - start.y);
    } else {
        b_y = (float)(start.y - dest.y);
    }

    if (a_x == 0 || b_y == 0) {
        *p_ratio_x = 0;
        *p_ratio_y = 0;
        return;
    }

    if (b_y > a_x) {
        *p_ratio_y = speed;
        *p_ratio_x = (int)((speed * a_x) / b_y);
    } else {
        *p_ratio_x = speed;
        *p_ratio_y = (int)((speed * b_y) / a_x);
    }

    if (start.x - dest.x == 0) {
        *p_ratio_x = 0;
    }

    if (start.y - dest.y == 0) {
        *p_ratio_y = 0;
    }

    if (start.x - dest.x > 0) {
        *p_ratio_x = -*p_ratio_x;
    }

    if (start.y - dest.y > 0) {
        *p_ratio_y = -*p_ratio_y;
    }
}

/**
 * \brief swap two number
 */
static void __swap (int *p_a, int *p_b)
{
    int c = *p_a;
    *p_a  = *p_b;
    *p_b  = c;
}

/**
 * \brief get random number
 */
void awge_random_get (int range, int *p_array)
{
    int i;

    srand((unsigned)time(NULL));

    for (i = 0; i < range; ++i) {
        p_array[i]=i;
    }

    for (i = range; i > 0; --i) {
        int r = rand()%i;
        __swap(p_array[i-1], p_array[r]);
    }
}

/* end of file */
