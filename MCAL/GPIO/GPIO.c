#include"GPIO.h"






 GPIO_enuErrorStatus_t GPIO_InitPin(GPIO_Cfg_t* cpy_struc_pin){
 	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;

 	GPIO_StructReg *  local_u32Ptr;

 	//local_u32Ptr= GPIOA;

 	local_u32Ptr =cpy_struc_pin->PORTX;

  	switch (cpy_struc_pin->GPIO_Pin_Mode) {

 		case GPIO_enuModes_Input_Floating:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_Input,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_NO_PULL,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}
 		case GPIO_enuModes_Input_Pull_down:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_Input,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_PULL_DOWN,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}
 		case GPIO_enuModes_Input_Pull_up:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_Input,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_PULL_UP,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}

 		case GPIO_enuModes_Output_open_drainPullUP:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_GeneralPurposeOutput,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputType(local_u32Ptr,OTYPER_OPEN_DRAIN,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputSpeed(local_u32Ptr, cpy_struc_pin->GPIO_Pin_Speed,cpy_struc_pin->GPIO_Pin_Pin);
 			//////////////
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_PULL_UP,cpy_struc_pin->GPIO_Pin_Pin);
 			break;
 		}
 		case GPIO_enuModes_Output_open_drain_PullDOWN:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_GeneralPurposeOutput,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputType(local_u32Ptr,OTYPER_OPEN_DRAIN,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputSpeed(local_u32Ptr, cpy_struc_pin->GPIO_Pin_Speed,cpy_struc_pin->GPIO_Pin_Pin);
 			//////////
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_PULL_DOWN,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}
 		case GPIO_enuModes_Output_push_pull_PullDOWN:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_GeneralPurposeOutput,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputType(local_u32Ptr,OTYPER_PUSH_PULL,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputSpeed(local_u32Ptr, cpy_struc_pin->GPIO_Pin_Speed,cpy_struc_pin->GPIO_Pin_Pin);
 			//////////////
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_PULL_DOWN,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}
 		case GPIO_enuModes_Output_push_pull_PullUP:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_GeneralPurposeOutput,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputType(local_u32Ptr,OTYPER_PUSH_PULL,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputSpeed(local_u32Ptr, cpy_struc_pin->GPIO_Pin_Speed,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigIOPULL_UP_DOWN(local_u32Ptr,PUPDR_PULL_UP,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}

 		case GPIO_enuModes_Analog:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_Analog,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}

 		case GPIO_enuModes_AF_Pull_down :
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_AlternateFunction,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}
 		case GPIO_enuModes_AF_Pull_up:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_AlternateFunction,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}
 		case GPIO_enuModes_AF_push_pull:
 		{
 			GPIO_ConfigIODirection(local_u32Ptr,MODERy_AlternateFunction,cpy_struc_pin->GPIO_Pin_Pin);
 			GPIO_ConfigOutputType(local_u32Ptr,OTYPER_PUSH_PULL,cpy_struc_pin->GPIO_Pin_Pin);

 			break;
 		}


 	}


 	return status;
 }





GPIO_enuErrorStatus_t GPIO_ConfigIODirection(GPIO_StructReg * PTR_StructReg,MODERy_tenuModes CPY_MODERyModes,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if(GPIOenuPIN<GPIO_enuPINNUMS)
	{

	u32 local_u32MaskReg=0;
	local_u32MaskReg=PTR_StructReg->MODER;

	/* CLEAR */
    local_u32MaskReg &=~((MASK_CLEAR_MODER)<<(GPIOenuPIN*MASK_SHIFT_BY_2));
    /* SET */
    local_u32MaskReg|=((CPY_MODERyModes)<<(GPIOenuPIN*MASK_SHIFT_BY_2));

	PTR_StructReg->MODER=local_u32MaskReg;
	}
	else{
		status=GPIO_enuStateNOTOK;
	}

	return status;

}



GPIO_enuErrorStatus_t GPIO_ConfigOutputType(GPIO_StructReg * PTR_StructReg,OTYPER_tenu_OUTPUTModes CPY_OUTPUTModes,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if(GPIOenuPIN<GPIO_enuPINNUMS)
	{

		u32 local_u32MaskReg=0;
		local_u32MaskReg=PTR_StructReg->OTYPER;



		if(CPY_OUTPUTModes)
		{
			/* SET */
			SET_BIT(local_u32MaskReg,GPIOenuPIN);
		}
		else
		{
			/* CLEAR */
			CLR_BIT(local_u32MaskReg,GPIOenuPIN);
		}

		PTR_StructReg->OTYPER=local_u32MaskReg;
	}
	else{
		status=GPIO_enuStateNOTOK;
	}

	return status;

}



GPIO_enuErrorStatus_t GPIO_ConfigOutputSpeed(GPIO_StructReg * PTR_StructReg,OSPEEDR_tenuModes CPY_OutPutSpeed,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if(GPIOenuPIN<GPIO_enuPINNUMS)
	{

	u32 local_u32MaskReg=0;
	local_u32MaskReg=PTR_StructReg->OSPEEDR;

	/* CLEAR */
    local_u32MaskReg &=~((MASK_CLEAR_MODER)<<(GPIOenuPIN*MASK_SHIFT_BY_2));
    /* SET */
    local_u32MaskReg|=((CPY_OutPutSpeed)<<(GPIOenuPIN*MASK_SHIFT_BY_2));

	PTR_StructReg->OSPEEDR=local_u32MaskReg;
	}
	else{
		status=GPIO_enuStateNOTOK;
	}

	return status;

}




