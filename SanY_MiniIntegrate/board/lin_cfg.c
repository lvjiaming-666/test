/*
 * Copyright 2019 - 2020 NXP
 * All rights reserved.
 *
 * This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software. The production use license in
 * Section 2.3 is expressly granted for this software.
 */
/*!
 * @file lin_cfg.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, Could be made static.
 * Function ld_read_by_id_callout is API and shall not be made static.
 * This API is declared in lin_cfg.c so that users can configure the response
 * for  Read by ID request.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * An object with static storage duration declared at block scope cannot be
 * accessed directly from outside the block. g_lin_hardware_ifc, g_lin_tl_descriptor_array,
 * timerGetTimeIntervalCallback are dependent on user configurations,
 * so they shall be declared in lin_cfg.c.
 */

#include "lin.h"

#if (SUPPORT_TRANSPORT_LAYER == 1U)
static lin_tl_pdu_data_t      LI0_tl_tx_queue_data[2];
static lin_tl_pdu_data_t      LI0_tl_rx_queue_data[2];
#endif /* end (SUPPORT_TRANSPORT_LAYER == 1U) */

const l_ifc_handle g_lin_hardware_ifc[HARDWARE_INSTANCE_COUNT] = {INVALID_IFC, INVALID_IFC, LI0};
const l_u32 g_lin_virtual_ifc[LIN_NUM_OF_IFCS] = {2};
volatile l_u8 g_buffer_backup_data[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/* definition and initialization of signal array */
volatile l_u8    g_lin_frame_data_buffer[LIN_FRAME_BUF_SIZE] =
{
  0xfc /* 0 : 11111100 */ /* start of frame LI0_Motor1Control */

  ,0x05 /* 1 : 00000101 */ /* start of frame LI0_Motor1State_Cycl */

  ,0xff /* 2 : 11111111 */

  ,0xff /* 3 : 11111111 */

  ,0xff /* 4 : 11111111 */

  ,0xff /* 5 : 11111111 */

  ,0xfe /* 6 : 11111110 */
};

/* definition and initialization of signal array */
volatile l_u8    g_lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{
  0xFF /* 0: start of flag frame LI0_Motor1Control */

  ,0xFF /* 1: start of flag frame LI0_Motor1State_Cycl */
};

/* definition and initialization for flag of frame */
volatile l_bool g_lin_frame_flag_handle_tbl[LIN_NUM_OF_FRMS] = {false, false, false, false};

/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 g_lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0};



/*****************************sporadic frame*****************************/
/*all sporadic frames for master node*/
/**********************************  Frame table **********************************/
static const lin_frame_t lin_frame_tbl[LIN_NUM_OF_FRMS] ={

    { LIN_FRM_UNCD, 1, LIN_RES_PUB, 0, 0, 1   , (lin_associate_frame_t*)0 }

   ,{ LIN_FRM_UNCD, 6, LIN_RES_SUB, 1, 1, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (lin_associate_frame_t*)0 }
  
};

static l_u8 LI0_lin_configuration_RAM[LI0_LIN_SIZE_OF_CFG]= {0x00, 0x30, 0x33, 0x3C, 0x3D ,0xFF};

static const l_u16  LI0_lin_configuration_ROM[LI0_LIN_SIZE_OF_CFG]= {0x0000, 0x30, 0x33, 0x3C, 0x3D ,0xFFFF};


