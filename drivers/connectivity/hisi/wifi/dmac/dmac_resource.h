/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : dmac_resource.h
  �� �� ��   : ����
  ��    ��   : z00326350
  ��������   : 2015��4��31��
  ����޸�   :
  ��������   : dmac_resource.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��1��31��
    ��    ��   : z00326350
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __HMAC_RESOURCE_H__
#define __HMAC_RESOURCE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "oal_types.h"
#include "oal_queue.h"
#include "mac_resource.h"
#include "mac_device.h"
#include "dmac_device.h"

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_RESOURCE_H

/*****************************************************************************
  2 �궨��
*****************************************************************************/

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

/* �洢dmac device�ṹ����Դ�ṹ�� */
typedef struct
{
    dmac_device_stru    ast_dmac_dev_info[MAC_RES_MAX_DEV_NUM];
    oal_queue_stru      st_queue;
    oal_uint            aul_idx[MAC_RES_MAX_DEV_NUM];
    oal_uint8           auc_user_cnt[MAC_RES_MAX_DEV_NUM];
#ifdef _PRE_WLAN_FEATURE_DOUBLE_CHIP
    oal_uint8           auc_resv[2];   /* ��оƬ��MAC_RES_MAX_DEV_NUM��1��˫оƬ��MAC_RES_MAX_DEV_NUM��2 */
#else
    oal_uint8           auc_resv[3];
#endif
}dmac_res_device_stru;

/* �洢dmac res��Դ�ṹ�� */
typedef struct
{
    dmac_res_device_stru st_dmac_dev_res;
}dmac_res_stru;

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/
extern dmac_res_stru    g_st_dmac_res;

/*****************************************************************************
  10 ��������
*****************************************************************************/
extern oal_uint32  dmac_res_alloc_mac_dev(oal_uint32 ul_dev_idx);
extern oal_uint32  dmac_res_free_mac_dev(oal_uint32 ul_dev_idx);
extern dmac_device_stru  *dmac_res_get_mac_dev(oal_uint32 ul_dev_idx);
extern oal_uint32  dmac_res_init(oal_void);

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of mac_resource.h */