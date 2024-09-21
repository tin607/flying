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
 * - 1.00 19-03-10  win, first implementation.
 * \endinternal
 */

#include "awge_internal.h"

/**
 * \brief 初始化wav
 */
aw_err_t awge_audio_wav_init (awge_audio_wav_t *p_audio_wav)
{
    p_audio_wav->fd          = 0;
    p_audio_wav->p_format_ex = NULL;

    return AW_OK;
}

/**
 * \brief 打开WAV文件
 */
bool_t awge_audio_wav_open (awge_audio_wav_t *p_audio_wav, const char *p_path)
{
    p_audio_wav->fd = awge_fs_open(p_path,
                                   NULL,
                                   AWGE_FS_CREAT | AWGE_FS_RDONLY);
    if(p_audio_wav->fd < 0) {
        return FALSE;
    }

    if (mmioDescend(hmmio, &ckInRIFF, NULL, 0) != 0) {
        return false;
    }

    if ((ckInRIFF.ckid    != FOURCC_RIFF)||
        (ckInRIFF.fccType != mmioFOURCC('W', 'A', 'V', 'E'))) {
        return false;
    }

    p_audio_wav->ck_in.ck_id = mmioFOURCC('f', 'm', 't', ' ');

    if (mmioDescend(hmmio, &ckIn, &ckInRIFF, MMIO_FINDCHUNK) != 0) {
        return false;
    }

    if (ckIn.cksize < sizeof(PCMWAVEFORMAT)) {
        return false;
    }

    wfex = (WAVEFORMATEX *)new char[ckIn.cksize];

    if (wfex == 0) {
        return false;
    }

    if (mmioRead(hmmio, (HPSTR)wfex, ckIn.cksize) != (LONG)ckIn.cksize) {
        return false;
    }

    if (mmioAscend(hmmio, &ckIn, 0) != 0) {
        return false;
    }

    return TRUE;
}

/* end of file */
