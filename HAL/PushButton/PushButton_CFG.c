



#include "PushButton.h"



PushButton_Cfg_t PushButton_Cfg[]={
		[PushBotton_ON]={
				.PushButton_Port=GPIOA  ,
				.PushButton_Pin=GPIO_enuPIN0  ,
				.PushButton_Speed=HIGH_SPEED  ,
			//	.PushButton_ActiveMode=LED_enu_AvtiveHigh  ,   //Based on your Hardware
				.PushButton_InputMode=GPIO_enuModes_Input_Pull_up,

		},


		[PushBotton_OFF]={
				.PushButton_Port=GPIOA  ,
				.PushButton_Pin=GPIO_enuPIN1  ,
				.PushButton_Speed=HIGH_SPEED  ,
			//	.PushButton_ActiveMode=LED_enu_AvtiveHigh  ,   //Based on your Hardware
				.PushButton_InputMode=GPIO_enuModes_Input_Pull_up,

		},


};



