

/*****************************************************************************
   1 头文件包含
*****************************************************************************/
#ifdef  __cplusplus
  #if  __cplusplus
  extern "C"{
  #endif
#endif

#include "MM_Ext.h"
#include "NasMmEcall.h"
#include "NasMmSndOm.h"
#include "MmCcInterface.h"
#include "SmsMmInterface.h"
#include "MmSsInterface.h"

/*****************************************************************************
    协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_NAS_MM_ECALL_C

#if (FEATURE_ON == FEATURE_ECALL)
/*****************************************************************************
   2 全局变量定义
*****************************************************************************/


/*****************************************************************************
   3 函数实现
*****************************************************************************/

NAS_MM_ECALL_INFO_STRU *NAS_MM_GetEcallInfoAddr(VOS_VOID)
{
    return &(g_MmGlobalInfo.stEcallInfo);
}


VOS_VOID NAS_MM_SetT3242ExpiredFlg(VOS_UINT8 ucT3242ExpiredFlg)
{
    NAS_MM_GetEcallInfoAddr()->ucT3242ExpiredFlg = ucT3242ExpiredFlg;
}


VOS_UINT8 NAS_MM_GetT3242ExpiredFlg(VOS_VOID)
{
    return (NAS_MM_GetEcallInfoAddr()->ucT3242ExpiredFlg);
}


VOS_VOID NAS_MM_SetT3243ExpiredFlg(VOS_UINT8 ucT3243ExpiredFlg)
{
    NAS_MM_GetEcallInfoAddr()->ucT3243ExpiredFlg = ucT3243ExpiredFlg;
}


VOS_UINT8 NAS_MM_GetT3243ExpiredFlg(VOS_VOID)
{
    return (NAS_MM_GetEcallInfoAddr()->ucT3243ExpiredFlg);
}


VOS_UINT8 NAS_MM_GetT3242StartNeededFlg(VOS_VOID)
{
    return (NAS_MM_GetEcallInfoAddr()->ucT3242StartNeededFlg);
}


VOS_VOID NAS_MM_SetT3242StartNeededFlg(VOS_UINT8 ucT3242StartNeededFlg)
{
    NAS_MM_GetEcallInfoAddr()->ucT3242StartNeededFlg = ucT3242StartNeededFlg;
}


VOS_UINT8 NAS_MM_GetT3243StartNeededFlg(VOS_VOID)
{
    return (NAS_MM_GetEcallInfoAddr()->ucT3243StartNeededFlg);
}


VOS_VOID NAS_MM_SetT3243StartNeededFlg(VOS_UINT8 ucT3243StartNeededFlg)
{
    NAS_MM_GetEcallInfoAddr()->ucT3243StartNeededFlg = ucT3243StartNeededFlg;
}


VOS_VOID NAS_MM_RcvT3242Expired_MmIdleNoCellAvailable(VOS_VOID *pRcvMsg)
{
    NAS_MM_SetT3242ExpiredFlg(VOS_TRUE);
}


VOS_VOID NAS_MM_RcvT3242Expired_MmIdleNormalService(VOS_VOID *pRcvMsg)
{
    /* 调用eCall inactivity 流程 */
    NAS_MM_PerformECallInactivity();
}
VOS_VOID NAS_MM_RcvT3243Expired_MmIdleNoCellAvailable(VOS_VOID *pRcvMsg)
{
    NAS_MM_SetT3243ExpiredFlg(VOS_TRUE);
}


VOS_VOID NAS_MM_RcvT3243Expired_MmIdleNormalService(VOS_VOID *pRcvMsg)
{
    /* 调用eCall inactivity 流程 */
    NAS_MM_PerformECallInactivity();
}
VOS_VOID NAS_MM_StopAllTimersRelatedToEcall(VOS_VOID)
{
    Mm_TimerStop(MM_TIMER_T3242);

    Mm_TimerStop(MM_TIMER_T3243);
}


VOS_VOID NAS_MM_ClearAllEcallTimersExpiredFlg(VOS_VOID)
{
    NAS_MM_SetT3242ExpiredFlg(VOS_FALSE);

    NAS_MM_SetT3243ExpiredFlg(VOS_FALSE);
}


VOS_VOID NAS_MM_ClearAllEcallTimersStartNeededFlg(VOS_VOID)
{
    NAS_MM_SetT3242StartNeededFlg(VOS_FALSE);

    NAS_MM_SetT3243StartNeededFlg(VOS_FALSE);
}


VOS_VOID NAS_MM_RcvMmcMmSysInfo_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    if (VOS_TRUE == NAS_MM_IsCsForbidden())
    {
        NAS_MM_SndMmcForbidenRslt();
    }
    else
    {
        /* 通知MMC当前CS的注册结果 */
        NAS_MM_SndMmcCsRegResultInd(MM_MMC_LU_PROC_FALSE,
                                    MM_MMC_LU_RESULT_FAILURE,
                                    NAS_MML_REG_FAIL_CAUSE_ECALL_INACTIVE);
    }

    NAS_MM_ProcBufferMsg_MmIdleECallInactive();
    
    return;
}
VOS_VOID NAS_MM_RcvMmcMmAttachReq_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    MMCMM_ATTACH_REQ_STRU              *pstAttchReq             = VOS_NULL_PTR;

    pstAttchReq = (MMCMM_ATTACH_REQ_STRU*)pRcvMsg;

    if (MM_TRUE == Mm_RcvMmcAttachReq(pstAttchReq))
    {
        /* 回复MMCMM_ATTACH_CNF的操作,清除等待ATTACH结果标志位 */
        if (MM_WAIT_CS_ATTACH == (g_MmGlobalInfo.stAttachInfo.enAttachType
                                & MM_WAIT_CS_ATTACH))
        {
            NAS_MM_SndMmcAttachCnf();
        }
        g_MmGlobalInfo.stAttachInfo.enAttachType = MM_WAIT_NULL_ATTACH;
    }

    return;
}
VOS_VOID NAS_MM_ProcMmcMmDetachReq_MmIdleECallInactive( VOS_VOID )
{
    /* 判断等待标志是否存在，如果存在则发送MMCMM_DETACH CNF */
    if (MM_WAIT_CS_DETACH== (g_MmGlobalInfo.stDetachInfo.enDetachType
                 & MM_WAIT_CS_DETACH))
    {
        NAS_MM_SndMmcDetachCnf(MM_DETACHED);
        /* 清除等待标志 */
        g_MmGlobalInfo.stDetachInfo.enDetachType = MM_WAIT_NULL_DETACH;
    }

    NAS_MM_SndMmcCsRegResultInd(MM_MMC_LU_PROC_FALSE,
                                MM_MMC_LU_RESULT_FAILURE,
                                NAS_MML_REG_FAIL_CAUSE_MS_CFG_DOMAIN_NOT_SUPPORT);

    return;
}



