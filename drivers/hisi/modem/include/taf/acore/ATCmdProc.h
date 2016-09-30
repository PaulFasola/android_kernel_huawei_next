/*
* Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
* foss@huawei.com
*
* If distributed as part of the Linux kernel, the following license terms
* apply:
*
* * This program is free software; you can redistribute it and/or modify
* * it under the terms of the GNU General Public License version 2 and 
* * only version 2 as published by the Free Software Foundation.
* *
* * This program is distributed in the hope that it will be useful,
* * but WITHOUT ANY WARRANTY; without even the implied warranty of
* * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* * GNU General Public License for more details.
* *
* * You should have received a copy of the GNU General Public License
* * along with this program; if not, write to the Free Software
* * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
*
* Otherwise, the following license terms apply:
*
* * Redistribution and use in source and binary forms, with or without
* * modification, are permitted provided that the following conditions
* * are met:
* * 1) Redistributions of source code must retain the above copyright
* *    notice, this list of conditions and the following disclaimer.
* * 2) Redistributions in binary form must reproduce the above copyright
* *    notice, this list of conditions and the following disclaimer in the
* *    documentation and/or other materials provided with the distribution.
* * 3) Neither the name of Huawei nor the names of its contributors may 
* *    be used to endorse or promote products derived from this software 
* *    without specific prior written permission.
* 
* * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef _ATCMDPROC_H_
#define _ATCMDPROC_H_

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "AtCtx.h"
#include "siapppb.h"
#include "MnErrorCode.h"
#include "TafAppPpp.h"
#include "TafDrvAgent.h"
#include "mdrv.h"

#include "spysystem.h"
#include "cpm.h"
#include "dms.h"
#include "AtParse.h"
#include "AtAppVcomInterface.h"
#include "AtMuxInterface.h"
#include "AtDipcInterface.h"
#include "AtMntn.h"
#include "AtSndMsg.h"
#include "NasOmInterface.h"
#include "ImmInterface.h"
#include "msp_errno.h"
#include "SOCPInterface.h"
#include "MtaPhyInterface.h"

#include "AcpuReset.h"
#include "siapppih.h"
#include "TafAgentInterface.h"
#include "TafAppXsmsInterface.h"

#include "AtXpdsInterface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)
/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define AT_USBCOM_DISABLED              (0)                                     /* ����ȥʹ��״̬(suspend/disable)*/
#define AT_USBCOM_ENABLED               (1)                                     /* ����ʹ��״̬(resume/enable)*/
#define AT_CC_CALSS_TYPE_INVALID       (255)

/* ATģ������һ����������XML�������� */
#define AT_XML_MAX_LEN               (1024)

#define AT_CUSD_M_NETWORK_TIMEOUT       (5)

#define AT_SFEATURE_DIV_STRING_LEN       (50)

#define AT_PB_IRA_MAX_NUM               (256)
#define AT_PB_GSM_MAX_NUM               (128)
#define AT_PB_GSM7EXT_MAX_NUM           (10)
#define AT_PB_GSM7EXT_SYMBOL            (0x1B)
#define AT_PB_81CODE_HEADER_LEN         (3)
#define AT_PB_82CODE_HEADER_LEN         (4)

 /* 81�����õ�8����15bit���б��룬��0hhh hhhh hXXX XXXX */
#define AT_PB_81_CODE_BASE_POINTER      (0x7f80)
/* GSM7Bit ����ķ�Χ��0~127 */
#define AT_PB_GSM7_CODE_MAX_VALUE       (0x7f)
/* GSM7Bit ����ĵ�8bit����Ϊ0 */
#define AT_PB_CODE_NO8_BIT              (0x80)



#define AT_ANTEN_LEV_MAX_NUM            (6)

#define AT_HEX_LEN_OF_ULONG_TYPE            (8)                                 /* Unsigned long���Ͷ�Ӧʮ����������λ�� */
#define AT_ROAM_FEATURE_OFF_NOCHANGE        (2)                                 /* at^syscfg roam����������δ�������Ϊ���ı� */
#define AT_SYSCFGEX_PARA_NUM                (7)                                 /* at^syscfgex��������Ĳ������� */
#define AT_SYSCFGEX_RAT_MODE_STR_LEN        (2)                                 /* at^syscfgex��ѯ�ϱ�����ģʽ�ַ������ȣ������ģʽΪG,�ϱ�01�ַ�������Ϊ2 */
#define AT_SYSCFGEX_RAT_NO_CHANGE_HEX_VALUE (0x99)

#define AT_NETSCAN_PARA_MAX_NUM         (4)
#define AT_NETSCAN_PARA_MIN_NUM         (2)
#define AT_NETSCAN_POWER_PARA_MAX_LEN   (4)
#define AT_NETSCAN_POWER_PARA_MIN_LEN   (3)
#define AT_NETSCAN_POWER_MIN_VALUE      (-110)
#define AT_NETSCAN_POWER_MAX_VALUE      (-47)
#define AT_ALL_GU_BAND                  (0x3FFFFFFF)

#define TAF_SERIAL_NUM_LEN              (16)

#define TAF_SERIAL_NUM_NV_LEN           (TAF_SERIAL_NUM_LEN + 4)


#define MN_MSG_TP_MTI_MASK              (3)
#define MN_MSG_SMS_MAX_NUM              (255)

#define AT_INVALID_INDEX                (65535)
#define AT_AP_SPEED_STRLEN              (16)

#define AT_MAX_CREATION_TIME_LEN        (31)  /* ϵͳ����ʱ�� */

/* AT^DISLOG��������255Ϊ�л�PCUI����DIAG����, 0Ϊ��DIAG��, 1Ϊ�ر�DIAG��  */
#define AT_DISLOG_PCUI_TO_DIAG          (255)
#define AT_DISLOG_DIAG_OPEN             (0)
#define AT_DISLOG_DIAG_CLOSE            (1)

#define AT_DISSD_OPEN             (0)
#define AT_DISSD_CLOSE            (1)



#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
/* AT^SHELL�������� , 0ΪWIFIʹ��SHELL��, 1Ϊ�ر�SHELL�� , 2Ϊ��SHELL�� */
#define AT_SHELL_WIFI_USE               (0)
#define AT_SHELL_CLOSE                  (1)
#define AT_SHELL_OPEN                   (2)

/* SHELL������У����������� */
#define AT_SHELL_PWD_VERIFY_MAX_TIMES   (3)
#endif

#define AT_USB_ENABLE_EVENT             (3)
#define AT_USB_SUSPEND_EVENT            (5)


#define AT_UART_MODE_ASHELL             (0)
#define AT_UART_MODE_CSHELL             (1)



#if (TAF_BYTE_ORDER == TAF_BIG_ENDIAN)
#define AT_GET_AUTH_LENGTH(pucData)   (((((TAF_UINT16)(*(pucData))) << 8) & 0xFF00) | (((TAF_UINT16)(*((pucData) + 1))) & 0x00FF))
#define AT_GET_IPCP_LENGTH(pucData)   (((((TAF_UINT16)(*(pucData))) << 8) & 0xFF00) | (((TAF_UINT16)(*((pucData) + 1))) & 0x00FF))
#else
#define AT_GET_AUTH_LENGTH(pucData)   ((((TAF_UINT16)(*(pucData))) & 0x00FF) | ((((TAF_UINT16)(*((pucData) + 1)) << 8)) & 0xFF00))
#define AT_GET_IPCP_LENGTH(pucData)   ((((TAF_UINT16)(*(pucData))) & 0x00FF) | ((((TAF_UINT16)(*((pucData) + 1)) << 8)) & 0xFF00))
#endif


#define AT_STOP_TIMER_CMD_READY(ucIndex)  {\
                                              AT_StopRelTimer(ucIndex, &gastAtClientTab[ucIndex].hTimer);\
                                              g_stParseContext[ucIndex].ucClientStatus = AT_FW_CLIENT_STATUS_READY;\
                                              gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_CURRENT_OPT_BUTT;\
                                              gastAtClientTab[ucIndex].opId = 0;\
                                          }


#define AT_ADDR_TYPE_UNKNOWN_ISDN       (0x80| (MN_MSG_TON_UNKNOWN << 4) | MN_MSG_NPI_ISDN)
#define AT_ADDR_TYPE_INTERNATIONAL_ISDN (0x80| (MN_MSG_TON_INTERNATIONAL << 4) | MN_MSG_NPI_ISDN)
#define At_UpChar(Char)                 ((('a' <= (Char)) && ((Char) <= 'z'))?((Char) - 0x20):(Char))
#define At_GetCodeType(Char)            (('+' == Char)? (AT_ADDR_TYPE_INTERNATIONAL_ISDN) : (AT_ADDR_TYPE_UNKNOWN_ISDN))

#define At_GetSmsArea(SaveArea)        ((MN_MSG_MEM_STORE_SIM == SaveArea )?AT_STRING_SM:AT_STRING_ME)

#define At_CheckCmdSms(Char,Mode)    ((0 == (Mode))?((ucAtS3) == (Char)):((((ucAtS3) == (Char)) || (('\x1a') == (Char))) || (('\x1b') == (Char))))
#define At_CheckSplitChar(Char)      ((((ucAtS3) == (Char)) || (('\x1a') == (Char))) || (('\x1b') == (Char)))

#define AT_UNICODE2VALUE(x)    ((x) = ((((x) & 0x00ff) << 8) | (((x) & 0xff00) >> 8)))

#define AT_CMD_BUF_LEN                          12040
#define AT_CLIENT_NULL                          0         /*δʹ��״̬*/
#define AT_CLIENT_USED                          1         /*ռ��״̬*/

#define AT_UNICODE_SMS_MAX_LENGTH               140       /*����ϢUNICODE����󳤶�*/
#define AT_ASCII_SMS_MAX_LENGTH                 160       /*����ϢASCII����󳤶�*/
#define AT_SMS_MAX_LENGTH                       160       /*����Ϣ������󳤶�*/
#define AT_SMS_SEG_MAX_LENGTH                   800
#define AT_COM_BUFF_LEN                        1600
#define AT_MODEM_USER_DLCI                      64        /*usbmodem����ʹ�õ���·��*/
#define AT_CALL_MAX_NUM                         7         /* ��������Ŀ */
#define AT_SMS_RP_ADDRESS_MAX_LEN               12

#define AT_PB_NAME_MAX_LENGTH                   AT_MSG_MAX_TPDU_LEN


#define AT_PCVOICE_SAMPLE_RATE                  (8000)
#define AT_PCVOICE_DATA_BIT                     (16)
#define AT_PCVOICE_FRAME_PERIOD                 (20)

/*DTMF���*/
#define AT_DTMF_START                           (1)
#define AT_DTMF_STOP                            (0)
#define AT_VTS_DEFAULT_DTMF_LENGTH              (65)
#define AT_DTMF_DEFAULT_DTMF_LENGTH             (60000)

#define AT_DTMF_MIN_DTMF_OFF_LENGTH             (10)                            /* osa��������С���ȵĶ�ʱ��Ϊ10ms */

#define AT_QUICK_START_DISABLE    0x00000000
#define AT_QUICK_START_ENABLE     0x01000101

#define AT_CNMR_QRY_GAS_NMR_DATA        (1)         /* ^cnmr��ѯ2g��nmr ����*/
#define AT_CNMR_QRY_WAS_NMR_DATA        (2)         /* ^cnmr��ѯ3g��nmr ����*/
#define AT_CNMR_QRY_LTE_NMR_DATA        (3)         /* ^cnmr��ѯ4g��nmr ����*/

#define AT_CTRL_Z                       (0x1A)      /* CTRL-Z */
#define AT_ESC                          (0x1B)      /* ESC */
#define AT_CR                           (0x0D)      /* CR */

#define AT_NVIM_PARA_LEN    NV_ITEM_AT_PARA_SIZE

#define  AT_UPCASE( c ) ( (((c) >= 'a') && ((c) <= 'z')) ? ((c) - 0x20) : (c) )

#define AT_SMS_EVENT_TYPE                                   0
#define AT_CS_EVENT_TYPE                                    1
#define AT_PS_EVENT_TYPE                                    2
#define AT_PH_EVENT_TYPE                                    3
#define AT_PB_EVENT_TYPE                                    4
#define AT_SS_EVENT_TYPE                                    5
#define AT_DS_EVENT_TYPE                                    6
#define AT_SET_EVENT_TYPE                                   7
#define AT_QRY_EVENT_TYPE                                   8
#define AT_DATA_IND_EVENT_TYPE                              9
#define AT_DATA_STATUS_EVENT_TYPE                           10
#define AT_SAT_IND_EVENT_TYPE                               11
#define AT_SAT_RSP_EVENT_TYPE                               12
#define AT_SAT_DATA_EVENT_TYPE                              13

#define AT_BUTT_INDEX                                       0xFF
#define AT_CNMI_STANDARD                                    0
#define AT_MSG_DELETE_SINGLE                                0x01
#define AT_MSG_DELETE_READ                                  0x02
#define AT_MSG_DELETE_UNREAD                                0x04
#define AT_MSG_DELETE_SENT                                  0x08
#define AT_MSG_DELETE_UNSENT                                0x10
#define AT_MSG_DELETE_ALL                                   0x20
typedef TAF_UINT8   AT_MSG_DELETE_ENUM_U8;

#define AT_SMS_NVIM_SUPPORT                                 0
#define AT_BUTT_CLIENT_ID                                   ((MN_CLIENT_ID_T)(-1))
#define AT_CSCA_CSMP_STORAGE_INDEX                          0

#define AT_MSG_MAX_TPDU_LEN                                 176
#define AT_MSG_INTERNAL_ISDN_ADDR_TYPE                      145

#define AT_MSG_MAX_MSG_SEGMENT_NUM                          2

#define MN_AT_INTERFACE_MSG_HEADER_LEN                      ((sizeof(MN_AT_IND_EVT_STRU) - VOS_MSG_HEAD_LENGTH) - 4)

#define AT_MN_MAX_SMS_TPDU_LEN                              164

/*Refer to 27005 <fo> SMS-DELIVER, SMS-SUBMIT (default 17)*/
#define AT_CSMP_FO_DEFAULT_VALUE1                           17
#define AT_CSMP_SUBMIT_VP_DEFAULT_VALUE                     (167)

/*Refer to 27005 <fo>  SMS-STATUS-REPORT, or SMS-COMMAND (default 2)*/
#define AT_CSMP_FO_DEFAULT_VALUE2                           2

/*23040 9.2.3.3 bit no 3 and 4 of the first octet of SMS SUBMIT*/
#define AT_GET_MSG_TP_VPF( ucVpf, ucFo)                     (ucVpf = (ucFo & 0x18) >> 3)

/* �����úͲ�ѯʱ�����̣�����������������ʱ�� */
#define AT_SET_CFUN_TIME   (75000)
#define AT_SET_PARA_TIME   (30000) /*<==A32D12591*/
#define AT_QRY_PARA_TIME   (30000) /*<==A32D12429*/
#define AT_TEST_PARA_TIME  (30000)

#define AT_SET_CGLA_PARA_TIME   (90000)

/* ���DCM 461-0701-0202 461-0701-0203�ش�������AT������ǰ�������� */
#define AT_SMS_SET_PARA_TIME   (105000) /*<==A32D12591*/

#if (FEATURE_IMS == FEATURE_ON)
/* increase 15s for CMGS and CMSS set command */

#define AT_SMS_CMGS_SET_PARA_TIME        (210000)

#define AT_SMS_CMSS_SET_PARA_TIME        (180000)
/* increase 15s for SS service request command */
#define AT_SS_CUSD_SET_PARA_TIME         (45000)
#else
#define AT_SMS_CMGS_SET_PARA_TIME        (105000)
#define AT_SMS_CMSS_SET_PARA_TIME        (105000)
#define AT_SS_CUSD_SET_PARA_TIME         (30000)
#endif


/* ��PDP����ͶϿ�ʱAT���TIMER��ʱ������ */
#define AT_ACT_PDP_TIME    (362000)    /* 362 ��, APS��360��, 3380��30��һ�ι�5��150�� */
#define AT_DETACT_PDP_TIME (50000)     /* 50��, APS��48��, 3390��8��һ�ι�5��40�� */
#define AT_MOD_PDP_TIME    (170000)    /* 170��, APS��168��, 3381��8��һ��5��40�� */

#define AT_NOT_SET_TIME  0

#define AT_COPS_SPEC_SRCH_TIME                             (120000)             /* COPSָ������ʱ�� */
#define AT_COPS_LIST_SRCH_TIME                             (240000)             /* COPS�б�����ʱ�� */
#define AT_COPS_LIST_ABORT_TIME                            (15000)              /* COPS�б��Ѵ��ʱ��, ��15S����ΪMMA�ı���ʱ��Ϊ10S */


/* ����ATģ��ȴ�SYSCFG/SYSCFGEX�Ļظ�ʱ�䶨ʱ��*/
#define AT_SYSCFG_SET_PARA_TIME                             (100000)            /* iteration 13�޸�Ϊ��ʱ��Ϊ100S */

#define AT_NETSCAN_SET_PARA_TIME                            (120000)

#define AT_ABORT_NETSCAN_SET_PARA_TIME                      (15 * 1000)


#define AT_UPGRADE_TIME_5S      5000
#define AT_UPGRADE_TIME_50S     50000

#define AT_CGATT_SET_PARA_TIME                             (240000)

/* ����ҵ������150s��ʱ����at�ı�����ʱ����Ҫ��ss�����ı�����ʱ������λ160s */
#define AT_SET_SS_PARA_TIME             (160000)
#define AT_QRY_SS_PARA_TIME             (160000)


#define AT_PPP_PROTOCOL_REL_TIME  5000   /*�ȴ�PPP��ӦAT_PPP_PROTOCOL_REL_IND_MSG�ı�����ʱ��ʱ��*/
#define AT_HOLD_CMD_TIMER_LEN   (360000)    /*����AT��������Ķ�ʱ��ʱ��������Ϊ�AT������ʱ��360000*/

#define AT_BCD_HEX(x) ((TAF_UINT8)((TAF_UINT8)(((x) & 0xF0)>>4) + (TAF_UINT8)(((x) & 0x0F)*0x0A)))

#define AT_BCD_REVERSE(x)   (TAF_UINT8)((((x) << 4) & 0xf0) + (((x) >> 4) & 0x0f))

/*PPP����ʱ��������������δָ��CID(��*99#��������)����Ĭ��ʹ������CID*/
#define AT_DIAL_DEFAULT_CID         1

#define AT_INVALID_TZ_VALUE         0x7F



/* AT�����������õĵ�ַ��󳤶� */
#define AT_NDIS_ADDR_PARA_LEN           (15)
#define AT_NDIS_IPV4_ADDR_PARA_LEN      (15)
#define AT_NDIS_IPV6_ADDR_PARA_LEN      (63)

#define AT_SERVICE_CS_PS                        (2)     /*PS��CSҵ��ʹ�� */
#define AT_DEVICE_STATE_FROM_COFIGFILE          (0)     /*0:MDM+DIAG+PCUI*/
#define AT_DEVICE_STATE_FROM_UE                 (4372)  /*4372:CDROM/MDM+NDIS+DIAG+PCUI+CDROM+SD+BT*/
#define AT_CUSTOMIZE_ITEM_DEFAULT_VAL_CHANGED   (2)     /*������޸�,��Ϊ�����������ĵ�Ĭ��ֵ*/
#define AT_CUSTOMIZE_ITEM_DEFAULT_VAL_UNCHANGE  (0)     /*������δ�޸�,Ϊ�����������ĵ�Ĭ��ֵ*/
#define AT_HSUPA_ENABLE_STATE                   (1)     /*en_NV_Item_WAS_RadioAccess_Capa NV����HSUPAΪʹ��״̬*/
#define AT_HSUPA_DISABLE_STATE                  (0)     /*en_NV_Item_WAS_RadioAccess_Capa NV����HSUPAΪδʹ��״̬*/
#define AT_HSDPA_ENABLE_STATE                   (1)     /*en_NV_Item_WAS_RadioAccess_Capa NV����HSDPAΪʹ��״̬*/
#define AT_HSDPA_DISABLE_STATE                  (0)     /*en_NV_Item_WAS_RadioAccess_Capa NV����HSDPAΪδʹ��״̬*/
#define AT_HSDSCH_PHY_CATEGORY_DEFAULT_VAL      (10)     /*en_NV_Item_WAS_RadioAccess_Capa NV����HSDPA�����ȼ�Ĭ��ֵ*/
#define AT_PS_PTL_VER_R7                        (4)     /*en_NV_Item_WAS_RadioAccess_Capa NV����Access Stratum Release Indicator*/

#define AT_SIM_LOCK_MNC_NUM_DEFAULT_VAL         (0xaa)     /*en_NV_Item_CustomizeSimLockPlmnInfo NV����mnc num��Ĭ��ֵ*/
#define AT_SIM_LOCK_PLMN_RANGE_DEFAULT_VAL      (0xAAU)  /*en_NV_Item_CustomizeSimLockPlmnInfo NV��range_begin��range_end��Ĭ��ֵ*/
#define AT_SIM_LOCK_MAXTIMES_DEFAULT_VAL        (10)    /*en_NV_Item_CustomizeSimLockMaxTimes NV��LockMaxTimes��Ĭ��ֵ*/
#define AT_GPRS_ACT_TIMER_LEN_DEFAULT_VAL       (0)     /*en_NV_Item_GPRS_ActiveTimerLength NV��Ĭ��ֵΪ20s,��λ:��*/
#define AT_HSDSCH_PHY_CATEGORY_6                (6)     /*WAS_HSDSCH_PHY_CATEGORY_6*/
#define AT_HSDSCH_PHY_CATEGORY_8                (8)     /*WAS_HSDSCH_PHY_CATEGORY_8*/
#define AT_HSDSCH_PHY_CATEGORY_10               (10)
#define AT_HSDSCH_PHY_CATEGORY_11               (11)    /*WAS_HSDSCH_PHY_CATEGORY_11*/

#define AT_HSDSCH_PHY_CATEGORY_12               (12)    /*WAS_HSDSCH_PHY_CATEGORY_12*/
#define AT_HSDSCH_PHY_CATEGORY_14               (14)    /*WAS_HSDSCH_PHY_CATEGORY_14*/

/* enHSDSCHSupport */
#define AT_DEST_HSDPA_ENABLE                    (1)
#define AT_DEST_HSDPA_DISABLE                   (0)

/* enEDCHSupport */
#define AT_DEST_HSUPA_ENABLE                    (1)
#define AT_DEST_HSUPA_DISABLE                   (0)

/* Source WCDMA RRC Version */
#define AT_SRC_ONLY_WCDMA                       (0)
#define AT_SRC_NOT_SUPPORT_HSUPA                (1)
#define AT_SRC_ALL_SUPPORT                      (2)

/*�������ú������͵���չλ�����ڵײ���뺯��ͳһ������extλ�����ϱ�ʱͳһ����*/
#define AT_NUMBER_TYPE_EXT                      (0x80)


#define AT_NUMBER_TYPE_UNKOWN           (128);


#define AT_AP_RATE_STRLEN                        (16)

#define AT_FASTDORM_DEFAULT_TIME_LEN            (5)

#define AT_FACTORY_INFO_LEN             (78)
#define AT_MMI_TEST_FLAG_OFFSET         (24)
#define AT_MMI_TEST_FLAG_LEN            (4)
#define AT_MMI_TEST_FLAG_SUCC           "ST P"

#define AT_HUK_PARA_LEN                                     (32)        /* ^HUK����������� */
#define AT_FACAUTHPUBKEY_PARA_LEN                           (1040)      /* ^FACAUTHPUBKEY���Կ�������� */
#define AT_FACAUTHPUBKEY_SIGN_PARA_LEN                      (64)        /* ^FACAUTHPUBKEY���Կǩ���������� */
#define AT_RSA_CIPHERTEXT_PARA_LEN                          (256)       /* RSA���Ĳ������� */
#define AT_PORTCTRLTMP_PARA_LEN                             (16)        /* ^PORTCTRLTMP����������� */
#define AT_SIMLOCKDATAWRITE_PARA_LEN                        (1096)      /* ��������������������ṹ�峤�� */
#define AT_PORTATTRIBSET_PARA_ONOFF_LEN                     (1)         /* ^PORTATTRIBSET�˿�״̬�������� */
#define AT_PERSONALIZATION_CODE_LEN                         (8)         /* ��������ͨ�������Ŷγ��� */
#define AT_PERSONALIZATION_NET_CODE_LEN                     (6)         /* ��������NET���������Ŷγ��� */
#define AT_PERSONALIZATION_NET_CODE_BCD_LEN                 (3)         /* ��������NET���������Ŷ�BCD����ĳ��� */
#define AT_PERSONALIZATION_SUBNET_CODE_BCD_LEN              (4)         /* ��������NETSUB���������Ŷ�BCD����ĳ��� */
#define AT_PERSONALIZATION_SP_CODE_BCD_LEN                  (4)         /* ��������SP���������Ŷ�BCD����ĳ��� */
#define AT_PERSONALIZATION_CODE_FOURTH_CHAR_INDEX           (3)         /* ���������Ŷε��ĸ��ַ������� */
#define AT_NVWRSECCTRL_PARA_SECTYPE_LEN                     (1)         /* ^NVWRSECCTRL��ȫ�������Ͳ������� */

#define AT_APSEC_CMD_MAX_LEN            (553)       /* "AT^APSEC=<SP_request>"(9+544) ������󳤶� */
#define AT_APSEC_CMD_MIN_LEN            (21)        /* "AT^APSEC=<SP_request>"(9+12)  ������С���� */

#define AT_BODYSARWCDMA_MAX_PARA_NUM                        (16)
#define AT_BODYSARWCDMA_MAX_PARA_GROUP_NUM                  (8)
#define AT_BODYSARGSM_MAX_PARA_NUM                          (16)
#define AT_BODYSARGSM_MAX_PARA_GROUP_NUM                    (8)
#define AT_RF_BAND_ANY_STR                                  "3FFFFFFF"
#define AT_RF_BAND_ANY                                      (0x3FFFFFFF)
#define AT_WCDMA_BAND_DEFAULT_POWER                         (24)
#define AT_GSM_GPRS_850_DEFAULT_POWER                       (33)
#define AT_GSM_EDGE_850_DEFAULT_POWER                       (27)
#define AT_GSM_GPRS_900_DEFAULT_POWER                       (33)
#define AT_GSM_EDGE_900_DEFAULT_POWER                       (27)
#define AT_GSM_GPRS_1800_DEFAULT_POWER                      (30)
#define AT_GSM_EDGE_1800_DEFAULT_POWER                      (26)
#define AT_GSM_GPRS_1900_DEFAULT_POWER                      (30)
#define AT_GSM_EDGE_1900_DEFAULT_POWER                      (26)
#define AT_GSM_GPRS_BAND_OFFSET                             (0)
#define AT_GSM_EDGE_BAND_OFFSET                             (16)

#define  AT_CERSSI_MAX_TIMER_INTERVAL   (20)           // �ź������ϱ�������ʱ��20S


/* �������ݲ���3�ı���ʱ ����ַ��������'='�� */
#define         AT_BASE64_PADDING      '='

/* ���ӽ��뼼��ƽ���acting plmn�ļ�ID�� */
#define USIMM_ATT_RAT_BALANCING_FID     (0x4F36)
#define USIMM_ATT_ACTING_PLMN_FID       (0x4F34)

/* Added by z00316370 for UTS 2015-5-16 begin */
#define AT_MEID_OCTET_NUM               (7)
/* Added by z00316370 for UTS 2015-5-16 end */

enum B64ReultType{
    b64Result_OK=0,
    b64Result_CODE_SIZE_ERROR,
    b64Result_DATA_SIZE_SMALLNESS,
    b64Result_CODE_ERROR
};

#define  AT_RSFR_RSFW_NAME_LEN      7           /* ĿǰNAMEֻ֧��(VERSION/SIMLOCK/vSIM) */
#define  AT_RSFR_RSFW_SUBNAME_LEN   7           /* SUBNAME���Ȳ�����7 */

/* (TAF_PH_SIMLOCK_PLMN_STR_LEN*2+1)*TAF_MAX_SIM_LOCK_RANGE_NUM = 340 */
/* SIMLOCK���ַ������340���ַ��������Ҳ���ᳬ��1024 */
#define  AT_RSFR_RSFW_MAX_LEN       1024

extern VOS_UINT32  At_SimlockPlmnNumToAscii(
    const VOS_UINT8                     *pucPlmnRange,
    VOS_UINT8                           ucPlmnRangeLen,
    VOS_UINT8                            *pucAsciiStr
);


/* RNIC����������󳤶� */
#define AT_RMNET_NAME_MAX_LENGTH        (8)

/* ��ʵ�������֧������RNIC����*/
#define AT_RMNET_MAX_COUNT              (3)

/* Added by m00312079 for CDMA 1X Iteration 6 2015-1-4 begin */
#define AT_CFREQLOCK_PARA_NUM_MIN       (1)
#define AT_CFREQLOCK_PARA_NUM_MAX       (9)
/* Added by m00312079 for CDMA 1X Iteration 6 2015-1-4 end */

/* Added by w00316404 for eMBMS project, 2015-5-22, begin */
#define AT_MBMS_SERVICE_ID_LENGTH           (6)
#define AT_MBMS_MCC_LENGTH                  (3)
#define AT_MBMS_MNC_MAX_LENGTH              (3)
#define AT_MBMS_SERVICE_ID_AND_MCC_LENGTH   (9)
#define AT_MBMS_TMGI_MAX_LENGTH             (12)

#define AT_MBMS_UTC_MAX_LENGTH              (12)

typedef VOS_UINT8 AT_MBMS_TYPE;
#define AT_MBMS_SERVICE_ENABLER_TYPE            0
#define AT_MBMS_ACTIVATE_TYPE                   1
#define AT_MBMS_DEACTIVATE_TYPE                 2
#define AT_MBMS_DEACTIVATE_ALL_TYPE             3
#define AT_MBMS_PREFERENCE_TYPE                 4
#define AT_MBMS_SIB16_GET_NETWORK_TIME_TYPE     5
#define AT_MBMS_BSSI_SIGNAL_LEVEL_TYPE          6
#define AT_MBMS_NETWORK_INFORMATION_TYPE        7
#define AT_MBMS_MODEM_STATUS_TYPE               8

typedef VOS_UINT8 AT_COEX_PARA_TYPE;
#define AT_COEX_PARA_COEX_ENABLE                0
#define AT_COEX_PARA_TX_BEGIN                   1
#define AT_COEX_PARA_TX_END                     2
#define AT_COEX_PARA_TX_POWER                   3
#define AT_COEX_PARA_RX_BEGIN                   4
#define AT_COEX_PARA_RX_END                     5

#define AT_COEX_PARA_COEX_ENABLE_MIN            0
#define AT_COEX_PARA_COEX_ENABLE_MAX            1
#define AT_COEX_PARA_TX_BEGIN_MIN               0
#define AT_COEX_PARA_TX_BEGIN_MAX               65535
#define AT_COEX_PARA_TX_END_MIN                 0
#define AT_COEX_PARA_TX_END_MAX                 65535
#define AT_COEX_PARA_TX_POWER_MIN               -32767
#define AT_COEX_PARA_TX_POWER_MAX               32767
#define AT_COEX_PARA_RX_BEGIN_MIN               0
#define AT_COEX_PARA_RX_BEGIN_MAX               65535
#define AT_COEX_PARA_RX_END_MIN                 0
#define AT_COEX_PARA_RX_END_MAX                 65535
/* Added by w00316404 for eMBMS project, 2015-5-22, end */

/* ��װOSA������Ϣ�ӿ� */
#define AT_ALLOC_MSG_WITH_HDR(ulMsgLen)\
            PS_ALLOC_MSG_WITH_HEADER_LEN(WUEPS_PID_AT, (ulMsgLen))

/* ��װOSA��Ϣͷ */
#define AT_CFG_MSG_HDR(pstMsg, ulRecvPid, ulMsgId)\
            ((MSG_HEADER_STRU *)(pstMsg))->ulSenderCpuId   = VOS_LOCAL_CPUID;\
            ((MSG_HEADER_STRU *)(pstMsg))->ulSenderPid     = WUEPS_PID_AT;\
            ((MSG_HEADER_STRU *)(pstMsg))->ulReceiverCpuId = VOS_LOCAL_CPUID;\
            ((MSG_HEADER_STRU *)(pstMsg))->ulReceiverPid   = (ulRecvPid);\
            ((MSG_HEADER_STRU *)(pstMsg))->ulMsgName       = (ulMsgId)