GPIO_enuErrorStatus_t GPIO_ConfigIOPULL_UP_DOWN(GPIO_StructReg * PTR_StructReg,PUPDR_tenuModes CPY_PULLU_PULLD,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if(GPIOenuPIN<GPIO_enuPINNUMS)
	{

	u32 local_u32MaskReg=0;
	local_u32MaskReg=PTR_StructReg->PUPDR;

	/* CLEAR */
    local_u32MaskReg &=~((MASK_CLEAR_MODER)<<(GPIOenuPIN*MASK_SHIFT_BY_2));
    /* SET */
    local_u32MaskReg|=((CPY_PULLU_PULLD)<<(GPIOenuPIN*MASK_SHIFT_BY_2));

	PTR_StructReg->PUPDR=local_u32MaskReg;
	}
	else{
		status=GPIO_enuStateNOTOK;
	}

	return status;

}




GPIO_enuErrorStatus_t GPIO_ReadInputPort(GPIO_StructReg * PTR_StructReg,u16 *add_u16RegVal)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if(add_u16RegVal)
	{


	*add_u16RegVal=(PTR_StructReg->IDR) &(MASK_READ_INPUT_DATA);

	}
	else{
		status=GPIO_enuStateNullPTR;
	}

	return status;

}

GPIO_enuErrorStatus_t GPIO_ReadInputPin(GPIO_StructReg * PTR_StructReg,GPIO_tenuPINS copy_PinNum,u16 *Add_PinVal)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;

	*Add_PinVal=GET_BIT(PTR_StructReg->IDR,copy_PinNum) ;

	return status;

}



GPIO_enuErrorStatus_t GPIO_OutputPort(GPIO_StructReg * PTR_StructReg,u16 Cpy_PortVal)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;


		PTR_StructReg->ODR=Cpy_PortVal;

	return status;

}






GPIO_enuErrorStatus_t GPIO_OutputPin(GPIO_StructReg * PTR_StructReg,GPIO_tenuPINS copy_PinNum,u16 Cpy_PinState)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;

	if(Cpy_PinState==1){
		SET_BIT(PTR_StructReg->ODR,copy_PinNum);

	}
	else if(Cpy_PinState==0)
	{
		CLR_BIT(PTR_StructReg->ODR,copy_PinNum);

	}


	return status;

}








GPIO_enuErrorStatus_t GPIO_SetResetBitRegister(GPIO_StructReg * PTR_StructReg,u16 Cpy_SetVal,u16 Cpy_ResetVal)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;

	//if(Cpy_ResetVal== (~Cpy_SetVal)){
	u32 local_u32SetRest;
	local_u32SetRest=(Cpy_SetVal)|(Cpy_ResetVal<<8); //					<<8  not 16   whyyyyy!!!!!!!!!!!!!!

	PTR_StructReg->BSRR=local_u32SetRest;


	return status;

}


/*
//Configuration habla ??
GPIO_enuErrorStatus_t GPIO_LockBitConfiguration(GPIO_StructReg * PTR_StructReg) ///.....
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;


	return status;

}
*/


GPIO_enuErrorStatus_t GPIO_AlternateFunLow(GPIO_StructReg * PTR_StructReg,GPIO_tenuAFs Cpy_AF,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if( (Cpy_AF < GPIO_enuAFNUMs )&& (GPIOenuPIN < GPIO_enuPINNUMS ) )
	{
	u32 local_u32Mask;
	//
	local_u32Mask=PTR_StructReg->AFRL;

	/* CLEAR */
	local_u32Mask &=~((MASK_CLEAR_AF)<<(GPIOenuPIN*MASK_SHIFT_BY_4));
    /* SET */
	local_u32Mask|=((Cpy_AF)<<(GPIOenuPIN*MASK_SHIFT_BY_4));

	PTR_StructReg->AFRL=local_u32Mask;
	}
	else
	{
		status=GPIO_enuStateNOTOK;

	}

	return status;

}



GPIO_enuErrorStatus_t GPIO_AlternateFun(GPIO_StructReg * PTR_StructReg,GPIO_tenuAFs Cpy_AF,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if( (Cpy_AF < GPIO_enuAFNUMs )&& (GPIOenuPIN < GPIO_enuPINNUMS ) )
	{
	u32 local_u32Mask;
	//
	local_u32Mask=PTR_StructReg->AFRL;

	/* CLEAR */
	local_u32Mask &=~((MASK_CLEAR_AF)<<(GPIOenuPIN*MASK_SHIFT_BY_4));
    /* SET */
	local_u32Mask|=((Cpy_AF)<<(GPIOenuPIN*MASK_SHIFT_BY_4));

	PTR_StructReg->AFRL=local_u32Mask;
	}
	else
	{
		status=GPIO_enuStateNOTOK;

	}

	return status;

}



GPIO_enuErrorStatus_t GPIO_AlternateFunHigh(GPIO_StructReg * PTR_StructReg,GPIO_tenuAFs Cpy_AF,GPIO_tenuPINS GPIOenuPIN)
{
	GPIO_enuErrorStatus_t status =GPIO_enuStateOK;
	if( (Cpy_AF < GPIO_enuAFNUMs )&& (GPIOenuPIN < GPIO_enuPINNUMS ) )
	{
	u32 local_u32Mask;
	//
	local_u32Mask=PTR_StructReg->AFRH;

	/* CLEAR */
	local_u32Mask &=~((MASK_CLEAR_AF)<<(GPIOenuPIN*MASK_SHIFT_BY_4));
    /* SET */
	local_u32Mask|=((Cpy_AF)<<(GPIOenuPIN*MASK_SHIFT_BY_4));

	PTR_StructReg->AFRH=local_u32Mask;
	}
	else
	{
		status=GPIO_enuStateNOTOK;

	}

	return status;

}