VOS_VOID NAS_MM_RcvMmcMmPlmnSrchInit_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    g_MmGlobalInfo.ucPreState = g_MmGlobalInfo.ucState;
    g_MmGlobalInfo.ucNotCampONPreState = g_MmGlobalInfo.ucState;
    Mm_ComSetMmState(MM_IDLE_PLMN_SEARCH);

    return;
}



VOS_VOID NAS_MM_RcvMmcMmCoverageLostInd_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    g_MmGlobalInfo.ucSysInfoFlg = MM_FALSE;

    g_MmGlobalInfo.ucPreState = g_MmGlobalInfo.ucState;
    g_MmGlobalInfo.ucMmServiceState = MM_NO_SERVICE;

    /* 保存出服务区前的状态,在搜网成功后用于判断LAI是否改变 */
    g_MmGlobalInfo.ucNotCampONPreState = g_MmGlobalInfo.ucState;

    Mm_ComSetMmState(MM_IDLE_NO_CELL_AVAILABLE);

    g_MmSubLyrShare.MmShare.ucPagingPlmnSrch = MM_PAGING_PLMNSRCH_FALSE;

    return;
}
VOS_VOID NAS_MM_RcvMmcMmPowerOffReq_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    if (MM_TRUE == Mm_RcvMmcPowerOffReq(pRcvMsg))
    {
        /* 向MMC发送MMCMM_POWER_OFF_CNF */
        Mm_SndMmcPowerOffCnf();
        
        Mm_ComSetMmState(MM_STATE_NULL);
    }

    return;
}
VOS_VOID NAS_MM_RcvMmcMmWAcInfoChangeInd_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    MMCMM_W_AC_INFO_CHANGE_IND_STRU  *pstAcInfoChangeInd = VOS_NULL_PTR;

    pstAcInfoChangeInd = (MMCMM_W_AC_INFO_CHANGE_IND_STRU*)pRcvMsg;

    /* 当前小区变为注册受限，不需要迁移MM状态 */
    if (NAS_MML_RESTRICTION_UNBAR_TO_BAR == pstAcInfoChangeInd->enCsRestrictRegisterChange)
    {
        g_MmGlobalInfo.ucMmServiceState = NAS_MM_GetLauUptNeededCsSrvStatus();
    }

    return;
}
VOS_VOID NAS_MM_RcvSmsEstReq_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    if (MM_TRUE == Mm_RcvSmsEstReq(pRcvMsg))
    {
        /* 回复SMS失败,不需要重拨 */    
        Mm_SndSmsRelInd(g_MmSmsEstReq.ulTi, NAS_MMCM_REL_CAUSE_MM_INTER_ERR_ECALL_INACTIVE); 
    }

    return;
}
VOS_VOID NAS_MM_RcvSsEstReq_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    if (MM_TRUE == Mm_RcvSsEstReq(pRcvMsg))
    {
        /* 回复SS失败,不需要重拨 */
        Mm_SndSsRelInd(g_MmSsEstReq.ulTi, NAS_MMCM_REL_CAUSE_MM_INTER_ERR_ECALL_INACTIVE);
    }

    return;
}
VOS_VOID NAS_MM_RcvCcEstReq_MmIdleECallInactive(
    VOS_VOID                           *pRcvMsg
)
{
    VOS_UINT32                          ulCsForbiddenFlg;
    
    if (MM_FALSE == Mm_RcvCcEstReq(pRcvMsg))
    {
        return;
    }

    if ((MM_CONST_NUM_8  > g_MmCcEstReq.ulTransactionId)
     || (MM_CONST_NUM_14 < g_MmCcEstReq.ulTransactionId))
    {
        /* TI不合法,直接回复失败 */
        Mm_SndCcRelInd(g_MmCcEstReq.ulTransactionId,
                           NAS_MMCM_REL_CAUSE_MM_INTER_ERR_TI_INVALID);
        return;
    }

#if (FEATURE_ON == FEATURE_LTE)
    /* 当前在LTE下,直接回复失败,异常保护,实际LTE下不会进入这个状态(重选除外) */
    if (NAS_MML_NET_RAT_TYPE_LTE == NAS_MML_GetCurrNetRatType())
    {
        Mm_SndCcRelInd(g_MmCcEstReq.ulTransactionId,
                           NAS_MMCM_REL_CAUSE_MM_INTER_ERR_UE_INVALID_STATE);
        return;
    }
#endif

    ulCsForbiddenFlg = NAS_MM_IsCsForbidden();

    /* 防止离开ecall inactive时其他状态设置此标记为VOS_FALSE */
    NAS_MML_SetCsAttachAllowFlg(VOS_TRUE);

    /* 紧急呼叫 */
    if (MMCC_EMERGENCY_CALL == g_MmCcEstReq.ulCallType)
    {
        /* CS被bar或CS被forbidden不允许注册,直接发起CS的紧急业务 */
        if (VOS_TRUE == NAS_MML_GetCsRestrictRegisterFlg())
        {  
            /* 记录收到建立请求时的状态 */
            g_MmGlobalInfo.ucStaOfRcvXXEstReq = MM_IDLE_LOCATION_UPDATE_NEEDED;
    
            NAS_MM_EstMmConnection(MM_CONN_CTRL_CC);

            return;
        }

         /* CS被bar或CS被forbidden不允许注册,直接发起CS的紧急业务 */
        if (VOS_TRUE == ulCsForbiddenFlg)
        {  
            /* 记录收到建立请求时的状态 */
            g_MmGlobalInfo.ucStaOfRcvXXEstReq = MM_IDLE_LIMITED_SERVICE;
    
            NAS_MM_EstMmConnection(MM_CONN_CTRL_CC);

            return;
        }
    }
    else
    {
        /* CS正常业务被bar或CS被forbidden则直接回复呼叫失败 */
        if ((VOS_TRUE == NAS_MML_GetCsRestrictNormalServiceFlg())
         || (VOS_TRUE == ulCsForbiddenFlg))
        {  
            Mm_SndCcRelInd(g_MmCcEstReq.ulTransactionId,
                            NAS_MMCM_REL_CAUSE_MM_INTER_ERR_CS_ACCESS_BAR);
            return;
        }
    }

    /* 记录收到建立请求时的状态 */
    g_MmGlobalInfo.ucStaOfRcvXXEstReq = g_MmGlobalInfo.ucState;

    /* 先缓存呼叫请求 */
    NAS_MM_UpdateConnCtrlInfo(MM_CONN_CTRL_CC);

    /* 发起LAU */
    g_MmGlobalInfo.LuInfo.ucLuType = MM_IE_LUT_NORMAL_LU;
    g_MmGlobalInfo.LuInfo.ucLuAttmptCnt = 0;
    
    Mm_ComLuOnly();

    return;
}




