/*
 * can.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Pustake
 */

#ifndef CAN_H_
#define CAN_H_

/*
 * Can.h
 *
 *  Created on: Feb 8, 2022
 *      Author: Pustake
 */

#ifndef CAN_VAR
# define _CAN extern
# define _CAN_INIT(x)
#else
# define _CAN
# define _CAN_INIT(x)  = x
#endif

/*****************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include <stdio.h>              // sprintf()
#include <string.h>             // strlen()
#include "platform.h"           // Located in the FIT BSP module
#include "r_sci_rx_if.h"        // The SCI FIT module API interface file
#include "r_rscan_rx_if.h"      // The RSCAN FIT module API interface file
#include "r_cg_userdefine.h"

//#include "main.h"               // MSG and STATE enums


/************************************************************
 #define

 ************************************************************/
#define RX_BUFSIZE      40
#define TX_BUFSIZE      60




/******************************************************************************/


_CAN sci_hdl_t    g_sci_handle;
_CAN char         g_txbuf[];
_CAN can_txmsg_t  g_txmsg;
_CAN uint32_t            g_ovfl_cnt _CAN_INIT(10);
_CAN can_filter_t        g_filter;

_CAN unsigned int a;
//_CAN unsigned int TareCnt _CAN_INIT(0);
//_CAN unsigned  int 	CAN_SlaveID  _CAN_INIT(0);
_CAN unsigned int Dump,Recharge,wait;
_CAN _Bool Flag_CalibOperation;
//_CAN _Bool Flag_ManualOperation;
//_CAN _Bool Start_Weight_Cal_Flag;
//_CAN _Bool Head_In_Combi;   //
//_CAN _Bool Flag_Run;        //
//_CAN _Bool Flag_RunCyc;     //
//_CAN _Bool Flag_Run_Stage1;   //
//_CAN _Bool Head_In_Recharge;
//_CAN _Bool Flag_RunOperation;
_CAN _Bool ManOpr_Vib_Flag;
//_DECL unsigned  int 	CAN_SlaveID _INIT(0);

//_CAN unsigned int Auto_Tare_Flag;  //
//_CAN unsigned int run_time_flag,run_time_taken;
_CAN unsigned int LongTime_Not_In_Combi_Count,LongTime_Not_In_Combi_flag;



/*
_DECL _Bool Flag_WB_Trig;
_DECL unsigned char	GAIN _INIT(7);
_DECL unsigned char	SPEED _INIT(2);
//_DECL unsigned int	ADSAMPLES _INIT(4);
_DECL unsigned char	Diff_Cnt_Val _INIT(3);
_DECL unsigned char	Stable_Count_Val _INIT(1);
_DECL unsigned int    Auto_Zero_Interval;
_DECL unsigned int	Settle_Time _INIT(200);
_DECL signed int 	Firing_Angle _INIT(5500);
_DECL unsigned int	SD_LF_Time _INIT(5);
_DECL unsigned int 	VBRT_Cyl _INIT(5);
_DECL unsigned int FB_OD_Time _INIT(10);
_DECL unsigned int FB_OT_Time _INIT(10);		// Open Time time for the FeedBucket
_DECL unsigned int WB_OD_Time _INIT(10);		// Open Delay time for he WeighingBucket
_DECL unsigned int WB_OT_Time _INIT(10);		// Open Time time for the Weighing Bucket
_DECL signed int Calib_Slope_1,Calib_Slope_2,Calib_Slope_3,Calib_Slope_4,Calib_Slope_5,Calib_Slope_6,Calib_Slope_7,Calib_Slope_8,Calib_Slope_9,Calib_Slope_10;
_DECL signed int		CalibSlope;
_DECL signed int Tare_Cnt_1,Tare_Cnt_2,Tare_Cnt_3,Tare_Cnt_4,Tare_Cnt_5,Tare_Cnt_6,Tare_Cnt_7,Tare_Cnt_8,Tare_Cnt_9,Tare_Cnt_10;
_DECL signed int		CalibCnt;
_DECL signed int Calib_Cnt_1,Calib_Cnt_2,Calib_Cnt_3,Calib_Cnt_4,Calib_Cnt_5,Calib_Cnt_6,Calib_Cnt_7,Calib_Cnt_8,Calib_Cnt_9,Calib_Cnt_10;
_DECL _Bool ManOpr_Vib_Flag;
_DECL _Bool ManOpr_FB_Flag;
_DECL _Bool ManOpr_WB_Flag;
_DECL _Bool ManOpr_SS_Flag;
_DECL _Bool ManOpr_CS_Flag;
//_DECL unsigned int calibration_wt_flag;
_DECL _Bool Tare_Flag;
_DECL _Bool Dump_Flag;
_DECL _Bool Calibeate_Flag;
_DECL signed int		CurrentWt;
_DECL unsigned int homing_flag_fb,homing_flag_wb;
_DECL _Bool Flag_FB_Trig;				// FeedBucket Run Flag
_DECL _Bool Flag_WtReady;
_DECL _Bool wt_calculated_flag;
_DECL unsigned char 		stable_count;
_DECL unsigned char 		auto_zero_count;
_DECL signed int	adc_count;
_DECL unsigned int	Settle_TMR _INIT(0);

*/





typedef enum e_state
{
    STATE_CONNECTING_UART,
    STATE_CONNECTING_CAN,
    STATE_CAN_TO_UART,
    STATE_UART_TO_CAN
} state_t;

typedef enum e_uart_msg
{
    MSG_NONE,
    MSG_DISPLAY_MENU,
    MSG_SEND_CAN,
    MSG_RESUME_CAN,
    MSG_OVERFLOW
} uart_msg_t;

void init_can(void);
void init_can_again(void);
void can_rx231_init_ports(void);
void wait_can_network(void);
void MainCallback(can_cb_evt_t event, void *p_args);
void ChanCallback(uint8_t chan, can_cb_evt_t event, void *p_args);
//void Delay_Loop(unsigned int time_sec);
void  process_uart_msg(void);
void  Clr_WatchDog(void);
void CAN_SEND_MEG(struct CFrame *CANFrame1);
void Check_CAN_Status(void);
void process_can_msg(can_rxmsg_t *rxmsg);
void Send_data(void);
void Create_Send_CAN_Frame(void);
void Send_Tarecount();
void Send_Calibcount();
void calculate_weight(void);


#endif /* CAN_H_ */
