#include "SysTick_Cfg.h"

static CBF_t cbf;




void STK_init(){
	u32 local_u32MAsk;
	//local_u32MAsk=STK_CTRL;
#if STK_CLKSOURCE_MODE ==STK_AHB_CLOCK
	SET_BIT( STK_CTRL ,CLKSOURCE);


#elif STK_CLOCK_SOURCE == STK_AHB_DIVIDED_BY_8
	CLR_BIT( STK_CTRL ,CLKSOURCE);

#endif

#if STK_EXCEPTION_REQUEST == STK_EXCEPTION_DISABLE
	CLR_BIT( STK_CTRL ,TICKINT);


#elif STK_EXCEPTION_REQUEST == STK_EXCEPTION_ENABLE
	SET_BIT( STK_CTRL ,TICKINT);


#endif

}

void STK_StartTimer(){
	 STK_VAL=0;
	SET_BIT( STK_CTRL ,ENABLE);




}


void STK_StopTimer(){
	CLR_BIT( STK_CTRL ,ENABLE);
}



STK_enuErrorStatus_t STK_SetCBF(CBF_t NotificationFunc){
	STK_enuErrorStatus_t status =STK_enuStateOK;
	if(NotificationFunc)
	{
		cbf=NotificationFunc;

	}

	else
	{
		status=STK_enuStateNullPTR;

	}

	return status;
}


STK_enuErrorStatus_t STK_SetPeriod_ms(u32 cpy_ReloadValue_ms){
	STK_enuErrorStatus_t status =STK_enuStateOK;

	u32 Loc_u32ReloadValue = 0;
	if(STK_CLKSOURCE_MODE == STK_AHB_DIVIDED_BY_8)
	{
		Loc_u32ReloadValue = (cpy_ReloadValue_ms * 2000)-1;
	}
	else if(STK_CLKSOURCE_MODE == STK_AHB_CLOCK)
	{
		Loc_u32ReloadValue = (cpy_ReloadValue_ms * 16000)-1;
	}

	STK_SetCountTime(Loc_u32ReloadValue);


	return status;
}





STK_enuErrorStatus_t STK_SetPeriod_S(u32 cpy_ReloadValue_s){
	STK_enuErrorStatus_t status =STK_enuStateOK;



	return status;
}


STK_enuErrorStatus_t STK_SetCountTime(u32 cpy_ReloadValue){
	STK_enuErrorStatus_t status =STK_enuStateOK;
	if(cpy_ReloadValue<=MAX_RELOAD){

		STK_LOAD=cpy_ReloadValue;
	}
	else
	{
		status=STK_enuStateNOTOK;
	}


	return status;
}



 void SysTick_Handler (void)
{

	cbf();
}