VOS_VOID NAS_MM_PerformECallInactivity( VOS_VOID )
{
    MM_MSG_IMSI_DETACH_IND_STRU         stDetachIndMsg;
    VOS_UINT8                           ucRestrictRegister;
    VOS_UINT32                          ulCsForbFlg;

    PS_MEM_SET(&stDetachIndMsg, 0x0, sizeof(stDetachIndMsg));
    
    ucRestrictRegister = NAS_MML_GetCsRestrictRegisterFlg();
    ulCsForbFlg        = NAS_MM_IsCsForbidden();
    
    /* 如果CS的更新状态为U1且CS已经attach且不限制CS的注册且CS非forbidden,系统消息指示需要attach,则先进行CS的detach流程 */
    if ((NAS_MML_LOCATION_UPDATE_STATUS_UPDATED == NAS_MML_GetCsUpdateStatus())
     && (VOS_FALSE                              == ucRestrictRegister)
     && (VOS_FALSE                              == ulCsForbFlg)) 
    {
        if ((MM_STATUS_ATTACHED == g_MmSubLyrShare.MmShare.ucCsAttachState)
         && (MM_ATT_NEED        == g_MmGlobalInfo.ucAttFlg))
        {
            g_MmGlobalInfo.ucDetachType = MM_DETACH_CS_NORMAL;

            NAS_MM_FillMobileID(&(stDetachIndMsg.MmIeMobileId.MobileID));

            g_MmGlobalInfo.ucPreState = g_MmGlobalInfo.ucState;
            Mm_ComSetMmState(WAIT_FOR_RR_CONNECTION_IMSI_DETACH);

            Mm_ComMsgImsiDetachIniSndOfEstReq(&stDetachIndMsg);
            Mm_TimerStart(MM_TIMER_PROTECT_SIGNALLING);
            
            NAS_MM_SndGmmCsConnectInd(MMGMM_CS_CONNECT_ESTING);


            /* 更新MM的服务状态为MM_DETACHED */
            g_MmGlobalInfo.ucMmServiceState = MM_DETACHED;

            return;
        }
    }

    /* 更新MM的服务状态为MM_DETACHED */
    g_MmGlobalInfo.ucMmServiceState = MM_DETACHED;

    /* 通知RRC和SMS模块attach状态发生变化 */
    Mm_ComNasInfoSav(MM_STATUS_DETACHED, NAS_MML_GetSimCsSecurityCksn());

    /* 更新MM状态为mm_ecall_inactive状态 */
    Mm_ComSetMmState(MM_IDLE_ECALL_INACTIVE);

    /* 停止MM运行的所有定时器 */    
    Mm_TimerStop(MM_TIMER_STOP_ALL);

    /* 清除attempt counter以及下面的LU相关值,因为有可能前面LAU尝试失败 */
    g_MmGlobalInfo.LuInfo.ucLuAttmptCnt          = 0;
    g_MmGlobalInfo.LuInfo.ucT3212ExpiredFlg      = MM_FALSE;    
    g_MmGlobalInfo.LuInfo.ucRetryFlg             = MM_FALSE;
    g_MmGlobalInfo.LuInfo.ucT3213AttmptCnt       = 0;
    g_MmGlobalInfo.LuInfo.ucImmAccRejLuAttmptCnt = 0;
    
    /* 清除T3242和T3243超时标记 */
    NAS_MM_ClearAllEcallTimersExpiredFlg();

    /* 更新CS的更新状态为not updatd */
    NAS_MML_SetCsUpdateStatus(NAS_MML_LOCATION_UPDATE_STATUS_NOT_UPDATED);

    /* 写usim卡文件(U值按照not update写入) */    
    NAS_MM_DelLaiTmsiCK();

    NAS_MML_SetCsUpdateStatus(NAS_MML_LOCATION_UPDATE_DISABLED);

    return;
}


