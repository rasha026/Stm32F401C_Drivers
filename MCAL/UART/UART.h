
#include "UART_cfg.h"
#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"

#define USART_1_BASE_ADDRESS 			0x40011000
#define USART_2 BASE_ADDRESS			0x40004400
#define USART_6 BASE_ADDRESS			0x40011400

#define BBR_3		3
#define BBR_4		4

#define BBR_MASK   0XFFFF0000

#define SBK				0
#define RWU				1
#define RE				2
#define TE				3
#define IDLEIE			4
#define RXNEIE			5
#define TCIE			6
#define TXEIE			7
#define PEIE			8
#define PS				9
#define PCE				10
#define WAKE 			11
#define M				12
#define UE 				13
#define OVER8 			15
//////////////////////////////
#define PE				0
#define FE				1
#define NF				2
#define ORE				3
#define IDLE			4
#define RXNE			5
#define TC				6
#define TXE				7
#define LBD				8
#define CTS				9



typedef struct
{
	u32	USART_SR;
	u32 USART_DR;
	u32 USART_BRR;
	u32 USART_CR1;
	u32 USART_CR2;
	u32 USART_CR3;
	u32 USART_GTPR;

}UARTX;



#define USART1				((UARTX*)(0x40011000))
#define USART2				((UARTX*)(0x40004400))
#define USART6				((UARTX*)(0x40011400))

typedef void(*UARTCBF_t)(void);



typedef enum{
	USART_enuStateOK= 0,
	USART_enuStateNOTOK,
	USART_enuStateNullPTR,
	USART_enuStateBusy,
	USART_enuStateIdle,
}USART_enuErrorStatus_t;





typedef enum{
	oversampling_by_16=0,
	oversampling_by_8,
}Oversampling_mode_cfg_t;

typedef enum{
	USART_Disable=0,
	USART_ENABLE,
}USART_ENABLE_cfg_t;

typedef enum{
	DataPins_8=0,
	DataPins_9,
}wordLength_cfg_t;

typedef enum{
	idleLine=0,
	addressMark,
}Wakeup_method_cfg_t;


typedef enum{
	evenParity=0,
	oddParity,
	DisableParity,
}paritySelection_cfg_t;


typedef enum{
	disable=0,
	enable,
}setEnable_cfg_t;




typedef struct
{
	UARTX* UART_X;
	Oversampling_mode_cfg_t Oversampling;
	setEnable_cfg_t UartEnable;
	wordLength_cfg_t WordLength;
	paritySelection_cfg_t ParityControl;

	setEnable_cfg_t TransDateRegisterEmpty_Int;
	setEnable_cfg_t ReceiveDateRegisterEmpty_Int;


	setEnable_cfg_t TransComplete_Int;


	setEnable_cfg_t TransEnable;
	setEnable_cfg_t ReceiveEnable;
	u16 BaudRate;

}Uart_ConfigType_t;




//USART_enuErrorStatus_t USART_AsyncConfig(UARTX* cpy_USART ,USART_cfg_t cpy_USART_cfg);



USART_enuErrorStatus_t USART_SetPEInterrupt(UARTX* cpy_USART,u8 cpy_enableVal );


USART_enuErrorStatus_t USART_SetOverSampling(UARTX* cpy_USART,Oversampling_mode_cfg_t cpy_enableVal );
USART_enuErrorStatus_t USART_SetUSART(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal );

USART_enuErrorStatus_t USART_SetWordLength(UARTX* cpy_USART,wordLength_cfg_t cpy_enableVal );


USART_enuErrorStatus_t USART_SetParity(UARTX* cpy_USART,paritySelection_cfg_t cpy_enableVal );


USART_enuErrorStatus_t USART_SetTXInterrupt(UARTX* cpy_USART,u8 cpy_enableVal );
USART_enuErrorStatus_t USART_SetTransmissionCompleteInterrupt(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal );

USART_enuErrorStatus_t USART_SetRXNEInterrupt(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal );

USART_enuErrorStatus_t USART_SetTXEIEInterrupt(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal );



USART_enuErrorStatus_t USART_SetTransmitter(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal );

USART_enuErrorStatus_t USART_SetReceiver(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal );


USART_enuErrorStatus_t USART_ClearStatusRegister(UARTX* cpy_USART );


USART_enuErrorStatus_t USART_SetBaudRate(UARTX* cpy_USART,u32 cpy_baudRate );

USART_enuErrorStatus_t USART_SendBuffer(UARTX* cpy_USART ,u8* Buffer,u32 size );

USART_enuErrorStatus_t test(UARTX* cpy_USART ,u8* Buffer,u32 size );


USART_enuErrorStatus_t test2(UARTX* cpy_USART ,u8* Buffer,u32 size );

USART_enuErrorStatus_t USART_ReceiveBuffer(UARTX* cpy_USART ,u8* Buffer,u32 size );


USART_enuErrorStatus_t USART_WriteData_ZeroCopy(UARTX* cpy_USART ,u16 cpy_data );

USART_enuErrorStatus_t USART_ReadData(UARTX* cpy_USART ,u16 *cpyAdd_data );

USART_enuErrorStatus_t  USART_SetCallBackFun(UARTCBF_t NotifyFun);

