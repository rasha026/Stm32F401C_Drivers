



#ifndef GPIO_H_
#define GPIO_H_

#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"
//base addresses of GPIOX
#define GPIOA_BASE_ADDRESS 				0x40020000
#define GPIOB_BASE_ADDRESS 				0x40020400
#define GPIOC_BASE_ADDRESS 				0x40020800
#define GPIOD_BASE_ADDRESS 				0x40020C00
#define GPIOE_BASE_ADDRESS 				0x40021000

typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_StructReg;




//*((volatile u32*)(RCC_BASE_ADDRESS	+	0x00))

//	POINTER TO STRUCT TO POINT TO BASE ADDRESS
#define GPIOA 				((GPIO_StructReg*)(GPIOA_BASE_ADDRESS))
#define GPIOB				((GPIO_StructReg*)(GPIOB_BASE_ADDRESS))
#define GPIOC 				((GPIO_StructReg*)(GPIOC_BASE_ADDRESS))
#define GPIOD 				((GPIO_StructReg*)(GPIOD_BASE_ADDRESS))
#define GPIOE				((GPIO_StructReg*)(GPIOE_BASE_ADDRESS))




extern GPIO_StructReg *GPIOX_ARR[];



typedef enum{
	GPIO_enuStateOK= 0,
	GPIO_enuStateNOTOK,
	GPIO_enuStateNullPTR,
	GPIO_enuStateReady,
	GPIO_enuStateNOTReady,
	GPIO_enuStateWrongCf,

}GPIO_enuErrorStatus_t;






typedef enum{

	GPIO_enuPIN0=0,
	GPIO_enuPIN1,
	GPIO_enuPIN2,
	GPIO_enuPIN3,
	GPIO_enuPIN4,
	GPIO_enuPIN5,
	GPIO_enuPIN6,
	GPIO_enuPIN7,
	GPIO_enuPIN8,
	GPIO_enuPIN9,
	GPIO_enuPIN10,
	GPIO_enuPIN11,
	GPIO_enuPIN12,
	GPIO_enuPIN13,
	GPIO_enuPIN14,
	GPIO_enuPIN15,
	GPIO_enuPINNUMS,



}GPIO_tenuPINS;







typedef enum{
	MODERy_Input=0,
	MODERy_GeneralPurposeOutput,
	MODERy_AlternateFunction,
	MODERy_Analog ,
}MODERy_tenuModes;




#define MASK_CLEAR_MODER 					(0b11)
#define MASK_SHIFT_BY_2						(2)




//OTYPER
typedef enum{
	OTYPER_PUSH_PULL=0,
	OTYPER_OPEN_DRAIN,

}OTYPER_tenu_OUTPUTModes;


//OSPEEDR

typedef enum{
	LOW_SPEED=0,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED,

}OSPEEDR_tenuModes;

//PUPDR
typedef enum{
	PUPDR_NO_PULL=0,
	PUPDR_PULL_UP,
	PUPDR_PULL_DOWN,
}PUPDR_tenuModes;




typedef enum{

	GPIO_enuAF0=0,
	GPIO_enuAF1,
	GPIO_enuAF2,
	GPIO_enuAF3,
	GPIO_enuAF4,
	GPIO_enuAF5,
	GPIO_enuAF6,
	GPIO_enuAf7,
	GPIO_enuAF8,
	GPIO_enuAF9,
	GPIO_enuAF10,
	GPIO_enuAF11,
	GPIO_enuAF12,
	GPIO_enuAF13,
	GPIO_enuAF14,
	GPIO_enuAF15,
	GPIO_enuAFNUMs,
}GPIO_tenuAFs;



#define MASK_READ_INPUT_DATA			(0X00FF)
#define MASK_CLEAR_AF					(8)
#define MASK_SHIFT_BY_4					(4)