/********************** Go to sleep Initialization *************************/
/* Delay of this schedule table is: (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms */
/* then rounded up to a value is multiple of time base */
static const lin_schedule_data_t LI0_lin_gotosleep_data[1] = {
   {LI0_MasterReq, 2, {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}
};


/******************** Schedule table Initialization ************************/
static const lin_schedule_data_t LI0_NormalTable_data[2] = {

   {LI0_Motor1Control, 10, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_Motor1State_Cycl, 10, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
};


/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
static const lin_schedule_data_t LI0_MasterReqTable_data[1] = {

   {LI0_MasterReq, 6, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
};
/******************** Schedule table Initialization ************************/
/* If not specify by users, then by default delay of this schedule table is: */
/* (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms, then rounded up to a value */
/* that is multiple of time base */
static const lin_schedule_data_t LI0_SlaveRespTable_data[1] = {

   {LI0_SlaveResp, 6, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
};

/********************* Schedule table structure Initialization ***************/
static const lin_schedule_t lin_schedule_tbl[LIN_NUM_OF_SCHD_TBL] ={

   /*interface_name = LI0 */
   {0, LIN_SCH_TBL_NULL  ,(lin_schedule_data_t*)0 }
  
   ,{1, LIN_SCH_TBL_GO_TO_SLEEP  , &LI0_lin_gotosleep_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI0_MasterReqTable_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI0_SlaveRespTable_data[0] }
  
   ,{2, LIN_SCH_TBL_NORM  , &LI0_NormalTable_data[0] }
  
};
/****************************LIN interface configuration ****************************/
const lin_protocol_user_config_t g_lin_protocol_user_cfg_array[LIN_NUM_OF_IFCS] = {

    /* Interface_name = LI0 */
    {
        .protocol_version = LIN_PROTOCOL_13,         /*lin_protocol_version */
        .language_version = LIN_PROTOCOL_13,         /*lin_language_version */
        .diagnostic_class = LIN_DIAGNOSTIC_CLASS_I,            /* LIN Diagnostic Class */
        .function = (bool)LIN_MASTER,                 /*  function LIN_MASTER*/

        .number_of_configurable_frames = 4,                            /*  num_of_frames */
        .frame_start = 0,                              /*  frame_start */
        .frame_tbl_ptr = lin_frame_tbl,                                          /*  frame_tbl */

        .list_identifiers_ROM_ptr = LI0_lin_configuration_ROM,       /*  *configuration_ROM */
        .list_identifiers_RAM_ptr = LI0_lin_configuration_RAM,       /*  *configuration_RAM */
        .max_idle_timeout_cnt =  10000,     /* Max Idle Timeout Count */
        .num_of_schedules = 5,                                  /*  num_of_schedules */
        .schedule_start = 0,                                  /*  schedule_start */
        .schedule_tbl = lin_schedule_tbl,             /* schedule_tbl */

        .slave_ifc_handle = INVALID_SLAVE_INDEX,
        .master_ifc_handle = LI0_Master,
        .lin_user_config_ptr = &lin0_InitConfig0,
#if (SUPPORT_TRANSPORT_LAYER == 1U)
        .tl_tx_queue_data_ptr = LI0_tl_tx_queue_data,
        .tl_rx_queue_data_ptr = LI0_tl_rx_queue_data,
        .max_message_length = 6             /* Max message length */
#endif /* end (SUPPORT_TRANSPORT_LAYER == 1U) */
    }
};

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_read_by_id_callout
 * Description   : This function is an example of response; real implementation is application-dependent
 *                 You can use one of the following define to set PCI of response frame for
 *                 this service to the correct value
 * Implements    : ld_read_by_id_callout_Activity
 *END**************************************************************************/

l_u8 ld_read_by_id_callout(l_ifc_handle iii, l_u8 id, l_u8 *data)
{
    l_u8 retval = LD_NEGATIVE_RESPONSE;

    /* Get the current configuration */
    const lin_protocol_user_config_t  *prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];

    if (prot_user_config_ptr->function == (bool)LIN_SLAVE)
    {
        /* Following code is an example - Real implementation is application-dependent */
        /* the handling does essentially depend on the id of the requested item */
        /* This example implement with ID = 32 - LIN_READ_USR_DEF_MIN */
        if (id == LIN_READ_USR_DEF_MIN)
        {
            /*
            * id received is user defined 32
            */
            /* A positive response is ready to be sent to the user defined request */
            data[0] = (l_u8) (id + 1U);    /* Data user define */
            data[1] = (l_u8) (id + 2U);    /* Data user define */
            data[2] = (l_u8) (id + 3U);    /* Data user define */
            data[3] = (l_u8) (id + 4U);    /* Data user define */
            data[4] = (l_u8) (id + 5U);    /* Data user define */
            retval = LD_POSITIVE_RESPONSE;
        }
        else
        {
            /*
            * id received is user defined 63 - no response
            */
        }
    } /* End (conf->function == _SLAVE_) */
   return retval;
}