VOS_VOID NAS_MM_RecordEcallTimerStartNeededFlag(VOS_VOID)
{
    /* 非eCall only模式，不需要启动T3243/T3243 */
    if (NAS_MML_ECALL_ONLY != NAS_MML_GetCallMode())
    {
        return;
    }
    
    /*如果T3242或T3243在运行，先停止该定时器 */
    if (MM_TIMER_RUNNING == NAS_MM_QryTimerStatus(MM_TIMER_T3242))
    {
        Mm_TimerStop(MM_TIMER_T3242);
    }

    if (MM_TIMER_RUNNING == NAS_MM_QryTimerStatus(MM_TIMER_T3243))
    {
        Mm_TimerStop(MM_TIMER_T3243);
    }
    
    if (MMCC_EMERGENCY_CALL == g_MmCcEstReq.ulCallType)
    {
        /* 如果为紧急呼叫, 设置启动T3242标识 */
        NAS_MM_SetT3242StartNeededFlg(VOS_TRUE);
        
        NAS_MM_SetT3243ExpiredFlg(VOS_FALSE);
    }
    else
    {
        /* 如果为normal呼叫, 设置启动T3243标识 */
        NAS_MM_SetT3243StartNeededFlg(VOS_TRUE);
        
        NAS_MM_SetT3242ExpiredFlg(VOS_FALSE);
    }
}