/* ��װOSA��Ϣͷ(AT�ڲ���Ϣ) */
#define AT_CFG_INTRA_MSG_HDR(pstMsg, ulMsgId)\
            AT_CFG_MSG_HDR(pstMsg, WUEPS_PID_AT, ulMsgId)

/* ��ȡOSA��Ϣ���� */
#define AT_GET_MSG_ENTITY(pstMsg)\
            ((VOS_VOID *)&(((MSG_HEADER_STRU *)(pstMsg))->ulMsgName))

/* ��ȡOSA��Ϣ���� */
#define AT_GET_MSG_LENGTH(pstMsg)\
            (((MSG_HEADER_STRU *)(pstMsg))->ulLength)

/* ��װOSA������Ϣ�ӿ� */
#define AT_SEND_MSG(pstMsg)\
            if (VOS_OK != PS_SEND_MSG(WUEPS_PID_AT, pstMsg))\
            {\
                AT_ERR_LOG("AT_SEND_MSG: Send message fail!\n");\
            }

/* Modified by l00301449 for Iteration 13, 2015-04-21, begin */
#define AT_CGCATT_MODE_PS               (1)
#define AT_CGCATT_MODE_CS               (2)
#define AT_CGCATT_MODE_CS_PS            (3)


/* Modified by l00301449 for Iteration 13, 2015-04-21, end */
/* Added by w00316404 for eMBMS project, 2015-5-22, begin */
#define AT_COEX_INVALID                 (0x00ff0000)
/* Added by w00316404 for eMBMS project, 2015-5-22, end */

/* Added by w00351686 for CDMA Iteration 16 2015-7-23 begin */
#define AT_CCONTDTMF_PARA_NUM_MIN       (2)
#define AT_CCONTDTMF_PARA_NUM_MAX       (3)
/* Added by w00351686 for CDMA Iteration 16 2015-7-23 end */

/*******************************************************************************
  3 ö�ٶ���
*******************************************************************************/
/*�����˿�������*/
#define AT_PHY_PORT_MAX                 (AT_PORT_BUTT)


/*�ṩ��OM��ѯ�������ݵĺ����ӿ�*/

extern CPM_RCV_FUNC               g_apAtPortDataRcvFuncTab[AT_PHY_PORT_MAX];

/*****************************************************************************
 ö����    : AT_VOICE_DOMAIN_TYPE_ENUM
 Э�����  :
 ö��˵��  : ��ѡ������
*****************************************************************************/
enum AT_VOICE_DOMAIN_TYPE_ENUM
{
    AT_VOICE_DOMAIN_TYPE_CS_ONLY            = 1,
    AT_VOICE_DOMAIN_TYPE_CS_PREFERRED       = 2,
    AT_VOICE_DOMAIN_TYPE_IMS_PS_PREFERRED   = 3,
    AT_VOICE_DOMAIN_TYPE_IMS_PS_ONLY        = 4,
    AT_VOICE_DOMAIN_TYPE_BUTT
};
typedef VOS_UINT32 AT_VOICE_DOMAIN_TYPE_ENUM_UINT32;


/*****************************************************************************
 ö����    : AT_TEMPPRT_STATUS_IND_ENUM
 �ṹ˵��  :
             0: AT_TEMPPRT_STATUS_IND_DISABLE  �±�״̬�ϱ�NV��ر�
             1: AT_TEMPPRT_STATUS_IND_ENABLE   �±�״̬�ϱ�NV���
*****************************************************************************/
enum AT_TEMPPRT_STATUS_IND_ENUM
{
    AT_TEMPPRT_STATUS_IND_DISABLE   = 0,
    AT_TEMPPRT_STATUS_IND_ENABLE,
    AT_TEMPPRT_STATUS_IND_BUTT
};
typedef VOS_UINT32 AT_TEMPPRT_STATUS_IND_ENUM_UINT32;

/*****************************************************************************
 ö����    : AT_RSIM_STATUS_ENUM
 �ṹ˵��  : ^RSIM �����ѯ����б�
             0: û���κο��Ӵ��ϣ�
             1: �Ѿ��Ӵ���SIM/USIM/UIM��
             2:SIM/USIM/UIM��æ��Ҫ�ȴ���
*****************************************************************************/
enum AT_RSIM_STATUS_ENUM
{
    AT_RSIM_STATUS_USIMM_CARD_ABSENT            = 0x00,
    AT_RSIM_STATUS_USIMM_CARD_AVAILABLE       = 0x01,
    AT_RSIM_STATUS_USIMM_CARD_BUSY                 = 0x02,
    AT_RSIM_STATUS_USIMM_CARD_BUTT                 = 0xff
};
typedef VOS_UINT8  AT_RSIM_STATUS_ENUM_UINT8;

/*****************************************************************************
 ö����    : AT_PHYNUM_TYPE_ENUM_UINT32
 Э�����  :
 ö��˵��  : ����������
*****************************************************************************/
enum AT_PHYNUM_TYPE_ENUM
{
    AT_PHYNUM_TYPE_IMEI,
    AT_PHYNUM_TYPE_MEID,
    AT_PHYNUM_TYPE_MAC,
    AT_PHYNUM_TYPE_ESN,
    AT_PHYNUM_TYPE_SVN,
    AT_PHYNUM_TYPE_UMID,
    AT_PHYNUM_TYPE_BUTT
};
typedef VOS_UINT32 AT_PHYNUM_TYPE_ENUM_UINT32;

/*SMS version PHASE2�汾 SMS PHASE2+�汾*/
enum AT_CSMS_MSG_VERSION_ENUM
{
    AT_CSMS_MSG_VERSION_PHASE2,
    AT_CSMS_MSG_VERSION_PHASE2_PLUS
};
typedef TAF_UINT8 AT_CSMS_MSG_VERSION_ENUM_U8;

/* AT TIMER ID list*/
enum AT_TIMER_TYPE_ENUM
{
    AT_CMD_PROCESS_TYPE       = 0x0000,                                         /* ��������صļ�ʱ�����ڴ���AT����ʱʹ�� */
    AT_INTERNAL_PROCESS_TYPE  = 0x0100                                          /* AT�ڲ������ļ�ʱ�������ں������������ */
};

enum AT_CLCC_MODE_ENUM
{
    AT_CLCC_MODE_VOICE,                                                         /* voice */
    AT_CLCC_MODE_DATA,                                                          /* data */
    AT_CLCC_MODE_FAX,                                                           /* fax */
    AT_CLCC_MODE_VFDV,                                                          /* voice followed by data, voice mode */
    AT_CLCC_MODE_AVDV,                                                          /* alternating voice/data, voice mode */
    AT_CLCC_MODE_AVFV,                                                          /* alternating voice/fax, voice mode */
    AT_CLCC_MODE_VFDD,                                                          /* voice followed by data, data mode */
    AT_CLCC_MODE_AVDD,                                                          /* alternating voice/data, data mode */
    AT_CLCC_MODE_AVFF,                                                          /* alternating voice/fax, fax mode */
    AT_CLCC_MODE_UNKNOWN                                                        /* unknown */
};
typedef TAF_UINT8 AT_CLCC_MODE_ENUM_U8;

enum AT_CPAS_STATUS_ENUM
{
    AT_CPAS_STATUS_READY,                                                       /* ready (MT allows commands from TA/TE) */
    AT_CPAS_STATUS_UNAVAILABLE,                                                 /* unavailable (MT does not allow commands from TA/TE */
    AT_CPAS_STATUS_UNKNOWN,                                                     /* unknown (MT is not guaranteed to respond to instructions) */
    AT_CPAS_STATUS_RING,                                                        /* ringing (MT is ready for commands from TA/TE, but the ringer is active) */
    AT_CPAS_STATUS_CALL_IN_PROGRESS,                                            /* call in progress (MT is ready for commands from TA/TE, but a call is in progress) */
    AT_CPAS_STATUS_ASLEEP                                                       /* asleep (MT is unable to process commands from TA/TE because it is in a low functionality state) */
};
typedef TAF_UINT8 AT_CPAS_STATUS_ENUM_U8;

enum AT_WIFI_MODE_ENUM
{
    AT_WIFI_MODE_ONLY_PA                = 0x00,                                 /* WIFIֻ֧��PAģʽ */
    AT_WIFI_MODE_ONLY_NOPA              = 0x01,                                 /* WIFIֻ֧��NO PAģʽ */
    AT_WIFI_MODE_PA_NOPA                = 0x02,                                 /* WIFIͬʱ֧��PAģʽ��NO PAģʽ */

    AT_WIFI_MODE_BUTT                   = 0xFF
};
typedef VOS_UINT8 AT_WIFI_MODE_ENUM_UINT8;

typedef enum
{
    AT_CMD_BUTT,
    AT_CMD_APHPLMN,
    AT_CMD_ANQUERY,
    AT_CMD_CGDATA,
    AT_CMD_CGPADDR,
    AT_CMD_CGEQNEG,
    AT_CMD_CGAUTH,
    AT_CMD_CGDNS,
    AT_CMD_CEER,
    AT_CMD_CPAS,
    AT_CMD_CGMI,
    AT_CMD_CGMM,
    AT_CMD_GMM,
    AT_CMD_CGMR,
    AT_CMD_CGSN,
    AT_CMD_SN,
    AT_CMD_HWVER,
    AT_CMD_HVER,
    AT_CMD_FHVER,
    AT_CMD_PFVER,
    AT_CMD_CLAC,
    AT_CMD_GSN,
    AT_CMD_GCAP,
    AT_CMD_SRVST,
    AT_CMD_RSSI,
    AT_CMD_CERSSI,
    AT_CMD_CNMR,
    AT_CMD_CECELLID,
    AT_CMD_LFROMCONNTOIDLE,
    AT_CMD_LWTHRESHOLDCFG,
    AT_CMD_SYSMODE,
    AT_CMD_SIMST,
    AT_CMD_HS,
    AT_CMD_I,
    AT_CMD_T,
    AT_CMD_P,
    AT_CMD_X,
    AT_CMD_Z,
    AT_CMD_Q,
    AT_CMD_CIMI,
    AT_CMD_VTS,
    AT_CMD_DTMF,
    AT_CMD_CGANS,
    AT_CMD_CGANS_EXT,
    AT_CMD_APENDPPP,
    AT_CMD_CGCMOD,
    AT_CMD_CGACT,
    AT_CMD_CGDCONT,
    AT_CMD_CGDSCONT,
    AT_CMD_DSFLOWCLR,
    AT_CMD_DSFLOWQRY,
    AT_CMD_DSFLOWRPT,
    AT_CMD_CGTFT,
    AT_CMD_CGEQREQ,
    AT_CMD_CGEQMIN,
    AT_CMD_COPS,
    AT_CMD_CGAUTO,
    AT_CMD_CPBS,
    AT_CMD_CPBR,
    AT_CMD_CPBR2,
    AT_CMD_CPBF,
    AT_CMD_CPBW,
    AT_CMD_CPBW2,
    AT_CMD_SCPBW,
    AT_CMD_SCPBR,
    AT_CMD_CNUM,
    AT_CMD_CMEE,
    AT_CMD_CSCS,
    AT_CMD_CSIM,
    AT_CMD_CCHO,
    AT_CMD_CCHC,
    AT_CMD_CGLA,
    AT_CMD_CPIN,
    AT_CMD_CARDLOCK,
    AT_CMD_CARDATR,
    AT_CMD_CPIN_2,
    AT_CMD_CICCID,
    AT_CMD_CPWD,
    AT_CMD_CGCLASS,
    AT_CMD_CLIP,
    AT_CMD_CLIR,/*add by zhoujun40661 2006-11-6 for A32D07303*/
    AT_CMD_COLP,/*add by zhoujun40661 2006-11-6 for A32D07303*/
    AT_CMD_CLCC,
    AT_CMD_CLCK,
    AT_CMD_CTFR,
    AT_CMD_CMLCK,
    AT_CMD_CGSMS,
    AT_CMD_CGATT,
    AT_CMD_CGCATT,
    AT_CMD_CFUN,
    AT_CMD_CSQ,
    AT_CMD_CBC,
    AT_CMD_CBND,
    AT_CMD_CPDW,
    AT_CMD_NVIM,
    AT_CMD_DAM_PARASTUB,
    AT_CMD_ENOS_PARASTUB,
    AT_CMD_COMPARE_PLMN_SUPPORT_WILDCARD,
    AT_CMD_USIM_STUB,
    AT_CMD_REFRESH_STUB,
    AT_CMD_AUTO_RESEL_STUB,
    /* Modified by c00318887 for file refresh��Ҫ����������, 2015-3-27, begin */
    AT_CMD_DELAYBG_STUB,
    /* Modified by c00318887 for file refresh��Ҫ����������, 2015-3-27, end */
    AT_CMD_PIDREINIT,
    AT_CMD_IMSRATSTUB,
    AT_CMD_IMSCAPSTUB,
    AT_CMD_DOMAINSTUB,
    AT_CMD_USIM,
    AT_CMD_SIM,
    AT_CMD_PDPSTUB,
    AT_CMD_CSND,
    AT_CMD_CSTA,
    AT_CMD_CCUG,
    AT_CMD_CGREG,
    AT_CMD_CEREG,
    AT_CMD_CCWA,
    AT_CMD_CCFC,
    AT_CMD_CUSD,
    AT_CMD_CSSN,
    AT_CMD_CREG,
    AT_CMD_S0,
    AT_CMD_S3,
    AT_CMD_S4,
    AT_CMD_S5,
    AT_CMD_S6,
    AT_CMD_S7,
    AT_CMD_V,
    AT_CMD_E,
    AT_CMD_L,
    AT_CMD_M,
    AT_CMD_AMP_C,
    AT_CMD_AMP_D,
#if (FEATURE_ON == FEATURE_AT_HSUART)
    AT_CMD_AMP_S,
#endif
    AT_CMD_AMP_F,
    AT_CMD_CRC,
    AT_CMD_CMOD,
    AT_CMD_CMMI,
    AT_CMD_CBST,
    AT_CMD_CHUP,
    AT_CMD_D,
    AT_CMD_O,
    AT_CMD_H,
    AT_CMD_A,
    AT_CMD_CHLD,
    AT_CMD_ALS,
    AT_CMD_CUUS1,
    AT_CMD_CPAM,
    AT_CMD_CCIN,
    AT_CMD_TIME,
    AT_CMD_CTZR,

    AT_CMD_CPLS,
    AT_CMD_CPOL,
    AT_CMD_CSIN,
    AT_CMD_CSTR,
    AT_CMD_CSEN,
    AT_CMD_CSMN,
    AT_CMD_CSTC,
    AT_CMD_STSF,
    AT_CMD_STGI,
    AT_CMD_STGR,
    AT_CMD_IMSICHG,
    AT_CMD_TEST,
    AT_CMD_CWAS,
    AT_CMD_CGAS,
    AT_CMD_APPDIALMODE,
    AT_CMD_LCSTARTTIME,
    AT_CMD_MAXFREELOCKSIZE,
    AT_CMD_CPULOAD,
    AT_CMD_CELLINFO,
    AT_CMD_MEANRPT,
    AT_CMD_QCDMG,
    AT_CMD_AT2OM,
    AT_CMD_U2DIAG,
    AT_CMD_DWINS,
    AT_CMD_YJCX,
    AT_CMD_SETPID,
    AT_CMD_GETPORTMODE,
    AT_CMD_CVOICE,
    AT_CMD_DDSETEX,
    AT_CMD_NDISDUP,
    AT_CMD_AUTHDATA,
    AT_CMD_DHCP,
    AT_CMD_CRPN,
    AT_CMD_NDISSTATQRY,
    AT_CMD_NDISCONN,
    AT_CMD_NDISADD,
    AT_CMD_DNSPRIM,
    AT_CMD_DNSSND,
    AT_CMD_DLOADVER,
    AT_CMD_DLOADINFO,
    AT_CMD_NVBACKUP,
    AT_CMD_NVRESTORE,
    AT_CMD_AUTHORITYVER,
    AT_CMD_AUTHORITYID,
    AT_CMD_GODLOAD,
    AT_CMD_RESET,
    AT_CMD_NVRSTSTTS,
    AT_CMD_HWNATQRY,
    AT_CMD_FLASHINFO,
    AT_CMD_CMSR,
    AT_CMD_CMGI,
    AT_CMD_CMMT,
    AT_CMD_USSDMODE,
    AT_CMD_ADCTEMP,
    AT_CMD_COMM,
    AT_CMD_HSPA,
    AT_CMD_CSNR,
    AT_CMD_FREQLOCK,
    AT_CMD_CPSC,
    AT_CMD_CFRQ,
    AT_CMD_CFPLMN,
    AT_CMD_CQST,
    AT_CMD_CAATT,
    AT_CMD_SYSINFO,
    AT_CMD_SYSINFOEX,
    AT_CMD_CEMODE,
    AT_CMD_LTECS,

    AT_CMD_SYSCFG,
    AT_CMD_SYSCFGEX,
    AT_CMD_CMM,
    AT_CMD_SPN,
    AT_CMD_CARDMODE,
    AT_CMD_DIALMODE,
    AT_CMD_PORTSEL,
    AT_CMD_CURC,
    AT_CMD_BOOT,
    AT_CMD_CIMEI,
    AT_CMD_TRIG,
    AT_CMD_GCFIND,
    AT_CMD_MDATE,
    AT_CMD_FACINFO,
    AT_CMD_RXPRI,
    AT_CMD_SIMLOCK,
    AT_CMD_MAXLCK_TIMES,
    AT_CMD_PHYNUM,
    AT_CMD_RSIM,
    AT_CMD_GTIMER,
    AT_CMD_PLATFORM,
    AT_CMD_CSVER,
    AT_CMD_QOS,
    AT_CMD_SDOMAIN,
    AT_CMD_DPACAT,
    AT_CMD_HSSPT,
    AT_CMD_BSN,
    AT_CMD_SFM,
    AT_CMD_TMODE,
    AT_CMD_FCHAN,
    AT_CMD_FTXON,
    AT_CMD_FDAC,

    AT_CMD_SD,
    AT_CMD_INFORRS,
    AT_CMD_INFORBU,
    AT_CMD_DATALOCK,
    AT_CMD_GPIOPL,
    AT_CMD_VERSION,

    AT_CMD_FRXON,
    AT_CMD_FPA,
    AT_CMD_FLNA,
    AT_CMD_FRSSI,
    AT_CMD_RXDIV,
    AT_CMD_CALLSRV,
    AT_CMD_CSDFLT,
    AT_CMD_SECUBOOTFEATURE,
    AT_CMD_SECUBOOT,
    AT_CMD_WIENABLE,
    AT_CMD_WIMODE,
    AT_CMD_WIBAND,
    AT_CMD_WIFREQ,
    AT_CMD_WIRATE,
    AT_CMD_WIPOW,
    AT_CMD_WITX,
    AT_CMD_WIRX,
    AT_CMD_WIRPCKG,
    AT_CMD_TMMI,
    AT_CMD_TSELRF,
    AT_CMD_TCHRENABLE,
    AT_CMD_TCHRINFO,
    AT_CMD_CDUR,
    AT_CMD_TSCREEN,
    AT_CMD_SSID,
    AT_CMD_WIKEY,
    AT_CMD_WILOG,
    AT_CMD_WIPARANGE,
    AT_CMD_WIINFO,
    AT_CMD_WUPWD,
    AT_CMD_BATVOL,
    AT_CMD_PRODTYPE,
    AT_CMD_FEATURE,

    AT_CMD_CTA,

    AT_CMD_CGMTU,



    AT_CMD_BANDSW,
    AT_CMD_F_FCHANS,
    AT_CMD_F_FSEGMENT,
    AT_CMD_F_FPOWS,
    AT_CMD_F_FPAS,
    AT_CMD_F_FLNAS,
    AT_CMD_F_FTXWAVE,
    AT_CMD_F_FSTART,
    AT_CMD_F_FRSSIS,
    AT_CMD_F_FCMTMS,

    AT_CMD_F_FBLK,
    AT_CMD_F_FIPSTART,

    AT_CMD_F_FMAXPOWER,
    AT_CMD_F_FPAPOWER,
    AT_CMD_F_FPDMS,
   AT_CMD_F_FCALIIP2S,
   AT_CMD_F_FCALIDCOCS,
   AT_CMD_F_FGAINSTATES,
   AT_CMD_F_FDBBATTS,
   AT_CMD_F_FBBATTS,
   AT_CMD_F_FCALITXIQS,
    /*װ�� ����У׼ end */

/*  AT_CMD_FCHAN, */
/*  AT_CMD_FTXON, */
/*  AT_CMD_FRXON, */
    AT_CMD_FVCTCXO,
    AT_CMD_FQPDDCRES,
    AT_CMD_FCALPDDCS,
    AT_CMD_FPDPOWS,
    AT_CMD_FANT,
    AT_CMD_FPOW,
/*  AT_CMD_FPA, */
/*  AT_CMD_FDAC, */
/*  AT_CMD_FLNA, */
/*  AT_CMD_FRSSI, */

    /*�������۲�start */
    AT_CMD_SSYNC,
    AT_CMD_STXBW,
    AT_CMD_STXCHAN,
    AT_CMD_SSUBFRAME,
    AT_CMD_SPARA,

    AT_CMD_SSEGNUM,
    AT_CMD_STXMODUS,
    AT_CMD_STXRBNUMS,
    AT_CMD_STXRBPOSS,
    AT_CMD_STXPOWS,
    AT_CMD_STXCHANTYPES,
    AT_CMD_SSEGLEN,
    AT_CMD_SRXSET,
    AT_CMD_SRXPOW,
    AT_CMD_SRXSUBFRA,
    AT_CMD_SRXBLER,
    AT_CMD_SSTART,
    AT_CMD_SSTOP,


    AT_CMD_SMS_BEGAIN,
    AT_CMD_CSMS,
    AT_CMD_CPMS,
    AT_CMD_CMSQ,
    AT_CMD_CMGF,
    AT_CMD_CSCA,
    AT_CMD_CSMP,
    AT_CMD_CSDH,
    AT_CMD_CNMI,
    AT_CMD_CMGL,
    AT_CMD_CMGR,
    AT_CMD_CMGS,
    AT_CMD_CMGW,
    AT_CMD_CMGD,
    AT_CMD_CSSM,
    AT_CMD_CMGC,
    AT_CMD_CMSS,
    AT_CMD_CMST,
    AT_CMD_CNMA,    /*begin add by zhoujun40661 2006-10-24 for CNMA*/
    AT_CMD_CCNMA,   /*begin add by zhoujun40661 2006-10-24 for CNMA*/
    AT_CMD_CMSTUB,
    AT_CMD_CMMS,
    AT_CMD_RSTRIGGER,
#if ((FEATURE_ON == FEATURE_GCBS) || (FEATURE_ON == FEATURE_WCBS))
    AT_CMD_CSCB,
#endif
    AT_CMD_CLVL,
    AT_CMD_VMSET,
    AT_CMD_CRSM,
    AT_CMD_PNN,
    AT_CMD_CPNN,
    AT_CMD_OPL,
    AT_CMD_GLASTERR,
    AT_CMD_PCSCINFO,
    AT_CMD_CELLSRCH,
    AT_CMD_CCC,
    AT_CMD_PORT,
    AT_CMD_APTHROUGHPUT,
    AT_CMD_APDIALMODE,
    AT_CMD_APCONNST,
    AT_CMD_APPWRONREG,
    AT_CMD_GMI,
    AT_CMD_GMR,
    AT_CMD_WIFIGLOBALMAC,
    AT_CMD_CSQLVL,
    AT_CMD_SCID,
    AT_CMD_CSQLVLEXT,
    AT_CMD_DISSD,
    AT_CMD_SDREBOOT,
    AT_CMD_DOCK,
    AT_CMD_APPDMVER,
    AT_CMD_OPWORD,
    AT_CMD_CPWORD,
    AT_CMD_DISLOG,
#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
    AT_CMD_SHELL,
    AT_CMD_SPWORD,
#endif
    AT_CMD_RSRPCFG,
    AT_CMD_RSCPCFG,
    AT_CMD_ECIOCFG,
    AT_CMD_CELLROAM,
    AT_CMD_PDPROFMOD,
    AT_CMD_FRSTATUS,
    AT_CMD_GETEXBANDINFO,
    AT_CMD_GETEXBANDTESTINFO,
    AT_CMD_APBATLVL,
    AT_CMD_OPENPORT,
    AT_CMD_SDLOAD,
    AT_CMD_AUTHVER,
#if (FEATURE_ON == FEATURE_IPV6)
    AT_CMD_IPV6CAP,
    AT_CMD_DHCPV6,
    AT_CMD_APRAINFO,
    AT_CMD_APLANADDR,
#endif
    AT_CMD_VERTIME,
    AT_CMD_PRODNAME,
    AT_CMD_FWAVE,
    AT_CMD_EQVER,
    AT_CMD_APRPTSRVURL,
    AT_CMD_APXMLINFOTYPE,
    AT_CMD_APXMLRPTFLAG,

    AT_CMD_FASTDORM,

    AT_CMD_CGTFTRDP,
    AT_CMD_CGEQOS,
    AT_CMD_CGEQOSRDP,
    AT_CMD_CGCONTRDP,
    AT_CMD_CGSCONTRDP,

    AT_CMD_APCRADWIFIBS,
    AT_CMD_APNDISCON,
    AT_CMD_APCRADETHSTA,
    AT_CMD_APFMCDHCPSTA,
    AT_CMD_APDIALM,
    AT_CMD_APWIFIBS,
    AT_CMD_APWIFISEC,
    AT_CMD_APDHCP,
    AT_CMD_APCURPROF,
    AT_CMD_APPROFRD,

    AT_CMD_MEMQUERY,
    AT_CMD_TBAT,
    AT_CMD_PSTANDBY,
    AT_CMD_WIWEP,
    AT_CMD_CMDLEN,

    AT_CMD_LOCINFO,
    AT_CMD_CIPHERQRY,
    AT_CMD_QRYNVRESUME,

    AT_CMD_NVBACKUPSTAT,
    AT_CMD_NANDBBC,
    AT_CMD_NANDVER,
    AT_CMD_CHIPTEMP,

    AT_CMD_CPIN2,
    AT_CMD_CSASM,
    AT_CMD_DNSQUERY,

    AT_CMD_APRPTPORTSEL,
    AT_CMD_CHDATA,
    AT_CMD_GPIO,
    AT_CMD_USBSWITCH,

    AT_CMD_RSFR,
    AT_CMD_RSFW,
    AT_CMD_ANTSTATE,
    AT_CMD_SARREDUCTION,

    AT_CMD_HUK,
    AT_CMD_FACAUTHPUBKEY,
    AT_CMD_IDENTIFYSTART,
    AT_CMD_IDENTIFYEND,
    AT_CMD_SIMLOCKDATAWRITE,
    AT_CMD_PHONESIMLOCKINFO,
    AT_CMD_SIMLOCKDATAREAD,
    AT_CMD_PHONEPHYNUM,
    AT_CMD_PORTCTRLTMP,
    AT_CMD_PORTATTRIBSET,

    AT_CMD_APSIMST,

    AT_CMD_CPOS,
    AT_CMD_CPOSR,
    AT_CMD_XCPOSR,
    AT_CMD_CGPSCLOCK,

    AT_CMD_CGPSINFO,
    AT_CMD_LOGCFG,
    AT_CMD_LOGSAVE,
    AT_CMD_LOGNVE,

    /* Added by H00300778 for 1X SMS Begin */
    AT_CMD_CCMGS,
    AT_CMD_CCMGW,
    AT_CMD_CCMGD,
    /* Added by H00300778 for 1X SMS end */
    AT_CMD_CCSASM,


#if ( VOS_WIN32 == VOS_OS_VER )
    AT_CMD_SETRPLMN,
#endif


    AT_CMD_NVM,

    AT_CMD_CMUT,

    #if(FEATURE_ON == FEATURE_UE_MODE_TDS)
    AT_CMD_SCELLINFO,
    AT_CMD_SCALIB,

    AT_CMD_CMTM,
    #endif

    AT_CMD_APSEC,
    AT_CMD_CISA,

    AT_CMD_SIMLOCKUNLOCK,

    AT_CMD_APDS,
    AT_CMD_CLPR,
    AT_CMD_CCSERR,
    AT_CMD_WLTHRESHOLDCFG,
    AT_CMD_ACINFO,
    AT_CMD_CLTEROAMALLOW,

    AT_CMD_SWVER,

    AT_CMD_CBG,

    AT_CMD_MMPLMNINFO,

    /* Added by c00318887 for AT&T phaseII, 2015-3-12, begin */
    AT_CMD_EONSUCS2,
    /* Added by c00318887 for AT&T phaseII, 2015-3-12, end */

    AT_CMD_PLMN,
    AT_CMD_XLEMA,
    AT_CMD_COPN,
    AT_CMD_BODYSARON,

    AT_CMD_BODYSARWCDMA,
    AT_CMD_BODYSARGSM,

    AT_CMD_IMEIVERIFY,
    AT_CMD_LOGPORT,

    AT_CMD_NVRD,
    AT_CMD_NVWR,
    AT_CMD_NVRDLEN,
    AT_CMD_NVRDEX,
    AT_CMD_NVWREX,

    AT_CMD_NVWRPART,

    AT_CMD_STCFGDPCH,
    AT_CMD_STRXBER,

    AT_CMD_NCELLMONITOR,
    AT_CMD_USERSRVSTATE,

    AT_CMD_SIMSLOT,

    AT_CMD_SIMINSERT,

    AT_CMD_MODEMLOOP,

    AT_CMD_RELEASERRC,

    AT_CMD_REFCLKFREQ,

    AT_CMD_PULLOMLOG,

    AT_CMD_REJINFO,

    AT_CMD_PLMNSELEINFO,

    AT_CMD_DIESN,
    AT_CMD_CHIPSN,
    AT_CMD_HANDLEDECT,

    /* Added by zhuli for VSIM, 2013-10-15 Begin */
    AT_CMD_HVSDH,
    AT_CMD_HVSST,
    AT_CMD_HVSCONT,
    AT_CMD_HVPDH,
    AT_CMD_SCICHG,
    AT_CMD_HVTEE,
    AT_CMD_HVCHECKCARD,
    /* Added by zhuli for VSIM, 2013-10-15 end */

    AT_CMD_EOPLMN,

    AT_CMD_NETSCAN,

#if (FEATURE_ON == FEATURE_AT_HSUART)
    AT_CMD_IPR,
    AT_CMD_ICF,
    AT_CMD_IFC,
#endif

    AT_CMD_FPLLSTATUS,

    AT_CMD_ECID,


    AT_CMD_SWITCH_UART,

    AT_CMD_MIPICLK,

    AT_CMD_CLCC_IMS,
#if (FEATURE_ON == FEATURE_IMS)
    AT_CMD_CIREG,
    AT_CMD_CIREP,
    AT_CMD_VOLTEIMPU,
    AT_CMD_CCWAI,
    AT_CMD_UICCAUTH,
    AT_CMD_CURSM,
    AT_CMD_KSNAFAUTH,
#endif

    AT_CMD_ANTSWITCH,
    /* GUģAT����͹������������ID���ֵ����������IDʱҪ���ӵ���IDǰ */

    AT_CMD_CIMSROAMINGSTUB,
    AT_CMD_CREDIALSTUB,
    AT_CMD_IMSVOICEINTERSYSLAUSTUB,
    AT_CMD_IMSVOICEMMENABLESTUB,

    AT_CMD_CIMSUSSDSTUB,

#if (FEATURE_ON == FEATURE_IMS)
    AT_CMD_CACMIMS,
#endif

    AT_CMD_DPDTTEST,
    AT_CMD_DPDT,
    AT_CMD_DPDTQRY,

    AT_CMD_CECALL,
    AT_CMD_ECLSTART,
    AT_CMD_ECLSTOP,
    AT_CMD_ECLCFG,
    AT_CMD_ECLMSD,

#if (FEATURE_ON == FEATURE_DSDS)
    AT_CMD_PSPROTECTMODE,
#endif
    AT_CMD_PHYINIT,

    AT_CMD_FPOWDET,

    AT_CMD_JDETEX,

    AT_CMD_RATFREQLOCK,

#if (FEATURE_ON == FEATURE_IMS)
    AT_CMD_CALL_MODIFY_INIT,
    AT_CMD_CALL_MODIFY_ANS,
    AT_CMD_ECONFDIAL,
    AT_CMD_CLCCECONF,
    AT_CMD_ECONFERR,
#endif
    AT_CMD_CHLD_EX,

    AT_CMD_CDMACONNST,

    AT_CMD_GSMFREQLOCK,

    AT_CMD_ACTIVEMODEM,


    AT_CMD_CCLK,

    AT_CMD_CFSH,

    AT_CMD_CRM,

    AT_CMD_CARDTYPE,

    AT_CMD_CQOSPRI,

    /* Added by f279542 for CDMA 1X Iteration 4, 2014-11-10, begin */
    AT_CMD_CBURSTDTMF,
    /* Added by f279542 for CDMA 1X Iteration 4, 2014-11-10, end */

    AT_CMD_CLOCINFO,
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    /* Added by y00322978 for CDMA Iteration 17, 2015-7-9, begin */
    AT_CMD_CSID,
    AT_CMD_QCCB,
    AT_CMD_EMCCBM,
    AT_CMD_CSIDLIST,
    /* Added by y00322978 for CDMA Iteration 17, 2015-7-9, end */
#endif

    AT_CMD_CCLPR,


    /* Added by m00312079 for CDMA 1X Iteration 6 2014-12-25 begin */
    AT_CMD_CDMACSQ,
    AT_CMD_CFREQLOCK,
    /* Added by m00312079 for CDMA 1X Iteration 6 2014-12-25 end */

    AT_CMD_APDSFLOWRPTCFG,

    /* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, Begin */
    AT_CMD_IMSSWITCH,
    AT_CMD_CEVDP,
    /* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, End */

    AT_CMD_DSFLOWNVWRCFG,
#if (FEATURE_ON == FEATURE_HUAWEI_VP)
    AT_CMD_VOICEPREFER,
#endif

    AT_CMD_CUSTOMDIAL,

    AT_CMD_CDMAMODEMSWITCH,

    /* Added by w00316404 for TTY MODE, 2015-02-07, begin */
    AT_CMD_TTYMODE,
    /* Added by w00316404 for TTY MODE, 2015-02-07, end */
    AT_CMD_FEMCTRL,

    AT_CMD_NVWRSECCTRL,

#if (FEATURE_ON == FEATURE_UE_UICC_MULTI_APP_SUPPORT)
    AT_CMD_CRLA,
    AT_CMD_CARDSESSION,
    AT_CMD_PRFAPP,
    AT_CMD_CCIMI,
#endif

    /*Added by z00306637 for RATRFSWITCH, 2015-01-04, begin*/
    AT_CMD_RATRFSWITCH,
    /*Added by z00306637 for RATRFSWITCH, 2015-01-04, end*/

	/* Added by z00316370 for UTS 2015-5-15 begin */
    AT_CMD_1XCHAN,
    AT_CMD_CVER,
    AT_CMD_CCMGG,
    AT_CMD_GETSTA,
    AT_CMD_GETESN,
    AT_CMD_GETMEID,
    AT_CMD_CHIGHVER,
    /* Added by z00316370 for UTS 2015-5-15 end */

    /* Added by w00316404 for eMBMS project, 2015-5-22, begin */
#if(FEATURE_ON == FEATURE_LTE)
#if(FEATURE_ON == FEATURE_LTE_MBMS)
    AT_CMD_MBMSCMD,
    AT_CMD_MBMSEV,
    AT_CMD_MBMSINTERESTLIST,
#endif
    AT_CMD_LTELOWPOWER,
    AT_CMD_ISMCOEX,
#endif
    /* Added by w00316404 for eMBMS project, 2015-5-22, end */
    AT_CMD_CAGPSCFGPOSMODE,
    AT_CMD_CAGPSSTART,
    AT_CMD_CAGPSSTOP,
    AT_CMD_CAGPSCFGMPCADDR,
    AT_CMD_CAGPSCFGPDEADDR,
    AT_CMD_CAGPSQRYREFLOC,
    AT_CMD_CAGPSQRYTIME,
    AT_CMD_CAGPSREPLYNIREQ,
    AT_CMD_CAGPSPRMINFO,
    AT_CMD_CAGPSDATACALLSTATUS,
    AT_CMD_CUPBINDSTATUS,
    AT_CMD_CAGPSFORWARDDATA,

    /* Added by x00314862 for CDMA Iteration 14 2015-7-22 begin */
    AT_CMD_CAGPSPOSINFO,
    /* Added by x00314862 for CDMA Iteration 14 2015-7-22 end */
    /* Added by z00316370 for Nv_Esn_Meid 2015-7-18 begin */
    AT_CMD_MEID,
    /* Added by z00316370 for Nv_Esn_Meid 2015-7-18 end */

    AT_CMD_IMSPDPCFG,

    /* Added by lwx277467 for Transmision Mode, 2015-07-30, begin */
    AT_CMD_TRANSMODE,
    /* Added by lwx277467 for Transmision Mode, 2015-07-30, end */

    /* Added by w00351686 for CDMA Iteration 16 2015-7-24 begin */
    AT_CMD_CCONTDTMF,
    /* Added by w00351686 for CDMA Iteration 16 2015-7-24 end */
	
    AT_CMD_CDORMTIMER,

    /* Added by lwx277467 for Transmision Mode, 2015-07-30, begin */
    AT_CMD_UE_CENTER,
    /* Added by lwx277467 for Transmision Mode, 2015-07-30, end */

    AT_CMD_LOGENALBE,
	
    AT_CMD_MIPIWR,
    AT_CMD_MIPIRD,
    AT_CMD_SSIWR,
    AT_CMD_SSIRD,

    /* Added by z00301431 for ACT_PDP_STUB, 2015-11-4, begin */
    AT_CMD_ACTPDPSTUB,
    /* Added by z00301431 for ACT_PDP_STUB, 2015-11-4, end */

    AT_CMD_COMM_BUTT,

}AT_CMD_INDEX_ENUM;

