


#include "RCC.h"
#include "../GPIO/GPIO.h"




RCC_enuErrorStatus_t RCC_SetHSI(RCC_enu_Status cpy_RCCstatus){
	u8 local_ClkSys;
	RCC_GetSysClk(&local_ClkSys);

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	if(cpy_RCCstatus)
	{
		SET_BIT(RCC_CR,HSION);
	}
	else
	{
		if(local_ClkSys==cpy_RCCstatus)
		{
			status=RCC_enuStateWrongCf;
		}
		else
		{
		CLR_BIT(RCC_CR,HSION);
		}
	}

	return status;

}

RCC_enuErrorStatus_t RCC_IsReadyHSI(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u16 localConter=0;

	//Wait till be ready
	while(GET_BIT(RCC_CR,HSIRDY)==NotReady && localConter<WAITING_TIME)
		{
			localConter++;
		}

		if(GET_BIT(RCC_CR,HSIRDY)==Ready)
		{
			status=RCC_enuStateOK;
		}
		else{
			status=RCC_enuStateNOTReady;
		}

	return status;
}


RCC_enuErrorStatus_t RCC_CfgSHI(u8 cpy_HSITrimVal){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u32 u32_LocalMask;

	u32_LocalMask= RCC_CR;
	u32_LocalMask&=HSI_TRIM_MASK;
	u32_LocalMask|=cpy_HSITrimVal<<HSITRIM0;

	RCC_CR=u32_LocalMask;

	return status;
}





//HSE
RCC_enuErrorStatus_t RCC_SetHSESysClk(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u32 localMAsk;

	localMAsk=RCC_CFGR;
	localMAsk&=(0xFFFFFFFC);
	localMAsk|=1;
	RCC_CFGR=localMAsk;


	return status;

}


RCC_enuErrorStatus_t RCC_SetPHSISysClk(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u32 localMAsk;

	localMAsk=RCC_CFGR;
	localMAsk&=(0xFFFFFFFC);
	//localMAsk|=0;
	RCC_CFGR=localMAsk;


	return status;

}


RCC_enuErrorStatus_t RCC_SetPLLSysClk(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u32 localMAsk;

	localMAsk=RCC_CFGR;
	localMAsk&=(0xFFFFFFFC);
	localMAsk|=2;
	RCC_CFGR=localMAsk;


	return status;

}



//HSE
RCC_enuErrorStatus_t RCC_SetHSE(RCC_enu_Status cpy_RCCstatus){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u8 local_ClkSys;
	RCC_GetSysClk(&local_ClkSys);

	if(cpy_RCCstatus)
	{
		SET_BIT(RCC_CR,HSEON);


	}
	else
	{
		if(local_ClkSys==cpy_RCCstatus)
		{
			status=RCC_enuStateWrongCf;

		}
		else
		{
			CLR_BIT(RCC_CR,HSEON);

		}

	}

	return status;

}

RCC_enuErrorStatus_t RCC_IsReadyHSE(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u16 localConter=0;


	//Wait till be ready
	while(GET_BIT(RCC_CR,HSERDY)==NotReady && localConter<WAITING_TIME)
		{
			localConter++;
		}

		if(GET_BIT(RCC_CR,HSERDY)==Ready)
		{
			status=RCC_enuStateReady;



		}
		else{
			status=RCC_enuStateNOTReady;
		}

	return status;
}


RCC_enuErrorStatus_t RCC_CfgHSE(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;

#if (HSE_PYP_CFG==HSE_PYP_ON)
	{
		SET_BIT(RCC_CR,HSEPYP);
	}
#else
	{
		CLR_BIT(RCC_CR,HSEPYP);

	}
#endif


	return status;
}






//PLL
RCC_enuErrorStatus_t RCC_SetPLL(RCC_enu_Status cpy_RCCstatus){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;

	u8 local_ClkSys;
	RCC_GetSysClk(&local_ClkSys);

	if(cpy_RCCstatus)
	{
		SET_BIT(RCC_CR,PLLON);
	}
	else
	{
		if(local_ClkSys==cpy_RCCstatus)
			{
				status=RCC_enuStateWrongCf;
			}
			else
			{
				CLR_BIT(RCC_CR,PLLON);
			}

	}
	return status;

}

RCC_enuErrorStatus_t RCC_IsReadyPLL(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u16 localConter=0;

	//Wait till be ready
	while(GET_BIT(RCC_CR,PLLRDY)==NotReady && localConter<WAITING_TIME)
		{
			localConter++;
		}

		if(GET_BIT(RCC_CR,PLLRDY)==Ready)
		{
			status=RCC_enuStateReady;
		}
		else{
			status=RCC_enuStateNOTReady;
		}

	return status;
}

/*
 *
 *
 * 0: HSI clock selected as PLL and PLLI2S clock entry
 * 1: HSE oscillator clock selected as PLL and PLLI2S clock entr
 *
 */
