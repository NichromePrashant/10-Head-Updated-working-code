/*
 * Global.h
 *
 *  Created on: Feb 14, 2022
 *      Author: Pustake
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#define CAN_WAIT_TIME 5

#ifndef GLOBAL_VAR
# define _GLOBAL extern
# define _GLOBAL_INIT(x)
#else
# define _GLOBAL
# define _GLOBAL_INIT(x)  = x
#endif

//#include "r_cg_userdefine.h"
//#define TEST_BUFF_NUM (5)
#define FB_CYCLE_TIME   2000
#define WB_CYCLE_TIME   2000
#define VIB_CYCLE_TIME  2000
#define SS_CYCLE_TIME   2000
#define CS_CYCLE_TIME   2000
#define MAX_LONGTIME_NOT_IN_COMBI_COUNT 20


#define FB_WAIT_TIME 540

#define CAN_WAIT_TIME 5

/////can/////////

_GLOBAL unsigned  int 	CAN_SlaveID  _GLOBAL_INIT(0);
_GLOBAL unsigned int TareCnt _GLOBAL_INIT(0);
_GLOBAL unsigned int Auto_Tare_Flag;
_GLOBAL _Bool Head_In_Combi;
_GLOBAL _Bool Flag_Run;
_GLOBAL _Bool Flag_RunCyc;
_GLOBAL _Bool Flag_Run_Stage1;
_GLOBAL _Bool Flag_Run_Stage2;
_GLOBAL _Bool Flag_Run_Stage3;
_GLOBAL _Bool Flag_Run_Stage4;
_GLOBAL _Bool Flag_Run_Stage5;
_GLOBAL _Bool Head_In_Recharge;
_GLOBAL _Bool Flag_RunOperation;
_GLOBAL _Bool Start_Weight_Cal_Flag;
_GLOBAL unsigned int run_time_flag,run_time_taken;

_GLOBAL unsigned int state _GLOBAL_INIT(0);




////////RunOP
_GLOBAL unsigned int time_to_start_fb,time_to_start_fb_flag;
_GLOBAL unsigned int WB_Angle_Ptr;
_GLOBAL unsigned int Run_Cycle_Time_Flag;
_GLOBAL unsigned int Run_Cycle_Counter;
_GLOBAL unsigned int	Cycle_TMR;
_GLOBAL unsigned int SetTimer;
_GLOBAL unsigned int Counter;

///////manual opeartion//////
_GLOBAL unsigned int t00,t01,t02,t03;
_GLOBAL unsigned int 	VBT_Cntr;
_GLOBAL unsigned int	SD_LF_TMR;
_GLOBAL _Bool Flag_ManualOperation;

_GLOBAL _Bool Flag_DumpCyc;



//////timer///

//_GLOBAL char ad_time_out_flag1;

/////////
_GLOBAL _Bool Flag_WB_Trig;
_GLOBAL unsigned char	GAIN _GLOBAL_INIT(7);
_GLOBAL unsigned char	SPEED _GLOBAL_INIT(2);
_GLOBAL unsigned int	ADSAMPLES _GLOBAL_INIT(4);
_GLOBAL unsigned char	Diff_Cnt_Val _GLOBAL_INIT(3);
_GLOBAL unsigned char	Stable_Count_Val _GLOBAL_INIT(1);
_GLOBAL unsigned int    Auto_Zero_Interval;
_GLOBAL unsigned int	Settle_Time _GLOBAL_INIT(200);
_GLOBAL signed int 	Firing_Angle _GLOBAL_INIT(5500);
_GLOBAL unsigned int	SD_LF_Time _GLOBAL_INIT(5);
_GLOBAL unsigned int 	VBRT_Cyl _GLOBAL_INIT(5);
_GLOBAL unsigned int FB_OD_Time _GLOBAL_INIT(10);
_GLOBAL unsigned int FB_OT_Time _GLOBAL_INIT(10);		// Open Time time for the FeedBucket
_GLOBAL unsigned int WB_OD_Time _GLOBAL_INIT(10);		// Open Delay time for he WeighingBucket
_GLOBAL unsigned int WB_OT_Time _GLOBAL_INIT(10);		// Open Time time for the Weighing Bucket
_GLOBAL signed int Calib_Slope_1,Calib_Slope_2,Calib_Slope_3,Calib_Slope_4,Calib_Slope_5,Calib_Slope_6,Calib_Slope_7,Calib_Slope_8,Calib_Slope_9,Calib_Slope_10;
_GLOBAL signed int		CalibSlope;
_GLOBAL signed int Tare_Cnt_1,Tare_Cnt_2,Tare_Cnt_3,Tare_Cnt_4,Tare_Cnt_5,Tare_Cnt_6,Tare_Cnt_7,Tare_Cnt_8,Tare_Cnt_9,Tare_Cnt_10;
_GLOBAL signed int		CalibCnt;
_GLOBAL signed int Calib_Cnt_1,Calib_Cnt_2,Calib_Cnt_3,Calib_Cnt_4,Calib_Cnt_5,Calib_Cnt_6,Calib_Cnt_7,Calib_Cnt_8,Calib_Cnt_9,Calib_Cnt_10;
/////////////////////feed bucket weight bucket////
_GLOBAL unsigned int FB_OT_TMR;
_GLOBAL _Bool ManOpr_FB_Flag;
_GLOBAL _Bool ManOpr_WB_Flag;
_GLOBAL _Bool ManOpr_SS_Flag;
_GLOBAL _Bool ManOpr_CS_Flag;
_GLOBAL unsigned int calibration_wt_flag;
_GLOBAL _Bool Tare_Flag;
_GLOBAL _Bool Dump_Flag;
_GLOBAL _Bool Calibeate_Flag;
_GLOBAL signed int		CurrentWt;
_GLOBAL unsigned int homing_flag_fb,homing_flag_wb;
_GLOBAL _Bool Flag_FB_Trig;				// FeedBucket Run Flag
_GLOBAL _Bool Flag_WtReady;
_GLOBAL _Bool wt_calculated_flag;
_GLOBAL unsigned char 		stable_count;
_GLOBAL unsigned char 		auto_zero_count;
_GLOBAL signed int	adc_count;
_GLOBAL unsigned int	Settle_TMR _GLOBAL_INIT(0);
_GLOBAL unsigned int enable_time_count;
_GLOBAL unsigned int Initial_Vibrator_Flag;
_GLOBAL _Bool ot_flag;
_GLOBAL unsigned int WB_OT_TMR;
_GLOBAL unsigned int fb_time_taken_flag,wb_time_taken_flag,lf_time_taken_flag,FB_OfD_TMR_flag;
_GLOBAL unsigned int fb_time_taken_counter,wb_time_taken_counter,lf_time_taken_counter;
_GLOBAL _Bool Flag_WB_Trig_Edge;

/////fb////
_GLOBAL unsigned int FB_Clk_Pulses;
_GLOBAL unsigned int FB_OD_TMR;				// Open Delay Timer of the Feed Bucket
_GLOBAL unsigned int FB_OfD_TMR;
_GLOBAL unsigned int FB_OfD_Time _GLOBAL_INIT(300);				// disable Delay Timer of the Feed Bucket enable
_GLOBAL _Bool Flag_FB_Trig_Edge;
_GLOBAL _Bool Flag_FB_Stage1;
_GLOBAL _Bool Flag_FB_Stage2;
_GLOBAL _Bool Flag_FB_Stage3;
_GLOBAL _Bool Flag_FB_HomIN;
_GLOBAL _Bool Flag_FB_Status;
//_Bool Flag_FB_Trig;				// FeedBucket Run Flag
_GLOBAL _Bool Flag_FB_Trig_Edge;		// Check edge of the feedBucket Run Flag
_GLOBAL _Bool Flag_FB_OD_TMR;
_GLOBAL _Bool Flag_FB_OT_TMR;
_GLOBAL unsigned int FB_Rot_Count;
_GLOBAL unsigned int enb_i,enb_flag;
_GLOBAL unsigned int MotoPro_FB;

_GLOBAL unsigned int shift_speed_row_FB;

////wb/////
_GLOBAL unsigned int WB_Clk_Pulses;
_GLOBAL unsigned int shift_speed_row_WB;
_GLOBAL unsigned int WB_OD_TMR;
_GLOBAL unsigned int MotoPro _GLOBAL_INIT(0);
_GLOBAL _Bool Flag_WB_Stage1;
_GLOBAL _Bool Flag_WB_Stage2;
_GLOBAL _Bool Flag_WB_Stage3;
_GLOBAL unsigned int DSidx, DSidx_FB;
_GLOBAL _Bool Flag_WB_OD_TMR;
_GLOBAL _Bool Flag_WB_OT_TMR;

_GLOBAL _Bool Flag_WB_HomIN;
//_Bool Flag_DumpCyc;
_GLOBAL _Bool Flag_RechCyc;
_GLOBAL _Bool Flag_WB_Status;


//_GLOBAL unsigned long int  absolute_diff(unsigned long int v1,unsigned long int v2);

///////////////////calibration//////
_GLOBAL _Bool Flag_CalOpr_Stage1;
_GLOBAL _Bool Flag_Calib_Done;
_GLOBAL _Bool Flag_CalOpr_Stage1;
_GLOBAL _Bool Flag_CalOpr_Stage2;
_GLOBAL _Bool Flag_CalOpr_Stage3;


////Auto tare///
_GLOBAL unsigned int Tare_Send_Time,Tare_Send_Flag;
_GLOBAL _Bool Flag_Tare_Done;
//_DECL unsigned int enb_flag;
//_DECL _Bool enb_flag;    //new change



/////Flash/////
///



#endif /* GLOBAL_H_ */
