/***********************************************************************
*
*  FILE        : 10HDMHWNC.c
*  DATE        : 2022-02-08
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include <stdio.h>              // sprintf()
#include <string.h>             // strlen()
#include "platform.h"           // Located in the FIT BSP module
#include "r_sci_rx_if.h"        // The SCI FIT module API interface file.
#include "r_rscan_rx_if.h"
#include "can.h"
#include "Peripheral.h"
#include "ADC_CS5532.h"
#include "Timer.h"
#include <r_cg_userdefine.h>
#include "r_cg_port.h"
#define GLOBAL_VAR
#include "globals.h"
#include "Auto_Tare.h"
#include "RUN_OP.h"
#include "Calibration.h"
#include "Stepper_Motor.h"





extern unsigned char 		adc_stable;
extern unsigned  int 	CAN_SlaveID;

void main(void);

void main(void)
{
    if(state==0)
    {
	Init_Pins();                     // Initialize Port Pins at Power On
    }
    if(state==1)
    {
	Init_Vals();	               	// Initialize Variable and Flags at Power On
    }
    if(state==2)
    {
	Init_Peripherals();             // Initialize Peripheral Function used
    }
	mS_Delay(1000);		            // Wait here
	/*-----------------------------------------Instruction below is to generate CAN Slave ID for Each Slave Dynamically*/
	if(state==3)
	{
	if(DIP1 == 0)	CAN_SlaveID = CAN_SlaveID|0x01;
	if(DIP2 == 0)	CAN_SlaveID = CAN_SlaveID|0x02;
	if(DIP3 == 0)	CAN_SlaveID = CAN_SlaveID|0x04;
	if(DIP4 == 0)	CAN_SlaveID = CAN_SlaveID|0x08;
	state = 4;

	}
	/*-----------------------------------------------------------------------------------------------------------------*/
	if(state==4)
	{
	PowerOnHomIN();		                   // At Power On take stepper to Homing position
	}
	mS_Delay(1000);		                  // Wait here
	if (state==5)
	{
    Reset_Asic();		                  // Reset to the CS5532
	}
	if(state==6)
	{
	init_asic();		                  // Initialize the CS5532 LoadCell mV to ADC converter
	}
	if(state==7)
	{
	Asic_start();		                  // Starts the CS5532 LoadCell mV to ADC conversion
	}
	mS_Delay(1000);		                  // Wait here

	while(1)
    {
		Clr_WatchDog();			          // Clear watch dog timer and reset

		if(state==8)
		{
		if((calibration_wt_flag == 1 || Settle_TMR == 0))
		{
				read_adc();						  // Read Load Cell ADC count from CS5532
				check_stable();					  // Check if the Counts are Stable

				if(adc_stable)
				{
					calculate_weight();
					Flag_WtReady = 1;
					wt_calculated_flag = 1;
				}
				else
				{
					Flag_WtReady=0;
					wt_calculated_flag = 1;
				}
				state = 9;
		}
		}


		if(state == 9)
		{
		if(Flag_WB_Trig == 0 &&  Auto_Tare_Flag==1)
		{
			Auto_Tare();

		}
		   state = 10;
		}

		if(state == 10)
		{
		if(Flag_ManualOperation == 1)
		{
			Clr_WatchDog();
			ManualOperation();
			Flag_ManualOperation = 0;


		}
		state = 11;
		}


		if(state == 11)
		{
		if(Flag_CalibOperation == 1)
		{
			Clr_WatchDog();
			Head_In_Recharge = 0;
			CalibOperation();

			if(Flag_Calib_Done == TRUE)
			{
				Clr_WatchDog();
				read_adc();				// Continuous read ADC in run time
				check_stable();			// Check weather ADC count stable

				if(adc_stable)
				{
					calculate_weight();		// Continuously calculate the weight above ADC count   4194.572

				}
			}
		}
		state =12;
		}


	if(state == 12)
	{
		if(Flag_RunOperation == 1)
		{
			Clr_WatchDog();
			RunOperation();

		}
		state = 13;
	}

	if(state==13)
	{
		if(LongTime_Not_In_Combi_Count>=MAX_LONGTIME_NOT_IN_COMBI_COUNT)
		{
			LongTime_Not_In_Combi_flag  = 1;
			LongTime_Not_In_Combi_Count = 0;

		}
		state = 14;
	}

	if(state==14)
	{
		if((Tare_Send_Flag == 1) && (Tare_Send_Time == 0))
		{
			Send_Tarecount();
			Tare_Send_Flag = 0;
		}
	}
	 state = 8;
    }
}