typedef enum
{
    AT_CMD_CURRENT_OPT_BUTT                                 = 0,
    AT_CMD_D_GET_NUMBER_BEFORE_CALL,

    AT_CMD_D_CS_VOICE_CALL_SET,

    AT_CMD_D_CS_DATA_CALL_SET,

    AT_CMD_D_PPP_CALL_SET,
    AT_CMD_PPP_ORG_SET,

    AT_CMD_PS_DATA_CALL_END_SET,

    AT_CMD_WAIT_PPP_PROTOCOL_REL_SET,

    AT_CMD_D_IP_CALL_SET,
    AT_CMD_CGDATA_SET,

    AT_CMD_CGACT_ORG_SET,
    AT_CMD_CGACT_END_SET,
    AT_CMD_CGANS_ANS_SET,
    AT_CMD_CGANS_ANS_EXT_SET,

    AT_CMD_CMMI_SET,
    AT_CMD_CMMI_QUERY_CLIP,
    AT_CMD_CMMI_QUERY_CLIR,

    AT_CMD_H_SET,
    AT_CMD_END_SET,
    AT_CMD_CALL_END_SET,
    AT_CMD_H_PS_SET,

    AT_CMD_A_SET,

    AT_CMD_S0_SET,
    AT_CMD_S0_READ,

    AT_CMD_CGMI_READ,

    AT_CMD_CGMM_READ,

    AT_CMD_CGMR_READ,

    AT_CMD_CGSN_READ,

    AT_CMD_CIMI_READ,
    AT_CMD_ICCID_READ,
    AT_CMD_CSTA_SET,
    AT_CMD_CSTA_READ,

    AT_CMD_CHUP_SET,

    AT_CMD_DTMF_SET,
    AT_CMD_VTS_SET,

    AT_CMD_CLIP_READ,

    AT_CMD_COLP_READ,
    AT_CMD_CLIR_SET,
    AT_CMD_CLIR_READ,
    AT_CMD_CLCC_SET,
    /* AT+CAPS����ʵ������ò���״̬ */
    AT_CMD_CPAS_SET,

    AT_CMD_COPS_SET_AUTOMATIC,
    AT_CMD_COPS_SET_MANUAL,
    AT_CMD_COPS_SET_DEREGISTER,
    AT_CMD_COPS_SET_MANUAL_AUTOMATIC_MANUAL,
    AT_CMD_COPS_READ,
    AT_CMD_COPS_TEST,
    AT_CMD_COPS_ABORT_PLMN_LIST,

    AT_CMD_CPOL_SET,
    AT_CMD_CPOL_READ,
    /* Added by y00307564 for CDMA Iteration 8 2015-2-5 begin */
    AT_CMD_CPOL_TEST,
    /* Added by y00307564 for CDMA Iteration 8 2015-2-5 end */

    AT_CMD_CFUN_SET,
    AT_CMD_CFUN_READ,

    AT_CMD_CBND_SET,
    AT_CMD_CBND_READ,

    AT_CMD_CSQ_SET,
    AT_CMD_CBC_SET,

    AT_CMD_CPBF_SET,
    AT_CMD_CPBR_SET,
    AT_CMD_CPBR2_SET,
    AT_CMD_SCPBR_SET,
    AT_CMD_CPBW_SET,
    AT_CMD_CNUM_READ,

    AT_CMD_CSIM_SET,
    AT_CMD_CCHO_SET,
    AT_CMD_CCHC_SET,
    AT_CMD_CGLA_SET,
    AT_CMD_CRSM_SET,
    AT_CMD_CPIN_VERIFY_SET,
    AT_CMD_CPIN_UNBLOCK_SET,
    AT_CMD_CPIN_READ,

    AT_CMD_CPWD_SET,
    AT_CMD_CPWD_CHANGE_PIN,

    AT_CMD_CLCK_PIN_HANDLE,
    AT_CMD_CARD_LOCK_SET,
    AT_CMD_CARD_LOCK_READ,
    AT_CMD_CARD_ATR_READ,
    AT_CMD_CLCK_UNLOCK,
    AT_CMD_CLCK_LOCK,
    AT_CMD_CLCK_QUERY,
    /* Added by w00316404 for M project A characeristic AT part, 2015-4-7, Begin */
    AT_CMD_CLCK_SIMLOCKUNLOCK,
    AT_CMD_CLCK_SIMLOCKDATAREAD,
    /* Added by w00316404 for M project A characeristic AT part, 2015-4-7, End */
    AT_CMD_CTFR_SET,

    AT_CMD_CGEQREQ_SET,
    AT_CMD_CGEQREQ_READ,

    AT_CMD_CGEQMIN_SET,
    AT_CMD_CGEQMIN_READ,

    AT_CMD_CGPADDR_SET,
    AT_CMD_CGEQNEG_SET,
    AT_CMD_CGEQNEG_TEST,

    AT_CMD_CGACT_READ,

    AT_CMD_CGCLASS_SET,
    AT_CMD_CGCLASS_READ,

    AT_CMD_CGATT_ATTACH_SET,
    AT_CMD_CGATT_DETAACH_SET,

    AT_CMD_CGCATT_PS_ATTACH_SET,
    AT_CMD_CGCATT_CS_ATTACH_SET,
    AT_CMD_CGCATT_PS_CS_ATTACH_SET,
    AT_CMD_CGCATT_PS_DETAACH_SET,
    AT_CMD_CGCATT_CS_DETAACH_SET,
    AT_CMD_CGCATT_PS_CS_DETAACH_SET,

    AT_CMD_CGDCONT_SET,
    AT_CMD_CGDCONT_READ,

    AT_CMD_CGREG_READ,

    AT_CMD_CEREG_READ,

    AT_CMD_CGDSCONT_SET,
    AT_CMD_CGDSCONT_READ,

    AT_CMD_CGTFT_SET,
    AT_CMD_CGTFT_READ,

    AT_CMD_CGAUTH_SET,
    AT_CMD_CGAUTH_READ,

    AT_CMD_CGDNS_SET,
    AT_CMD_CGDNS_READ,

    AT_CMD_CGCMOD_SET,

    AT_CMD_CGAUTO_SET,
    AT_CMD_CGAUTO_READ,

    AT_CMD_AUTHDATA_SET,
    AT_CMD_AUTHDATA_READ,
    AT_CMD_PDPROFMOD_SET,
    /* �첽��Ϣʵ�����ӵĲ������ */
    AT_CMD_D_GPRS_SET,
    AT_CMD_NDISCONN_SET,
    AT_CMD_DSFLOWCLR_SET,
    AT_CMD_DSFLOWQRY_SET,
    AT_CMD_DSFLOWRPT_SET,
    AT_CMD_DWINS_SET,
    AT_CMD_PDPSTUB_SET,
    AT_CMD_CGCONTRDP_SET,
    AT_CMD_CGSCONTRDP_SET,
    AT_CMD_CGTFTRDP_SET,
    AT_CMD_DHCP_READ,

    AT_CMD_CGEQOS_SET,
    AT_CMD_CGEQOS_READ,
    AT_CMD_CGEQOSRDP_SET,
    AT_CMD_NDISSTATQRY_READ,

    AT_CMD_LTECS_READ,
    AT_CMD_CEMODE_SET,
    AT_CMD_CEMODE_READ,
    AT_CMD_CREG_READ,

    AT_CMD_CCUG_SET,
    AT_CMD_CCUG_READ,

    AT_CMD_CCWA_DISABLE,
    AT_CMD_CCWA_ENABLE,
    AT_CMD_CCWA_QUERY,

    AT_CMD_CNMR_QUERY,
    AT_CMD_CECELLID_QUERY,

    AT_CMD_CCFC_DISABLE,
    AT_CMD_CCFC_ENABLE,
    AT_CMD_CCFC_QUERY,
    AT_CMD_CCFC_REGISTRATION,
    AT_CMD_CCFC_ERASURE,

    AT_CMD_CUSD_REQ,

    AT_CMD_CHLD_SET,

    AT_CMD_CMOD_SET,
    AT_CMD_CMOD_READ,

    AT_CMD_CBST_SET,
    AT_CMD_CBST_READ,

    AT_CMD_CSMS_SET,
    AT_CMD_CSMS_READ,

    AT_CMD_CMSQ_SET,

    AT_CMD_CMGF_SET,
    AT_CMD_CMGF_READ,

    AT_CMD_CSCA_SET,
    AT_CMD_CSCA_READ,

    AT_CMD_CSMP_SET,
    AT_CMD_CSMP_READ,

    AT_CMD_CMGL_SET,

    AT_CMD_CMGR_SET,

    AT_CMD_CMGS_TEXT_SET,
    AT_CMD_CMGS_PDU_SET,

    AT_CMD_CNMA_TEXT_SET,
    AT_CMD_CNMA_PDU_SET,
    AT_CMD_CMSS_SET,
    AT_CMD_CMST_SET,

    AT_CMD_CMGW_TEXT_SET,
    AT_CMD_CMGW_PDU_SET,

    AT_CMD_CMGD_SET,
    AT_CMD_CMGD_TEST,

    AT_CMD_CMGI_SET,

    AT_CMD_CMGC_TEXT_SET,
    AT_CMD_CMGC_PDU_SET,

    AT_CMD_CGSMS_SET,
    AT_CMD_CGSMS_READ,

    AT_CMD_CMMT_SET,

    AT_CMD_CSCB_SET,
    AT_CMD_CSCB_READ,

    AT_CMD_CBMGR_SET,

    AT_CMD_CBMGL_SET,

    AT_CMD_CBMGD_SET,

    AT_CMD_CCNMA_SET,
    AT_CMD_CCNMA_READ,

    AT_CMD_CPBS_SET,
    AT_CMD_CPBS_READ,

    AT_CMD_CPAM_SET,
    AT_CMD_CPAM_READ,

    AT_CMD_CPIN2_VERIFY_SET,
    AT_CMD_CPIN2_UNBLOCK_SET,
    AT_CMD_CPIN2_READ,

    AT_CMD_CNMI_SET,

    AT_CMD_CSSM_SET,
    AT_CMD_CSSM_READ,

    AT_CMD_CPMS_SET,
    AT_CMD_CPMS_READ,

    AT_CMD_CMMS_SET,
    AT_CMD_CMMS_READ,

    AT_CMD_CMSTUB_SET,                                                          /* ��ʾ����^CMSTUB���ò��� */
    AT_CMD_DLOADINFO_READ,                                                      /* ��ʾ����^DLOADINFO��ѯ���� */
    AT_CMD_AUTHORITYVER_READ,                                                   /* ��ʾ����^AUTHORITYVER��ѯ���� */
    AT_CMD_AUTHORITYID_READ,                                                    /* ��ʾ����^AUTHORITYID��ѯ���� */
    AT_CMD_GODLOAD_SET,                                                         /* ��ʾ����^GODLOAD���ò��� */
    AT_CMD_SDLOAD_SET,                                                          /* ��ʾ����^SDLOAD���ò��� */

    AT_CMD_HWNATQRY_READ,                                                       /* ��ʾ����^HWNATQRY��ѯ���� */
    AT_CMD_FLASHINFO_READ,                                                      /* ��ʾ����^FLASHINFO��ѯ���� */
    AT_CMD_AUTHVER_READ,                                                        /* ��ʾ����^AUTHVER��ѯ���� */

    AT_CMD_CDUR_READ,                                                           /* ��ʾ����^CDUR��ѯ���� */
    AT_CMD_PFVER_READ,                                                          /* ��ʾ����^PFVER��ѯ���� */
    AT_CMD_DLOADVER_READ,                                                       /* ��ʾ����^DLOADVER��ѯ���� */
    AT_CMD_CPULOAD_READ,                                                        /* ��ʾ����^CPULOAD��ѯ���� */
    AT_CMD_MFREELOCKSIZE_READ,                                                  /* ��ʾ����^MFREELOCKSIZE��ѯ���� */

    AT_CMD_MEMINFO_READ,

    AT_CMD_STPD_SET,
    AT_CMD_CLVL_SET,
    AT_CMD_VMSET_SET,
    AT_CMD_F_SET,
    AT_CMD_VMSET_READ,                                                          /* AT^VMSET����ʵ���ѯ״̬ */
    AT_CMD_CVOICE_READ,                                                         /* AT^CVOICE����ʵ���ѯ״̬ */
    AT_CMD_DDSETEX_SET,                                                         /* AT^DDSETEX����ʵ������״̬ */
    AT_CMD_DDSETEX_READ,                                                        /* AT^DDSETEX����ʵ���ѯ״̬ */
    AT_CMD_NVRESTORE_READ,
    AT_CMD_NVRSTSTTS_READ,
    AT_CMD_CVOICE_SET,
    AT_CMD_STMN_SET,
    AT_CMD_STTR_SET,
    AT_CMD_STEN_SET,
    AT_CMD_STGI_SET,
    AT_CMD_STGR_SET,
    AT_CMD_IMSICHG_SET,
    AT_CMD_IMSICHG_READ,
    AT_CMD_INFORBU_SET,
    AT_CMD_INFORRS_SET,
    AT_CMD_CPNN_TEST,
    AT_CMD_CSEN_SET,
    AT_CMD_CSTR_SET,
    AT_CMD_CFRQ_SET,
    AT_CMD_CFRQ_READ,
    AT_CMD_CIMEI_SET,
    AT_CMD_CQST_SET,
    AT_CMD_CDEF_SET,
    AT_CMD_CQST_READ,
    AT_CMD_CAATT_SET,
    AT_CMD_CAATT_READ,
    AT_CMD_SYSINFO_READ,
    AT_CMD_SYSINFOEX_READ,
    AT_CMD_CFPLMN_SET,
    AT_CMD_CFPLMN_READ,
    AT_CMD_SYSCFG_SET,
    AT_CMD_SYSCFG_READ,
    AT_CMD_SYSCFG_TEST,
    AT_CMD_SYSCFGEX_READ,
    AT_CMD_SYSCFGEX_TEST,
    AT_CMD_PNN_READ,
    AT_CMD_CPNN_READ,
    AT_CMD_OPL_READ,
    AT_CMD_HS_READ,
    AT_CMD_SS_REGISTER,
    AT_CMD_SS_ERASE,
    AT_CMD_SS_ACTIVATE,
    AT_CMD_SS_DEACTIVATE,
    AT_CMD_SS_INTERROGATE,
    AT_CMD_SS_REGISTER_PSWD,
    /* Delete AT_CMD_SS_GET_PSWD */
    AT_CMD_SS_USSD,
    AT_CMD_SET_TMODE,
    AT_CMD_SET_FTXON,
    AT_CMD_SET_FRXON,
    AT_CMD_SET_FWAVE,                                                           /* ��ʾ����^FWAVE���ò��� */
    AT_CMD_QUERY_RSSI,
    AT_CMD_SET_RXDIV,
    AT_CMD_SET_RXPRI,
    AT_CMD_SS_DEACTIVE_CCBS,
    AT_CMD_SS_INTERROGATE_CCBS,
    AT_CMD_CSQLVLEXT_SET,
    AT_CMD_CSQLVL_SET,                                                          /* ��ʾ����^CSQLVL���ò��� */
    AT_CMD_APPDMVER_READ,                                                       /* ��ʾ����^APPDMVER��ѯ���� */
    AT_CMD_APBATLVL_READ,                                                       /* ��ʾ����^APBATLVL��ѯ���� */
    AT_CMD_MSID_READ,
    AT_CMD_CWAS_QUERY,
    AT_CMD_CGAS_QUERY,
    AT_CMD_CELLINFO_QUERY,
    AT_CMD_MEANRPT_QUERY,
    AT_CMD_REGISTER_TIME_READ,
    AT_CMD_ANQUERY_READ,
    AT_CMD_HOMEPLMN_READ,
    AT_CMD_VERSIONTIME_READ,
    AT_CMD_FREQLOCK_SET,
    AT_CMD_FREQLOCK_QUERY,
    AT_CMD_CSNR_QUERY,
    AT_CMD_RRC_VERSION_SET,
    AT_CMD_RRC_VERSION_QUERY,
    AT_CMD_YJCX_SET,
    AT_CMD_YJCX_QUERY,
    AT_CMD_CRPN_QUERY,
    AT_CMD_SPN_QUERY,
    AT_CMD_CC_STATE_QUERY,
    AT_CMD_MM_TEST_CMD_SET,


    AT_CMD_RSIM_READ,
    AT_CMD_GPIOPL_SET,
    AT_CMD_GPIOPL_QRY,
    AT_CMD_DATALOCK_SET,
    AT_CMD_TBATVOLT_QRY,
    AT_CMD_VERSION_QRY,
    AT_CMD_SECUBOOT_QRY,
    AT_CMD_SECUBOOT_SET,
    AT_CMD_SECUBOOTFEATURE_QRY,
    AT_CMD_PRODTYPE_QRY,
    AT_CMD_SFEATURE_QRY,
    AT_CMD_FCHAN_SET,
    AT_CMD_RXPRI_QRY,
    AT_CMD_TSELRF_SET,
    AT_CMD_TBAT_SET,
    AT_CMD_TBAT_QRY,
    AT_CMD_STANDBY_SET,
    AT_CMD_DRV_AGENT_HARDWARE_QRY,
    AT_CMD_DRV_AGENT_FULL_HARDWARE_QRY,
    AT_CMD_WAS_MNTN_SET_CELLSRH,
    AT_CMD_WAS_MNTN_QRY_CELLSRH,
    AT_CMD_DRV_AGENT_RXDIV_SET_REQ,
    AT_CMD_DRV_AGENT_RXDIV_QRY_REQ,
    AT_CMD_DRV_AGENT_SIMLOCK_SET_REQ,
    AT_CMD_MMA_GET_CURRENT_ATTACH_STATUS,
    AT_CMD_APP_QRY_ALS_REQ,
    AT_CMD_MMA_MT_POWER_DOWN,
    AT_CMD_MMA_SET_PREF_PLMN,
    AT_CMD_MMA_SET_PREF_PLMN_TYPE,
    AT_CMD_APP_SET_UUSINFO_REQ,
    AT_CMD_APP_SET_ALS_REQ,
    AT_CMD_MSG_MMA_SET_PIN,
    AT_CMD_CSSN_SET,


    AT_CMD_BOOTROMVER_READ,

    AT_CMD_NVBACKUP_SET,
    AT_CMD_NVRESTORE_SET,
    AT_CMD_RESET_SET,
    AT_CMD_NVRSTSTTS_SET,
    AT_CMD_TBAT_READ,
    AT_CMD_SECUBOOTFEATURE_READ,

    AT_CMD_CURC_READ,
    AT_CMD_UNSOLICITED_RPT_SET,
    AT_CMD_UNSOLICITED_RPT_READ,
    AT_CMD_NCELL_MONITOR_SET,
    AT_CMD_NCELL_MONITOR_READ,
    AT_CMD_USER_SRV_STATE_READ,

    AT_CMD_TMODE_SET,
    AT_CMD_TMODE_READ,
    AT_CMD_TMODE_TEST,

    AT_CMD_BANDSW_SET,
    AT_CMD_BANDSW_READ,

    AT_CMD_F_FCHANS_SET,
    AT_CMD_F_FCHANS_READ,

    AT_CMD_F_FSEGMENT_SET,
    AT_CMD_F_FSEGMENT_READ,

    AT_CMD_F_FPOWS_SET,
    AT_CMD_F_FPOWS_READ,

    AT_CMD_F_FPAS_SET,
    AT_CMD_F_FPAS_READ,

    AT_CMD_F_FLNAS_SET,
    AT_CMD_F_FLNAS_READ,

    AT_CMD_F_FTXWAVE_SET,
    AT_CMD_F_FTXWAVE_READ,

    AT_CMD_F_FSTART_SET,
    AT_CMD_F_FSTART_READ,

    AT_CMD_F_FRSSIS_SET,

    AT_CMD_F_FCMTMS_READ,

    AT_CMD_F_FBLK_SET,
    AT_CMD_F_FBLK_READ,

    AT_CMD_F_FIPSTART_SET,

    AT_CMD_F_FPDMS_SET,

    AT_CMD_F_FMAXPOWER_SET,
    AT_CMD_F_FMAXPOWER_READ,

    AT_CMD_F_FPAPOWER_SET,
    AT_CMD_F_FPAPOWER_READ,

    AT_CMD_F_FPDMS_READ,


    /*  AT_CMD_FCHAN_SET, */
    AT_CMD_FCHAN_READ,

    AT_CMD_FANT_SET,
    AT_CMD_FANT_READ,

    AT_CMD_FPOW_SET,

    AT_CMD_FPA_SET,
    AT_CMD_FDAC_SET,

    AT_CMD_FLNA_SET,
    AT_CMD_FLNA_READ,

    AT_CMD_FTXON_SET,
    AT_CMD_FTXON_READ,

    AT_CMD_FRXON_SET,
    AT_CMD_FRXON_READ,

    AT_CMD_FVCTCXO_SET,
    AT_CMD_FVCTCXO_READ,

    AT_CMD_FRSSI_READ,

    /*�������۲�start */
    AT_CMD_SSYNC_SET,
    AT_CMD_SSYNC_READ,

    AT_CMD_STXBW_SET,
    AT_CMD_STXBW_READ,

    AT_CMD_STXCHAN_SET,
    AT_CMD_STXCHAN_READ,

    AT_CMD_SSUBFRAME_SET,
    AT_CMD_SSUBFRAME_READ,

    AT_CMD_SPARA_SET,
    AT_CMD_SPARA_READ,

    AT_CMD_SSEGNUM_SET,
    AT_CMD_SSEGNUM_READ,

    AT_CMD_STXMODUS_SET,
    AT_CMD_STXMODUS_READ,

    AT_CMD_STXRBNUMS_SET,
    AT_CMD_STXRBNUMS_READ,

    AT_CMD_STXRBPOSS_SET,
    AT_CMD_STXRBPOSS_READ,

    AT_CMD_STXPOWS_SET,
    AT_CMD_STXPOWS_READ,

    AT_CMD_STXCHANTYPES_SET,
    AT_CMD_STXCHANTYPES_READ,

    AT_CMD_SSEGLEN_SET,
    AT_CMD_SSEGLEN_READ,

    AT_CMD_SRXSET_SET,
    AT_CMD_SRXSET_READ,

    AT_CMD_SRXPOW_SET,
    AT_CMD_SRXPOW_READ,

    AT_CMD_SRXSUBFRA_SET,
    AT_CMD_SRXSUBFRA_READ,

    AT_CMD_SRXBLER_READ,

    AT_CMD_SSTART_SET,
    AT_CMD_SSTART_READ,

    AT_CMD_SSTOP_SET,

    AT_CMD_CIPERQRY_READ,
    AT_CMD_LOCINFO_READ,
    AT_CMD_ACINFO_READ,

    AT_CMD_CERSSI_READ,

    //�������۲�end
    AT_CMD_ADC_SET,
    AT_CMD_FASTDORM_SET,
    AT_CMD_FASTDORM_READ,
    AT_CMD_APTHROUGH_PUT_READ,                                                  /* ��ʾ����^APTHROUGHPUT��ѯ���� */
    AT_CMD_APDIALMODE_READ,                                                     /* ��ʾ����^APDIALMODE��ѯ���� */

    AT_CMD_ACPUMEMINFO,
    AT_CMD_CCPUMEMINFO,
#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
    AT_CMD_SPWORD_SET,
#endif
    AT_CMD_SIMLOCKSTATUS_READ,
    AT_CMD_CSDFLT_READ,

    AT_CMD_CGPADDR_TEST,

    AT_CMD_NVBACKUPSTAT_READ,
    AT_CMD_NANDBBC_READ,
    AT_CMD_NANDVER_READ,
    AT_CMD_CHIPTEMP_READ,

    AT_CMD_CSASM_SET,
    AT_CMD_DNSQUERY_SET,
    AT_CMD_CELLROAM_READ,

    AT_CMD_TCHRENABLE_SET,
    AT_CMD_TCHRENABLE_TEST,
    AT_CMD_RSFR_VERSION_QRY,

    AT_CMD_MAXLCKTMS_SET,                                                       /* ��ʾ����^MAXLCKTMS���ò��� */

    AT_CMD_HUK_SET,
    AT_CMD_FACAUTHPUBKEY_SET,
    AT_CMD_IDENTIFYSTART_SET,
    AT_CMD_IDENTIFYEND_SET,
    AT_CMD_SIMLOCKDATAWRITE_SET,
    AT_CMD_PHONESIMLOCKINFO_READ,
    AT_CMD_SIMLOCKDATAREAD_READ,
    AT_CMD_PHONEPHYNUM_SET,
    AT_CMD_PHONEPHYNUM_READ,
    AT_CMD_PORTCTRLTMP_SET,
    AT_CMD_PORTCTRLTMP_READ,
    AT_CMD_PORTATTRIBSET_SET,
    AT_CMD_PORTATTRIBSET_READ,
    AT_CMD_OPWORD_SET,
    AT_CMD_CLVL_READ,

    AT_CMD_APSIMST_SET,

#if(FEATURE_ON == FEATURE_UE_MODE_TDS)
    AT_CMD_SCALIB_SET,
    AT_CMD_SCALIB_READ,
    AT_CMD_SCELLINFO_READ,

    AT_CMD_CMTM_READ,
#endif
    AT_CMD_CPOS_SET,
    AT_CMD_CGPSCLOCK_SET,


    AT_CMD_CERSSI_SET,
    AT_CMD_CNMR_READ,
    AT_CMD_CELL_ID_READ,
    AT_CMD_CPSERR_SET,

    AT_CMD_APSEC_SET,
    AT_CMD_CISA_SET,

    AT_CMD_CMUT_SET,
    AT_CMD_CMUT_READ,

    AT_CMD_SIMLOCKUNLOCK_SET,

    AT_CMD_CLPR_SET,
    AT_CMD_FWAVE_SET,
    AT_CMD_SWVER_SET,

    AT_CMD_CBG_SET,
    AT_CMD_CBG_READ,

    AT_CMD_MMPLMNINFO_QRY,

    /* Added by c00318887 for AT&T phaseII, 2015-3-12, begin */
    AT_CMD_EONSUCS2_QRY,
    /* Added by c00318887 for AT&T phaseII, 2015-3-12, end */

    AT_CMD_PLMN_QRY,
    AT_CMD_XLEMA_QRY,

    AT_CMD_BODYSARON_SET,

    AT_CMD_FCALIIP2S_SET,
    AT_CMD_FCALIIP2S_READ,
    AT_CMD_FCALIDCOCS_SET,
    AT_CMD_FCALIDCOCS_READ,
    AT_CMD_FGAINSTATES_SET,
    AT_CMD_FGAINSTATES_READ,
    AT_CMD_FDBBATTS_SET,
    AT_CMD_FDBBATTS_READ,
    AT_CMD_FBBATTS_SET,
    AT_CMD_FBBATTS_READ,
    AT_CMD_FCALITXIQS_SET,
    AT_CMD_FCALITXIQS_READ,

    AT_CMD_F_FCALPDDCS_SET,
    AT_CMD_F_FCALPDDCS_RD,
    AT_CMD_F_FPDPOWS_SET,
    AT_CMD_F_FQPDDCRES_SET,
    AT_CMD_IMEI_VERIFY_READ,

    AT_CMD_COPN_QRY,
    AT_CMD_STCFGDPCH_SET,
    AT_CMD_STRXBER_SET,

    AT_CMD_SIMINSERT_SET,

    AT_CMD_RELEASE_RRC_SET,

    AT_CMD_REFCLKFREQ_SET,
    AT_CMD_REFCLKFREQ_READ,

    AT_CMD_HANDLEDECT_SET,
    AT_CMD_HANDLEDECT_QRY,

    AT_CMD_HVSDH_SET,
    AT_CMD_HVSDH_READ,
    AT_CMD_HVSCONT_READ,
    AT_CMD_HVSST_SET,
    AT_CMD_HVSST_QRY,
    AT_CMD_HVPDH_SET,
    AT_CMD_SCICHG_SET,
    AT_CMD_SCICHG_QRY,

    AT_CMD_EOPLMN_SET,
    AT_CMD_EOPLMN_QRY,

    AT_CMD_NVMANUFACTUREEXT_SET,
    AT_CMD_NETSCAN_SET,
    AT_CMD_ABORT_NETSCAN,

    AT_CMD_FPLLSTATUS_QRY,

    AT_CMD_ECID_SET,

    AT_CMD_CLCC_QRY,
#if (FEATURE_ON == FEATURE_IMS)
    AT_CMD_CIREG_SET,
    AT_CMD_CIREG_QRY,
    AT_CMD_CIREP_SET,
    AT_CMD_CIREP_QRY,
    AT_CMD_IMPU_SET,
    AT_CMD_CCWAI_SET,
    AT_CMD_UICCAUTH_SET,
    AT_CMD_CURSM_SET,
    AT_CMD_KSNAFAUTH_SET,
#endif

    AT_CMD_ANTSWITCH_SET,
    AT_CMD_ANTSWITCH_QRY,
    AT_CMD_CACMIMS_SET,

    AT_CMD_MODEMSTATUS,
    AT_CMD_RATCOMBINEPRIO,

    AT_CMD_MIPI_CLK_QRY,

    AT_CMD_DPDTTEST_SET,
    AT_CMD_DPDT_SET,
    AT_CMD_DPDTQRY_SET,

#if (FEATURE_ON == FEATURE_DSDS)
    AT_CMD_PSPROTECTMODE_SET,
#endif
    AT_CMD_PHYINIT_SET,
    AT_CMD_CECALL_SET,
    AT_CMD_CECALL_QRY,
    AT_CMD_ECLSTART_SET,
    AT_CMD_ECLSTOP_SET,
    AT_CMD_ECLCFG_SET,
    AT_CMD_ECLCFG_QRY,
    AT_CMD_ECLMSD_SET,
    AT_CMD_ECLMSD_QRY,
    AT_CMD_FPOWDET_QRY,

    AT_CMD_JDETEX_SET,

    AT_CMD_RATFREQLOCK_SET,

#if (FEATURE_ON == FEATURE_IMS)
    AT_CMD_CALL_MODIFY_INIT_SET,
    AT_CMD_CALL_MODIFY_ANS_SET,
    AT_CMD_ECONF_DIAL_SET,
    AT_CMD_CLCCECONF_QRY,
    /* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, Begin */
    AT_CMD_IMS_SWITCH_SET,
    AT_CMD_IMS_SWITCH_QRY,
    AT_CMD_VOICE_DOMAIN_SET,
    AT_CMD_VOICE_DOMAIN_QRY,
    /* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, End */
#endif
    AT_CMD_CHLD_EX_SET,
    AT_CMD_APDS_SET,

    AT_CMD_GSM_FREQLOCK_SET,

    AT_CMD_CARDTYPE_QUERY,

    AT_CMD_CRM_SET,

    AT_CMD_CQOSPRI_SET,

    AT_CMD_CLOCINFO_QRY,

    AT_CMD_CSID_QRY,

#if (FEATURE_ON == FEATURE_LTE)
    AT_CMD_FRSTATUS_SET,
#endif

    AT_CMD_CFSH_SET,

    /* Added by f279542 for CDMA 1X Iteration 4, 2014-11-10, begin */
    AT_CMD_CBURSTDTMF_SET,
    /* Added by f279542 for CDMA 1X Iteration 4, 2014-11-10, end */

    /* Added by y00307564 for CDMA 1X Iteration 6, 2014-12-29, begin */
    AT_CMD_CFREQLOCK_SET,
    AT_CMD_CFREQLOCK_QRY,
    /* Added by y00307564 for CDMA 1X Iteration 6, 2014-12-29, end */

    AT_CMD_CCMGS_SET,
    AT_CMD_CCMGW_SET,
    AT_CMD_CCMGD_SET,

    AT_CMD_CCSASM_SET,

    /* Added by m00312079 for CDMA 1X Iteration 6 2014-12-25 begin */
    AT_CMD_CDMACSQ_SET,
    AT_CMD_CDMACSQ_QRY,
    /* Added by m00312079 for CDMA 1X Iteration 6 2014-12-25 end */

    AT_CMD_APDSFLOWRPTCFG_SET,
    AT_CMD_APDSFLOWRPTCFG_QRY,

    AT_CMD_DSFLOWNVWRCFG_SET,
    AT_CMD_DSFLOWNVWRCFG_QRY,

    AT_CMD_CTA_SET,
    AT_CMD_CTA_QRY,


#if (FEATURE_ON == FEATURE_HUAWEI_VP)
    AT_CMD_VOICEPREFER_SET,
    AT_CMD_VOICEPREFER_QRY,
#endif
    AT_CMD_CUSTOMDIAL_SET,

    /* Added by w00316404 for TTY MODE, 2015-02-07, begin */
    AT_CMD_TTYMODE_SET,
    AT_CMD_TTYMODE_READ,
    /* Added by w00316404 for TTY MODE, 2015-02-07, end */
    AT_CMD_FEMCTRL_SET,
    AT_CMD_NVWRSECCTRL_SET,

#if (FEATURE_ON == FEATURE_UE_UICC_MULTI_APP_SUPPORT)
    AT_CMD_CRLA_SET,
    AT_CMD_CARDSESSION_QRY,

    AT_CMD_CCIMI_SET,
#endif

    /* Added by y00322978 for CDMA Iteration 17, 2015-7-10, begin */
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    AT_CMD_QCCB_SET,
    AT_CMD_CSIDLIST_SET,
    AT_CMD_CSID_SET,
    AT_CMD_EMCCBM_QRY,
#endif

    AT_CMD_CCLPR_SET,


    /* Added by y00322978 for CDMA Iteration 17, 2015-7-10, end */
    /* Added by z00316370 for UTS 2015-5-15 begin */
    AT_CMD_1XCHAN_SET,
    AT_CMD_1XCHAN_QRY,
    AT_CMD_CVER_QRY,
    AT_CMD_CCMGG_QRY,
    AT_CMD_GETSTA_QRY,
    AT_CMD_GETESN_QRY,
    AT_CMD_GETMEID_QRY,
    AT_CMD_CHIGHVER_QRY,
    /* Added by z00316370 for UTS 2015-5-15 end */
    /* Added by w00316404 for eMBMS project, 2015-5-22, begin */
#if(FEATURE_ON == FEATURE_LTE)
#if(FEATURE_ON == FEATURE_LTE_MBMS)
    AT_CMD_MBMS_SERVICE_OPTION_SET,
    AT_CMD_MBMS_SERVICE_STATE_SET,
    AT_CMD_MBMS_PREFERENCE_SET,
    AT_CMD_MBMS_SIB16_NETWORK_TIME_QRY,
    AT_CMD_MBMS_BSSI_SIGNAL_LEVEL_QRY,
    AT_CMD_MBMS_NETWORK_INFO_QRY,
    AT_CMD_EMBMS_STATUS_QRY,
    AT_CMD_MBMS_UNSOLICITED_CFG_SET,
    AT_CMD_MBMS_INTERESTLIST_SET,
    AT_CMD_MBMS_AVL_SERVICE_LIST_QRY,
#endif
    AT_CMD_LTE_LOW_POWER_CONSUMPTION_SET,
    AT_CMD_LTE_WIFI_COEX_SET,
    AT_CMD_LTE_WIFI_COEX_QRY,
#endif
    /* Added by w00316404 for eMBMS project, 2015-5-22, end */

    AT_CMD_CGMTU_READ,

    AT_CMD_CAGPSCFGPOSMODE_SET,
    AT_CMD_CAGPSSTART_SET,
    AT_CMD_CAGPSSTOP_SET,
    AT_CMD_CAGPSCFGMPCADDR_SET,
    AT_CMD_CAGPSCFGPDEADDR_SET,

    /* Added by z00316370 for Nv_Esn_Meid 2015-7-23 begin */
    AT_CMD_MEID_SET,
    /* Added by z00316370 for Nv_Esn_Meid 2015-7-23 end */

    AT_CMD_IMSPDPCFG_SET,
	
    /* Added by w00351686 for CDMA Iteration 16 2015-7-24 begin */
    AT_CMD_CCONTDTMF_SET,
    /* Added by w00351686 for CDMA Iteration 16 2015-7-24 end */

    /* Added by lwx277467 for Transmision Mode, 2015-07-30, begin */
    AT_CMD_TRANSMODE_READ,
    /* Added by lwx277467 for Transmision Mode, 2015-07-30, end */
	
    AT_CMD_DORMTIMER_SET,
    AT_CMD_DORMTIMER_QRY,

    /* Added by lwx277467 for Transmision Mode, 2015-07-30, begin */
    AT_CMD_UE_CENTER_SET,
    AT_CMD_UE_CENTER_QRY,
    /* Added by lwx277467 for Transmision Mode, 2015-07-30, end */

    AT_CMD_MIPI_WR,
    AT_CMD_MIPI_RD,
    AT_CMD_SSI_WR,
    AT_CMD_SSI_RD,

    AT_CMD_INVALID,

    /* GUģAT����͹�������ĵ�ǰ����ID�����������IDʱҪ���ӵ���IDǰ */
    AT_CMD_COMM_CURRENT_OPT

}AT_CMD_CURRENT_OPT_ENUM;

