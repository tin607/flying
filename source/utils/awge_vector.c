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
*******************************************************************************/

/**
 * \file
 * \brief 
 *
 * \internal
 * \par Modification history
 * - 1.00 18-08-09  win, first implementation.
 * \endinternal
 */

#include <awge_internal.h>

#define __VECTOR_MIN_LEN    256

/**
 * \brief create vector
 */
awge_vector_t *awge_vector_create (size_t size)
{
    awge_vector_t *p_v = (awge_vector_t *)aw_mem_alloc(sizeof(struct awge_vector_t));

    if (p_v == NULL) {
        return NULL;
    }

    p_v->p_data = aw_mem_alloc(__VECTOR_MIN_LEN * size);

    if (p_v->p_data == NULL) {
        am_mem_free(p_v);
        return NULL;
    }

    p_v->size      = size;
    p_v->total_len = __VECTOR_MIN_LEN;
    p_v->len       = 0;

    return p_v;
}

/**
 * \brief destory vector
 */
void awge_vector_destroy (awge_vector_t *p_v)
{
    aw_mem_free(p_v->p_data);
    aw_mem_free(p_v);
}

/**
 * \brief get vector length
 */
size_t awge_vector_length (awge_vector_t *p_v)
{
    return p_v->len;
}

/**
 * \brief vector push
 */
aw_err_t awge_vector_push (awge_vector_t *p_v, void *p_mem)
{
    void *p_tmp = NULL;

    if (p_v->len >= p_v->total_len) {
        p_tmp            = p_v->p_data;
        p_v->total_len <<= 1;
        p_v->p_data      = aw_mem_realloc(p_v->p_data,
                                          p_v->total_len * p_v->size);

        if (p_v->p_data == NULL) {
            p_v->p_data      = p_tmp;
            p_v->total_len >>= 1;
            return -AW_ENOMEM;
        }
    }

    memcpy(p_v->p_data + p_v->len * p_v->size, p_mem, p_v->size);
    p_v->len++;

    return AW_OK;
}

/**
 * \brief vector pop
 */
aw_err_t awge_vector_pop (awge_vector_t *p_v, void *p_mem)
{
    void *p_tmp;

    if (p_v->len <= 0) {
        return -AW_EINVAL;
    }

    p_v->len--;
    memcpy(p_mem, p_v->p_data + p_v->len * p_v->size, p_v->size);

    if ((p_v->total_len >= (__VECTOR_MIN_LEN << 1)) &&
        (p_v->len       <= (p_v->total_len >> 1)))   {
        p_tmp            = p_v->p_data;
        p_v->total_len >>= 1;
        p_v->p_data      = aw_mem_realloc(p_v->p_data,
                                          p_v->total_len * p_v->size);

        if (p_v->p_data == NULL) {
            p_v->total_len <<= 1;
            p_v->p_data      = p_tmp;
            return -AW_ENOMEM;
        }
    }

    return AW_OK;
}

/**
 * \brief vector begin
 */
awge_iterator_t awge_vector_begin (awge_vector_t *p_v)
{
    return p_v->p_data;
}

/**
 * \brief vector end
 */
awge_iterator_t awge_vector_end (awge_vector_t *p_v)
{
    return p_v->p_data + (p_v->size * p_v->len);
}

/**
 * \brief memove foreward
 */
static inline
void __vector_memove_foreward (awge_vector_t *p_v, void *p_from, void *p_to)
{
    size_t  size = p_v->size;
    void   *p;

    for (p = p_to; p >= p_from; p -= size) {
        memcpy(p + size, p, size);
    }
}

#if 0

/**
 * \brief memove backward
 */
static inline
void __vector_memove_backward (awge_vector_t *p_v, void *p_from, void *p_to)
{
    memcpy(p_from, p_from + p_v->size, p_to - p_from);
}

#endif

/**
 * \brief iterate
 */
size_t awge_vector_iter_index (awge_vector_t *p_v, awge_iterator_t iter)
{
    return (iter - p_v->p_data) / p_v->size;
}

/**
 * \brief vector insert
 */
