#include "Led.h"



LED_enuErrorStatus_t LED_init(){
	LED_enuErrorStatus_t status=LED_enuStateOK;
	u16 local_u16Idx;

	for(local_u16Idx=0;local_u16Idx<Led_Count;local_u16Idx++)
	{
		GPIO_Cfg_t GPIO_LedObj;
		GPIO_LedObj.GPIO_Pin_Pin=LED_cfg[local_u16Idx].Led_Pin;
		GPIO_LedObj.PORTX=LED_cfg[local_u16Idx].Led_Port;
		GPIO_LedObj.GPIO_Pin_Speed=LED_cfg[local_u16Idx].Led_Speed;
		GPIO_LedObj.GPIO_Pin_Mode=LED_cfg[local_u16Idx].Led_InOutputMode;


		GPIO_InitPin(&GPIO_LedObj);
	}

	return status;
}

LED_enuErrorStatus_t LED_SetState( LED_enut_LedSys  Cpy_LedSys, LED_enu_t_State Cpy_LedState){
	LED_enuErrorStatus_t status=LED_enuStateOK;

	GPIO_SetPin(LED_cfg[Cpy_LedSys].Led_Port,LED_cfg[Cpy_LedSys].Led_Pin,(Cpy_LedState ^LED_cfg[Cpy_LedSys].Led_ActiveMode));

	return status;
}