typedef enum
{
    AT_STRING_SM = 0,
    AT_STRING_ME,
    AT_STRING_ON,
    AT_STRING_EN,
    AT_STRING_FD,
    AT_STRING_BD,
    AT_STRING_REC_UNREAD_TEXT,
    AT_STRING_REC_READ_TEXT,
    AT_STRING_STO_UNSENT_TEXT,
    AT_STRING_STO_SENT_TEXT,
    AT_STRING_ALL_TEXT,
    AT_STRING_REC_UNREAD_PDU,
    AT_STRING_REC_READ_PDU,
    AT_STRING_STO_UNSENT_PDU,
    AT_STRING_STO_SENT_PDU,
    AT_STRING_ALL_PDU,
    AT_STRING_IP,
    AT_STRING_PPP,
#if (FEATURE_ON == FEATURE_IPV6)
    AT_STRING_IPV6,
    AT_STRING_IPV4V6,
#endif

    AT_STRING_0E0,
    AT_STRING_1E2,
    AT_STRING_7E3,
    AT_STRING_1E3,
    AT_STRING_1E4,
    AT_STRING_1E5,
    AT_STRING_1E6,
    AT_STRING_1E1,
    AT_STRING_5E2,
    AT_STRING_5E3,
    AT_STRING_4E3,
    AT_STRING_6E8,
    AT_STRING_CREG,
    AT_STRING_CGREG,
#if (FEATURE_ON == FEATURE_LTE)
    AT_STRING_CEREG,
#endif
    AT_STRING_SRVST,
    AT_STRING_MODE,
    AT_STRING_RSSI,
    AT_STRING_TIME,
    AT_STRING_CTZV,
    AT_STRING_ERRRPT,
    AT_STRING_CCALLSTATE,

    AT_STRING_CERSSI,

    AT_STRING_ACINFO,

    AT_STRING_CS_CHANNEL_INFO,

    AT_STRING_RESET,

    AT_STRING_REFCLKFREQ,

    AT_STRING_REJINFO,

    AT_STRING_PLMNSELEINFO,

    AT_STRING_NETSCAN,

#if (FEATURE_ON == FEATURE_IMS)
    AT_STRING_CIREPH,
    AT_STRING_CIREPI,
    AT_STRING_CIREGU,

    AT_STRING_CALL_MODIFY_IND,
    AT_STRING_CALL_MODIFY_BEG,
    AT_STRING_CALL_MODIFY_END,

    AT_STRING_ECONFSTATE,

#endif

    /* Added by y00307564 for 1X SS Project, 2014-11-14, begin */
    AT_STRING_CDISP,
    AT_STRING_CCONNNUM,
    AT_STRING_CCALLEDNUM,
    AT_STRING_CCALLINGNUM,
    AT_STRING_CREDIRNUM,
    AT_STRING_CSIGTONE,
    AT_STRING_CLCTR,
    AT_STRING_CCWAC,
    /* Added by y00307564 for 1X SS Project, 2014-11-14, end */

    /* Added by c00318887 for AT&T phaseII, 2015-3-2, begin */
    AT_STRING_FILECHANGE,
    /* Added by c00318887 for AT&T phaseII, 2015-3-2, end */

    /* Added by w00316404 for eMBMS project, 2015-5-22, begin */
#if((FEATURE_ON == FEATURE_LTE) && (FEATURE_ON == FEATURE_LTE_MBMS))
    AT_STRING_MBMSEV,
#endif
    /* Added by w00316404 for eMBMS project, 2015-5-22, end */
    AT_STRING_SRCHEDPLMNINFO,
    AT_STRING_BUTT
}AT_STRING_CONTENT_ENUM;


#define AT_CMD_CLVL_VAL_MAX             (5)
enum AT_CMD_CLVL_VALUE_ENUM
{
    AT_CMD_CLVL_LEV_0                 = 0,
    AT_CMD_CLVL_LEV_1                 = 50,
    AT_CMD_CLVL_LEV_2                 = 60,
    AT_CMD_CLVL_LEV_3                 = 68,
    AT_CMD_CLVL_LEV_4                 = 74,
    AT_CMD_CLVL_LEV_5                 = 80
};

typedef TAF_UINT8 AT_CMD_BLOCK_STATE_TYPE;
#define AT_CMD_READY            0
#define AT_CMD_PEND             1
#define AT_CMD_ABORT            2


typedef TAF_UINT8 AT_DATA_STATE_TYPE;
#define AT_DATA_STOP_STATE            0
#define AT_DATA_START_STATE            1

typedef TAF_UINT8 AT_CMD_MODE_TYPE;
#define AT_NORMAL_MODE          0
#define AT_SMS_MODE             1
#define AT_XML_MODE             2

typedef TAF_UINT8 AT_CHANNEL_TYPE;
#define AT_CMD_CHANNEL           0
#define AT_DATA_CHANNEL          1


typedef TAF_UINT8 AT_DATA_MODE_TYPE;
#define AT_DATA_BUTT_MODE           0
#define AT_PPP_DATA_MODE            1
#define AT_IP_DATA_MODE             2
#define AT_CSD_DATA_MODE            3
#define AT_DIAG_DATA_MODE           4
#define AT_OM_DATA_MODE             5
#define AT_AP_DATA_MODE            6

typedef TAF_UINT8 AT_V_TYPE;
#define AT_V_BREVITE_TYPE            0
#define AT_V_ENTIRE_TYPE            1


typedef TAF_UINT8 AT_CMD_ECHO_TYPE;
#define AT_E_NO_ECHO_CMD            0
#define AT_E_ECHO_CMD               1

typedef TAF_UINT8 AT_COPS_MODE_TYPE;
#define AT_COPS_AUTOMATIC_TYPE            0
#define AT_COPS_MANUAL_TYPE            1
#define AT_COPS_DEREGISTER_TYPE            2
#define AT_COPS_ONLY_SET_FORMAT_TYPE            3
#define AT_COPS_MANUAL_AUTOMATIC_TYPE            4

enum AT_COPS_RAT_ENUM
{
    AT_COPS_RAT_GSM    = 0,
    AT_COPS_RAT_WCDMA  = 2,
    AT_COPS_RAT_LTE    = 7,
    AT_COPS_RAT_BUTT
};
typedef VOS_UINT8 AT_COPS_RAT_ENUM_UINT8;

typedef TAF_UINT8 AT_D_GPRS_ACTIVE_TYPE;
#define AT_IP_ACTIVE_TE_PPP_MT_PPP_TYPE            0
#define AT_PPP_ACTIVE_TE_PPP_MT_NOT_PPP_TYPE            1
#define AT_IP_ACTIVE_TE_NOT_PPP_MT_NOT_PPP_TYPE            2

typedef TAF_UINT8 AT_DATA_DOMAIN_TYPE;
#define AT_DATA_CS_DOMAIN                  0       /*CS��*/
#define AT_DATA_PS_DOMAIN                  1       /*PS��*/

typedef TAF_UINT8 AT_SMT_BUFFER_STATE;
#define AT_SMT_BUFFER_EMPTY                0
#define AT_SMT_BUFFER_USED                 1

/*��Ҫ���ٴ���������At_QuickHandleCmd��aucQuickCmd�����е�λ�ö��壬*/
#define AT_QUICK_HANDLE_SYSINFO_CMD            0
#define AT_QUICK_HANDLE_COPS_QRY_CMD           1
#define AT_QUICK_HANDLE_COPS_SET_FORMAT_2_CMD  2
#define AT_QUICK_HANDLE_COPS_SET_FORMAT_0_CMD  3
#define AT_QUICK_HANDLE_CSQ_CMD                4
#define AT_QUICK_HANDLE_SPN_SIM                5
#define AT_QUICK_HANDLE_SPN_USIM               6
#define AT_QUICK_HANDLE_CPMS_SET_CMD           7

typedef enum
{
    AT_COM_CMD_SUB_PROC_CONTINUE = 0,        /* ������������Ĵ��� */
    AT_COM_CMD_SUB_PROC_ABORT,               /* ��ֹ��������Ĵ��� */
    AT_COM_CMD_SUB_PROC_FINISH,              /* ������������Ĵ��� */

    AT_COM_CMD_SUB_PROC_BUTT
}AT_COMBINE_CMD_SUBSEQUENT_PROCESS_ENUM;


typedef enum AT_NVIM_PARA_ENUM
{
    AT_NVIM_CPMS_TYPE = 0,

    AT_NVIM_BUTT_TYPE                   /* ���� */
}AT_NVIM_PARA_ENUM;





/*****************************************************************************
 ö����    : AT_CUSTOMIZE_ITEM_DEFAULT_VAL_ENUM
 Э�����  :
 ö��˵��  : AT��������^CDSFLT���ö�����ΪĬ��ֵ
*****************************************************************************/
enum AT_CUSTOMIZE_ITEM_DEFAULT_VAL_ENUM
{
    AT_CUSTOMIZE_ITEM_DEFAULT_VALUE_FROM_CFGFILE = 0,      /*������Ĭ��ֵΪ�����������ĵ��е�ֵ*/
    AT_CUSTOMIZE_ITEM_DEFAULT_VALUE_FROM_UE,               /*�������е�ֵΪ�����Զ����Ĭ��ֵ*/
    AT_CUSTOMIZE_ITEM_DEFAULT_VALUE_BUTT
};
typedef VOS_UINT8  AT_CUSTOMIZE_ITEM_DFLT_ENUM_UINT8;

/*****************************************************************************
 ö����    : AT_SD_OPRT_ENUM_UINT32
 Э�����  :
 ö��˵��  : SD����������
*****************************************************************************/
enum AT_SD_OPRT_ENUM
{
    AT_SD_OPRT_FORMAT = 0,      /* ��ʽ��SD������ */
    AT_SD_OPRT_ERASE,           /* ����SD������ */
    AT_SD_OPRT_WRITE,           /* д���ݵ�SD����ָ����ַ�� */
    AT_SD_OPRT_READ,            /* ��ȡSD��ָ����ַ������ */
    AT_SD_OPRT_QUERY_STATUS,    /* ��ѯSD������״̬ */
    AT_SD_OPRT_BUTT
};
typedef VOS_UINT32 AT_SD_OPRT_ENUM_UINT32;


/*****************************************************************************
 ö����    : AT_SD_OPRT_RSLT_ENUM_UINT8
 Э�����  :
 ö��˵��  : SD���������
*****************************************************************************/
enum AT_SD_OPRT_RSLT_ENUM
{
    AT_SD_OPRT_RSLT_FINISH = 0,     /* ��һ�� SD��������� */
    AT_SD_OPRT_RSLT_NOT_FINISH,     /* ��һ��SD�����ڽ����� */
    AT_SD_OPRT_RSLT_ERR,            /* ��һ��SD������������*/
    AT_SD_OPRT_RSLT_BUTT,
};
typedef VOS_UINT8 AT_SD_OPRT_RSLT_ENUM_UINT8;

/*****************************************************************************
 ö����    : AT_SD_STATUS_ENUM_UINT8
 Э�����  :
 ö��˵��  : SD����λ״̬
*****************************************************************************/
enum AT_SD_EXIST_STATUS_ENUM
{
    AT_SD_STATUS_NOT_EXIST = 0,     /* SD����λ */
    AT_SD_STATUS_EXIST,             /* SD��λ */
    AT_SD_STATUS_BUTT,
};
typedef VOS_UINT8 AT_SD_EXIST_STATUS_ENUM_UINT8;

/*****************************************************************************
 ö����    : AT_SD_ERR_ENUM_UINT32
 Э�����  :
 ö��˵��  : SD������������
*****************************************************************************/
enum AT_SD_ERR_ENUM
{
    AT_SD_ERR_CRAD_NOT_EXIST = 0,      /* ��ʾSD������λ */
    AT_SD_ERR_INIT_FAILED,             /* ��ʾSD����ʼ��ʧ�� */
    AT_SD_ERR_OPRT_NOT_ALLOWED,        /* ���������� */
    AT_SD_ERR_ADDR_ERR,                /* ��ʾ<address>��ַ�Ƿ� */
    AT_SD_ERR_OTHER_ERR,               /* ����δ֪���� */
    AT_SD_ERR_BUTT
};
typedef VOS_UINT32 AT_SD_ERR_ENUM_UINT32;


/*****************************************************************************
 ö����    : AT_SIMLOCK_OPRT_ENUM_UINT8
 Э�����  :
 ö��˵��  : SD����������
*****************************************************************************/
enum AT_SIMLOCK_OPRT_ENUM
{
    AT_SIMLOCK_OPRT_UNLOCK = 0,         /* Simlock �������� */
    AT_SIMLOCK_OPRT_SET_PLMN_INFO,      /* ���������Ŷ� */
    AT_SIMLOCK_OPRT_QRY_STATUS,              /* ��ѯ��ǰ������״̬ */
    AT_SIMLOCK_OPRT_BUTT
};
typedef VOS_UINT8 AT_SIMLOCK_OPRT_ENUM_UINT8;


/*****************************************************************************
 �ṹ��    : AT_NV_WCDMA_RRC_CONVERT_TBL_STRU
 �ṹ˵��  : Rrc�汾�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT8  ucSrcWcdmaRRC;                               /* �汾�� */
    VOS_UINT8  ucDestHSDPA;                                 /* �Ƿ�֧��DPA */
    VOS_UINT8  ucDestHSUPA;                                 /* �Ƿ�֧��UPA */
} AT_NV_WCDMA_RRC_CONVERT_TBL_STRU;


typedef TAF_UINT8 AT_CPMS_MEM_TYPE;
#define AT_CPMS_MEM_SM_TYPE            0
#define AT_CPMS_MEM_ME_TYPE             1

typedef TAF_UINT8 AT_CLCK_TYPE;
#define AT_CLCK_P2_TYPE            0
#define AT_CLCK_SC_TYPE            1
#define AT_CLCK_AO_TYPE            2
#define AT_CLCK_OI_TYPE            3
#define AT_CLCK_OX_TYPE            4
#define AT_CLCK_AI_TYPE            5
#define AT_CLCK_IR_TYPE            6
#define AT_CLCK_AB_TYPE            7
#define AT_CLCK_AG_TYPE            8
#define AT_CLCK_AC_TYPE            9
#define AT_CLCK_PS_TYPE            10
#define AT_CLCK_FD_TYPE            11
/* Added by w00316404 for M project A characeristic AT part, 2015-4-7, Begin */
#define AT_CLCK_PN_TYPE            12
#define AT_CLCK_PU_TYPE            13
#define AT_CLCK_PP_TYPE            14
/* Added by w00316404 for M project A characeristic AT part, 2015-4-7, End */

typedef TAF_UINT8 AT_CMLCK_TYPE;
#define AT_CMLCK_PS_TYPE            0
typedef TAF_UINT8 AT_SAT_ENVELOPE_TYPE;
#define AT_SAT_ENVELOPE_MENU        0xD3
#define AT_SAT_ENVELOPE_CALL        0xD4
#define AT_SAT_ENVELOPE_EVENT       0xD6
#define AT_SAT_ENVELOPE_TIMER       0xD7

/* NV��en_NV_Resume_Flag����Чֵ:0��1 */
#define AT_NV_RESUME_SUCC               (0)
#define AT_NV_RESUME_FAIL               (1)


/*DIALMODE*/
#define AT_DIALMODE_MODEM      (0)
#define AT_DIALMODE_NDIS       (1)
#define AT_DIALMODE_DUAL       (2)
#define AT_DIALMODE_ABNORMAL   (3)

/*�������ͣ�����ģʽΪ0�� ǿ������Ϊ1*/
#define AT_NOM_LOAD      (0)
#define AT_FORC_LOAD     (1)

#define AT_NV_RESTORE_SUCCESS                   0
#define AT_NV_RESTORE_FAIL                      1

#define AT_NV_RESTORE_RESULT_INIT  0x5A5A5A5A
#define AT_NV_RESTORE_RUNNING      0x5A5A55AA


#define AT_SIMLOCK_MAX_ERROR_TIMES  (3)  /* Simlock�������ʧ�ܴ��� */

#define TAF_SW_VER_INFO_LEN         (31)
#define TAF_ISO_VER_INFO_LEN        (50)
#define TAF_PRODUCT_NAME_LEN        (50)
#define TAF_WEBUI_VER_LEN           (127)
#define TAF_FLASH_INFO_LEN          (100)
#define TAF_NET_MODE_LEN            (10)

/*WIFI��ģʽ*/
#define AT_WIFI_START_NORMAL         (0)
#define AT_WIFI_START_TEST           (1)
/*WIFI ��ģʽ*/
#define AT_WIFI_SUPPORT_MODE_CW      (0)
#define AT_WIFI_SUPPORT_MODE_A       (1)
#define AT_WIFI_SUPPORT_MODE_B       (2)
#define AT_WIFI_SUPPORT_MODE_G       (3)
#define AT_WIFI_SUPPORT_MODE_N       (4)

/*WIFI����*/
#define AT_WIFI_BAND_20M             (0)
#define AT_WIFI_BAND_40M             (1)

/*WIFI��������ջ�ģʽ*/
#define AT_WIFI_TX_MODE              (17)
#define AT_WIFI_RX_MODE              (18)

/*WIFI�����״̬*/
#define AT_WIFI_TX_ON                 (1)
#define AT_WIFI_TX_OFF                (0)

/*WIFI���ջ�״̬*/
#define AT_WIFI_RX_ON                 (1)
#define AT_WIFI_RX_OFF                (0)

/*WIFI���ʵ�������*/
#define AT_WIFI_POWER_MIN             (-15)
#define AT_WIFI_POWER_MAX             (30)

#define AT_FEATURE_EXIST              (1)
#define AT_FEATURE_MAX                (15)

/* AP-Modem �У�Ŀǰ���֧�����3��HSIC ATͨ�� */
#define AT_HSIC_AT_CHANNEL_INDEX_ONE    (0)
#define AT_HSIC_AT_CHANNEL_INDEX_TWO    (1)
#define AT_HSIC_AT_CHANNEL_INDEX_THREE  (2)
#define AT_HSIC_AT_CHANNEL_INDEX_FOUR   (3)

#define AT_HSIC_AT_CHANNEL_MAX          (4)

/* ��RILʹ�õ�ATͨ������ */
#define AT_HSIC_AT_FOR_RIL_MAX          (2)

#if (FEATURE_ON == FEATURE_VCOM_EXT)
/* APPVCOM ��� 5 ���˿�Ϊ��AT ��*/
#define AT_VCOM_AT_CHANNEL_MAX          (APP_VCOM_DEV_INDEX_BUTT - 5)
#else
#define AT_VCOM_AT_CHANNEL_MAX          (APP_VCOM_DEV_INDEX_BUTT)
#endif

#define AT_SIMLOCKUNLOCK_PWD_PARA_LEN   (16)

enum AT_CUUSI_MSG_TYPE_ENUM
{
    AT_CUUSI_MSG_ANY,
    AT_CUUSI_MSG_ALERT,
    AT_CUUSI_MSG_PROGRESS,
    AT_CUUSI_MSG_CONNECT,
    AT_CUUSI_MSG_RELEASE,
    AT_CUUSI_MSG_BUTT
};
typedef VOS_UINT32 AT_CUUSI_MSG_TYPE_ENUM_U32;

enum AT_CUUSU_MSG_TYPE_ENUM
{
    AT_CUUSU_MSG_ANY,
    AT_CUUSU_MSG_SETUP,
    AT_CUUSU_MSG_DISCONNECT,
    AT_CUUSU_MSG_RELEASE_COMPLETE,
    AT_CUUSU_MSG_BUTT
};
typedef VOS_UINT32 AT_CUUSU_MSG_TYPE_ENUM_U32;

typedef struct
{
    MN_CALL_UUS1_MSG_TYPE_ENUM_U32      enCallMsgType;
    AT_CUUSU_MSG_TYPE_ENUM_U32          enCuusuMsgType;
}AT_CALL_CUUSU_MSG_STRU;

typedef struct
{
    MN_CALL_UUS1_MSG_TYPE_ENUM_U32      enCallMsgType;
    AT_CUUSI_MSG_TYPE_ENUM_U32          enCuusiMsgType;
}AT_CALL_CUUSI_MSG_STRU;

typedef TAF_UINT32 (*pAtSetParaFunc)(TAF_UINT8 ucIndex);
typedef TAF_UINT32 (*pAtQueryParaFunc)(TAF_UINT8 ucIndex);

typedef TAF_UINT32 (*pAtAppCBF)(TAF_UINT8 ucIndex,TAF_UINT8 ucType,TAF_UINT8* pData,TAF_UINT16 usLen);


/* DIAG���Ƿ�򿪵�ö�ٽṹ  */
enum  AT_DIAG_OPEN_FLAG_ENUM
{
    AT_DIAG_OPEN_FLAG_OPEN,             /* 0 Ϊ�� */
    AT_DIAG_OPEN_FLAG_CLOSE,            /* 1 Ϊ�ر� */
    AT_DIAG_OPEN_FLAG_BUTT
};
typedef  VOS_UINT32  AT_DIAG_OPEN_FLAG_ENUM_U32;

