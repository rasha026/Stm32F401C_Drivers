



#include "SCHED.h"
//#include "../../HAL/Led/Led.h"
//#include "../../HAL/PushButton/PushButton.h"
#include "../../HAL/LCD/LCD.h"
static void App1_Runnable(void);
static void App2_Runnable(void);
static void App3_Runnable(void);
static void LCD_Task(void);
static void switchApp(void);

const task_info_t  task_info[RUNNABLE_NUM]=
{
/*
		[0]={
				.name="LED1",
				.runnable_cbf=&App1_Runnable,
				.period_ms=1,
				.start_delay_ms=0,

		},

		[1]={
				.name="LED2",
				.runnable_cbf=&App2_Runnable,
				.period_ms=500,
				.start_delay_ms=0,

		},
		[2]={
				.name="LED3",
				.runnable_cbf=&App3_Runnable,
				.period_ms=1000,
				.start_delay_ms=0,
		},
	************************************************************************************************************************************************************************
*/
	/*	[0]={
				.name="switch",
				.runnable_cbf=&switchApp,
				.period_ms=5,
				.start_delay_ms=0,

		},
		*/

//************************************************************************************************************************************************************************


		[0]={
				.name="LCD",
				.runnable_cbf=&LCD_Task,
				.period_ms=2,
				.start_delay_ms=35,


		},

};






void LCD_Task(){
	char * Rstring="Hello :)";
	if(initState==0)
	{
		LCD_init();
	}
	else
	{
		if(ReqType==No_Req)
		{

		LCD_AsyncWriteString(Rstring ,8,0,0,0);
		ReqType =ReqType_Write;
		}
		else if(ReqType==ReqType_Write)
		{
			writeSeq();


			if(ReqType==ReqType_Done)
				ReqType=ReqType_Clear;



		}

		else if(ReqType==ReqType_Clear)
		{

			//ClearSeq();
			//ReqType=No_Req;

		}

	}

}



/*
void App1_Runnable(void){
	static u8 count=0;

	count =~count;
	if (count==0)
	{
		LED_SetState(Led_Alarm,LED_enu_ON);

	}
	else{
		LED_SetState(Led_Alarm,LED_enu_OFF);


	}


}
void App2_Runnable(void){

	static u8 count2=0;
	count2 =~count2;

	if (count2==0)
	{LED_SetState(Led_Warning,LED_enu_ON);
	}
	else{
		LED_SetState(Led_Warning ,LED_enu_OFF);
	}

}
void App3_Runnable(void){
	static u8 count3=0;
	count3 =~count3;
	if (count3==0)
	{LED_SetState(Led_ERROR,LED_enu_ON);
	}
	else{
		LED_SetState(Led_ERROR,LED_enu_OFF);

	}

}
*/





/*
u16 prevState[PushBotton_Count]={PushButton_Released};
u8 switchState[PushBotton_Count]={PushButton_Released};

void switchApp(void){
	u8 static counter[PushBotton_Count]={PushButton_Released};
	u16 currentState;
	for(int idx=0;idx<PushBotton_Count;idx++)
	{
		PushButton_ReadPushButtonState(idx,&currentState);
		if(currentState==prevState[idx])
			{
				counter[idx]++;

			}
			else{
				counter[idx]=0;
			}
			if(counter[idx]==5)
			{
				switchState[idx]=currentState;
				counter[idx]=0;

				if(currentState==PushButton_Pressed)
				{
					if(idx==PushBotton_OFF)
					{

						LED_SetState(Led_Alarm,LED_enu_ON);
					}

					else if(idx==PushBotton_ON)
					{

						LED_SetState(Led_Warning,LED_enu_ON);
					}



				}
				else{
					if(idx==PushBotton_OFF)
					{

						LED_SetState(Led_Alarm,LED_enu_OFF);
					}

					else if(idx==PushBotton_ON)
					{
						LED_SetState(Led_Warning,LED_enu_OFF);
					}

				}

			}
			prevState[idx]=currentState;



	}



}

*/