typedef enum
{
	//Input
	GPIO_enuModes_Input_Floating=0,
	GPIO_enuModes_Input_Pull_up,
	GPIO_enuModes_Input_Pull_down,
	//Output
	GPIO_enuModes_Output_push_pull_PullUP,
	GPIO_enuModes_Output_open_drainPullUP,
	GPIO_enuModes_Output_push_pull_PullDOWN,
	GPIO_enuModes_Output_open_drain_PullDOWN,
	//Analog
	GPIO_enuModes_Analog,
	//Alternate function
	GPIO_enuModes_AF_Pull_up,
	GPIO_enuModes_AF_Pull_down,
	GPIO_enuModes_AF_push_pull,
	GPIO_enuModes_AF_push_pull_Pull_up,
	GPIO_enuModes_AF_push_pull_Pull_down,
	GPIO_enuModes_AF_open_drain,
	GPIO_enuModes_AF_open_drain_Pull_up,
	GPIO_enuModes_AF_open_drain__Pull_down,



}GPIO_tenuModes;

typedef enum
{
	//Input
	GPIO_enuPorts_PORTA=0,
	GPIO_enuPorts_PORTB,
	GPIO_enuPorts_PORTC,
	GPIO_enuPorts_PORTD,
	GPIO_enuPorts_PORTE,

}GPIO_tenuPorts;





typedef struct{
	GPIO_tenuPINS GPIO_Pin_Pin;
	OSPEEDR_tenuModes GPIO_Pin_Speed;
	GPIO_tenuModes GPIO_Pin_Mode;
	GPIO_StructReg *PORTX;

}GPIO_Cfg_t;




GPIO_enuErrorStatus_t GPIO_InitPin(GPIO_Cfg_t* cpy_struc_pin);

GPIO_enuErrorStatus_t GPIO_ConfigIODirection(GPIO_StructReg * PTR_StructReg,MODERy_tenuModes CPY_MODERyModes,GPIO_tenuPINS GPIOenuPIN);

GPIO_enuErrorStatus_t GPIO_ConfigOutputType(GPIO_StructReg * PTR_StructReg,OTYPER_tenu_OUTPUTModes CPY_OUTPUTModes,GPIO_tenuPINS GPIOenuPIN);
GPIO_enuErrorStatus_t GPIO_ConfigOutputSpeed(GPIO_StructReg * PTR_StructReg,OSPEEDR_tenuModes CPY_OutPutSpeed,GPIO_tenuPINS GPIOenuPIN);

GPIO_enuErrorStatus_t GPIO_ConfigIOPULL_UP_DOWN(GPIO_StructReg * PTR_StructReg,PUPDR_tenuModes CPY_PULLU_PULLD,GPIO_tenuPINS GPIOenuPIN);

GPIO_enuErrorStatus_t GPIO_ReadInputPort(GPIO_StructReg * PTR_StructReg,u16 *add_u16RegVal);
GPIO_enuErrorStatus_t GPIO_ReadInputPin(GPIO_StructReg * PTR_StructReg,GPIO_tenuPINS copy_PinNum,u16 *Add_PinVal);

GPIO_enuErrorStatus_t GPIO_OutputPort(GPIO_StructReg * PTR_StructReg,u16 Cpy_PortVal);

GPIO_enuErrorStatus_t GPIO_OutputPin(GPIO_StructReg * PTR_StructReg,GPIO_tenuPINS copy_PinNum,u16 Cpy_PinState);








GPIO_enuErrorStatus_t GPIO_SetResetBitRegister(GPIO_StructReg * PTR_StructReg,u16 Cpy_SetVal,u16 Cpy_ResetVal);

GPIO_enuErrorStatus_t GPIO_AlternateFunLow(GPIO_StructReg * PTR_StructReg,GPIO_tenuAFs Cpy_AF,GPIO_tenuPINS GPIOenuPIN);

GPIO_enuErrorStatus_t GPIO_AlternateFunHigh(GPIO_StructReg * PTR_StructReg,GPIO_tenuAFs Cpy_AF,GPIO_tenuPINS GPIOenuPIN);



GPIO_enuErrorStatus_t GPIO_AlternateFun(GPIO_StructReg * PTR_StructReg,GPIO_tenuAFs Cpy_AF,GPIO_tenuPINS GPIOenuPIN);
/*
//Configuration habla ??
GPIO_enuErrorStatus_t GPIO_LockBitConfiguration(GPIO_StructReg * PTR_StructReg)... ;

*/





#endif