#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
/*  SHELL���Ƿ�򿪵�ö�ٽṹ  */
enum  AT_SHELL_OPEN_FLAG_ENUM
{
    AT_SHELL_OPEN_FLAG_WIFI,
    AT_SHELL_OPEN_FLAG_CLOSE,
    AT_SHELL_OPEN_FLAG_OPEN,
    AT_SHELL_OPEN_FLAG_BUTT
};
typedef  VOS_UINT32  AT_SHELL_OPEN_FLAG_ENUM_U32;
#endif

/* ������NV�е�Ȩ������Ľṹ */
#define AT_DISLOG_PWD_LEN               (16)                /*  DISLOG����Ȩ�޵����볤��  */

#define AT_SETZ_LEN                     (16)


/* 0 ʹ��SD��; 1 ��ֹSD�� */
enum AT_SD_ENABLE_FLAG_ENUM
{
    AT_SD_ENABLE_FLAG_ENABLE,
    AT_SD_ENABLE_FLAG_DISABLE,
    AT_SD_ENABLE_FLAG_BUTT
};

/* Added by w00316404 for M project A characeristic AT part, 2015-4-7, Begin */
enum  AT_CLCK_MODE_ENUM
{
    AT_CLCK_MODE_UNLOCK,                /* 0 ȥ���� */
    AT_CLCK_MODE_LOCK,                  /* 1 ���� */
    AT_CLCK_MODE_QUERY_STATUS,          /* 2 ��ѯ */
    AT_CLCK_MODE_BUTT
};
typedef  VOS_UINT32  AT_CLCK_MODE_ENUM_U32;
/* Added by w00316404 for M project A characeristic AT part, 2015-4-7, End */




/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/
/*ģ���������士HEADER */

/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
/* A CONVERSION_TABLE is an array mapping 7 or 8 bit values to 16 bit values. */
typedef struct
{
    VOS_UINT8                           ucOctet;
    VOS_UINT8                           ucReserve;
    VOS_UINT16                          usUnicode;
}AT_PB_CONVERSION_TABLE_STRU;

/* AT��һ�����ƽṹ�����ڼ�¼��ǰʹ���ĸ�DSP����ǰ��TMODEֵ*/
typedef struct
{
    VOS_BOOL                            bDspLoadFlag;
    TAF_UINT8                           ucIndex;          /*AT���������Indexֵ*/
    TAF_PH_TMODE_ENUM_UINT8             ucCurrentTMode;
    AT_DEVICE_CMD_RAT_MODE_ENUM_UINT8   ucDeviceRatMode;
    AT_DEVICE_CMD_BAND_ENUM_UINT8       ucDeviceAtBand;
    AT_DSP_BAND_ARFCN_STRU              stDspBandArfcn;
    /*AT^FDAC���õ�FDACֵ��AT^FWAVE���õ�powerֵ��ʾ�ĺ�����ͬ��ȡ�����õ�ֵ*/
    VOS_BOOL                            bFdacFlag;       /* FDAC�Ƿ���Ч*/
    VOS_UINT16                          usFDAC;          /* ��ӦW��AGC,G��TxVpa*/
    VOS_UINT16                          usRxDiv;         /* �ּ�����*/
    VOS_UINT16                          usRxPri;         /* ��������*/
    VOS_UINT16                          usOrigBand;      /* ��¼��ʽת�����������ּ�����*/
    AT_DSP_RF_ON_OFF_ENUM_UINT8         ucRxOnOff;       /* Rx on offֵ*/
    VOS_UINT8                           ucPaLevel;       /* �������PA�ȼ�*/
    VOS_UINT8                           ucLnaLevel;      /* ���ջ�LNA�ȼ�*/
    VOS_UINT8                           ucPriOrDiv;      /* ��ǰ���������û��Ƿּ�����*/
    AT_DSP_RF_ON_OFF_ENUM_UINT8         ucTxOnOff;       /* Tx On offֵ*/
    VOS_UINT8                           ucRxonOrTxon;    /* ��¼���һ��ִ�е��Ǵ򿪽��ջ�(RXON=1)�������Ǵ򿪷����(TXON=1)����*/




    VOS_UINT8                           aucReserved[2];
    VOS_BOOL                            bPowerFlag;      /* Power�Ƿ���Ч*/
    VOS_UINT16                          usPower;         /* AT^FWAVE���õĹ���ֵ*/
    VOS_UINT16                          usTxMode;        /* AT^FWAVE���õ�<type>ֵת��Ϊ���͸��������ֵ(�ñ���ֻ��G������ʹ��):
                                                                   <type>Ϊ0�������������Σ�usTxMode��Ϊ1��<type>Ϊ����ֵ��usTxMode��Ϊ0 */
}AT_DEVICE_CMD_CTRL_STRU;


typedef struct
{
    MN_MSG_ASCII_ADDR_STRU              stAsciiAddr;                            /*<oa/da>[,<tooa/toda>*/
    TAF_UINT8                           aucBuffer[AT_SMS_SEG_MAX_LENGTH];       /*��ʼ��SMSC�ĵ�ַ��֮����TPDU*/
    TAF_BOOL                            bWaitForNvStorageStatus;
    TAF_BOOL                            bWaitForUsimStorageStatus;
    TAF_BOOL                            bWaitForCpmsSetRsp;
    TAF_UINT8                           ucCnmaType;                             /*��¼+CNMA[=<n>�е�<n>*/
    TAF_UINT8                           ucPduLen;                               /*TPDU���ֽ�����������SMSC��ַ���ֽ���*/
    MN_MSG_COMMAND_TYPE_ENUM_U8         CommandType;
    TAF_UINT8                           ucMessageNumber;                        /*[1,3]���߾��Ա��*/
    TAF_UINT8                           ucMessageNumberType;                    /*������ͣ����Ի������*/
    MN_MSG_STATUS_TYPE_ENUM_U8          SmState;
    MN_MSG_MEM_STORE_ENUM_U8            enSmMemStore;
    TAF_UINT8                           ucMsgDeleteTypes;
    TAF_UINT8                           ucMsgSentSmNum;
    TAF_UINT8                           ucFo;
    MN_MSG_TP_PID_TYPE_ENUM_U8          enPid;                                  /*TP-PID*/
    VOS_UINT8                           aucReserved[1];
}AT_SMS_STRU;

typedef struct
{
    MN_CALL_CUG_CFG_STRU        CugMode;
    MN_CALL_CLIR_CFG_ENUM_U8    ClirInfo;
    MN_CALL_TYPE_ENUM_U8        CallType;
    MN_CALL_ID_T                CallId;
    VOS_UINT8                   aucReserved[5];
}AT_CALL_INFO_STRU;


typedef struct
{
    MN_CLIENT_ID_T          usClientId;                                         /* ָʾ��ǰ�û��� */
    MN_OPERATION_ID_T       opId;                                               /* Operation ID, ��ʶ���β��� */
    TAF_UINT8               ucUsed;                                             /* ָʾ��ǰ�����Ƿ��ѱ�ʹ�� */

    AT_USER_TYPE            UserType;                                           /* ָʾ��ǰ�û����� */
    TAF_UINT8               ucPortType;                                         /* ָʾ��ǰ�˿����� */
    AT_PORT_NO              ucPortNo;                                           /* ָʾ��ǰUSB COM���ں� */
    TAF_UINT8               ucDlci;                                             /* ָʾ��ǰ��·�� */
    AT_MODE_TYPE            Mode;                                               /* ָʾ��ǰ����ģʽ��ֻ���MUX��APP */
    AT_DATA_MODE_TYPE       DataMode;                                           /* ָʾ��ǰ����ģʽ��ֻ���MUX��APP */
    TAF_UINT8               ModemStatus;                                        /* Modem ״̬ */
    AT_IND_MODE_TYPE        IndMode;                                            /* ָʾ��ǰ����ģʽ��ֻ���MUX��APP */
    AT_DATA_STATE_TYPE      DataState;                                          /* ָʾ��ǰ����ģʽ��ֻ���MUX��APP */

    TAF_UINT8               ucCsRabId;
    TAF_UINT8               ucPsRabId;
    TAF_UINT8               ucCid;

    AT_CMD_CURRENT_OPT_ENUM CmdCurrentOpt;                                      /* ָʾ��ǰ�û�������������� */

    TAF_UINT32              ulCause;                                            /* ָʾ��ǰCauseֵ */

    pAtAppCBF               pAppCallBack;

    AT_CALL_INFO_STRU       AtCallInfo;

    TAF_UINT16              usPppId;

    TAF_UINT16              usSmsTxtLen;                                        /* ָʾ��ǰ�����ı����� */
    TAF_UINT16              usAsyRtnNum;                                        /* ָʾ��ǰ����������� */

    VOS_UINT8               aucReserved[2];

    HTIMER                  hTimer;                                             /* ��Ӧ�Ķ�ʱ�� */
    TAF_UINT32              ulTemp;

    AT_CMD_INDEX_ENUM       CmdIndex;                                           /* ָʾ��ǰ�û����������� */

    AT_SMS_STRU             AtSmsData;
} AT_CLIENT_MANAGE_STRU;


typedef struct
{
    TAF_UINT8   aucBuffer[AT_CMD_MAX_LEN + 20];    /* �������ý������Ĳ����ַ��� */
    TAF_UINT16  usBufLen;                      /* ������ʶ�����ַ������� */
}AT_SEND_DATA_BUFFER_STRU;

typedef struct
{
    AT_RRETURN_CODE_ENUM_UINT32 ucIndex;
    TAF_UINT8  *Result[2];
}AT_RETURN_TAB_TYPE_STRU;

typedef struct
{
    AT_CPMS_MEM_TYPE ReadMem1;
    AT_CPMS_MEM_TYPE DeleteMem2;
    AT_CPMS_MEM_TYPE WriteMem3;
    AT_CPMS_MEM_TYPE SendMem4;
}AT_CPMS_TYPE_STRU;

typedef struct
{
    AT_STRING_CONTENT_ENUM   StrType;
    TAF_UINT8 *pucText;
}AT_STRING_TYPE_STRU;

typedef TAF_INT (*USB_SERIAL_SEND_DATA)
(
    TAF_UINT8 *pData,               /*����ָ��*/
    TAF_UINT16 usLen                /*���ݳ���*/
);

#define AT_MSG_BUFFER_USED                                  1
#define AT_MSG_BUFFER_FREE                                  0

typedef struct
{
    TAF_UINT8                           ucIndex;
    TAF_UINT8                           aucReserve1[5];
    TAF_UINT16                          usDataLen;
    TAF_UINT8                           *pData;
}AT_PS_MODEM_DATA_IND_STRU;


/*Taf_DefCsAutoAnswerInfo�����Ĳ�������*/
typedef TAF_UINT32 TAF_CS_AUTO_ANSWER_INFO; /* ����CS���Զ�Ӧ��ʱ�䣬��λΪ�룬
                                               �����0����ʾ��֧���Զ�Ӧ�� */


typedef struct
{
    TAF_UINT16  usUsed;                                       /*��ʹ�ü�¼�� */
    TAF_UINT16  usTotal;                                      /* ����¼�� */
    TAF_UINT16  usNameMaxLen;                                 /* ������󳤶� */
    TAF_UINT16  usNumMaxLen;                                  /* ������󳤶� */
    TAF_UINT16  usAnrNumLen;                                  /*  ANR������󳤶� */
    TAF_UINT16  usEmailLen;                                   /*  Email��󳤶� */
}AT_PB_INFO_STRU;


typedef MN_CALL_NUM_TYPE_ENUM_U8 AT_CSTA_NUM_TYPE_ENUM_U8;

/* USB�豸��̬NV��Ľṹ�� */
typedef struct
{
    TAF_UINT32  ulStatus;     /* 1: NV��Ч��־λ��0����Ч */
    TAF_UINT32  ulValue;      /* �豸��̬index */
    TAF_UINT32  ulReserve1;   /* ���� */
    TAF_UINT32  ulReserve2;   /* ���� */
}AT_USB_ENUM_STATUS_STRU;

/*****************************************************************************
 �ṹ��    : AT_WIFI_SSID_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : en_NV_Item_WIFI_KEY NV���Ӧ�Ľṹ��
             ���ڱ���wifi ��ȫ��Ϣ
*****************************************************************************/
typedef struct
{

    VOS_UINT8    aucWifiSsid[AT_WIFI_SSID_LEN_MAX];
    VOS_UINT8    aucReserved[83];
}AT_WIFI_SSID_STRU;


typedef struct
{
    VOS_UINT8    aucWifiAuthmode[16];
    VOS_UINT8    aucWifiBasicencryptionmodes[5];
    VOS_UINT8    aucWifiWpaencryptionmodes[5];
    VOS_UINT8    aucWifiWepKey1[27];
    VOS_UINT8    aucWifiWepKey2[27];
    VOS_UINT8    aucWifiWepKey3[27];
    VOS_UINT8    aucWifiWepKey4[27];
    VOS_UINT8    aucWifiWepKeyIndex[4];
    VOS_UINT8    aucWifiWpapsk[65];
    VOS_UINT8    ucWifiWpsenbl;
    VOS_UINT8    ucWifiWpscfg;
    VOS_UINT8    ucreserve;
}AT_WIFI_SEC_STRU;


typedef struct
{
    VOS_UINT32      bitOpbSupport       : 1;
    VOS_UINT32      bitOpgSupport       : 1;
    VOS_UINT32      bitOpnSupport       : 1;
    VOS_UINT32      bitOpSpare          : 29;

    VOS_UINT8       usbHighChannel;                                             /* 802.11b��ʽ����ŵ��� */
    VOS_UINT8       usbLowChannel;                                              /* 802.11b��ʽ��С�ŵ��� */
    VOS_UINT8       aucRsv1[2];
    VOS_UINT16      ausbPower[2];                                               /* 802.11b��ʽ���������� */

    VOS_UINT8       usgHighChannel;                                             /* 802.11g��ʽ����ŵ��� */
    VOS_UINT8       usgLowChannel;                                              /* 802.11g��ʽ��С�ŵ��� */
    VOS_UINT8       aucRsv2[2];
    VOS_UINT16      ausgPower[2];                                               /* 802.11g��ʽ���������� */

    VOS_UINT8       usnHighChannel;                                             /* 802.11n��ʽ����ŵ��� */
    VOS_UINT8       usnLowChannel;                                              /* 802.11n��ʽ��С�ŵ��� */
    VOS_UINT8       aucRsv3[2];
    VOS_UINT16      ausnPower[2];                                               /* 802.11n��ʽ���������� */
}AT_WIFI_INFO_STRU;


/* �豸��̬�ĸ���:A1,A2,A,B,D,E,1,2,3,4,5,6,16 */
#define AT_SETPORT_DEV_LEN              (21)

/* �豸��̬��Ӧ������ */
#define AT_SETPORT_DEV_MAP_LEN          (AT_SETPORT_DEV_LEN + 1)

/* �豸��̬���17����� */
#define AT_SETPORT_PARA_MAX_LEN 17

/* �豸��̬��ϲ�������ַ��������17���豸��̬�����2���ַ���16������ */
#define AT_SETPORT_PARA_MAX_CHAR_LEN ((17*2) + 16)


typedef enum tagAT_DEV__PID_UNIFY_IF_PROT
{
    AT_DEV_VOID             = 0x00,
    AT_DEV_MODEM            = 0x01,
    AT_DEV_PCUI             = 0x02,
    AT_DEV_DIAG             = 0x03,
    AT_DEV_PCSC             = 0x04,
    AT_DEV_GPS              = 0x05,
    AT_DEV_GPS_CONTROL      = 0x06,
    AT_DEV_NDIS             = 0x07,
    AT_DEV_NDISDATA         = 0x08,
    AT_DEV_NDISCTRL         = 0x09,
    AT_DEV_BLUE_TOOTH       = 0x0A,
    AT_DEV_FINGER_PRINT     = 0x0B,
    AT_DEV_ACMCTRL          = 0x0C,
    AT_DEV_MMS              = 0x0D,
    AT_DEV_PC_VOICE         = 0x0E,
    AT_DEV_DVB              = 0x0F,
    AT_DEV_4G_MODEM         = 0x10,
    AT_DEV_4G_NDIS          = 0x11,
    AT_DEV_4G_PCUI          = 0x12,
    AT_DEV_4G_DIAG          = 0x13,
    AT_DEV_4G_GPS           = 0x14,
    AT_DEV_4G_PCVOICE       = 0x15,
    AT_DEV_NCM              = 0x16,
    AT_DEV_LTE_DIAG         = 0x17,
    AT_DEV_CDROM            = 0xA1,
    AT_DEV_SD               = 0xA2,
    AT_DEV_RNDIS            = 0xA3,
    AT_DEV_NONE             = 0xFF
} AT_DEV_PID_UNIFY_IF_PROT;
/* PORT */
typedef struct
{
    VOS_UINT8   aucAtSetPara[3];
    VOS_UINT8   ucDrvPara;
    VOS_UINT8   aucAtDispPara[15];
}AT_SET_PORT_PARA_MAP_STRU;

typedef struct
{
    VOS_UINT32  ulPidEnabled;
}AT_PID_ENABLE_TYPE_STRU;

/* AT����������������ݽṹ */

/* ���������ع��Ķ���(����Ŀǰ�������������Ĺ��) */
#define AT_COMBINE_MAX_SEMICOLON    40   /* һ��AT���������֧��40���ֺ�(refer to Q) */
#define AT_COMBINE_MAX_COMBINE_CMD  40   /* һ��AT�������ɷֽ�Ϊ40���������(refer to Q) */
#define AT_COMBINE_MAX_LEN          545  /* һ���������������545���ֽ�(refer to Q) */
#define AT_COMBINE_MAX_SUB_CMD      40   /* һ������������ɷֽ�Ϊ40������AT����(refer to Q) */
#define AT_INDEPENDENT_CMD_MAX_LEN  545  /* һ��������������ֽ�Ķ���AT�����Ϊ545���ֽ�(refer to Q) */

/* ����AT��������е�';'����ʹ�õĽṹ�� */
typedef struct
{
    VOS_UINT32  ulCount;                                    /* AT���������';'�ų��ֵĴ��� */
    VOS_UINT16  ausSCPosition[AT_COMBINE_MAX_SEMICOLON];    /* AT���������';'�ų��ֵ�λ��(��������) */
}AT_COMBINE_CMD_SEMICOLON_PARSE_STRU;



typedef struct
{
    VOS_UINT32  ulCount;                                    /* AT�������ֺ����ָ������������� */
    struct
    {
        VOS_UINT32  ulLen;
        VOS_UINT8   aucCombineCmd[AT_COMBINE_MAX_LEN];
        VOS_UINT8   aucReserved[3];
    }stCombineCmd[AT_COMBINE_MAX_COMBINE_CMD];
}AT_COMBINE_CMD_SPLIT_STRU;   /* ���ݷֺŽ���AT�����ķָ�����AT�����ָ�Ϊ���ɸ����AT���� */


typedef struct
{
    VOS_UINT32      ulTotalCnt;                             /* ����AT����ĸ��� */
    VOS_UINT32      ulProcCnt;                              /* �Ѿ�������ϵĶ���AT������� */
    struct
    {
        VOS_UINT32  ulLen;
        VOS_UINT8   aucATCmd[AT_INDEPENDENT_CMD_MAX_LEN];
        VOS_UINT8   aucReserved[3];                         /*���ֽڶ���*/
    }stATCmd[AT_COMBINE_MAX_SUB_CMD];
}AT_COMBINE_CMD_PARSE_RSLT_STRU;    /* ���AT���������� */


typedef struct
{
    TAF_UINT32          ulBuffLen;                     /* ���������ĳ��� */
    TAF_UINT8           aucDataBuff[AT_COM_BUFF_LEN];  /* �������� */
}AT_DATA_STREAM_BUFFER_STRU;           /* AT��������ṹ�� */

/* begin V7R1 PhaseI Modify */
typedef struct
{
    MN_PH_SYS_MODE_EX_ENUM_U8           enSysMode;
    VOS_CHAR                           *pcStrSysModeName ;
}AT_PH_SYS_MODE_TBL_STRU;

typedef struct
{
    MN_PH_SUB_SYS_MODE_EX_ENUM_U8       enSubSysMode;
    VOS_CHAR                           *pcStrSubSysModeName ;
}AT_PH_SUB_SYS_MODE_TBL_STRU;

/* end V7R1 PhaseI Modify */

enum AT_RRC_VERSION_ENUM
{
    AT_RRC_VERSION_WCDMA                = 0,
    AT_RRC_VERSION_DPA                  = 1,
    AT_RRC_VERSION_DPA_AND_UPA          = 2,
    AT_RRC_VERSION_HSPA_PLUNS           = 6,
    AT_RRC_VERSION_BUTT
};
typedef VOS_UINT8 AT_RRC_VERSION_ENUM_UINT8;


enum AT_PTL_VER_TYPE_ENUM
{
    AT_PTL_VER_ENUM_R3,
    AT_PTL_VER_ENUM_R4,
    AT_PTL_VER_ENUM_R5,
    AT_PTL_VER_ENUM_R6,
    AT_PTL_VER_ENUM_R7,
    AT_PTL_VER_ENUM_R8,
    AT_PTL_VER_ENUM_R9,
    AT_PTL_VER_ENUM_BUTT
};
typedef VOS_UINT8 AT_PTL_VER_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : AT_DPACAT_CATEGORY_TYPE_ENUM
 �ṹ˵��  : DPACAT�������HSDPA���ʵȼ�
                           0: ֧�����ʵȼ�3.6M
                           1: ֧�����ʵȼ�7.2M
                           2: ֧�����ʵȼ�1.8M
                           3: ֧�����ʵȼ�14.4M
                           4: ֧�����ʵȼ�21M
*****************************************************************************/
enum AT_DPACAT_CATEGORY_TYPE_ENUM
{
    AT_DPACAT_CATEGORY_TYPE_3600K                 = 0,
    AT_DPACAT_CATEGORY_TYPE_7200K                 = 1,
    AT_DPACAT_CATEGORY_TYPE_1800K                 = 2,
    AT_DPACAT_CATEGORY_TYPE_14400K               = 3,
    AT_DPACAT_CATEGORY_TYPE_21000K               = 4,
    AT_DPACAT_CATEGORY_TYPE_BUTT
};
typedef VOS_UINT32 AT_DPACAT_CATEGORY_TYPE_ENUM_U32;


typedef struct
{
    PS_BOOL_ENUM_UINT8                  enHSDSCHSupport;                        /* �Ƿ�֧��enHSDSCHSupport�ı�־                */
    VOS_UINT8                           ucHSDSCHPhyCategory;                    /* R6�汾֧��HS-DSCH����������ͱ�־                  */
    PS_BOOL_ENUM_UINT8                  enMacEhsSupport;                        /* �Ƿ�֧����ǿ��HSDPA�ı�־                */
    VOS_UINT8                           ucHSDSCHPhyCategoryExt;                 /* R6�汾�����ϰ汾֧��HS-DSCH����������ͱ�־    */
    PS_BOOL_ENUM_UINT8                  enMultiCellSupport;                     /* �Ƿ�֧�� Multi cell support,���֧��MultiCell,Ex2���� */

}AT_DPACAT_PARA_STRU;

typedef struct
{
    VOS_UINT32                          ulHspaStatus;                           /* 0��ʾδ����,��ôDPA��UPA��֧��;1��ʾ���� */

    VOS_UINT8                           aucRsv1[4];                             /* RF ������Ϣ                                  */

    PS_BOOL_ENUM_UINT8                  enSupportPwrBoosting;                   /* 16QAM������أ��Ƿ�֧��E-DPCCH Power Boosting*/
    PS_BOOL_ENUM_UINT8                  enSf4Support;                           /* �Ƿ�֧��ul dpcch ʹ�� slotFormat4 */

    VOS_UINT8                           aucRsv2[1];                             /* ENUMERATED  OPTIONAL                         */
    AT_PTL_VER_TYPE_ENUM_UINT8          enAsRelIndicator;                       /* Access Stratum Release Indicator             */

    PS_BOOL_ENUM_UINT8                  enHSDSCHSupport;                        /* �Ƿ�֧��enHSDSCHSupport�ı�־                */
    VOS_UINT8                           ucHSDSCHPhyCategory;                    /* ֧��HS-DSCH����������ͱ�־                  */

    PS_BOOL_ENUM_UINT8                  enMacEhsSupport;
    VOS_UINT8                           ucHSDSCHPhyCategoryExt;
    PS_BOOL_ENUM_UINT8                  enMultiCellSupport;                     /* �Ƿ�֧�� Multi cell support,���֧��MultiCell,Ex2���� */
    VOS_UINT8                           ucHSDSCHPhyCategoryExt2;                /* HS-DSCH physical layer category extension 2 */

    PS_BOOL_ENUM_UINT8                  enCellSpecTxDiversityForDc;             /*  This IE is optionally present if Dual-Cell HSDPA is supported. Otherwise it is not needed.
                                                                                    The IE is not needed in the INTER RAT HANDOVER INFO message. Otherwise, it is optional*/
    VOS_UINT8                           aucRsv3[1];                             /* �����Ժ���չHS-DSCH physical layer category extension 3 */

    PS_BOOL_ENUM_UINT8                  enEDCHSupport;                          /* �Ƿ�֧��EDCH�ı�־                           */
    VOS_UINT8                           ucEDCHPhyCategory;                      /* ֧��UPA�ĵȼ�                                */
    PS_BOOL_ENUM_UINT8                  enSuppUl16QAM;                          /* �Ƿ�֧������16QAM����֧��ʱucEDCHPhyCategoryExt����Ч */
    VOS_UINT8                           ucEDCHPhyCategoryExt;                   /* ���е��ز�֧��16QAMʱ����д7 */
    PS_BOOL_ENUM_UINT8                  enSuppEDpdchInterpolationFormula;       /* 16QAM������أ��Ƿ�֧��E-DPDCH power interpolation formula */
    PS_BOOL_ENUM_UINT8                  enSuppHsdpaInFach;                      /* ֧��CELL_FACH��HS-DSCH�Ľ��� */
    PS_BOOL_ENUM_UINT8                  enSuppHsdpaInPch;                       /* ֧��CELL_PCH��URA_PCH��HS-DSCH�Ľ��� */

    PS_BOOL_ENUM_UINT8                  enMacIsSupport;                         /* �Ƿ�֧��MAC_I/MAC_Is */

    PS_BOOL_ENUM_UINT8                  enFDPCHSupport;                         /* �Ƿ�֧��FDPCH�ı�־                          */

    PS_BOOL_ENUM_UINT8                  enHsscchLessSupport;                    /* �Ƿ�֧�� hsscchlessHsdschOperation           */
    PS_BOOL_ENUM_UINT8                  enUlDpcchDtxSupport;                    /* �Ƿ�֧�� discontinuousDpcchTransmission      */

    PS_BOOL_ENUM_UINT8                  enAdjFreqMeasWithoutCmprMode;           /* �Ƿ�֧�� Adjacent Frequency measurements without compressed mode */

    PS_BOOL_ENUM_UINT8                  enMimoSingleStreamStrict;               /* �Ƿ�����ֻ��ʹ�õ���MIMO */
    PS_BOOL_ENUM_UINT8                  enMimoWithDlTxDiversity;                /* R9���ԣ���MIMO����ʱ�����п����ŵ��Ƿ�����ʹ�÷ּ� */

    /* V7r1 ˫ģ����NV�� LTE���� */
    PS_BOOL_ENUM_UINT8                  enSptAbsPriBasedReselInUtra;            /* ֧��UTRA�е����ȼ���ѡ��Ĭ��Ϊ0��1Ϊ֧�֣�0Ϊ��֧�� */

    VOS_UINT8                           ucHSDSCHPhyCategoryExt3;                /* HS-DSCH physical layer category extension 3 */
    PS_BOOL_ENUM_UINT8                  enDcMimoSupport;                        /* �Ƿ�֧��DC+MIMO */
    PS_BOOL_ENUM_UINT8                  enSuppCommEDCH;                         /* E-RACH�������� */

    PS_BOOL_ENUM_UINT8                  enDcUpaSupport;                         /* �Ƿ�֧��DC UPA�ı�־ */
    VOS_UINT8                           ucEDCHPhyCategoryExt2;                  /* EDCH  category extension 2*/
    PS_BOOL_ENUM_UINT8                  enEdpdchGainFactorFlg;                  /* E-DPDCH���ʻ�������ʹ�ܱ�־λ */
    VOS_UINT8                           aucRsv4[7];
}AT_NVIM_UE_CAPA_STRU;
enum AT_NVWR_SEC_TYPE_ENUM
{
    AT_NVWR_SEC_TYPE_OFF = 0,                                                   /* ��ȫ���ƹر� */
    AT_NVWR_SEC_TYPE_ON,                                                        /* ��ȫ���ƿ��� */
    AT_NVWR_SEC_TYPE_BLACKLIST,                                                 /* ��ȫ���ƺ�����ģʽ */
    AT_NVWR_SEC_TYPE_BUTT
};
typedef VOS_UINT8 AT_NVWR_SEC_TYPE_ENUM_UINT8;
enum AT_SYSCFGEX_RAT_TYPE_ENUM
{
    AT_SYSCFGEX_RAT_AUTO = 0,              /* ���뼼��Ϊ�Զ�ģʽ */
    AT_SYSCFGEX_RAT_GSM,                   /* GSM���뼼�� */
    AT_SYSCFGEX_RAT_WCDMA,                 /* WCDMA���뼼�� */
    AT_SYSCFGEX_RAT_LTE,                   /* LTE���뼼�� */
    /* Modified by l00301449 for CDMA 1X Iteration 13, 2015-04-17, begin */
    AT_SYSCFGEX_RAT_1X,                    /* 1X���뼼�� */
    AT_SYSCFGEX_RAT_DO   = 7,              /* DO���뼼�� */
    /* Modified by l00301449 for CDMA 1X Iteration 13, 2015-04-17, end */
    AT_SYSCFGEX_RAT_NO_CHANGE = 99,        /* ���뼼���ޱ仯 */
    AT_SYSCFGEX_RAT_BUTT
};
typedef VOS_UINT8 AT_SYSCFGEX_RAT_TYPE_ENUM_UINT8;
typedef struct
{
    VOS_UINT8                           ucRatOrderNum;                          /* syscfgex�����õ�acqoder�е�ָʾ���뼼���ĸ��� */
    AT_SYSCFGEX_RAT_TYPE_ENUM_UINT8     aenRatOrder[TAF_PH_MAX_GUL_RAT_NUM];    /* at^syscfgex�����õ�acqoder�������ȼ� */
}AT_SYSCFGEX_RAT_ORDER_STRU;


enum AT_SYSCFG_RAT_TYPE_ENUM
{
    AT_SYSCFG_RAT_AUTO          = 2,                                                /* ���뼼��Ϊ�Զ�ģʽ */
    AT_SYSCFG_RAT_1X            = 3,                                                /* 1X ģʽ */
    AT_SYSCFG_RAT_HRPD          = 4,                                                /* HRDP ģʽ */
    AT_SYSCFG_RAT_1X_AND_HRPD   = 8,                                                /* 1X&HRPD ģʽ */
    AT_SYSCFG_RAT_GSM           = 13,                                               /* GGSM���뼼�� */
    AT_SYSCFG_RAT_WCDMA         = 14,                                               /* WCDMA���뼼�� */
    AT_SYSCFG_RAT_NO_CHANGE     = 16,                                               /* ���뼼���ޱ仯 */
    AT_SYSCFG_RAT_BUTT
};
typedef VOS_UINT8 AT_SYSCFG_RAT_TYPE_ENUM_UINT8;
enum AT_SYSCFG_RAT_PRIO_ENUM
{
    AT_SYSCFG_RAT_PRIO_AUTO = 0,                                                /* �������ȼ�����Ϊ�Զ� */
    AT_SYSCFG_RAT_PRIO_GSM,                                                     /* �������ȼ�����ΪGSM����  */
    AT_SYSCFG_RAT_PRIO_WCDMA,                                                   /* �������ȼ�����ΪWCDMA���� */
    AT_SYSCFG_RAT_PRIO_NO_CHANGE,                                               /* �������ȼ�Ϊ���ı� */
    AT_SYSCFG_RAT_PRIO_BUTT
};
typedef VOS_UINT8 AT_SYSCFG_RAT_PRIO_ENUM_UINT8;


typedef VOS_UINT32 (*MN_PS_EVT_FUNC)(VOS_UINT8 ucIndex, VOS_VOID *pEvtInfo);

