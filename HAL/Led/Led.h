
#include "Led_CFG.h"
#include "../../MCAL/GPIO/GPIO.h"

typedef enum{
	LED_enuStateOK= 0,
	LED_enuStateNOTOK,
	LED_enuStateNullPTR,
}LED_enuErrorStatus_t;

typedef enum {
	LED_enu_AvtiveHigh,
	LED_enu_AvtiveLow,


}LED_enu_t_ActiveMode;


typedef enum {
	LED_enu_ON,
	LED_enu_OFF,


}LED_enu_t_State;




typedef struct{
	GPIO_StructReg *Led_Port;
	GPIO_tenuPINS Led_Pin;
	OSPEEDR_tenuModes Led_Speed;
	LED_enu_t_ActiveMode Led_ActiveMode;
	GPIO_tenuModes Led_InOutputMode;
}LED_Cfg_t;





extern LED_Cfg_t LED_cfg[Led_Count];
LED_enuErrorStatus_t LED_init();



LED_enuErrorStatus_t LED_SetState( LED_enut_LedSys  Cpy_LedSys, LED_enu_t_State Cpy_LedState);