RCC_enuErrorStatus_t RCC_CfgPLL(u8 P_Val,u8 Q_Val,u16 N_Val,u8 M_Val,enu_tPLLCFG PLLSRC_Val){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u32 u32_localMask;
	if(GET_BIT(RCC_CR,PLLON)==OFF)
	{
		if(Q_Val <=2 || Q_Val >=15)
		{
			u32_localMask=RCC_PLLCFGR;
			u32_localMask&=PLLQ_MASK;
			u32_localMask|=Q_Val<<PLLQ0;
			RCC_PLLCFGR=u32_localMask;

		}
		else
		{
			status=RCC_enuStateWrongCf;
			return status;

		}

		if(N_Val <=2 || N_Val >=432)
		{
			u32_localMask=RCC_PLLCFGR;
			u32_localMask&=PLLN_MASK;
			u32_localMask|=N_Val<<PLLN0;
			RCC_PLLCFGR=u32_localMask;


		}
		else
		{
			status=RCC_enuStateWrongCf;
			return status;

		}
		if(M_Val <=2 || M_Val >=63)
		{
			u32_localMask=RCC_PLLCFGR;
			u32_localMask&=PLLM_MASK;
			u32_localMask|=M_Val<<PLLM0;
			RCC_PLLCFGR=u32_localMask;


		}
		else
		{
			status=RCC_enuStateWrongCf;
			return status;

		}

		if( (P_Val/2==0)&& (P_Val <=2 || P_Val >=8) )
		{
			u32_localMask=RCC_PLLCFGR;
			u32_localMask&=PLLP_MASK;
			u32_localMask|=P_Val<<PLLP0;
			RCC_PLLCFGR=u32_localMask;


		}
		else
		{
			status=RCC_enuStateWrongCf;
			return status;

		}


		if(GET_BIT(RCC_CR,PLLON2)==OFF)
		{
			CLR_BIT(RCC_PLLCFGR,PLLSRC);
			RCC_PLLCFGR|=PLLSRC_Val<<PLLSRC;
		}
		else
		{
			status=RCC_enuStateWrongCf;
			return status;

		}
	}

	else{
		status=RCC_enuStateWrongCf;
	}


//RCC_PLLCFGR

	return status;
}







//PLL2

RCC_enuErrorStatus_t RCC_SetPLL2(RCC_enu_Status cpy_RCCstatus){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;

	u8 local_ClkSys;
	RCC_GetSysClk(&local_ClkSys);

	if(cpy_RCCstatus)
	{
		SET_BIT(RCC_CR,PLLON2);
	}
	else
	{
		if(local_ClkSys==cpy_RCCstatus)
			{
				status=RCC_enuStateWrongCf;
			}
			else
			{
				CLR_BIT(RCC_CR,PLLON2);
			}

	}
	return status;

}

RCC_enuErrorStatus_t RCC_IsReadyPLL2(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	u16 localConter=0;

	//Wait till be ready
	while(GET_BIT(RCC_CR,PLLRDY2)==NotReady && localConter<WAITING_TIME)
		{
			localConter++;
		}

		if(GET_BIT(RCC_CR,PLLRDY2)==Ready)
		{
			status=RCC_enuStateReady;
		}
		else{
			status=RCC_enuStateNOTReady;
		}

	return status;
}







RCC_enuErrorStatus_t RCC_SetCSS(){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
#if( CSS_ENABLE == CSS_ON)
	{
		SET_BIT(RCC_CR,CSSON);


	}
#else
	{
		CLR_BIT(RCC_CR,CSSON);

	}
#endif

	return status;
}




RCC_enuErrorStatus_t RCC_GetSysClk(u8 *cpy_AddClkSys){

	RCC_enuErrorStatus_t status =RCC_enuStateOK;
	if(cpy_AddClkSys){
		u32 localSW0=0,localSW1=0;
		localSW0=GET_BIT(RCC_CFGR,SW0);
		localSW1=GET_BIT(RCC_CFGR,SW1);
		*cpy_AddClkSys=localSW0|(localSW1<<1);
	}
	else
	{
		status=RCC_enuStateNullPTR;
	}

	return status;
}



//NEED TO edit HSE And PLL

void RCC_GetFCPU_M(u16 *cpy_AddFCPU){


		u8 localSW0=0,localSW1=0;
		u8 localVal;

		RCC_GetSysClk(&localVal);
		//trace_printf("%d",*cpy_AddClkSys);
		if(localVal ==HSI_oscillator)
			*cpy_AddFCPU=16;
		else if (localVal ==HSE_oscillator)
			*cpy_AddFCPU=16;
		else if (localVal ==PLL_oscillator)
			*cpy_AddFCPU=16;




}


#define OTGFSEN   7
RCC_enuErrorStatus_t RCC_SetAHB2(u8 cpySetVal)
{
	RCC_enuErrorStatus_t status =RCC_enuStateOK;

	if(cpySetVal==1){
		SET_BIT(RCC_AHB2ENR,OTGFSEN);

	}
	else if(cpySetVal==0)
	{
		CLR_BIT(RCC_AHB2ENR,OTGFSEN);

	}


	return status;

}



RCC_enuErrorStatus_t RCC_SetAHB1(u8 cpy_peripheral,u8 cpySetVal)
{
	RCC_enuErrorStatus_t status =RCC_enuStateOK;

	if(cpySetVal==1){
		SET_BIT(RCC_AHB1ENR,cpy_peripheral);

	}
	else if(cpySetVal==0)
	{
		CLR_BIT(RCC_AHB1ENR,cpy_peripheral);

	}


	return status;

}


RCC_enuErrorStatus_t RCC_SetAPB2(u8 cpy_peripheral,u8 cpySetVal)
{
	RCC_enuErrorStatus_t status =RCC_enuStateOK;

	if(cpySetVal==1){
		SET_BIT(RCC_APB2ENR,cpy_peripheral);

	}
	else if(cpySetVal==0)
	{
		CLR_BIT(RCC_AHB2ENR,cpy_peripheral);

	}


	return status;

}


void RCC_EnablePort(GPIO_tenuPorts GPIOX )
{
	SET_BIT(RCC_AHB1ENR,GPIOX); //FOR Port A
}



void RCC_AHB1EnablePeripheral(RCC_AHB1Peripherals RCC_AHB1Peripheral ,u8 val)
{
	if (val)
		SET_BIT(RCC_AHB1ENR,RCC_AHB1Peripheral);
	else
		CLR_BIT(RCC_AHB1ENR,RCC_AHB1Peripheral);
}