/*****************************************************************************
 �ṹ��    : AT_PS_EVT_FUNC_TBL_STRU
 �ṹ˵��  : PS���¼������������ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulEvtId;
    MN_PS_EVT_FUNC                      pEvtFunc;
} AT_PS_EVT_FUNC_TBL_STRU;


#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
typedef struct
{
    VOS_UINT8                           ucShellPwdCheckFlag;                    /* VOS_TRUE:������У�飬VOS_FALSE:����δУ��*/
    VOS_UINT8                           ucErrTimes;                             /* ��¼�����������Ĵ��� */
    VOS_UINT8                           aucRsv[2];
}AT_SP_WORD_CTX_STRU;
#endif


typedef struct
{
    /* ��Ȩ��Կ����(δ��half-byte����) */
    VOS_UINT8                           aucPubKey[AT_FACAUTHPUBKEY_PARA_LEN];
    /* ��Ȩ��ԿSSKǩ������(δ��half-byte����) */
    VOS_UINT8                           aucPubKeySign[AT_FACAUTHPUBKEY_SIGN_PARA_LEN];
}AT_FACAUTHPUBKEY_SET_REQ_STRU;


typedef struct
{
    /* �ṹ������, �����������������͵İ���״̬, �����Ŷ�, CK, UK��������Ϣ(δ��half-byte����) */
    VOS_UINT8       aucCategoryData[AT_SIMLOCKDATAWRITE_PARA_LEN];
}AT_SIMLOCKDATAWRITE_SET_REQ_STRU;


typedef struct
{
    TAF_UINT8                           aucSerialNum[TAF_SERIAL_NUM_NV_LEN];
}TAF_PH_SERIAL_NUM_STRU;
typedef struct
{
    AT_WCDMA_BAND_SET_UN        unWcdmaBand;                    /* ��¼WƵ����Ϣ */
    VOS_UINT32                  ulRsv;
    AT_GSM_BAND_SET_UN          unGsmBand;                      /* ��¼GƵ����Ϣ */
}AT_NV_WG_RF_MAIN_BAND_STRU;


typedef struct
{
    VOS_UINT8                   ucParaNum;                                      /* ��������������� */
    VOS_UINT8                   ucRsv[3];                                       /* ����λ */
    VOS_INT16                   asPower[AT_BODYSARWCDMA_MAX_PARA_GROUP_NUM];    /* WƵ�ι�������ֵ */
    VOS_UINT32                  aulBand[AT_BODYSARWCDMA_MAX_PARA_GROUP_NUM];    /* WƵ��λ�� */
}AT_BODYSARWCDMA_SET_PARA_STRU;



/* ɾ������AT^EOPLMN�����洢�����Ľṹ��AT_EOPLMN_SET_REQ_STRU */


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


extern AT_PB_CONVERSION_TABLE_STRU  g_astIraToUnicode[AT_PB_IRA_MAX_NUM];
extern AT_PB_CONVERSION_TABLE_STRU  g_astGsmToUnicode[AT_PB_GSM_MAX_NUM];
extern AT_PB_CONVERSION_TABLE_STRU  g_astGsm7extToUnicode[AT_PB_GSM7EXT_MAX_NUM];


extern AT_CMD_FORMAT_TYPE                   gucAtCmdFmtType;
extern pAtChkFuncType                       pgAtCheckFunc;
extern AT_V_TYPE                            gucAtVType;            /* ָʾ����������� */
extern AT_CSCS_TYPE                         gucAtCscsType;
extern AT_CLIENT_MANAGE_STRU                gastAtClientTab[AT_MAX_CLIENT_NUM];
extern TAF_UINT8                            gaucAtCrLf[];               /*�س�����*/
extern const TAF_UINT8                      gaucAtCmeErrorStr[];        /*������ʾ�ִ�*/
extern const TAF_UINT8                      gaucAtCmsErrorStr[];        /*������ʾ�ִ�*/
extern const TAF_UINT8                      gaucAtTooManyParaStr[];     /*����̫����ʾ�ִ�*/
extern AT_SEND_DATA_BUFFER_STRU             gstAtSendData;
extern AT_SEND_DATA_BUFFER_STRU             gstAtCombineSendData[];
extern const AT_SMS_CMD_TAB_STRU            gastAtSmsCmdTab[];
extern AT_CMD_ECHO_TYPE                     gucAtEType;
extern VOS_UINT32                           gucAtXType;
extern VOS_UINT32                           gucAtQType;
extern TAF_UINT8                            *pgucAtSndCrLfAddr;
extern TAF_UINT8                            *pgucAtSndCodeAddr;
extern TAF_UINT8                            gstAtSendDataBuffer[];
extern const AT_RETURN_TAB_TYPE_STRU        gastAtReturnCodeTab[];
extern const AT_STRING_TYPE_STRU            gastAtStringTab[];
extern TAF_UINT8                            gastAtPppIndexTab[AT_MAX_CLIENT_NUM];
extern TAF_UINT32                           gulPBPrintTag;
extern AT_PB_INFO_STRU                      gstPBATInfo;
extern VOS_UINT8                            g_ucXsmsRecNum;
extern TAF_UINT8                            gucAtPortSel;

extern const TAF_UINT16 gusAtSmsCmdNum;

extern MN_OPERATION_ID_T                    g_OpId;
extern AT_CSTA_NUM_TYPE_ENUM_U8             g_enAtCstaNumType;

extern AT_COMBINE_CMD_SPLIT_STRU            g_stAtComCmdSplit[];
extern AT_COMBINE_CMD_PARSE_RSLT_STRU       g_stAtComCmdParseRslt[];
extern const TAF_UINT16                     gusAtBasicCmdNum;

extern AT_DATA_STREAM_BUFFER_STRU           g_aucAtDataBuff[];




extern TAF_UINT8                    gucAtOmIndex;
extern TAF_UINT8                    gucOmDiagIndex;

extern AT_SET_PORT_PARA_MAP_STRU            g_astSetPortParaMap[AT_SETPORT_DEV_MAP_LEN];
extern AT_DEVICE_CMD_CTRL_STRU              g_stAtDevCmdCtrl;
extern VOS_BOOL                             g_bAtDataLocked;
extern VOS_UINT8                            g_ucDtrDownFlag;

#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
extern AT_SP_WORD_CTX_STRU                  g_stSpWordCtx;
#endif

#if(FEATURE_ON == FEATURE_MULTI_MODEM)
/* AT��������ε�PID��Ӧ��  */
extern AT_MODEM_PID_TAB_STRU                   g_astAtModemPidTab[];
#endif


extern MTA_BODY_SAR_STATE_ENUM_UINT16       g_enAtBodySarState;

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  8 OTHERS����
*****************************************************************************/
extern VOS_UINT32 At_ProcSimLockPara(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           *pucData,
    VOS_UINT16                          usLen
);

/***All the following function are defined in AtSetParaCmd.c***/
extern VOS_UINT32 AT_SetMDatePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetFacInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetPhyNumPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetGTimerPara(VOS_UINT8 ucIndex);

/***All the following function are defined in AtQueryParaCmd.c***/
extern VOS_UINT32 AT_QryMDatePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryFacInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryPhyNumPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryGTimerPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryRsimPara(VOS_UINT8 ucIndex);

extern TAF_UINT32   At_QryCmgdPara(TAF_UINT8 ucIndex);
extern TAF_VOID     At_TimeOutProc(REL_TIMER_MSG *pMsg);
extern TAF_UINT32   At_ClientIdToUserId (TAF_UINT16 usClientId, TAF_UINT8 *pucIndexId);