aw_err_t awge_vector_insert (awge_vector_t    *p_v,
                             awge_iterator_t   iter,
                             void             *p_mem)
{
    void *p_tmp = NULL;

    if (p_v->len >= p_v->total_len) {
        p_tmp            = p_v->p_data;
        p_v->total_len <<= 1;
        p_v->p_data      = aw_mem_realloc(p_v->p_data,
                                          p_v->total_len * p_v->size);

        if (p_v->p_data == NULL) {
            p_v->p_data      = p_tmp;
            p_v->total_len >>= 1;
            return -AW_ENOMEM;
        }
    }

    __vector_memove_foreward(p_v,
                             iter,
                             p_v->p_data + p_v->len * p_v->size);
    memcpy(iter, p_mem, p_v->size);
    p_v->len++;

    return AW_OK;
}

/**
 * \brief vector insert at
 */
aw_err_t awge_vector_insert_at (awge_vector_t *p_v,
                                size_t         index,
                                void          *p_mem)
{
    awge_iterator_t iter;

    if (index >= p_v->total_len) {
        p_v->len = index + 1;
        while (p_v->len >= p_v->total_len) {
            p_v->total_len <<= 1;
        }
        p_v->p_data = aw_mem_realloc(p_v->p_data,
                                     p_v->total_len * p_v->size);
        iter = p_v->p_data + p_v->size * index;
        memcpy(iter, p_mem, p_v->size);
    } else {
        iter = p_v->p_data + p_v->size * index;
        awge_vector_insert(p_v, iter, p_mem);
    }

    return AW_OK;
}

/**
 * \brief vector next
 */
awge_iterator_t awge_vector_next (awge_vector_t *p_v, awge_iterator_t iter)
{
    return iter + p_v->size;
}

/**
 * \brief vector value
 */
aw_err_t awge_vector_iter_val (awge_vector_t   *p_v,
                               awge_iterator_t  iter,
                               void            *p_mem)
{
    memcpy(p_mem, iter, p_v->size);
    return AW_OK;
}

/**
 * \brief vector value at
 */
aw_err_t awge_vector_val_at (awge_vector_t *p_v, size_t index, void *p_mem)
{
    memcpy(p_mem, p_v->p_data + index * p_v->size, p_v->size);
    return AW_OK;
}

/**
 * \brief remove iter
 */
aw_err_t awge_vector_rm (awge_vector_t *p_v, awge_iterator_t iter)
{
    awge_iterator_t from;
    awge_iterator_t end;

    from = iter;
    end  = awge_vector_end(p_v);
    memcpy(from, from + p_v->size, end - from);
    p_v->len--;

    if ((p_v->total_len >= (__VECTOR_MIN_LEN << 2)) &&
        (p_v->len       <= (p_v->total_len   >> 2))) {

        void *p_save = p_v->p_data;

        p_v->total_len >>= 1;
        p_v->p_data      = aw_mem_realloc(p_v->p_data,
                                          p_v->total_len * p_v->size);

        if (p_v->p_data == NULL) {
            p_v->total_len <<= 1;
            p_v->p_data      = p_save;
            return -AW_ENOMEM;
        }
    }

    return AW_OK;
}

/**
 * \brief remove iter according to index
 */
aw_err_t awge_vector_rm_at (awge_vector_t *p_v, size_t index)
{
    awge_iterator_t iter;

    iter = p_v->p_data + p_v->size * index;
    return awge_vector_rm(p_v, iter);
}

/**
 * \brief output vector information
 */
void awge_vector_info (awge_vector_t *p_v)
{
    AW_INFOF(("total :%s : %d\r\n", __func__, p_v->total_len));
    AW_INFOF(("len :%s : %d\r\n",     __func__, p_v->len));
    AW_INFOF(("size:%s : %d\r\n",     __func__, p_v->size));
}

void awge_vector_print (awge_vector_t *p_v)
{
    int             num;
    awge_iterator_t iter;

    if (awge_vector_length(p_v) == 0) {
        AW_INFOF(("null length cvector!!\r\n"));
        return;
    }

    for (iter  = awge_vector_begin(p_v);
         iter != awge_vector_end(p_v);
         iter  = awge_vector_next(p_v, iter)) {
        awge_vector_val(p_v, iter, &num);
        AW_INFOF(("value:%d at:%d\r\n", num, awge_vector_iter_index(p_v, iter)));
    }
}


/* end of file */
