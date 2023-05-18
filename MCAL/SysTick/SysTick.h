#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"


/************************************************************************/
/*					Macros of STK Register								*/
/************************************************************************/



#define STK_CTRL						*((volatile u32*)(0xE000E010))
#define STK_LOAD						*((volatile u32*)(0xE000E014))
#define STK_VAL							*((volatile u32*)(0xE000E018))
#define STK_CALIB						*((volatile u32*)(0xE000E01C))


/*
 CFG
 */

#define STK_AHB_DIVIDED_BY_8			0
#define STK_AHB_CLOCK 					1
#define STK_EXCEPTION_DISABLE			0
#define STK_EXCEPTION_ENABLE			1

#define TICKINT							1
#define CLKSOURCE						2
#define ENABLE							0


#define ENABLE_TIMER_MASK				3
#define MAX_RELOAD						0x00FFFFFF






typedef void(*CBF_t)(void);

typedef enum{
	STK_enuStateOK= 0,
	STK_enuStateNOTOK,
	STK_enuStateNullPTR,
}STK_enuErrorStatus_t;
void STK_init();


STK_enuErrorStatus_t STK_SetCBF(CBF_t NotificationFunc);

STK_enuErrorStatus_t STK_SetPeriod_ms(u32 cpy_ReloadValue_ms);


void STK_StartTimer();

void STK_StopTimer();
STK_enuErrorStatus_t STK_SetPeriod_S(u32 cpy_ReloadValue_Ms);


STK_enuErrorStatus_t STK_SetCountTime(u32 cpy_ReloadValue);
