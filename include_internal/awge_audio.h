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
 * - 1.00 18-06-23  win, first implementation.
 * \endinternal
 */


#ifndef __AWGE_AUDIO_H
#define __AWGE_AUDIO_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char      ck_id[4];
  uint32_t  ck_size;
  char      fcc_type;
  uint32_t  dw_data_offset;
  uint32_t  dw_flags;
} awge_mmck_info_t;

/**
 * \brief wav file parmeters
 */
typedef struct {
    uint16_t format;
    uint16_t channels;
    uint32_t samples_per_sec;
    uint32_t avg_bytes_per_sec;
    uint16_t block_align;
    uint16_t bits_per_sample;
    uint16_t cb_size;
} awge_wave_format_ex_t;

/**
 * \brief audio wav
 */
typedef struct {
    awge_wave_format_ex_t *p_format_ex;
    int                    fd;
    awge_mmck_info_t       ck_in;
    awge_mmck_info_t       ck_in_riff;
} awge_audio_wav_t;

/**
 * \brief 初始化wav
 */
aw_err_t awge_audio_wav_init (awge_audio_wav_t *p_audio_wav);

/**
 * \brief 打开WAV文件
 */
bool_t awge_audio_wav_open (awge_audio_wav_t *p_audio_wav, const char *p_path);

/**
 * \brief 启动读操作
 */
bool_t awge_audio_wav_read_start (awge_audio_wav_t *p_audio_wav);

/**
 * \brief 读取数据
 */
bool_t awge_audio_wav_read (awge_audio_wav_t *p_audio_wav,
                            uint32_t          size,
                            void             *p_data,
                            uint32_t         *p_nread);

/**
 * \brief 关闭wav文件
 */
bool_t awge_audio_close (awge_audio_wav_t *p_audio_wav);

/**
 * \brief 获取wav文件参数
 */
static inline
awge_wave_format_ex_t *awge_get_format_get (awge_audio_wav_t *p_audio_wav)
{
    return p_audio_wav->p_format_ex;
}

/**
 * \brief 获取ck_size
 */
static inline
uint32_t awge_ck_size_get(awge_audio_wav_t *p_audio_wav)
{
    return p_audio_wav.ck_in.ck_size;
}

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_AUDIO_H */

/* end of file */