VOS_VOID NAS_MM_ClearEcallTimerInfo(VOS_VOID)
{
    /* 停止所有eCall相关定时器 */
    NAS_MM_StopAllTimersRelatedToEcall();

    /* 清除eCall T3242/T3243定时器启动标识 */
    NAS_MM_ClearAllEcallTimersStartNeededFlg();

    /* 清除eCall T3242/T3243定时器超时标识 */
    NAS_MM_ClearAllEcallTimersExpiredFlg();

}
VOS_VOID NAS_MM_InitEcallInfo(VOS_VOID)
{
    /* 清除eCall T3242/T3243定时器启动标识 */
    NAS_MM_ClearAllEcallTimersStartNeededFlg();

    /* 清除eCall T3242/T3243定时器超时标识 */
    NAS_MM_ClearAllEcallTimersExpiredFlg();
}


VOS_VOID NAS_MM_ProcEcallTimerStartNeededFlg(VOS_VOID)
{
    if (VOS_TRUE == NAS_MM_GetT3242StartNeededFlg())
    {
        Mm_TimerStart(MM_TIMER_T3242);

        NAS_MM_SetT3242StartNeededFlg(VOS_FALSE);
    }

    if (VOS_TRUE == NAS_MM_GetT3243StartNeededFlg())
    {
        Mm_TimerStart(MM_TIMER_T3243);

        NAS_MM_SetT3243StartNeededFlg(VOS_FALSE);
    }
}


VOS_VOID NAS_MM_ProcBufferMsg_MmIdleECallInactive( VOS_VOID )
{
    MMCC_EST_REQ_STRU                   stCcEstReqMsg;
    MMSMS_EST_REQ_STRU                  stSmsMsg; 
    MMSS_EST_REQ_STRU                   stSsMsg;

    /* 可能搜网状态缓存呼叫请求，anycell驻留后需要取出缓存处理 */
    if (MM_TRUE == g_MmGlobalInfo.ConnCtrlInfo[MM_CONN_CTRL_CC].RcvXXEstReq.ucFlg)
    {
        Mm_MakeCcEstReq(&stCcEstReqMsg);
        g_MmGlobalInfo.ConnCtrlInfo[MM_CONN_CTRL_CC].RcvXXEstReq.ucFlg = MM_FALSE;
        NAS_MM_RcvCcEstReq_MmIdleECallInactive(&stCcEstReqMsg);
    }
    else if (MM_TRUE == g_MmGlobalInfo.ConnCtrlInfo[MM_CONN_CTRL_SMS].RcvXXEstReq.ucFlg)
    {
        Mm_MakeSmsEstReq(&stSmsMsg);
        g_MmGlobalInfo.ConnCtrlInfo[MM_CONN_CTRL_SMS].RcvXXEstReq.ucFlg = MM_FALSE;
        NAS_MM_RcvSmsEstReq_MmIdleECallInactive(&stSmsMsg);
    }
    else if (MM_TRUE == g_MmGlobalInfo.ConnCtrlInfo[MM_CONN_CTRL_SS].RcvXXEstReq.ucFlg)
    {
        Mm_MakeSsEstReq(&stSsMsg);
        g_MmGlobalInfo.ConnCtrlInfo[MM_CONN_CTRL_SS].RcvXXEstReq.ucFlg = MM_FALSE;
        NAS_MM_RcvSsEstReq_MmIdleECallInactive(&stSsMsg);
    }
    else
    {
        
    }
    
    NAS_MM_UpdateCsServiceBufferStatusFlg();
    
    return;
}

#endif



#ifdef  __cplusplus
  #if  __cplusplus
  }
  #endif
#endif
