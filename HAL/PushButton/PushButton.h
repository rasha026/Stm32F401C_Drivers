
#include "../../MCAL/GPIO/GPIO.h"


#include "PushButton_CFG.h"


typedef enum{
	PushButton_enuStateOK= 0,
	PushButton_enuStateNOTOK,
	PushButton_enuStateNullPTR,
}PushButton_enuErrorStatus_t;




#define PushButton_Released			0
#define	PushButton_Pressed			1




typedef struct{
	GPIO_StructReg *PushButton_Port;
	GPIO_tenuPINS PushButton_Pin;
	OSPEEDR_tenuModes PushButton_Speed;
	GPIO_tenuModes PushButton_InputMode;
}PushButton_Cfg_t;

extern PushButton_Cfg_t PushButton_Cfg[];

PushButton_enuErrorStatus_t PushButton_init();



PushButton_enuErrorStatus_t PushButton_ReadPushButtonState(BushButton_tenu_BushButtonSys  Cpy_PushButtonSys, u16 *address_u16ButtonState);

