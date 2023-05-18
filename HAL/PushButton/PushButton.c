


#include "PushButton.h"


PushButton_enuErrorStatus_t PushButton_init(){
	PushButton_enuErrorStatus_t status=PushButton_enuStateOK;
	u16 local_u16Idx;
	for(local_u16Idx=0;local_u16Idx<PushBotton_Count;local_u16Idx++)
	{
		GPIO_Cfg_t GPIO_PushButtonObj;
		GPIO_PushButtonObj.GPIO_Pin_Pin=PushButton_Cfg[local_u16Idx].PushButton_Pin;
		GPIO_PushButtonObj.PORTX=PushButton_Cfg[local_u16Idx].PushButton_Port;
		GPIO_PushButtonObj.GPIO_Pin_Speed=PushButton_Cfg[local_u16Idx].PushButton_Speed;
		GPIO_PushButtonObj.GPIO_Pin_Mode=PushButton_Cfg[local_u16Idx].PushButton_InputMode;


		GPIO_InitPin(&GPIO_PushButtonObj);
	}
	return status;
}



PushButton_enuErrorStatus_t PushButton_ReadPushButtonState(BushButton_tenu_BushButtonSys  Cpy_PushButtonSys, u16 *address_u16ButtonState){
	PushButton_enuErrorStatus_t status=PushButton_enuStateOK;

	GPIO_ReadInputPin(PushButton_Cfg[Cpy_PushButtonSys].PushButton_Port, PushButton_Cfg[Cpy_PushButtonSys].PushButton_Pin,address_u16ButtonState);


	return status;
}
