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


#ifndef __AWGE_VECTOR_H
#define __AWGE_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "awge_internal.h"

typedef void *awge_iterator_t;

typedef struct {
    void    *p_data;
    size_t   len;
    size_t   total_len;
    size_t   size;
} awge_vector_t;

/**
 * \brief create vector
 */
awge_vector_t *awge_vector_create (size_t size);

/**
 * \brief destory vector
 */
void awge_vector_destroy (awge_vector_t *p_v);

/**
 * \brief get vector length
 */
size_t awge_vector_length (awge_vector_t *p_v);

/**
 * \brief vector push
 */
aw_err_t awge_vector_push (awge_vector_t *p_v, void *p_mem);

/**
 * \brief vector pop
 */
aw_err_t awge_vector_pop (awge_vector_t *p_v, void *p_mem);

/**
 * \brief vector begin
 */
awge_iterator_t awge_vector_begin (awge_vector_t *p_v);

/**
 * \brief vector end
 */
awge_iterator_t awge_vector_end (awge_vector_t *p_v);

/**
 * \brief vector next
 */
awge_iterator_t awge_vector_next (awge_vector_t *p_v, awge_iterator_t iter);

/**
 * \brief iterate
 */
size_t awge_vector_iter_index (awge_vector_t *p_v, awge_iterator_t iter);

/**
 * \brief vector value
 */
aw_err_t awge_vector_val (awge_vector_t   *p_v,
                          awge_iterator_t  iter,
                          void             p_mem);

/**
 * \brief vector value at
 */
aw_err_t awge_vector_val_at (awge_vector_t *p_v, size_t index, void *p_mem);

/**
 * \brief vector insert
 */
aw_err_t awge_vector_insert (awge_vector_t    *p_v,
                             awge_iterator_t   iter,
                             void             *p_mem);

/**
 * \brief vector insert at
 */
aw_err_t awge_vector_insert_at (awge_vector_t *p_v,
                                size_t         index,
                                void          *p_mem);

/**
 * \brief remove iter
 */
aw_err_t awge_vector_rm (awge_vector_t *p_v, awge_iterator_t iter);

/**
 * \brief remove iter according to index
 */
aw_err_t awge_vector_rm_at (awge_vector_t *p_v, size_t index);

/**
 * \brief output vector information
 */
void awge_vector_info (awge_vector_t *p_v);

/**
 * \brief outptu all value
 */
aw_err_t awge_vector_print (awge_vector_t *p_v);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_VECTOR_H */

/* end of file */
