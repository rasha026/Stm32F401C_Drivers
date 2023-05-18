#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"


/************************************************************************/
/*					Macros of RCC Register								*/
/************************************************************************/
#define  	RCC_BASE_ADDRESS    	(0x40023800)
#define		RCC_CR					*((volatile u32*)(RCC_BASE_ADDRESS	+	0x00))
#define		RCC_PLLCFGR				*((volatile u32*)(RCC_BASE_ADDRESS	+	0x04))
#define		RCC_CFGR				*((volatile u32*)(RCC_BASE_ADDRESS	+	0x08))
#define		RCC_CIR					*((volatile u32*)(RCC_BASE_ADDRESS	+	0x0C))
#define		RCC_AHB1RSTR			*((volatile u32*)(RCC_BASE_ADDRESS	+	0x10))
#define		RCC_AHB2RSTR			*((volatile u32*)(RCC_BASE_ADDRESS	+	0x14))

#define		RCC_APB1RSTR			*((volatile u32*)(RCC_BASE_ADDRESS	+	0x20))
#define		RCC_APB2RSTR			*((volatile u32*)(RCC_BASE_ADDRESS	+	0x24))

#define		RCC_AHB1ENR				*((volatile u32*)(RCC_BASE_ADDRESS	+	0x30))
#define		RCC_AHB2ENR				*((volatile u32*)(RCC_BASE_ADDRESS	+	0x34))

#define		RCC_APB1ENR				*((volatile u32*)(RCC_BASE_ADDRESS	+	0x40))
#define		RCC_APB2ENR				*((volatile u32*)(RCC_BASE_ADDRESS	+	0x44))

//RCC_CR
#define HSION 				0
#define HSIRDY 				1
#define HSITRIM0			3 			//DEAULT =10000 step =+-40KHZ

#define HSEON				16
#define HSERDY				17
#define HSEPYP				18
#define CSSON				19

#define PLLON				24
#define PLLRDY				25
#define PLLON2				26
#define PLLRDY2				27



#define HSI_TRIM_MASK		~(0xFFFFFFF8) 		//111...  00000 111


//RCC_CFGR
#define SW0					0
#define SW1					1
#define SWS0				2
#define SWS1				3

//RCC_PLLCFGR
#define PLLQ0				24
#define PLLP0				16
#define PLLM0				0
#define PLLN0				6
#define PLLSRC				22
#define PLLQ_MASK 			(0xF0FFFFFF)
#define PLLM_MASK 			(0xFFFFFFC0)
#define PLLN_MASK 			(0xFFFF8030)
#define PLLP_MASK 			(0xFFFCFFFF)

#define CSS_CFG 			CSS_ON
#define CSS_ON 				1
#define CSS_OF 				0

#define HSE_PYP_CFG 		HSE_PYP_ON
#define HSE_PYP_ON 			1
#define HSE_PYP_OF 			0

#define WAITING_TIME 0xff


#define DISABLE 		0
#define ENABLE 			1

typedef enum{
	RCC_enuStateOK= 0,
	RCC_enuStateNOTOK,
	RCC_enuStateNullPTR,
	RCC_enuStateReady,
	RCC_enuStateNOTReady,
	RCC_enuStateWrongCf,

}RCC_enuErrorStatus_t;


typedef enum{
	OFF=0,
	ON,
}RCC_enu_Status;

typedef enum{
	HSI=0,
	PLLI2S,
	HSE,
	PLL,
}RCC_enu_t_CONF;



typedef enum
{
	RCC_AHB1PORTA=0,
	RCC_AHB1_PORTB,
	RCC_AHB1_PORTC,
	RCC_AHB1_PORTD,
	RCC_AHB1_PORTE,
	RCC_AHB1_DMA1=21,
	RCC_AHB1_DMA2=22,

}RCC_AHB1Peripherals;




//CFG
typedef enum{
	NotReady=0,
	Ready,  //LOCKED if pll

}RCC_enu_RDYStatus;




typedef enum{
	no_division=0,
	division_by_2=4,
	division_by_3,
	division_by_4,
	division_by_5,
}RCC_enu_t_Prescaler;



typedef enum{
	HSI_oscillator=0,
	HSE_oscillator,
	PLL_oscillator,
	not_allowed,
}RCC_enu_t_System_clk_sw;


typedef enum{
	enu_tPLLCFG_HSI=0,
	enu_tPLLCFG_HSE,
}enu_tPLLCFG;



/*
 * definition:Function to Set HSI
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:RCC_enu_Status
 */
RCC_enuErrorStatus_t RCC_SetHSI(RCC_enu_Status cpy_RCCstatus);



/*
 * definition:Function to return if HSI is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:void
 */
RCC_enuErrorStatus_t RCC_IsReadyHSI();

/*
 * definition:Function to set configuration of HSI is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:HSITrimVal
 */
RCC_enuErrorStatus_t RCC_CfgSHI(u8 cpy_HSITrimVal);




/*
 * definition:Function to Set HSE
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:RCC_enu_Status
 */
RCC_enuErrorStatus_t RCC_SetHSE(RCC_enu_Status cpy_RCCstatus);


/*
 * definition:Function to return if HSE is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:void
 */
RCC_enuErrorStatus_t RCC_IsReadyHSE();

/*
 * definition:Function to set configuration of HSE is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:VOID
 */
RCC_enuErrorStatus_t RCC_CfgHSE();





/*
 * definition:Function to Set PLL
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:RCC_enu_Status
 */
RCC_enuErrorStatus_t RCC_SetPLL(RCC_enu_Status cpy_RCCstatus);


/*
 * definition:Function to return if PLL is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:void
 */
RCC_enuErrorStatus_t RCC_IsReadyPLL();



/*
 * definition:Function to set configuration of PLL is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT: R_Val, P_Val, Q_Val, N_Val, M_Val, PLLSRC_Val
 */
RCC_enuErrorStatus_t RCC_CfgPLL(u8 P_Val,u8 Q_Val,u16 N_Val,u8 M_Val,enu_tPLLCFG PLLSRC_Val);




/*
 * definition:Function to Set PLL2
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:RCC_enu_Status
 */
RCC_enuErrorStatus_t RCC_SetPLL2(RCC_enu_Status cpy_RCCstatus);



/*
 * definition:Function to return if PLL2 is ready or not
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:void
 */
RCC_enuErrorStatus_t RCC_IsReadyPLL2();





/*
 * definition:Function to Set CSS
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:RCC_enu_Status
 */

RCC_enuErrorStatus_t RCC_SetCSS();



/*
 * definition:Function to get System Clock
 * RETURN:RCC_enuErrorStatus_t
 * INPUT:*cpy_AddClkSys
 */

RCC_enuErrorStatus_t RCC_GetSysClk( u8 *cpy_AddClkSys);




/*
RCC_enuErrorStatus_t RCC_CfgSHI(u8 cpy_HSITrimVal){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u32 u32_LocalMask;

	u32_LocalMask= RCC_CR;
	u32_LocalMask&=HSI_TRIM_MASK;
	u32_LocalMask|=cpy_HSITrimVal<<HSITRIM0;

	RCC_CR=u32_LocalMask;

	return status;
}
*/




RCC_enuErrorStatus_t RCC_SetHSESysClk();


RCC_enuErrorStatus_t RCC_SetPHSISysClk();

RCC_enuErrorStatus_t RCC_SetPLLSysClk();


void RCC_GetFCPU_M(u16 *cpy_AddFCPU);




