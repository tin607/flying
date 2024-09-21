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
 * \brief AWGE文件适配层
 *
 * \internal
 * \par Modification history
 * - 1.00 19-03-31  win, first implementation.
 * \endinternal
 */

#ifndef __AWGE_FS_H
#define __AWGE_FS_H

#ifdef __cplusplus
extern "C" {
#endif

#define AWGE_FS_RDONLY    0x0000  /**< \brief 只读 */
#define AWGE_FS_WRONLY    0x0001  /**< \brief 只写 */
#define AWGE_FS_RDWR      0x0002  /**< \brief 可读写 */
#define AWGE_FS_APPEND    0x0008  /**< \brief 追加 */

#define AWGE_FS_EXCL      0x0100  /**< \brief 可执行 */
#define AWGE_FS_CREAT     0x0200  /**< \brief 创建 */
#define AWGE_FS_TRUNC     0x0400  /**< \brief 截断 */
#define AWGE_FS_DIRECTORY 0x0800  /**< \brief 目录  */

#define AWGE_FS_ACCMODE   (AWGE_FS_RDONLY | AWGE_FS_WRONLY | AWGE_FS_RDWR)

/**
 * \brief 打开文件
 */
int awge_fs_open (const char *p_path, int flags, mode_t mode);

#ifdef __cplusplus
}
#endif

#endif /* __AWGE_FS_H */

/* end of file */