extern TAF_UINT32   At_CheckPbSpecialCmd (TAF_UINT8* pData, TAF_UINT16 ulLen);
extern TAF_VOID     At_FormatResultData(TAF_UINT8 ucIndex,TAF_UINT32 ReturnCode);
extern TAF_UINT32   At_ParseExtendCmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_ParseDCmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_ParseSCmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_ParseDMCmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_ParseBasicCmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_VOID     At_SetMode(TAF_UINT8 ucIndex,AT_MODE_TYPE Mode,TAF_UINT8 ucSubMode);
extern TAF_UINT32   At_ParsePara(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_SetParaCmd(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryParaCmd(TAF_UINT8 ucIndex);
extern TAF_VOID     At_SendResultData(TAF_UINT8 ucIndex, TAF_UINT8* pData, TAF_UINT16 usLen );
extern VOS_VOID     AT_DisplayResultData (VOS_UINT8 ucIndex,VOS_UINT16 usLen);
extern VOS_VOID     AT_DisplaySelResultData(VOS_UINT16 usLen,VOS_UINT8 ucCount);
extern VOS_VOID     At_ProcHoldAtCmd (VOS_UINT8 ucIndex);
extern TAF_UINT32   At_CheckUsimStatus (
    TAF_UINT8                          *pucCmdName,
    VOS_UINT8                           ucIndex);
extern TAF_UINT32   At_AsciiNum2BcdNum (TAF_UINT8 *pucDst, TAF_UINT8 *pucSrc, TAF_UINT16 usSrcLen);
extern TAF_UINT32   At_AtioRcvDataInd (TAF_UINT8 ucIndex,TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_UINT32   At_UnicodePrint2Unicode(TAF_UINT8 *pData,TAF_UINT16 *pLen);
extern TAF_UINT32 At_UnicodePrintToAscii(TAF_UINT8 *pData,TAF_UINT16 *pLen);
extern TAF_VOID     At_PbAscii2Gsm7BitTransfer(TAF_UINT8 *pData, TAF_UINT16 *pLen);
extern TAF_VOID     At_PbGsm7bit2AsciiTransfer(TAF_UINT8 *pucAlphaTag, TAF_UINT8 *pulAlphaTagLen);
extern TAF_UINT32   At_UnicodeTranserToAscii(TAF_UINT8 *pData,TAF_UINT16 *pLen);
extern TAF_UINT32   At_FindMinCodeOffset(const TAF_UINT8 *pData, TAF_UINT16 usLen);
extern TAF_UINT32 At_UnicodeTransferTo81CalcLength(const TAF_UINT8 *pucData,
                                            TAF_UINT16      usLen,
                                            TAF_UINT16      *pusBaseCode,
                                            TAF_UINT16      *pusDstLen);
extern TAF_UINT32 At_UnicodeTransferTo82CalcLength(const TAF_UINT8 *pucData,
                                            TAF_UINT16      usLen,
                                            TAF_UINT16      *pusBaseCode,
                                            TAF_UINT16      *pusDstLen);
extern TAF_UINT32 At_UnicodeTransferTo81(const TAF_UINT8 *pucData,
                                      TAF_UINT16      usLen,
                                      TAF_UINT16      usCodeBase,
                                      TAF_UINT8       *pucDest);
extern TAF_UINT32 At_UnicodeTransferTo82(const TAF_UINT8 *pucData,
                                  TAF_UINT16      usLen,
                                  TAF_UINT16      usCodeBase,
                                  TAF_UINT8       *pucDest);
extern TAF_UINT32   At_UnicodeTransfer(TAF_UINT8 *pData, TAF_UINT16 *pLen, TAF_UINT32 ulMaxLength);
extern TAF_UINT32 At_OneUnicodeToGsm(TAF_UINT16 usSrc, TAF_UINT8 *pucDst, TAF_UINT16 *pusDstLen);
extern TAF_VOID At_PbGsmToUnicode(TAF_UINT8 *pucSrc, TAF_UINT16 usSrcLen, TAF_UINT8 *pucDst, TAF_UINT16 *pusDstLen);
extern TAF_UINT8*   At_GetStrContent(TAF_UINT32 ulType);
extern TAF_UINT32 At_SendRxOnOffToHPA( VOS_UINT32 ulRxSwitch );
extern TAF_UINT32 At_SendTxOnOffToHPA( TAF_UINT8 ucRxSwitch );
extern VOS_UINT32 At_SendRxOnOffToGHPA( VOS_UINT8 ucIndex, VOS_UINT32 ulRxSwitch );
extern VOS_UINT32 At_SendTxOnOffToGHPA( VOS_UINT8 ucIndex, VOS_UINT8 ucSwitch );
extern TAF_UINT32   At_String2Hex(TAF_UINT8 *nptr,TAF_UINT16 usLen,TAF_UINT32 *pRtn);
extern TAF_UINT32   AT_CountDigit(TAF_UINT8 *pData,TAF_UINT32 ulLen,TAF_UINT8 Char,TAF_UINT32 ulIndex);
extern TAF_UINT16   At_UnicodeFormatPrint(const TAF_UINT8 *pSrc, TAF_UINT8 *pDest, TAF_UINT32 Dcs);
extern TAF_UINT32   At_Ascii2UnicodePrint(TAF_UINT32 MaxLength,TAF_INT8 *headaddr,TAF_UINT8 *pucDst, TAF_UINT8 *pucSrc, TAF_UINT16 usSrcLen);
extern TAF_UINT16   At_PrintReportData(TAF_UINT32 MaxLength,TAF_INT8 *headaddr,TAF_UINT8 ucDataCodeType,TAF_UINT8 *pucDst,TAF_UINT8 *pucSrc,TAF_UINT16 usSrcLen);
extern TAF_UINT32   At_ChgTafErrorCode(TAF_UINT8 ucIndex,TAF_ERROR_CODE_ENUM_UINT32 enTafErrorCode);
/* Del At_AbortCmdProc */
extern TAF_UINT32   At_CheckCharWcmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_ParseWCmd(TAF_UINT8 * pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_Unicode2UnicodePrint(TAF_UINT32 MaxLength,TAF_INT8 *headaddr,TAF_UINT8 *pucDst, TAF_UINT8 *pucSrc, TAF_UINT16 usSrcLen);
extern TAF_VOID     At_UsimGsm7bit2AsciiTransfer(TAF_UINT8 *pucData, TAF_UINT32 *pulDataLen);
extern TAF_UINT32   At_HexString2AsciiNumPrint(TAF_UINT32 MaxLength,TAF_INT8 *headaddr,TAF_UINT8 *pucDst, TAF_UINT8 *pucSrc, TAF_UINT16 usSrcLen);
extern TAF_UINT32   At_MuxCmdProc (TAF_UINT8 ucIndex, TAF_UINT8* pData, TAF_UINT16 usLen);
extern TAF_UINT32   At_CheckMuxCmd(TAF_UINT8 *pData,TAF_UINT16 usLen );
extern TAF_VOID     At_SendReportMsg(TAF_UINT8 ucType,TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_SmsMsgProc(MN_AT_IND_EVT_STRU *pstData,TAF_UINT16 usLen);
extern TAF_VOID     At_SetMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_QryMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_CsMsgProc(MN_AT_IND_EVT_STRU *pstData,TAF_UINT16 usLen);
extern TAF_VOID     At_PppReleaseIndProc(TAF_UINT8 ucIndex);
extern TAF_VOID     At_PhMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_SsMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_DataStatusMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_UINT32   At_PrintfString(TAF_UINT8 *pStr1,TAF_UINT8 *pStr2);
extern TAF_VOID     At_SendDataProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_CmdCnfMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_VOID     At_VcMsgProc(MN_AT_IND_EVT_STRU *pstData,TAF_UINT16 usLen);
extern TAF_INT32    At_sprintf(TAF_INT32 MaxLength,TAF_CHAR *headaddr,TAF_CHAR *curraddr,const TAF_CHAR *fmt,...);
extern TAF_VOID     At_PIHMsgProc(MsgBlock* pMsg);
extern TAF_VOID     At_STKMsgProc(MsgBlock* pMsg);
extern TAF_VOID     At_PbMsgProc(MsgBlock* pMsg);
extern TAF_VOID     At_TAFPbMsgProc(TAF_UINT8* pData,TAF_UINT16 usLen);


/*************���˿ڳ�ʼ������****************/
extern VOS_UINT32 At_UsbModemRelInd(
    VOS_UINT8                           ucPortType,
    VOS_UINT8                           ucDlci
);



extern TAF_UINT32   At_SendData(TAF_UINT8 ucIndex,TAF_UINT8 ucType,TAF_UINT8* pData,TAF_UINT16 usLen);
extern TAF_UINT32   At_HexAlpha2AsciiString(TAF_UINT32 MaxLength,TAF_INT8 *headaddr,TAF_UINT8 *pucDst,TAF_UINT8 *pucSrc,TAF_UINT16 usSrcLen);

extern TAF_VOID     AT_MapCallTypeModeToClccMode(MN_CALL_TYPE_ENUM_U8 enCallType, VOS_UINT8 *penClccMode);
extern AT_CMD_CURRENT_OPT_ENUM  At_GetMnOptType(TAF_UINT8 ucType);

extern VOS_UINT32 At_SetSecuBootPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QrySecuBootPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetWiFiEnablePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiEnablePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiModePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiModePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiBandPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiBandPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiFreqPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiFreqPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiRatePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiRatePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiPowerPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiPowerPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiTxPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiTxPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiRxPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiRxPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiPacketPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiPacketPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiSsidPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiSsidPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiKeyPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiKeyPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWiFiLogPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWiFiLogPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWifiInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWifiPaRangePara (VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWifiPaRangePara (VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestWifiPaRangePara (VOS_UINT8 ucIndex);


#if (FEATURE_ON==FEATURE_LTE)
extern TAF_UINT32 At_SetSfm(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_QrySfm(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetFrStatus(VOS_UINT8 ucIndex);
#endif
#if (FEATURE_LTE==FEATURE_ON)
extern VOS_UINT32 AT_GetLteFeatureInfo(AT_FEATURE_SUPPORT_ST  *pstFeATure);
#endif
extern VOS_UINT32 AT_SetTmmiPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryTmmiPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetChrgEnablePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryChrgEnablePara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryChrgInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetTestScreenPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryBatVolPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetSelRfPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QrySelRfPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetWebPwdPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryWebPwdPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryProdTypePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryFeaturePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QrySecuBootFeaturePara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgfPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmglPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmstPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmssPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgwPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetDPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetAPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetHPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetEPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetVPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetTPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetPPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetXPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetZPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetQPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetAmpCPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetAmpDPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetAmpSPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_SetLPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_SetMPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetFPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetMsIdInfo(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetS0Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetS3Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetS4Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetS5Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetS6Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetS7Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetClipPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetClirPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetColpPara(TAF_UINT8 ucIndex);/*add by zhoujun40661 2006-11-6 for A32D07303*/
extern TAF_UINT32   At_SetCscsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmeePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCeerPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCregPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsdhPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCnmiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCnmaPara(TAF_UINT8 ucIndex);/*begin add by zhoujun40661 2006-10-24 for CNMA*/
extern TAF_UINT32   At_SetCcnmaPara(TAF_UINT8 ucIndex);/*begin add by zhoujun40661 2006-10-24 for CNMA*/
extern TAF_UINT32   At_SetCgregPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgsmsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCscaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsmsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsmpPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpmsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmsqPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCssmPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgdPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCstaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCcugPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCssnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetChldPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetVtsPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetClccPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetCpasPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetDtmfPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_SetCdurPara(VOS_UINT8 ucIndex);

extern TAF_UINT32   At_SetCrcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCbstPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmodPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetChupPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetCmmiPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_SetCgdscontPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_SetCgdcontPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgeqreqPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetPfverPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgeqminPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgpaddrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgcmodPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgactPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgansPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgtftPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgauthPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgautoPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 atSetCgeqosPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atQryCgeqosPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atSetCgeqosrdpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atSetCgcontrdpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atSetCgscontrdpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atSetCgtftrdpPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgdataPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsndPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgattPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgcattPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCopsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgclassPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCfunPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgmiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgmmPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgmrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCgsnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCimiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsqPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCbcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpdwPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_WriteSnPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetSnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetHwVerPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetFHVerPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCLACPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetGcapPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetSrvstPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetRssiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetTimePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCtzrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetModePara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetSimstPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetHSPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpbsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpbrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpbr2Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpbfPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpbwPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpbwPara2(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetScpbwPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetScpbrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCnumPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsimPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCchoPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCchcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCglaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCrsmPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpinPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCardlockPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpin2Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCcwaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCcfcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetClckPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCtfrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmlckPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCusdPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCpwdPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetDsFlowClrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetDsFlowQryPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetDsFlowRptPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgdnsPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetCpamPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetCcinPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetStpdPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetStmnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetSttrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetStenPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_ChangeSATCmdType(TAF_UINT32 cmdNo, TAF_UINT32 *CmdType);
extern TAF_UINT32   At_SetStgiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryStsfPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryStgiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryImsichgPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetStsfPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetStgrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCstrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsinPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsenPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCsmnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCstcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetImsichgPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetTestPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetFPlmnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetQuickStart(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetAutoAttach(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetSystemInfo(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetSystemInfoEx(TAF_UINT8 ucIndex);
extern TAF_UINT32 At_QryLtecsInfo(TAF_UINT8 ucIndex);

extern TAF_UINT32 At_QryCemode(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCwasPara(TAF_UINT8 ucIndex);
extern TAF_UINT32 At_SetCellSearch(TAF_UINT8 ucIndex);
/*w101153*/
extern TAF_UINT32   At_SetCGasPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_SetAppDialModePara(VOS_UINT8 ucIndex);

extern TAF_UINT32   At_SetCpolPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCplsPara(TAF_UINT8 ucIndex);

extern TAF_UINT32   At_SetCmmPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetSPNPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCardModePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetDialModePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetPortSelPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryPortSelPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCurcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCurcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryTimePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCtzrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetBOOTPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCellInfoPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_GetMeanRpt( TAF_UINT8 ucIndex );

extern TAF_UINT32   At_SetQcdmgPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetU2DiagPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetPcscInfo(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetPort(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetGetportmodePara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetCvoicePara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetDdsetexPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetUssdModePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetAdcTempPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCommDebugPara(TAF_UINT8 ucIndex);
extern TAF_UINT32 AT_SetNvRststtsPara(VOS_UINT8 ucIndex);

extern TAF_UINT32   At_SetCmsrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmmtPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetAt2OmPara(TAF_UINT8 ucIndex);

extern TAF_UINT32   At_QryU2DiagPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryPcscInfo(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCellSearch(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_QryPort(VOS_UINT8 ucIndex);
extern TAF_UINT32   AT_SetDwinsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetYjcxPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetpidPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   AT_SetNdisdupPara (VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetAuthdataPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCrpnPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetRxDiv(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_SetCallSrvPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_SetCsdfltPara(VOS_UINT8 ucIndex);

extern TAF_UINT32  At_SetTModePara(TAF_UINT8 ucIndex );
extern TAF_UINT32  At_SetFChanPara(TAF_UINT8 ucIndex );
extern TAF_UINT32  At_SetFTxonPara(TAF_UINT8 ucIndex );
extern TAF_UINT32  AT_SetFDac(TAF_UINT8 ucIndex );
extern TAF_UINT32  At_SetFRxonPara(VOS_UINT8 ucIndex );
extern TAF_UINT32  At_SetFpaPara(VOS_UINT8 ucIndex );
extern TAF_UINT32  At_SetFlnaPara(VOS_UINT8 ucIndex );
extern VOS_UINT32  At_SetDataLock(VOS_UINT8 ucIndex );
extern VOS_UINT32  At_SetSD(VOS_UINT8 ucIndex );
extern VOS_UINT32  At_SetGPIOPL(VOS_UINT8 ucIndex );
#if (FEATURE_ON==FEATURE_LTE)
VOS_UINT32  At_SetInfoRRS(VOS_UINT8 ucIndex );
#endif
extern VOS_UINT32  At_SetInfoRBU(VOS_UINT8 ucIndex );
extern VOS_UINT32 At_SaveRxDivPara(VOS_UINT16  usSetDivBands,VOS_UINT8 ucRxDivCfg);


extern VOS_UINT32   At_SetBsn(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetDpaCat(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryDpaCat(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetHspaSpt(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_ReadDpaCatFromNV(VOS_UINT8 *pucDpaRate);
extern VOS_UINT32   AT_ReadRrcVerFromNV(VOS_UINT8 *pucRrcVer);
extern VOS_UINT32   At_WriteDpaCatToNV(VOS_UINT8 ucDpaRate);
extern VOS_UINT32   AT_WriteRrcVerToNV(VOS_UINT8 ucSrcWcdmaRRC);

extern VOS_UINT32   AT_QryHspaSpt(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetQosPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_SetSDomainPara(VOS_UINT8 ucIndex);

extern TAF_UINT32  At_QryTModePara(TAF_UINT8 ucIndex );
extern TAF_UINT32  At_QryFChanPara(TAF_UINT8 ucIndex );
extern TAF_UINT32  At_QryFTxonPara(TAF_UINT8 ucIndex );
extern TAF_UINT32  AT_QryFDac(TAF_UINT8 ucIndex );

extern VOS_UINT32   At_QryPlatForm(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryBsn(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryCsVer(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryQosPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QrySDomainPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QrySimLockPlmnInfo(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_UnlockSimLock(
    VOS_UINT8                           ucIndex,
    VOS_UINT32                          ulParaCnt,
    AT_PARSE_PARA_TYPE_STRU             *pstParalist
);

extern VOS_UINT32 AT_ConvertCharToHex(
        VOS_UINT8                           ucChar,
        VOS_UINT8                          *pucHexValue
    );
extern VOS_UINT32 At_SetSimLockPlmnInfo(
    VOS_UINT8                           ucIndex,
    VOS_UINT32                          ulParaCnt,
    AT_PARSE_PARA_TYPE_STRU             *pstParalist
);
extern VOS_UINT32 At_CovertAtParaToSimlockPlmnInfo(
    VOS_UINT32                          ulParaCnt,
    AT_PARSE_PARA_TYPE_STRU             *pstParalist,
    TAF_CUSTOM_SIM_LOCK_PLMN_INFO_STRU  *pstSimLockPlmnInfo
);
extern VOS_UINT32 At_SetMaxLockTimes(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryMaxLockTimes(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryDataLock(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QrySD(VOS_UINT8 ucIndex );
extern VOS_UINT32   At_QryGPIOPL(VOS_UINT8 ucIndex );
extern VOS_UINT32   At_QryVersion(VOS_UINT8 ucIndex );

/*������hspa AT�������ú���*/
extern TAF_UINT32   At_SetRRCVersion(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCSNR(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetFreqLock(TAF_UINT8 ucIndex);

extern VOS_UINT32   At_SetSysCfgPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetSysCfgExPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_IsSupportGMode(
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder
);
extern VOS_UINT32 AT_IsSupportWMode(
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder
);
extern VOS_UINT32 AT_IsSupportLMode(
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder
);

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
VOS_UINT32 AT_IsSupport1XMode(
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder
);

VOS_UINT32 AT_IsSupportHrpdMode(
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder
);

VOS_UINT32 AT_SetQuitCallBack( VOS_UINT8 ucIndex  );
VOS_UINT32 AT_SetCSidList( VOS_UINT8 ucIndex   );
VOS_UINT32 AT_ConvertCSidListMcc(
    VOS_UINT8                          *pucPara,
    VOS_UINT16                          usLen,
    VOS_UINT32                         *pstMcc
);
VOS_UINT32 AT_SetCSidEnable(VOS_UINT8 ucIndex );
#endif

VOS_UINT32 AT_SetCclprPara(VOS_UINT8 ucIndex);


VOS_UINT32 AT_SetNetScan(
    VOS_UINT8                           ucIndex
);

VOS_UINT32 AT_AbortNetScan(
    VOS_UINT8                           ucIndex
);

extern TAF_UINT32   At_SetImeiPara(TAF_UINT8 ucIndex); /*added by luojian 60022475 2006.12.20*/
extern TAF_UINT32   At_SetTrigPara(TAF_UINT8 ucIndex); /*added by sunshaohua 62952 2007.06.20*/

#ifndef _PS_COMPILE_EDGE_ADAPT_MOIRI_B073_
extern TAF_UINT32   At_SetGcfIndPara(TAF_UINT8 ucIndex);
#endif
extern VOS_UINT32  At_SetGlastErrPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_SetClvlPara(VOS_UINT8 ucIndex);

extern VOS_UINT32   At_SetVMSETPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_SetCmgsSegmentPara(TAF_UINT8 ucIndex);

extern VOS_UINT32   AT_SetVertime ( VOS_UINT8 ucIndex );

/*�ڲ����úͲ�ѯNV������*/
#if ( VOS_WIN32 == VOS_OS_VER )
extern VOS_UINT32   AT_SetNvimPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_ResetNplmn ( VOS_UINT8 ucIndex );
extern VOS_UINT32 At_SetReadUsimStub( VOS_UINT8 ucIndex );

extern VOS_UINT32 AT_SetPidReinitPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32   AT_SetRplmnStub( VOS_UINT8 ucIndex );

VOS_UINT32  AT_SetDamParaStub( VOS_UINT8 ucIndex );

VOS_UINT32  AT_SetEonsParaStub( VOS_UINT8 ucIndex );
VOS_UINT32  AT_SetWildCardParaStub( VOS_UINT8 ucIndex );
extern TAF_UINT32 AT_SetUSIMPara(TAF_UINT8 ucIndex);

extern TAF_UINT32 AT_SetSIMPara(TAF_UINT8 ucIndex);


extern VOS_UINT32 AT_RefreshUSIMPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetSTKParaStub(VOS_UINT8 ucIndex);

extern VOS_UINT32   AT_SetTinTypeStub( VOS_UINT8 ucIndex );
extern  VOS_UINT32  AT_SetPsBearIsrFlgStub( VOS_UINT8 ucIndex );
extern VOS_UINT32 At_QryTinTypeStub(VOS_UINT8 ucIndex);


extern VOS_UINT32  AT_SetPsRegisterContainDrxStub( VOS_UINT8 ucIndex );
extern  VOS_UINT32 AT_QryPsRegisterContainDrxStub(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetCsUnAvailPlmnStub( VOS_UINT8 ucIndex );
extern VOS_UINT32 AT_SetForbRoamTaStub( VOS_UINT8 ucIndex );

VOS_UINT32 AT_SetDisableRatPlmnStub( VOS_UINT8 ucIndex );

extern VOS_UINT32 AT_SetImsRatStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetImsCapabilityStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetDomainStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCmdImsRoamingStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCmdRedailStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetImsVoiceInterSysLauEnableStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetImsVoiceMMEnableStub(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCmdImsUssdStub(VOS_UINT8 ucIndex);
#endif

/*������PDP��׮����*/
extern VOS_UINT32 At_SetNdisAddPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_SetDnsPrim(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_SetDnsSnd(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_GetSimLockStatus(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetGodloadPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_SetResetPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetNvBackUpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_SetNvRestorePara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetNvManufactureExtPara( VOS_UINT8 ucIndex );

extern TAF_UINT32   At_QryApDialModePara(TAF_UINT8 ucIndex);
extern VOS_UINT32   AT_SetWifiGlobalMacPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_QryWifiGlobalMacPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_SetCsqlvlPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_QryCpuLoadPara(VOS_UINT8 ucIndex);

extern VOS_UINT32   AT_SetDockPara (VOS_UINT8 ucIndex);
extern VOS_UINT32   AT_QryAppdmverPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32   AT_QryDislogPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32   AT_SetOpwordPara ( VOS_UINT8  ucIndex );
extern VOS_UINT32   AT_SetCpwordPara ( VOS_UINT8  ucIndex );
extern VOS_UINT32   AT_SetDislogPara ( VOS_UINT8 ucIndex );
#if (FEATURE_ON == FEATURE_SECURITY_SHELL)
extern VOS_UINT32 AT_SetSpwordPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetShellPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryShellPara(VOS_UINT8 ucIndex);

#endif
#if (FEATURE_ON==FEATURE_LTE)

extern VOS_UINT32 AT_SetRsrpCfgPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32  AT_QryRsrpCfgPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32 AT_SetRscpCfgPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32 AT_SetEcioCfgPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32  AT_QryRscpCfgPara ( VOS_UINT8 ucIndex );
extern VOS_UINT32  AT_QryEcioCfgPara ( VOS_UINT8 ucIndex );
/* ɾ��AT_QryCellRoamPara */

extern VOS_UINT32 AT_SetPdprofmodPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryPdprofmodPara(VOS_UINT8 ucIndex);


extern VOS_UINT32 AT_SetExbandInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetExbandTestInfoPara(VOS_UINT8 ucIndex);

#endif
extern VOS_UINT32   AT_SetApbatlvlPara( VOS_UINT8 ucIndex );
#if (FEATURE_ON == FEATURE_LTE)
extern  VOS_UINT32 AT_SetCeregPara(VOS_UINT8 ucIndex);
extern  VOS_UINT32 At_QryCeregPara(VOS_UINT8 ucIndex);
#endif
extern VOS_UINT32 AT_SetOpenportPara( VOS_UINT8 ucIndex );
extern VOS_UINT32 AT_SetSdloadPara(VOS_UINT8 ucIndex);

extern TAF_UINT32   At_QryS0Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryS3Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryS4Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryS5Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryS6Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryS7Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCmgfPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCcnmaPara(TAF_UINT8 ucIndex);/*add by zhoujun40661 2006-10-14*/
extern TAF_UINT32   At_QryClipPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryColpPara(TAF_UINT8 ucIndex);/*add by zhoujun40661 2006-11-6 for A32D07303*/
extern TAF_UINT32   At_QryClirPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCusdPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCcwaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCpinPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryIccidPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryPNNPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCPNNPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryOPLPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCpin2Para(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCpinStatus(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCardlockPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCardATRPara(TAF_UINT8 ucIndex);

VOS_UINT32 At_SetUsimStub(VOS_UINT8 ucIndex);
VOS_UINT32 At_SetRefreshStub(VOS_UINT8 ucIndex);
VOS_UINT32 At_SetAutoReselStub(VOS_UINT8 ucIndex);

/* Modified by c00318887 for file refresh��Ҫ����������, 2015-3-31, begin */
#if ( VOS_WIN32 == VOS_OS_VER )
VOS_UINT32 At_SetDelayBgStub(VOS_UINT8 ucIndex);
#endif
/* Modified by c00318887 for file refresh��Ҫ����������, 2015-3-31, end */
extern TAF_UINT32   At_QryCpbsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCfunPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCpamPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCgclassPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCopsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCgcattPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCgattPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryCgauthPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryCgautoPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryCgtftPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryCgactPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCgdcontPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   AT_QryCgeqreqPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCgeqminPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCgdscontPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_QryCrcPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCbstPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCmodPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCstaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCcugPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCssnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCscaPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCsmsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCsmpPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCpmsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCgsmsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCgregPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCregPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCsdhPara(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_QryMaxFreelockSizePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryLcStartTimePara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_QryCnmiPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCscsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCmeePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryCgdnsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryFrqPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryFPlmnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryDialModePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryQuickStart(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryAutoAttach(TAF_UINT8 ucIndex);

VOS_UINT32 AT_QrySysCfgExPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_QrySysCfgPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryGetportmodePara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_QryVMSETPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryClvlPara(VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryCvoicePara (VOS_UINT8 ucIndex);
extern VOS_UINT32   At_QryDdsetexPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_QryCmsrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryUssdModePara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryAdcTempPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCommDebugPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryDwinsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryYjcxPara(TAF_UINT8 ucIndex);
extern VOS_UINT32   At_QryCplsPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   At_QryCpolPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryNdisdupPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryAuthdataPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCrpnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_QryNdisStatPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryNdisConnPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryRxDiv(TAF_UINT8 ucIndex);
extern VOS_UINT32 At_QryCallSrvPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryCsdfltPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_OutputCsdfltDefault(
    VOS_UINT8                           ucIndex,
    VOS_BOOL                            bSimlockEnableFlg
);

extern VOS_UINT32 At_QryFrssiPara(VOS_UINT8 ucIndex);
extern VOS_UINT32  At_QryFpaPara(VOS_UINT8 ucIndex);
extern VOS_UINT32  At_QryFlnaPara(VOS_UINT8 ucIndex);
extern VOS_UINT32  At_QryFRxonPara(VOS_UINT8 ucIndex);
extern TAF_UINT32   AT_QryAlsPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetAlsPara(TAF_UINT8 ucIndex);
/*������AT�����ѯ����*/
extern TAF_UINT32   At_QryRRCVersion(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryCSNR(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_QryFreqLock(TAF_UINT8 ucIndex);
extern TAF_UINT32 At_QryGlastErrPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetIccidPara(TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetPNNPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetCPNNPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   At_SetOPLPara (TAF_UINT8 ucIndex);
extern TAF_UINT32   AT_SetCgeqnegPara( TAF_UINT8 ucIndex);

extern TAF_UINT32   At_ReadNumTypePara(TAF_UINT8 *pucDst,TAF_UINT8 *pucSrc);

extern TAF_UINT32   At_ChgMnErrCodeToAt(TAF_UINT8 ucIndex,TAF_UINT32 ulMnErrorCode);
extern TAF_UINT32   At_PrintListMsg(
    VOS_UINT8                            ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent,
    MN_MSG_TS_DATA_INFO_STRU            *pstTsDataInfo,
    TAF_UINT8                           *pucDst
);

extern TAF_VOID     At_PrintCsmsInfo(
    TAF_UINT8                           ucIndex
);

extern MN_OPERATION_ID_T  At_GetOpId(
    VOS_VOID
);

extern TAF_VOID     At_HandleSmtBuffer(
    VOS_UINT8                           ucIndex,
    AT_CNMI_BFR_TYPE                    ucBfrType
);

extern TAF_UINT16   At_PrintAsciiAddr(
    MN_MSG_ASCII_ADDR_STRU              *pstAddr,
    TAF_UINT8                           *pDst
);

extern TAF_UINT32   At_GetScaFromInputStr(
    const TAF_UINT8                     *pucAddr,
    MN_MSG_BCD_ADDR_STRU                *pstBcdAddr,
    TAF_UINT32                          *pulLen
);

extern MN_MSG_TS_DATA_INFO_STRU * At_GetMsgMem(
    VOS_VOID
);

extern TAF_UINT16   At_PrintMsgFo(
    MN_MSG_TS_DATA_INFO_STRU            *pstTsDataInfo,
    TAF_UINT8                           *pDst
);

extern TAF_UINT16   At_PrintAddrType(
    MN_MSG_ASCII_ADDR_STRU              *pstAddr,
    TAF_UINT8                           *pDst
);

extern TAF_UINT32   At_SetNumTypePara(
    TAF_UINT8                           *pucDst,
    TAF_UINT8                           *pucSrc,
    TAF_UINT16                          usSrcLen
);

extern VOS_VOID AT_PhSendRestoreFactParm( VOS_VOID );

extern TAF_UINT32   At_GetAsciiOrBcdAddr(
    TAF_UINT8                           *pucAddr,
    TAF_UINT16                          usAddrLen,
    TAF_UINT8                           ucAddrType,
    TAF_UINT16                          usNumTypeLen,
    MN_MSG_ASCII_ADDR_STRU              *pstAsciiAddr,
    MN_MSG_BCD_ADDR_STRU                *pstBcdAddr
);

extern TAF_VOID     At_SmsModSmStatusRspProc(
        TAF_UINT8                           ucIndex,
        MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_SmsInitResultProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pEvent
);

extern VOS_VOID     At_SmsDeliverErrProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID     At_SmsInitSmspResultProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID     At_SmsSrvParmChangeProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID     At_SmsRcvMsgPathChangeProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID     At_SmsStorageListProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID     At_SmsStorageExceedProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_PrintSetCpmsRsp(
    TAF_UINT8                           ucIndex
);

extern TAF_VOID At_ZeroReplaceBlankInString(
    VOS_UINT8                           *pData,
    VOS_UINT32                           ulLen
);

extern VOS_UINT32  AT_PhyNumIsNull(
    MODEM_ID_ENUM_UINT16                enModemId,
    AT_PHYNUM_TYPE_ENUM_UINT32           enSetType,
    VOS_BOOL                            *pbPhyNumIsNull
);

extern TAF_UINT16   At_PrintBcdAddr(
    MN_MSG_BCD_ADDR_STRU                *pstBcdAddr,
    TAF_UINT8                           *pDst
);

extern VOS_VOID     At_PrintGetCpmsRsp(
    VOS_UINT8                           ucIndex
);

extern TAF_UINT32   At_CheckNumLen(
    TAF_UINT16                          usMax,
    TAF_UINT16                          usLen
);

extern TAF_UINT32  At_CheckUssdNumLen(
    VOS_UINT8                           ucIndex,
    TAF_SS_DATA_CODING_SCHEME           dcs,
    TAF_UINT16                          usLen
);

extern TAF_UINT32   At_SmsPrintScts(
    const MN_MSG_TIMESTAMP_STRU         *pstTimeStamp,
    TAF_UINT8                           *pDst
);

extern TAF_UINT16   At_MsgPrintVp(
    MN_MSG_VALID_PERIOD_STRU            *pstValidPeriod,
    TAF_UINT8 *pDst
);

extern TAF_UINT32   At_SmsPrintState(
    AT_CMGF_MSG_FORMAT_ENUM_U8          enSmsFormat,
    MN_MSG_STATUS_TYPE_ENUM_U8          enStatus,
    TAF_UINT8                           *pDst
);

extern MN_MSG_SEND_ACK_PARM_STRU * At_GetAckMsgMem(
    VOS_VOID
);

extern TAF_VOID     At_MsgResultCodeFormat(
    TAF_UINT8                           ucIndex,
    TAF_UINT16                          usLength
);

extern VOS_VOID     At_SmsDeliverProc(
        TAF_UINT8                           ucIndex,
        MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_SetRcvPathRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_SetCscaCsmpRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);


extern VOS_UINT32 AT_TestSetPort(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_TestRstriggerPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestStsfPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestCpnnPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestOplPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestPnnPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestStgiPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestStgrPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestImsichgPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestSsidPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_TestWikeyPara(VOS_UINT8 ucIndex);

extern VOS_UINT32  AT_SetDissdCmd(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetSdrebootCmd(VOS_UINT8 ucIndex);

extern TAF_VOID     At_DeleteTestRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_ReadRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_ListRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_WriteSmRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID  At_DeleteRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_SetCnmaRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_SendSmRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_UINT32   At_CheckDigit( TAF_UINT8 Char );
extern TAF_UINT32   At_CheckColon( TAF_UINT8 Char );

extern TAF_UINT32   At_SetCmStubPara(TAF_UINT8 ucIndex);

extern TAF_UINT32   At_SetCmmsPara(
    TAF_UINT8                           ucIndex
);

extern TAF_UINT32   At_QryCmmsPara(
    TAF_UINT8                           ucIndex
);

extern TAF_VOID     At_SetCmmsRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern TAF_VOID     At_GetCmmsRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID AT_QryCscaRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU             *pstEvent
);

extern VOS_VOID At_SmsStubRspProc(
    VOS_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU             *pstEvent
);

extern TAF_VOID     At_SmsRspNop(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);
extern TAF_UINT32   At_MsgDeleteCmdProc(
    TAF_UINT8                           ucIndex,
    MN_OPERATION_ID_T                   opId,
    MN_MSG_DELETE_PARAM_STRU            stDelete,
    TAF_UINT32                          ulDeleteTypes
);

extern VOS_UINT32 At_GetSmsStorage(
    VOS_UINT8                           ucIndex,
    MN_MSG_MEM_STORE_ENUM_U8            enMemReadorDelete,
    MN_MSG_MEM_STORE_ENUM_U8            enMemSendorWrite,
    MN_MSG_MEM_STORE_ENUM_U8            enMemRcv
);

extern VOS_VOID At_QryParaRspCopsProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                            *pPara
);

/* Deleted by k902809 for Iteration 11, 2015-3-27, begin */

/* Deleted by k902809 for Iteration 11, Iteration 11 2015-3-27, end */

extern TAF_VOID     At_QryParaRspSysinfoProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

/* begin V7R1 PhaseI Modify */
extern VOS_VOID  AT_QryParaRspSysinfoExProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                           *pPara
);
/* end V7R1 PhaseI Modify */

extern TAF_VOID     At_QryParaRspCimiProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

extern TAF_VOID     At_QryParaRspCgclassProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

extern VOS_VOID     At_QryParaRspCregProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                            *pPara
);

extern VOS_VOID     At_QryParaRspCgregProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                            *pPara
);


extern TAF_VOID     At_QryParaRspIccidProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

extern TAF_VOID     At_QryParaRspPnnProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);
extern TAF_VOID     At_QryParaRspCPnnProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

#if(FEATURE_ON == FEATURE_LTE)

TAF_VOID At_QryParaRspCellRoamProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);
#endif

extern TAF_VOID     At_QryParaRspOplProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

extern TAF_VOID     At_QryParaRspCfplmnProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);



extern TAF_VOID     At_QryParaRspCgdnsProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

extern TAF_VOID     At_QryParaRspAuthdataProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);

extern TAF_VOID     At_QryRspUsimRangeProc(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           OpId,
    TAF_VOID                            *pPara
);
extern TAF_UINT32 At_QryNdisAddPara(TAF_UINT8 ucIndex);
extern TAF_UINT32 At_QryDnsPrim(VOS_UINT8 ucIndex);
extern TAF_UINT32 At_QryDnsSnd(VOS_UINT8 ucIndex);
extern TAF_UINT32 AT_QryDloadVerPara(VOS_UINT8 ucIndex);
extern TAF_UINT32 AT_QryDloadInfoPara(VOS_UINT8 ucIndex);
extern TAF_UINT32 AT_QryAuthorityIdPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryAuthorityVerPara( VOS_UINT8 ucIndex );
extern TAF_UINT32 AT_QryNvRststtsPara(VOS_UINT8 ucIndex);
extern TAF_UINT32 AT_QryFlashInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryAuthverPara(VOS_UINT8 ucIndex);

#if (FEATURE_ON == FEATURE_IPV6)
extern VOS_UINT32 AT_TestIpv6capPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryIpv6CapPara(VOS_UINT8 ucIndex);
#endif
extern VOS_UINT32 At_DialNumByIndexFromPb(VOS_UINT8  ucIndex,SI_PB_EVENT_INFO_STRU  *pEvent);
extern TAF_UINT32   At_PbReadCnfProc(VOS_UINT8 ucIndex,SI_PB_EVENT_INFO_STRU  *pEvent);

extern TAF_UINT32   At_PbCPBRCmdPrint(VOS_UINT8 ucIndex,TAF_UINT16 *pusDataLen,TAF_UINT8 *pucData,SI_PB_EVENT_INFO_STRU *pEvent);

extern TAF_UINT32   At_PbCPBR2CmdPrint(VOS_UINT8 ucIndex,TAF_UINT16 *pusDataLen,TAF_UINT8 *pucData,SI_PB_EVENT_INFO_STRU *pEvent);

extern TAF_UINT32   At_PbCNUMCmdPrint(VOS_UINT8 ucIndex,TAF_UINT16 *pusDataLen,TAF_UINT8 *pucData,SI_PB_EVENT_INFO_STRU *pEvent);

extern TAF_UINT32   At_PbSCPBRCmdPrint(VOS_UINT8 ucIndex,TAF_UINT16 *pusDataLen,SI_PB_EVENT_INFO_STRU *pEvent);

extern TAF_VOID     At_PbSearchCnfProc(VOS_UINT8 ucIndex,SI_PB_EVENT_INFO_STRU  *pEvent);


extern  TAF_VOID    At_CombineCmdStruInit(VOS_VOID);
extern  TAF_VOID    At_ResetCombineCmdStru(TAF_UINT8    ucIndex);
extern  TAF_UINT32  At_FormatCmdStr ( TAF_UINT8 *pData, TAF_UINT16 *pLen);
extern  TAF_UINT32  At_ScanDelChar( TAF_UINT8 *pData, TAF_UINT16 *pLen);
extern  TAF_UINT32  At_ScanCtlChar( TAF_UINT8 *pData, TAF_UINT16 *pLen);
extern  TAF_UINT32  At_ScanQuoteChar( TAF_UINT8 *pData, TAF_UINT16 *pLen);
extern  TAF_UINT32  At_ScanBlankChar( TAF_UINT8 *pData, TAF_UINT16 *pLen);
/*extern  TAF_UINT32  At_ScanLowerChar(TAF_UINT8* pData, TAF_UINT16 usLen); */
extern  TAF_UINT32  At_ScanSemicolonChar( TAF_UINT8 *pData,
                                           TAF_UINT16 usLen,
                                           AT_COMBINE_CMD_SEMICOLON_PARSE_STRU *pstComCmdSCParse);
extern  TAF_UINT32  At_CheckCharA( TAF_UINT8 Char );
extern  TAF_UINT32  At_CheckCharT( TAF_UINT8 Char );
extern  VOS_UINT32  At_CmdDataPreProc(
    VOS_UINT8                               *pData,
    VOS_UINT16                              *pusCmdLen
);
/*extern TAF_VOID     At_CmdMsgPreProc(TAF_UINT8 ucIndex, TAF_UINT8* pData, TAF_UINT16 usLen); */
/*extern VOS_UINT32   At_HoldAtCmd (VOS_UINT8   ucIndex, VOS_UINT8   *pData, VOS_UINT16  usLen); */
extern VOS_UINT32   At_FindPendAtChannelOrSmsEditMode(AT_USER_TYPE UserType);



#if ((FEATURE_ON == FEATURE_GCBS) || (FEATURE_ON == FEATURE_WCBS))

#define AT_MAX_CBS_MSGID_NUM            50

extern TAF_UINT32   At_QryCscbPara(
    TAF_UINT8                           ucIndex
);

extern TAF_UINT32 At_SetCscbPara(
    TAF_UINT8                           ucIndex
);

extern VOS_VOID At_SmsDeliverCbmProc(
        TAF_UINT8                           ucIndex,
        MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID At_GetCbActiveMidsRspProc(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);

extern VOS_VOID AT_ChangeCbMidsRsp(
    TAF_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent
);


#if (FEATURE_ON == FEATURE_ETWS)
VOS_VOID  At_ProcDeliverEtwsPrimNotify(
    VOS_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU             *pstEvent
);
#endif  /* (FEATURE_ON == FEATURE_ETWS) */


#endif

extern TAF_UINT32   Ppp_ReleasePppReq ( TAF_UINT16 usPppId);
extern TAF_UINT8    Cca_CurState(VOS_VOID);
extern TAF_VOID     SysCtrl_RFLdoDown(VOS_VOID);

extern TAF_UINT32   At_SetCdtmfsPara(
    TAF_UINT8                           ucIndex
);
extern TAF_UINT32   At_SetCdtmfePara(
    TAF_UINT8                           ucIndex
);

extern VOS_INT      UdiagValueCheck(VOS_UINT32 DiagValue);
extern VOS_UINT32   GetU2diagDefaultValue(VOS_VOID);
extern VOS_VOID     MMA_CardType(VOS_CHAR *pcDest);
TAF_UINT32          At_GetBandPara(TAF_UINT8 *nptr,TAF_UINT16 usLen,TAF_USER_SET_PREF_BAND64 * pStBand);

/*Ϊ�˹��Linux��̨���β���ʧ�����⣬���ȡ��ܷ�������ܷ����У�����������һ���ж��Ƿ�
  ΪLINUX����ϵͳ��API*/
extern VOS_INT      GetLinuxSysType(VOS_VOID);

extern VOS_VOID     CheckCurrentModemStatus(VOS_INT status);

extern TAF_VOID     AT_StubTriggerAutoReply(
    VOS_UINT8                           ucIndex,
    TAF_UINT8                           ucCfgValue
);

extern TAF_VOID     AT_StubSaveAutoReplyData(
    VOS_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent,
    MN_MSG_TS_DATA_INFO_STRU            *pstTsDataInfo
);

extern TAF_UINT32   AT_StubSendAutoReplyMsg(
    VOS_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU              *pstEvent,
    MN_MSG_TS_DATA_INFO_STRU            *pstTsDataInfo
);
extern VOS_UINT32 AT_SetCsqlvlExtPara(VOS_UINT8 ucIndex);
/* Deleted by y00322978 for CDMA 1X Iteration 11, 2015-4-11, begin */

/* Deleted by y00322978 for CDMA 1X Iteration 11, 2015-4-11, end */

/* Deleted by y00322978 for CDMA 1X Iteration 11, 2015-4-11, begin */

/* Deleted by y00322978 for CDMA 1X Iteration 11, 2015-4-11, end */

VOS_VOID AT_CsUus1InfoEvtIndProc(
    VOS_UINT8                           ucIndex,
    MN_CALL_EVENT_ENUM_U32              enEvent,
    MN_CALL_INFO_STRU                   *pstCallInfo
);

#if ( VOS_WIN32 == VOS_OS_VER )
extern VOS_VOID     USIMM_SendSMSDataInd1(VOS_VOID);
extern VOS_VOID     USIMM_SendSMSDataInd2(VOS_VOID);
extern VOS_VOID     MN_MSG_SetClass0Tailor(MN_MSG_CLASS0_TAILOR_U8                 enClass0Tailor);
#endif

extern VOS_UINT32   MMA_PhoneFindNtwkNameByPlmnId( TAF_PH_OPERATOR_NAME_STRU   *pstOperName);
extern VOS_UINT32   MMA_PhoneGetAllOperNumByLongNameFromOperTbl( TAF_PH_OPERATOR_NAME_STRU   *pstOperName,
                                                                                        VOS_UINT8 *pucMaxMncLen);
extern VOS_UINT32   MMA_PhoneGetAllOperNumByShortNameFromOperTbl( TAF_PH_OPERATOR_NAME_STRU   *pstOperName,
                                                                                        VOS_UINT8 *pucMaxMncLen);
extern VOS_VOID   MMA_PhoneGetAllOperInfoByLongNameFromOperTbl( TAF_PH_OPERATOR_NAME_STRU   *pstOrigOperName,
                                                                                       TAF_PH_OPERATOR_NAME_STRU   *pstOperName);
extern VOS_VOID   MMA_PhoneGetAllOperInfoByShortNameFromOperTbl( TAF_PH_OPERATOR_NAME_STRU   *pstOrigOperName,
                                                                                      TAF_PH_OPERATOR_NAME_STRU   *pstOperName);

extern VOS_BOOL AT_PH_IsPlmnValid(TAF_PLMN_ID_STRU *pstPlmnId);
extern VOS_BOOL MN_PH_IsUsingPlmnSel(VOS_VOID);


extern VOS_UINT32   AT_SetCccPara( TAF_UINT8 ucIndex );

/***All the following function are defined in AtSetParaCmd.c***/
extern TAF_UINT32 AT_SetRstriggerPara(
        TAF_UINT8                           ucIndex
);

/***All the following function are defined in AtQueryParaCmd.c***/
extern TAF_UINT32 AT_QryRstriggerPara(
    TAF_UINT8                           ucIndex
);

extern VOS_UINT32 At_QryApHplmn(VOS_UINT8  ucIndex);
extern VOS_UINT32 AT_QryAnQuery( VOS_UINT8 ucIndex );


/***All the following function are defined in MnMsgSmsProc.c***/
extern VOS_UINT32 AT_ReadActiveMessage(
        MODEM_ID_ENUM_UINT16                enModemId,
        MN_MSG_ACTIVE_MESSAGE_STRU         *pstActiveMessage
);

extern VOS_UINT32 AT_WriteActiveMessage(
    MODEM_ID_ENUM_UINT16                enModemId,
    MN_MSG_ACTIVE_MESSAGE_STRU         *pstOrgActiveMessageInfo,
    MN_MSG_ACTIVE_MESSAGE_STRU         *pstActiveMessageInfo
);
extern VOS_VOID At_BufferorSendResultData(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLength
);

extern TAF_UINT32 At_PrintMmTimeInfo(
    VOS_UINT8                           ucIndex,
    TAF_MMA_TIME_CHANGE_IND_STRU       *pMsg,
    TAF_UINT8                          *pDst
);

extern  TAF_UINT32  At_PrintTimeZoneInfo(
    NAS_MM_INFO_IND_STRU                *pstMmInfo,
    TAF_UINT8                           *pDst
);

/*****************************************************************************
 �� �� ��  : AT_PrintTimeZoneInfoNoAdjustment
 ��������  : ��ʾ��ǰʱ����Ϣ(����ʱ����Ϣ)
 �������  : pstMmInfo - MM INFO�ṹָ��
             pDst      - ��ʾ���ݵ�ַ
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 AT_PrintTimeZoneInfoNoAdjustment(
    NAS_MM_INFO_IND_STRU               *pstMmInfo,
    VOS_UINT8                          *pucDst
);

extern  TAF_VOID    At_PhIndProc(
    TAF_UINT8                           ucIndex,
    TAF_PHONE_EVENT_INFO_STRU           *pEvent
);

extern  VOS_UINT32 MN_PH_QryApHplmn(
    VOS_UINT32                          *pulMcc,
    VOS_UINT32                          *pulMnc
);

extern VOS_UINT32 MN_PH_QryAnQuery(
    VOS_INT16                           *psCpichRscp,
    VOS_INT16                           *psCpichEcNo,
    VOS_UINT8                           *pucRssi,
    VOS_UINT32                          *pulCellId
);
extern AT_CMD_ANTENNA_LEVEL_ENUM_UINT8 AT_CalculateAntennaLevel(
    VOS_INT16                           sRscp,
    VOS_INT16                           sEcio
);
#if (FEATURE_ON == FEATURE_LTE)
extern VOS_UINT8 AT_CalculateLTEAntennaLevel(
    VOS_INT16 usRsrp
);

extern TAF_VOID AT_CalculateLTESignalValue(
    VOS_INT16    *psRssi,
    VOS_UINT8    *pusLevel,
    VOS_INT16    *pusRsrp,
    VOS_INT16    *pusRsrq
);
#endif

extern VOS_UINT8 AT_GetSmoothLTEAntennaLevel(
    AT_CMD_ANTENNA_LEVEL_ENUM_UINT8     enLevel
);

extern VOS_VOID AT_GetSmoothAntennaLevel(
           VOS_UINT8                           ucIndex,
           AT_CMD_ANTENNA_LEVEL_ENUM_UINT8     enLevel );
extern VOS_UINT32  At_QryAppWronReg( VOS_UINT8 ucIndex );

extern  VOS_UINT32 At_SetCuus1Para(
    VOS_UINT8                           ucIndex
);

extern  VOS_UINT32 At_QryCuus1Para(
    VOS_UINT8                           ucIndex
);

VOS_VOID AT_GetOnlyGURatOrder(
    TAF_MMA_RAT_ORDER_STRU             *pstRatOrder
);
VOS_VOID AT_GetRatOrderNvim(
    MODEM_ID_ENUM_UINT16                enModemId,
    TAF_MMA_RAT_ORDER_STRU             *pstSysCfgRatOrder,
    VOS_UINT8                           ucUserSptLteFlag
);
VOS_UINT32 AT_ConvertSysCfgExBandPara(
    VOS_UINT8                          *pucPara,
    VOS_UINT16                          usLen,
    TAF_USER_SET_PREF_BAND64           *pstPrefBandPara
);

VOS_UINT32 At_CheckSysCfgExRatTypeValid(
    VOS_UINT8                           ucRatOrder
);
VOS_UINT32 At_CheckRepeatedRatOrder(
    AT_SYSCFGEX_RAT_ORDER_STRU         *pstSyscfgExRatOrder
);

TAF_VOID At_ResetGlobalVariable( VOS_VOID);




VOS_VOID AT_GetGuAccessPrioNvim (
    MODEM_ID_ENUM_UINT16                enModemId,
    AT_SYSCFG_RAT_PRIO_ENUM_UINT8      *penAcqorder
);

extern VOS_UINT32 AT_ParseSetDockCmd(
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 AT_HandleDockSetCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 AT_DockHandleCmd(
        VOS_UINT8                       ucIndex,
        VOS_UINT8                      *pucData,
        VOS_UINT16                      usLen
);

extern VOS_BOOL AT_CheckDockName(
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);
/*****************************************************************************
 �� �� ��  : AT_GetRateDisplayIndexForGsm
 ��������  : ��ȡGSMģʽ���������ȼ���������ʾ���е�����
 �������  : ��
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 AT_GetRateDisplayIndexForGsm(
    TAF_AGENT_SYS_MODE_STRU            *pstSysMode
);

/*****************************************************************************
 �� �� ��  : AT_GetRateDisplayIndexForWcdma
 ��������  : ��ȡWCDMAģʽ���������ȼ���������ʾ���е�����
 �������  : pstDlRateCategory - UE��������
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 AT_GetRateDisplayIndexForWcdma(
    AT_DOWNLINK_RATE_CATEGORY_STRU     *pstDlRateCategory
);

#if(FEATURE_ON == FEATURE_LTE)
VOS_UINT32 AT_GetRateDisplayIndexForLTE(
    AT_DOWNLINK_RATE_CATEGORY_STRU     *pstDlRateCategory
);
#endif

VOS_VOID At_SendMsgFoAttr(
    VOS_UINT8                           ucIndex,
    MN_MSG_TS_DATA_INFO_STRU            *pstTsDataInfo
);

VOS_VOID AT_SetDefaultRatPrioList(
    MODEM_ID_ENUM_UINT16                enModemId,
    TAF_MMA_RAT_ORDER_STRU             *pstSysCfgRatOrder,
    VOS_UINT8                           ucUserSptLteFlag
);
/* Deleted by k902809 for Iteration 11, 2015-3-28, begin */

/* Deleted by k902809 for Iteration 11, Iteration 11 2015-3-28, end */
extern VOS_VOID  AT_QryParaAnQueryProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                           *pPara
);

extern VOS_VOID  AT_QryParaHomePlmnProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                           *pPara
);


extern VOS_UINT32 AT_SetFwavePara(
    VOS_UINT8 ucIndex
);

/* Deleted by k902809 for Iteration 11, 2015-3-30, begin */

/* Deleted by k902809 for Iteration 11, Iteration 11 2015-3-30, end */

VOS_UINT32 AT_RcvSimLockQryRsp(VOS_VOID *pMsg);


extern VOS_UINT32 OM_AcpuTraceMsgHook(VOS_VOID *pMsg);

VOS_VOID AT_ShowCccRst(
    NAS_CC_STATE_INFO_STRU              *pstCcState,
    VOS_UINT16                          *pusLength
);



VOS_UINT32 AT_RcvDrvAgentAuthVerQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentGodloadSetRsp(VOS_VOID *pMsg);



VOS_VOID AT_RcvCdurQryRsp(
    VOS_UINT8                           ucIndex,
    MN_CALL_EVENT_ENUM_U32              enEvent,
    MN_CALL_INFO_STRU                   *pstCallInfo
);

VOS_UINT32 AT_RcvDrvAgentAppdmverQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentDloadverQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentDloadInfoQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentFlashInfoQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentAuthorityVerQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentAuthorityIdQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentUsimWriteStubSetRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentPfverQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentHwnatQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentSdloadSetRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentImsiChgQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentInfoRbuSetRsp(VOS_VOID *pMsg);
#if(FEATURE_ON == FEATURE_LTE)
VOS_UINT32 AT_RcvDrvAgentInfoRrsSetRsp(VOS_VOID *pMsg);
#endif


VOS_UINT32 AT_RcvDrvAgentCpnnQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentCpnnTestRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentNvBackupSetRsp(VOS_VOID *pMsg);

VOS_VOID AT_EventReport(
    VOS_UINT32                          ulPid,
    NAS_OM_EVENT_ID_ENUM_UINT16         enEventId,
    VOS_VOID                           *pPara,
    VOS_UINT32                          ulLen
);

VOS_UINT32 AT_RcvDrvAgentCpuloadQryRsp(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvDrvAgentMfreelocksizeQryRsp(VOS_VOID *pMsg);


VOS_UINT32 AT_RcvDrvAgentMemInfoQryRsp(VOS_VOID *pMsg);
VOS_UINT32 At_TestTmodePara(VOS_UINT8 ucIndex);

VOS_UINT32 At_TestFdacPara(VOS_UINT8 ucIndex);

/* �˺����� AtCmdMsgProc.c �� */
VOS_UINT32 AT_SetGlobalFchan(VOS_UINT8 ucRatMode);

VOS_UINT32 AT_ProcTestError(VOS_UINT8 ucIndex);




extern VOS_UINT32 atSetTmodePara(VOS_UINT8 ucClientId, VOS_UINT32 usTmode);
extern VOS_UINT32 atSetTmodeParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetBandSWPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetBandSWParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryBandSWPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryBandSWParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFCHANSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFCHANSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFCHANSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFCHANSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFSEGMENTPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFSEGMENTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFSEGMENTPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFSEGMENTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFPOWSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFPOWSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFPOWSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFPOWSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFPASPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFPASParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFPASPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFPASParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFLNASPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFLNASParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFLNASPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFLNASParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFTXWAVEPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFTXWAVEParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFTXWAVEPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFTXWAVEParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFSTARTPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFSTARTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFFSTARTPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFFSTARTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFRSSISPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFRSSISParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFFCMTMSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFFCMTMSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFMAXPOWERPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFMAXPOWERParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFMAXPOWERPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFMAXPOWERParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFPAPOWERPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFPAPOWERParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFPAPOWERPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFPAPOWERParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFBLKPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFBLKParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFBLKPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFBLKParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetFIPSTARTPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFIPSTARTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

#if(FEATURE_ON == FEATURE_LTE)
extern VOS_UINT32 atSetFPDMSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFPDMSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFPDMSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFPDMSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFCHANPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFCHANParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atQryFCHANPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFCHANParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
#endif

extern VOS_UINT32 atSetVCTCXOPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetVCTCXOParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryVCTCXOPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryVCTCXOParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetNVRDLenPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetNVRDExPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetNVWRExPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFCALPDDCSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFCALPDDCSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetFCALPDDCSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFCALPDDCSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFPDPOWSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFPDPOWSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetFQPDDCRESPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFQPDDCRESParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 AT_SetNVWRPartPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetFTXONPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFTXONParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFTXONPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFTXONParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetFRXONPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFRXONParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFRXONPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFRXONParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetFLNAPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFLNAParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQryFLNAPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFLNAParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);


extern VOS_UINT32 atQryTselrfPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetTselrfPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetTselrfParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atQryFRSSIPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryFRSSIParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetBsnPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryBsnPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetGpioplPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryGpioplPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQryRSimPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySfeaturePara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFWAVEPara(VOS_UINT8 ucClientId);


/*�������۲�start */
extern VOS_UINT32 atSetSSYNCPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetSSYNCParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySSYNCPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySSYNCParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXBWPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetSTXBWParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXBWPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySTXBWParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXCHANPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetSTXCHANParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXCHANPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySTXCHANParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSSUBFRAMEPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetSSUBFRAMEParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySSUBFRAMEPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySSUBFRAMEParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSPARAParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySPARAParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSSEGNUMParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySSEGNUMParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXMODUSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXMODUSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXRBNUMSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXRBNUMSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXRBPOSSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXRBPOSSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXPOWSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXPOWSParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSTXCHANTYPESParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTXCHANTYPESParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSSEGLENParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySSEGLENParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSRXSETParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySRXSETParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSRXSUBFRAParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySRXSUBFRAParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySRXBLERParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSSTARTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySSTARTParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetSSTOPParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetSPARAPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySPARAPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSSEGNUMPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySSEGNUMPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSTXMODUSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySTXMODUSPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSTXRBNUMSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySTXRBNUMSPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSTXRBPOSSPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySTXRBPOSSPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSTXPOWSPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySTXPOWSPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSTXCHANTYPESPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySTXCHANTYPESPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSSEGLENPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySSEGLENPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSRXSETPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySRXSETPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSRXSUBFRAPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySRXSUBFRAPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySRXBLERPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSSTARTPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atQrySSTARTPara(VOS_UINT8 ucClientId);

extern VOS_UINT32 atSetSSTOPPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetSTCFGDPCHPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetSTCFGDPCHParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atSetFPOWPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetFPOWParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atQrySTRXBERPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQrySTRXBERParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);



extern VOS_UINT32 atQryDLoadVer(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryDLoadVerCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atQryDLoadInfo(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryDLoadInfoCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atQryAuthorityVer(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryAuthorityVerCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atQryAuthorityID(VOS_UINT8 ucClientId);
extern VOS_UINT32 atQryAuthorityIDCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetNVBackup(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetNVBackupCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetNVRestore(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetNVRestoreCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetGodLoad(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetGodLoadCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetReset(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetResetCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetNVRstSTTS(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetNVRstSTTSCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atSetTBATPara(VOS_UINT8 ucClientId);
extern VOS_UINT32 atSetTbatCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 atRdTbatCnf(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32  AT_SetLteSdloadPara(VOS_UINT8 ucClientId);


extern VOS_UINT32 AT_ParseSetAnyStrCmd(
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 AT_HandleAnyStrSetCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);


extern VOS_UINT32 AT_HandleFacAuthPubKeyCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 AT_HandleSimLockDataWriteCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 At_HandleApModemSpecialCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 AT_SetApRptSrvUrlPara(
    VOS_UINT8 ucIndex
);

extern VOS_UINT32 AT_SetApXmlInfoTypePara(
    VOS_UINT8 ucIndex
);

extern VOS_UINT32 AT_SetApXmlRptFlagPara(
    VOS_UINT8 ucIndex
);

extern VOS_UINT32 AT_QryApRptSrvUrlPara(
    VOS_UINT8 ucIndex
);

extern VOS_UINT32 AT_QryApXmlInfoTypePara(
    VOS_UINT8 ucIndex
);

extern VOS_UINT32 AT_QryApXmlRptFlagPara(
    VOS_UINT8 ucIndex
);
extern VOS_UINT32 AT_QryEqverPara(
    VOS_UINT8                           ucIndex
);

extern VOS_UINT32 AT_SetProdNamePara(
    VOS_UINT8 ucIndex
);

extern VOS_UINT32 AT_QryProdNamePara(
    VOS_UINT8                           ucIndex
);



extern VOS_UINT32 AT_QryCipherPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryLocinfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryAcInfoPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 At_SmsProc ( VOS_UINT8 ucIndex, VOS_UINT8 *pData, VOS_UINT16 usLen);
extern VOS_VOID AT_DiscardInvalidCharForSms(TAF_UINT8* pData, TAF_UINT16 *pusLen);

extern VOS_UINT32 At_TestCmlckPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_TestCgauthPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_TestCpasPara(VOS_UINT8 ucIndex);


VOS_UINT32 AT_TestSyscfg(VOS_UINT8 ucIndex);
VOS_UINT32 AT_TestSyscfgEx(VOS_UINT8 ucIndex);
VOS_VOID AT_ClacCmdProc(VOS_VOID);
VOS_VOID At_CovertMsInternalRxDivParaToUserSet2(
    VOS_UINT16                          usCurBandSwitch,
    VOS_UINT32                         *pulUserDivBandsLow,
    VOS_UINT32                         *pulUserDivBandsHigh
);
VOS_UINT32 AT_GetOperatorNameFromParam(
    VOS_UINT16                         *usOperNameLen,
    VOS_CHAR                           *pucOperName,
    VOS_UINT16                          usBufSize,
    VOS_UINT32                          ulFormatType
);


extern VOS_UINT32 At_RegisterBasicCmdTable(VOS_VOID);
extern VOS_UINT32 At_RegisterExCmdTable(VOS_VOID);
extern VOS_UINT32 At_RegisterDeviceCmdTable(VOS_VOID);
extern VOS_UINT32 At_RegisterDeviceCmdTLTable(VOS_VOID);
extern VOS_UINT32 At_RegisterExPrivateCmdTable(VOS_VOID);

extern VOS_VOID At_InitUsimStatus(VOS_VOID);

/* ����L4A��CNF��IND��Ϣ�������Ҷ�Ӧ�������д��� */
VOS_UINT32 at_L4aCnfProc(MsgBlock* pMsgBlockTmp);

/* AT����LTEװ��FTM�ظ���Ϣ��� */
VOS_UINT32 At_FtmEventMsgProc(VOS_VOID *pMsg);

VOS_UINT32 At_TestCgatt(VOS_UINT8 ucIndex);

VOS_UINT32 At_TestNdisAdd(VOS_UINT8 ucIndex);



TAF_UINT32 At_SetDialGprsPara(
    TAF_UINT8                           ucIndex,
    TAF_UINT8                           ucCid,
    TAF_GPRS_ACTIVE_TYPE_UINT8          enActiveType
);
VOS_UINT32 AT_SetFastDormPara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_QryFastDormPara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_QryAcpuMemInfoPara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_QryCcpuMemInfoPara(TAF_UINT8 ucIndex);

extern VOS_UINT32 AT_SetMemInfoPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 At_ReadCustomizeServiceNV(
    NAS_NVIM_CUSTOMIZE_SERVICE_STRU              *pstCustSrv,
    VOS_UINT16                          *pusValueInfo
);

extern VOS_UINT32 At_ReadGprsActiveTimerLenNV(
    VOS_UINT32                          *pulGprsActiveTimerLen,
    VOS_UINT16                          *pusValueInfo
);



extern VOS_UINT32 AT_QryNvResumePara(VOS_UINT8 ucIndex);

extern VOS_VOID AT_GetSpecificPort(
    VOS_UINT8                           ucPortType,
    VOS_UINT8                           aucRewindPortStyle[],
    VOS_UINT32                         *pulPortPos,
    VOS_UINT32                         *pulPortNum
);

extern VOS_UINT32 AT_OpenSpecificPort(VOS_UINT8 ucPort);
extern VOS_UINT32 AT_CloseSpecificPort(VOS_UINT8 ucPort);
VOS_UINT32 AT_QryNvBackupStatusPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryNandBadBlockPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryNandDevInfoPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryChipTempPara(VOS_UINT8 ucIndex);
VOS_VOID AT_SetMemStatusRspProc(
    VOS_UINT8                           ucIndex,
    MN_MSG_EVENT_INFO_STRU             *pstEvent
);
VOS_UINT32 AT_SetDnsQueryPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetMemStatusPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetApRptPortSelectPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryApRptPortSelectPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestApRptPortSelectPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetChdataPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryChdataPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestChdataPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_SetGpioPara (VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestGpioPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_SetUsbSwitchPara (VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryUsbSwitchPara (VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestUsbSwitchPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetHsspt(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryHsspt(VOS_UINT8 ucIndex);

extern TAF_UINT32 At_SetScidPara(TAF_UINT8 ucIndex);

extern VOS_UINT32 AT_SetRsfrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestRsfrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetRsfwPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestRsfwPara(VOS_UINT8 ucIndex);
extern VOS_VOID AT_SetRsfrVersionCnf(VOS_UINT8 ucIndex, VOS_UINT8* pucData, VOS_UINT32 ulLen);
extern VOS_UINT32 AT_SpyMsgProc(VOS_VOID* pstMsg);

extern TAF_UINT32 At_PortSwitchSndMsg (TAF_UINT32 ulSwitchMode);
extern VOS_UINT32 AT_QryAntState(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QrySARReduction(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetSARReduction(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetHukPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetFacAuthPubkeyPara(
    VOS_UINT8                           ucIndex,
    AT_FACAUTHPUBKEY_SET_REQ_STRU      *pstFacAuthPubKey
);
extern VOS_UINT32 AT_SetIdentifyStartPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetIdentifyEndPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetSimlockDataWritePara(
    VOS_UINT8                           ucIndex,
    AT_SIMLOCKDATAWRITE_SET_REQ_STRU   *pstSimlockDataWrite
);
extern VOS_UINT32 AT_QryPhoneSimlockInfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QrySimlockDataReadPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetPhonePhynumPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryPhonePhynumPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetPortCtrlTmpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryPortCtrlTmpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetPortAttribSetPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryPortAttribSetPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetOpwordParaForApModem (VOS_UINT8 ucIndex);
extern VOS_VOID AT_PhSendRestoreFactParmNoReset( VOS_VOID );
VOS_UINT32 AT_GetWcdmaDivBandStr(VOS_UINT8 *pucGsmBandstr);

VOS_UINT32 AT_SetApSimStPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_TestApSimStPara(VOS_UINT8 ucIndex);

#if(FEATURE_ON == FEATURE_UE_MODE_TDS)
extern VOS_UINT32 At_SetTdsScalibPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atSetSCALIBParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 At_QryTdsScalibPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atQrySCALIBParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 At_QryTdsScellinfoPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 atQryScellinfoParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 At_QryCmtm(VOS_UINT8 ucIndex);
extern VOS_UINT32 atQryCmtmCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern VOS_UINT32 AT_GetTdsFeatureInfo(AT_FEATURE_SUPPORT_ST * pstFeATure);
#endif
extern  VOS_UINT32 atSetTdsParaCnfProc(VOS_UINT16 ucClientId, VOS_VOID *pMsgBlock);
extern  VOS_UINT32 atQryTdsFRSSIParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern  VOS_UINT32 atQryTdsTSELRFParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern  VOS_UINT32 atQryTdsFCHANParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern  VOS_UINT32 atQryTdsFTXONParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);
extern  VOS_UINT32 atQryTdsFRXONParaCnfProc(VOS_UINT8 ucClientId, VOS_VOID *pMsgBlock);

extern VOS_UINT32 atLcacellCnfProc(VOS_VOID *pMsgBlock);
extern VOS_VOID atLcacellInd(VOS_VOID *pMsgBlock);


VOS_UINT32 AT_SetNvmEccNumPara(VOS_UINT8 ucIndex);
VOS_VOID AT_ConvertMccToNasType(
    VOS_UINT32                          ulMcc,
    VOS_UINT32                         *pulNasMcc
);

extern VOS_UINT32 AT_SetCposPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCposrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetXcposrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCgpsClockPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCposrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryXcposrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestXcposrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_TestCgpsClockPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_ProcXmlText ( TAF_UINT8 ucIndex, TAF_UINT8 *pData, TAF_UINT16 usLen);

VOS_UINT32 AT_SetGpsInfoPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetLogCfgPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetLogNvePara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryLogNvePara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetLogSavePara(VOS_UINT8 ucIndex);


/*****************************************************************************
 �� �� ��  : AT_QryCPsErrPara
 ��������  : ��ѯPS����д�����
 �������  : ucIndex --- �û�����
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 AT_QryCPsErrPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_HandleApSndApduCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
);

extern VOS_UINT32 AT_SetCISAPara(
    VOS_UINT8                           ucIndex,
    VOS_UINT32                          ulLengthValue,
    VOS_UINT8                          *pucCommand,
    VOS_UINT16                          usCommandLength);

VOS_UINT32 AT_HandleApSecCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen);
extern VOS_UINT32 AT_SetApSecPara(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pcCmdPara,
    VOS_UINT16                          usParaLen );
extern VOS_UINT32 AT_TestApSecPara( VOS_UINT8 ucIndex );

/*****************************************************************************
 �� �� ��  : AT_QryCmutPara
 ��������  : ^CMUT=<n> ��ѯ����״̬
 �������  : ucIndex --- �û�����
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 AT_SetCmutPara(VOS_UINT8 ucIndex);


/*****************************************************************************
 �� �� ��  : AT_QryCmutPara
 ��������  : ^CMUT? ��ѯ����״̬
 �������  : ucIndex --- �û�����
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 ���ú���  :
 ��������  :
*****************************************************************************/
VOS_UINT32 AT_QryCmutPara(VOS_UINT8 ucIndex);



VOS_UINT32 At_AbortCopsPara(
    VOS_UINT8                           ucIndex
);


VOS_UINT32 AT_SetSimlockUnlockPara( VOS_UINT8 ucIndex );

/*****************************************************************************
 �� �� ��  : AT_SetApdsPara
 ��������  : ^APDS=<dial_string>,<sub_string>,<I>,<G>,<call_type>�������������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32
*****************************************************************************/
VOS_UINT32 AT_SetApdsPara(VOS_UINT8 ucIndex);

/*****************************************************************************
 �� �� ��  : AT_SetClprPara
 ��������  : ^CLPR=<call_id>�������������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32
*****************************************************************************/
VOS_UINT32 AT_SetClprPara(VOS_UINT8 ucIndex);

/*****************************************************************************
 �� �� ��  : AT_TestClprPara
 ��������  : �������������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32
*****************************************************************************/
VOS_UINT32 AT_TestClprPara(VOS_UINT8 ucIndex);

/*****************************************************************************
 �� �� ��  : AT_QryCCsErrPara
 ��������  : ^CCSERR�������������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32
*****************************************************************************/
VOS_UINT32 AT_QryCCsErrPara(VOS_UINT8 ucIndex);


VOS_UINT32 At_SetCerssiPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_QryCerssiPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_SetCnmrPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_QryCecellidPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryCnmrPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryCellIdPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetWlthresholdcfgPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 At_SetLWThresholdCfgPara(VOS_UINT8 ucIndex);



VOS_UINT32 AT_SetCLteRoamAllowPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryCLteRoamAllowPara(VOS_UINT8 ucIndex);


VOS_UINT32 At_SetSwverPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_RcvDrvAgentSwverSetCnf(VOS_VOID *pMsg);
VOS_UINT32 AT_SetCbgPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_QryCbgPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetCopnPara(VOS_UINT8 ucIndex);


VOS_VOID At_RcvMnCallSetCssnCnf(MN_AT_IND_EVT_STRU *pstData);
VOS_UINT32 AT_FillSsBsService(
    TAF_SS_ERASESS_REQ_STRU            *pstSSPara,
    AT_PARSE_PARA_TYPE_STRU            *pstAtPara
);

VOS_UINT32 AT_FillSsNoRepCondTime(
    VOS_UINT8                           ucSsCode,
    AT_PARSE_PARA_TYPE_STRU            *pstAtPara,
    TAF_SS_REGISTERSS_REQ_STRU         *pstSSPara
);


VOS_VOID At_QryMmPlmnInfoRspProc(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                           OpId,
    VOS_VOID                            *pPara
);
VOS_UINT32 At_QryMmPlmnInfoPara(VOS_UINT8 ucIndex);

/* Added by c00318887 for AT&T phaseII, 2015-3-12, begin */
VOS_UINT32 At_QryEonsUcs2Para(VOS_UINT8 ucIndex);
/* Added by c00318887 for AT&T phaseII, 2015-3-12, end */

/*****************************************************************************
 �� �� ��  : At_QryPlmnPara
 ��������  : ��ѯPLMN��mcc mnc
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : AT_ERROR��AT_WAIT_ASYNC_RETURN

*****************************************************************************/
VOS_UINT32 At_QryPlmnPara(VOS_UINT8 ucIndex);

/*****************************************************************************
 �� �� ��  : At_QryXlemaPara
 ��������  : ��ѯ^XLEMA�Ĵ���
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : AT_ERROR��AT_OK
*****************************************************************************/
VOS_UINT32 At_QryXlemaPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_SetBodySarOnPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryBodySarOnPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_GetGsmBandCapa(VOS_UINT32 *pulGBand);
VOS_UINT32 AT_SndMtaBodySarPara(
    VOS_UINT8                           ucIndex,
    MTA_BODY_SAR_STATE_ENUM_UINT16      enBodySarState,
    MTA_BODY_SAR_PARA_STRU             *pstBodySarPara);
VOS_UINT32 AT_SetBodySarWcdmaPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryBodySarWcdmaPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_TestBodySarWcdmaPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetBodySarGsmPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryBodySarGsmPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_TestBodySarGsmPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_CheckHsicUser(VOS_UINT8 ucIndex);

VOS_INT AT_CCpuResetCallback(
    DRV_RESET_CB_MOMENT_E               eparam,
    VOS_INT                             iUserData
);
VOS_INT AT_HifiResetCallback(
    DRV_RESET_CB_MOMENT_E               eparam,
    VOS_INT                             iUserData
);

VOS_UINT32 AT_RcvTempprtStatusInd(VOS_VOID *pMsg);


/*****************************************************************************
 �� �� ��  : At_QryIMEIVerifyPara
 ��������  : ��ѯIMEI��ȫУ��Ľ��
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : AT_ERROR��AT_WAIT_ASYNC_RETURN

*****************************************************************************/
VOS_UINT32 At_QryIMEIVerifyPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetNCellMonitorPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryNCellMonitorPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryUserSrvStatePara(VOS_UINT8 ucIndex);


VOS_UINT32 At_SetSIMSlotPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_QrySIMSlotPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetSimInsertPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetModemLoopPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetReleaseRrc(VOS_UINT8 ucIndex);

VOS_UINT32 AT_String2Hex( VOS_UINT8 *nptr,VOS_UINT16 usLen, VOS_UINT32 *pRtn);


VOS_UINT32 AT_SetRefclkfreqPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_QryRefclkfreqPara(VOS_UINT8 ucIndex);


/* Added by d0212987 for OM output log , 2013-6-4, begin */
VOS_UINT32 At_SetPullomlogrrcPara(VOS_UINT8 ucIndex);
/* Added by d0212987 for OM output log , 2013-6-4, end*/
/* Added by d0212987 for read die id and chip id, 2013-6-4, begin */
VOS_UINT32 At_SetDieSNPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_SetChipSNPara(VOS_UINT8 ucIndex);
/* Added by d0212987 for read die id and chip id, 2013-6-4, end */
VOS_UINT32 At_QryHandleDect(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetHandleDect(VOS_UINT8 ucIndex);

/*vSIM Project Begin*/
extern VOS_UINT32 AT_RcvDrvAgentHvpdhSetCnf(VOS_VOID *pMsg);
extern unsigned int AtBase64Decode(const void* pcode,const unsigned int code_size,void* out_pdata,
                                const unsigned int data_size,unsigned int* out_pwrited_data_size);
extern TAF_VOID At_PIHIndProc(TAF_UINT8 ucIndex, SI_PIH_EVENT_INFO_STRU *pEvent);
/*vSIM Project Begin*/



extern VOS_UINT32 AT_SetUserCfgOPlmnPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryUserCfgOPlmnPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_RcvNvManufactureExtSetCnf(VOS_VOID *pMsg);

VOS_UINT32 AT_TestNetScan( VOS_UINT8 ucIndex );


#if (FEATURE_ON == FEATURE_AT_HSUART)
VOS_VOID AT_UpdateUartCfgNV(VOS_VOID);
VOS_UINT32 AT_SetIprPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryIprPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetIcfPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryIcfPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetIfcPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryIfcPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetOPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_SetSwitchUart(VOS_UINT8 ucIndex);
#endif

VOS_UINT32 AT_SetEcidPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_QryClccPara(VOS_UINT8 ucIndex);

#if (FEATURE_ON == FEATURE_IMS)
/*****************************************************************************
 �� �� ��  : AT_QryCiregPara
 ��������  : +CIREG?��ѯ���������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32
*****************************************************************************/
VOS_UINT32 AT_QryCiregPara(VOS_UINT8 ucIndex);


/*****************************************************************************
 �� �� ��  : AT_QryCirepPara
 ��������  : +CIREP?��ѯ���������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32
*****************************************************************************/
VOS_UINT32 AT_QryCirepPara(VOS_UINT8 ucIndex);

/*****************************************************************************
 �� �� ��  : AT_SetCiregPara
 ��������  : +CIREG=<n>�������������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32

*****************************************************************************/
TAF_UINT32 AT_SetCiregPara(TAF_UINT8 ucIndex);

/*****************************************************************************
 �� �� ��  : AT_SetCirepPara
 ��������  : +CIREP=<reporting>�������������
 �������  : VOS_UINT8 ucIndex
 �������  : ��
 �� �� ֵ  : VOS_UINT32

*****************************************************************************/
TAF_UINT32 AT_SetCirepPara(TAF_UINT8 ucIndex);


VOS_UINT32 AT_SetVolteimpuPara(VOS_UINT8 ucIndex);

TAF_UINT32 AT_SetCacmimsPara(TAF_UINT8 ucIndex);

VOS_UINT32 AT_SetCcwaiPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetUiccAuthPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetURSMPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetKsNafAuthPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetCallModifyInitPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetCallModifyAnsPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_SetEconfDialPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryClccEconfInfo(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryEconfErrPara(VOS_UINT8 ucIndex);

/* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, Begin */
extern VOS_UINT32 AT_SetImsSwitchPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryImsSwitchPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCevdpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCevdpPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_InputValueTransToVoiceDomain(
    VOS_UINT32                          ulValue,
    TAF_MMA_VOICE_DOMAIN_ENUM_UINT32   *penVoiceDomain
);
/* Added by zwx247453 for VOLTE SWITCH, 2015-02-02, End */

#endif

VOS_UINT32 At_SetChldExPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 At_SetAntSwitchPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryAntSwitchPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_RcvDrvAgentAntSwitchSetCnf(VOS_VOID *pstData);
extern VOS_UINT32 AT_RcvDrvAgentAntSwitchQryCnf(VOS_VOID *pstData);



extern VOS_UINT32 AT_QryModemStatusPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetModemStatusPara( VOS_UINT8 ucIndex );
extern VOS_UINT32 AT_SetRATCombinePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryRATCombinePara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_QryMipiClkValue(VOS_UINT8 ucIndex);

#if (FEATURE_ON == FEATURE_DSDS)
extern VOS_UINT32 At_SetPsProtectModePara (VOS_UINT8 ucIndex);
#endif
extern VOS_UINT32 At_SetPhyInitPara (VOS_UINT8 ucIndex);

TAF_MMA_SERVICE_DOMAIN_ENUM_UINT8 At_ConvertDetachTypeToServiceDomain(
    VOS_UINT32                          ulCgcattMode
);

/* Added by h00313353 for Iteration 13, 2015-4-16, begin */
TAF_MMA_ATTACH_TYPE_ENUM_UINT8 At_ConvertCgcattModeToAttachType(
    VOS_UINT32                          ulCgcattMode
);
/* Added by h00313353 for Iteration 13, 2015-4-16, end */

extern VOS_UINT32 AT_FillCalledNumPara(
    VOS_UINT8                          *pucAtPara,
    VOS_UINT16                          usLen,
    MN_CALL_CALLED_NUM_STRU            *pstCalledNum
);

extern TAF_UINT32 At_AsciiString2HexSimple(TAF_UINT8 *pTextStr,TAF_UINT8 *pucSrc,TAF_UINT16 usSrcLen);

extern VOS_UINT32 AT_QryCclkPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCclkPara(VOS_UINT8 ucIndex);

#if (FEATURE_ON == FEATURE_HUAWEI_VP)
VOS_UINT32 AT_SetVoicePreferPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryVoicePreferPara(VOS_UINT8 ucIndex);
#endif

extern TAF_UINT32 At_QryCardTypePara(TAF_UINT8 ucIndex);
extern VOS_UINT32 AT_SetCcmgsPara(VOS_UINT8 ucIndex, VOS_UINT32 ulLengthValue, VOS_UINT8 *pucCommand, VOS_UINT16 usCommandLength);

extern VOS_UINT32 AT_SetCcmgwPara(VOS_UINT8 ucIndex, VOS_UINT32 ulLengthValue, VOS_UINT32 ulStatValue, VOS_UINT8 *pucCommand, VOS_UINT16 usCommandLength);

extern VOS_UINT32 AT_SetCcmgdPara(VOS_UINT8 ucIndex);

extern VOS_VOID At_XsmsIndProc(VOS_UINT8 ucIndex, TAF_XSMS_APP_MSG_TYPE_ENUM_UINT32  enEventType, TAF_XSMS_APP_AT_EVENT_INFO_STRU *pstEvent);

extern VOS_VOID At_XsmsCnfProc(VOS_UINT8 ucIndex, TAF_XSMS_APP_MSG_TYPE_ENUM_UINT32 enEventType, TAF_XSMS_APP_AT_EVENT_INFO_STRU *pstEvent);

extern VOS_VOID AT_ProcXsmsMsg(TAF_XSMS_APP_AT_CNF_STRU *pstMsg);

VOS_VOID AT_ProcXpdsMsg(AT_XPDS_MSG_STRU *pstMsg);

extern VOS_UINT32 AT_SetCdmaMemStatusPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_HandleApXsmsSndCmd(VOS_UINT8 ucIndex, VOS_UINT8 *pucData, VOS_UINT16 usLen);

extern VOS_UINT32 AT_HandleApXsmsWriteCmd(VOS_UINT8 ucIndex, VOS_UINT8 *pucData, VOS_UINT16 usLen);

extern VOS_UINT32 AT_SetCrmPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetCqosPriPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryCLocInfo(VOS_UINT8 ucIndex);


/* Added by f279542 for CDMA 1X Iteration 4, 2014-11-12, begin */
extern VOS_UINT32 AT_SetCBurstDTMFPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetCfshPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_CheckCfshNumber(
    VOS_UINT8                          *pucAtPara,
    VOS_UINT16                          usLen
);
/* Added by f279542 for CDMA 1X Iteration 4, 2014-11-12, end */

/* Added by y00307564 for CDMA 1X Iteration 6, 2014-12-29, begin */
extern VOS_UINT32 AT_CheckCFreqLockEnablePara(VOS_VOID);
extern VOS_UINT32 AT_SetCFreqLockPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCFreqLockInfo(VOS_UINT8 ucIndex);
/* Added by y00307564 for CDMA 1X Iteration 6, 2014-12-29, end */

/* Added by m00312079 for CDMA 1X Iteration 6 2014-12-25 begin */
extern VOS_UINT32 AT_SetCdmaCsqPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCdmaCsqPara(VOS_UINT8 ucIndex);
/* Added by m00312079 for CDMA 1X Iteration 6 2014-12-25 end */

VOS_UINT32 At_SetCustomDial(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetCdmaModemSwitch(VOS_UINT8 ucIndex);

/*Added by w00316404 for TTY MODE, 2015-02-07, begin*/
extern VOS_UINT32 AT_SetTTYModePara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryTTYModePara(VOS_UINT8 ucIndex);
/*Added by w00316404 for TTY MODE, 2015-02-07, end*/

extern VOS_UINT32 AT_SetCtaPara(VOS_UINT8 ucIndex);
extern VOS_UINT32 AT_QryCtaPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_QryCgmtuPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_SetFemCtrl(VOS_UINT8 ucIndex);

extern TAF_UINT32 At_AsciiNum2HexString(TAF_UINT8 *pucSrc, TAF_UINT16 *pusSrcLen);

/*Added by z00306637 for RATRFSWITCH, 2015-01-04, begin*/
extern VOS_UINT32 At_SetRatRfSwitch(VOS_UINT8 ucIndex);
extern VOS_UINT32 At_QryRatRfSwitch(VOS_UINT8 ucIndex);
/*Added by z00306637 for RATRFSWITCH, 2015-01-04, end*/

/* Added by z00316370 for UTS 2015-5-16 begin */
extern VOS_UINT32 AT_Set1xChanPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_Qry1xChanPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryProRevInUse(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryCasState(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryProGetEsn(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryProGetMeid(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_QryHighVer(VOS_UINT8 ucIndex);
/* Added by z00316370 for UTS 2015-5-16 end */

/* Added by lwx277467 for Transmission Mode, 2015-7-30, begin */
extern VOS_UINT32 AT_QryTransModePara(VOS_UINT8 ucIndex);
/* Added by lwx277467 for Transmission Mode, 2015-7-30, end */
/* Added by wx270776 for OM�ں�, 2015-7-25, begin */
extern VOS_VOID DIAG_LogShowToFile(VOS_BOOL bIsSendMsg);
/* Added by wx270776 for OM�ں�, 2015-7-25, end */
extern VOS_UINT32 AT_QryEmcCallBack( VOS_UINT8 ucIndex  );

extern VOS_UINT32 AT_QryCdmaDormTimerVal(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetCdmaDormantTimer(VOS_UINT8 ucIndex);

/* Added by lwx277467 for UE Mode, 2015-9-7, begin */
extern VOS_UINT32 AT_QryUECenterPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_SetUECenterPara(VOS_UINT8 ucIndex);

extern VOS_UINT32 AT_TestUECenterPara(VOS_UINT8 ucIndex);
/* Added by lwx277467 for UE Mode, 2015-9-7, end */

#if ((TAF_OS_VER == TAF_WIN32) || (TAF_OS_VER == TAF_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MapsTemplate.h*/
