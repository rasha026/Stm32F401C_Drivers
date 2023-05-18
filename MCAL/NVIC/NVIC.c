



#include "NVIC.h"
#include "diag/Trace.h"

NVIC_enuErrorStatus_t NVIC_EnableInterrupt(NVIC_tenuPeripheral cpy_PeripheralNum )
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;
	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u32 *ptr;
	local_u8bitNum=cpy_PeripheralNum%32;

	local_u8RegNum=cpy_PeripheralNum/32;

	ptr=NVIC_ISER;
	ptr+=local_u8RegNum;
	SET_BIT(*ptr,local_u8bitNum);

	}
	else
	{
		status=NVIC_enuStateNOTOK;
	}

	return status;

}


NVIC_enuErrorStatus_t NVIC_DisableInterrupt(NVIC_tenuPeripheral cpy_PeripheralNum )
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;
	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u32 *ptr;
	local_u8bitNum=cpy_PeripheralNum%32;
	local_u8RegNum=cpy_PeripheralNum/32;
	trace_printf("%d",local_u8bitNum);
	trace_printf("%d",local_u8RegNum);
	ptr=NVIC_ICER;
	ptr+=local_u8RegNum;
	SET_BIT(*ptr,local_u8bitNum);
	trace_printf("%d",*ptr);
	}
	else
	{
		status=NVIC_enuStateNOTOK;
	}
	return status;

}


NVIC_enuErrorStatus_t NVIC_SetPending(NVIC_tenuPeripheral cpy_PeripheralNum)
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;
	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u32 *ptr;
	local_u8bitNum=cpy_PeripheralNum%32;
	local_u8RegNum=cpy_PeripheralNum/32;

	ptr=NVIC_ISPR;
	ptr+=local_u8RegNum;
	SET_BIT(*ptr,local_u8bitNum);
	}
	else{
		status=NVIC_enuStateNOTOK;
	}
	return status;

}

NVIC_enuErrorStatus_t NVIC_CLEARPending(NVIC_tenuPeripheral cpy_PeripheralNum)
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;
	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u32 *ptr;
	local_u8bitNum=cpy_PeripheralNum%32;
	local_u8RegNum=cpy_PeripheralNum/32;
	ptr=NVIC_ICPR;
	ptr+=local_u8RegNum;
	SET_BIT(*ptr,local_u8bitNum);
	}
	else
	{
		status=NVIC_enuStateNOTOK;
	}

	return status;

}

NVIC_enuErrorStatus_t NVIC_GetActionStatus(NVIC_tenuPeripheral cpy_PeripheralNum,u8 *Adreess_ActiveValu)
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;

	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u32 *ptr;
	local_u8bitNum=cpy_PeripheralNum%32;
	local_u8RegNum=cpy_PeripheralNum/32;
	ptr=NVIC_IABR;
	ptr+=local_u8RegNum;
	*Adreess_ActiveValu=GET_BIT(*ptr,local_u8bitNum);
	}
	else
	{
		status=NVIC_enuStateNOTOK;
	}

	return status;
}



NVIC_enuErrorStatus_t NVIC_SetPriority(NVIC_tenuPeripheral cpy_PeripheralNum)
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;

	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u8 *ptr;
	local_u8bitNum=cpy_PeripheralNum%4;
	local_u8RegNum=cpy_PeripheralNum/4;
	ptr=NVIC_IPR;
	ptr+=local_u8RegNum;

	}
	else
	{
		status=NVIC_enuStateNOTOK;
	}

	return status;

}


NVIC_enuErrorStatus_t NVIC_SetSubGroupLevel(NVIC_tenuPeripheral cpy_PeripheralNum)
{
	NVIC_enuErrorStatus_t status =NVIC_enuStateOK;

	if(cpy_PeripheralNum<NVIC_enuPeripheral_Conunt){
	u8 local_u8bitNum;
	u8 local_u8RegNum;
	u8 *ptr;
	local_u8bitNum=cpy_PeripheralNum%4;
	local_u8RegNum=cpy_PeripheralNum/4;
	ptr=NVIC_IPR;
	ptr+=local_u8RegNum;
	}
	else
	{
		status=NVIC_enuStateNOTOK;
	}

	return status;


}

