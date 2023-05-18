#include "UART.h"
#include "../NVIC/NVIC.h"
#include "../RCC/RCC.h"
#include "diag/Trace.h"
#include "../DMA/DMA.h"

static UARTCBF_t UARTCBF;

static void Transmit_Recieve_CallBackFun();


u8* txBuffer;
u32 txSize;
u32 txIdx;
USART_enuErrorStatus_t tx_state=USART_enuStateIdle;

u8* rxBuffer;
u32 rxSize;
u32 rxIdx;
USART_enuErrorStatus_t rx_state=USART_enuStateIdle;






 void  USART_Init(Uart_ConfigType_t  cpy_USARTCfg )
{
	 u32 localMask;
	 //Enable port
	 if(tx_Pin.PORTX==GPIOA)
	  RCC_EnablePort(GPIO_enuPorts_PORTA);
	 else if(tx_Pin.PORTX==GPIOB)
		 RCC_EnablePort(GPIO_enuPorts_PORTB);
	 else if(tx_Pin.PORTX==GPIOC)
		 RCC_EnablePort(GPIO_enuPorts_PORTC);



	 if (cpy_USARTCfg.UART_X==USART1)
	 {
		 RCC_SetAPB2(4,1);
		 //Alternate FUN
		 GPIOA->AFRH=0X770;
	 }

	 else if (cpy_USARTCfg.UART_X==USART2)
	 {
		 //AF7
		 GPIOA->AFRH=0X770;
	 }


	 //init rx and tx pins
	GPIO_InitPin(&tx_Pin);
	GPIO_InitPin(&rx_Pin);

	//NVIC_EnableInterrupt(NVIC_enuPeripheral_37 );

	USART_SetOverSampling(cpy_USARTCfg.UART_X,cpy_USARTCfg.Oversampling);
	USART_SetBaudRate(cpy_USARTCfg.UART_X,cpy_USARTCfg.BaudRate );
	USART_SetUSART(cpy_USARTCfg.UART_X,cpy_USARTCfg.UartEnable );
	USART_SetWordLength(cpy_USARTCfg.UART_X,cpy_USARTCfg.WordLength );
	USART_SetParity(cpy_USARTCfg.UART_X,cpy_USARTCfg.ParityControl );
	//USART_SetTransmitter(cpy_USARTCfg.UART_X,cpy_USARTCfg.TransEnable  );
	//USART_SetReceiver(cpy_USARTCfg.UART_X,cpy_USARTCfg.ReceiveEnable  );


	USART_SetCallBackFun(&Transmit_Recieve_CallBackFun);
	USART_ClearStatusRegister(cpy_USARTCfg.UART_X);

}




USART_enuErrorStatus_t USART_SetOverSampling(UARTX* cpy_USART,Oversampling_mode_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==oversampling_by_8)
			SET_BIT(cpy_USART->USART_CR1,OVER8);
		else
			CLR_BIT(cpy_USART->USART_CR1,OVER8);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}
USART_enuErrorStatus_t USART_SetUSART(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==enable)
			SET_BIT(cpy_USART->USART_CR1,UE);
		else
			CLR_BIT(cpy_USART->USART_CR1,UE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}


USART_enuErrorStatus_t USART_SetWordLength(UARTX* cpy_USART,wordLength_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==DataPins_9)
			SET_BIT(cpy_USART->USART_CR1,M);
		else
			CLR_BIT(cpy_USART->USART_CR1,M);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}




USART_enuErrorStatus_t USART_SetParity(UARTX* cpy_USART,paritySelection_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==DisableParity)
			CLR_BIT(cpy_USART->USART_CR1,PCE);
		else
		{
			SET_BIT(cpy_USART->USART_CR1,PCE);
			if(cpy_enableVal==evenParity)
				CLR_BIT(cpy_USART->USART_CR1,PS);
			else
				SET_BIT(cpy_USART->USART_CR1,PS);
		}

	}
	else
		status=USART_enuStateNullPTR;

	return status;
}



USART_enuErrorStatus_t USART_SetTXInterrupt(UARTX* cpy_USART,u8 cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal)
			SET_BIT(cpy_USART->USART_CR1,TXEIE);
		else
			CLR_BIT(cpy_USART->USART_CR1,TXEIE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}

USART_enuErrorStatus_t USART_SetTransmissionCompleteInterrupt(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==enable)
			SET_BIT(cpy_USART->USART_CR1,TCIE);
		else
			CLR_BIT(cpy_USART->USART_CR1,TCIE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}

USART_enuErrorStatus_t USART_SetRXNEInterrupt(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==enable)
			SET_BIT(cpy_USART->USART_CR1,RXNEIE);
		else
			CLR_BIT(cpy_USART->USART_CR1,RXNEIE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}

USART_enuErrorStatus_t USART_SetTXEIEInterrupt(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==enable)
			SET_BIT(cpy_USART->USART_CR1,TXEIE);
		else
			CLR_BIT(cpy_USART->USART_CR1,TXEIE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}




USART_enuErrorStatus_t USART_SetTransmitter(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==enable)
			SET_BIT(cpy_USART->USART_CR1,TE);
		else
			CLR_BIT(cpy_USART->USART_CR1,TE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}


USART_enuErrorStatus_t USART_SetReceiver(UARTX* cpy_USART,setEnable_cfg_t cpy_enableVal )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{
		if(cpy_enableVal==enable)
			SET_BIT(cpy_USART->USART_CR1,RE);
		else
			CLR_BIT(cpy_USART->USART_CR1,RE);
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}


USART_enuErrorStatus_t USART_ClearStatusRegister(UARTX* cpy_USART )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{

		cpy_USART->USART_SR=0;
	}
	else
		status=USART_enuStateNullPTR;

	return status;
}


USART_enuErrorStatus_t USART_SetBaudRate(UARTX* cpy_USART,u32 cpy_baudRate )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	u16 FCPU;
	f64 f_Calc;
	RCC_GetFCPU_M(&FCPU);

	if(cpy_USART)
	{

		if(GET_BIT(cpy_USART->USART_CR1,OVER8)==0)
			if (FCPU==16)
				{f_Calc=16000000/(16*cpy_baudRate);
				}
		else
			if(FCPU==16)
			f_Calc=16000000/(8*cpy_baudRate);


		//trace_printf("fff%d ",(int)f_Calc);

		u32 localMask;
		f32 fraction;
		u32 ResultReal=0;
		u32 ResultFraction=0;
		fraction=f_Calc -(int)(f_Calc);
		fraction *=16;
		//trace_printf("fff%d ",fraction);
	if ((int)((int)(fraction*10.0))%10>=5)
	{
		if ((int)(fraction)>=15)
		{
			ResultFraction=15;
			ResultReal=(int)(f_Calc)+1;
			//trace_printf("fff%f ",ResultReal);
		}
		else
		{
			ResultFraction=(int)(fraction)+1;
			ResultReal=(int)(f_Calc);
		}
	}

	else
	{
		//trace_printf("%d ",f_Calc);
		ResultFraction=(int)fraction;
		ResultReal=(int)(f_Calc);

	}
	localMask=cpy_USART->USART_BRR;
	localMask&=BBR_MASK;
	localMask|=ResultFraction|(ResultReal<<BBR_4);

	cpy_USART->USART_BRR=localMask;
	}
	else
		status=USART_enuStateNullPTR;


	return status;
}


USART_enuErrorStatus_t USART_SendBuffer_ZeroCopy(UARTX* cpy_USART ,u8* Buffer,u32 size )
{
	USART_enuErrorStatus_t status=USART_enuStateBusy;
	if(cpy_USART)
		{


		SET_BIT(cpy_USART->USART_CR1,TE);
		SET_BIT(cpy_USART->USART_CR1,TCIE);
		if(tx_state==USART_enuStateIdle)
		{

			txBuffer=Buffer;
			//trace_printf(" ffffff%c",txBuffer[0]);
			txIdx=0;
			txSize=size;
			tx_state=USART_enuStateBusy;
			USART1->USART_DR =Buffer[txIdx];

			txIdx++;
				}


		 status=USART_enuStateIdle;

		}
	else
		status=USART_enuStateNullPTR;
	return status;
}



USART_enuErrorStatus_t USART_ReceiveBuffer(UARTX* cpy_USART ,u8* Buffer,u32 size )
{
	USART_enuErrorStatus_t status=USART_enuStateBusy;
	if(cpy_USART)
		{

		if(rx_state==USART_enuStateIdle)
		{
			SET_BIT(cpy_USART->USART_CR1,RE);
			/*Enable interrupt*/
			SET_BIT(cpy_USART->USART_CR1,RXNEIE);
			rxBuffer=Buffer;
			rxIdx=0;
			rxSize=size;
			rx_state=USART_enuStateBusy;

			USART_ClearStatusRegister(cpy_USART);



				}
		 status=USART_enuStateIdle;

		}
	else
		status=USART_enuStateNullPTR;
	return status;
}




USART_enuErrorStatus_t USART_WriteData(UARTX* cpy_USART ,u16 cpy_data )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
		cpy_USART->USART_DR=cpy_data;
	else
		status=USART_enuStateNullPTR;
	return status;
}

USART_enuErrorStatus_t USART_ReadData(UARTX* cpy_USART ,u16 *cpyAdd_data )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpyAdd_data &&cpy_USART)
		*cpyAdd_data=cpy_USART->USART_DR;
	else
		status=USART_enuStateNullPTR;
	return status;
}


USART_enuErrorStatus_t  USART_SetCallBackFun(UARTCBF_t NotifyFun)
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(NotifyFun)
	{
		UARTCBF=NotifyFun;
	}
	else
		status=USART_enuStateNullPTR;
	return status;

}





USART_enuErrorStatus_t  USART_TransmitUsingDMA(UARTX* cpy_USART,u8* Buffer,u32 size )
{
	USART_enuErrorStatus_t status=USART_enuStateOK;

	SET_BIT(cpy_USART->USART_CR3,7);
	NVIC_EnableInterrupt(NVIC_enuPeripheral_70);
	if(cpy_USART)
	{

		DMA_Cfg_t DMA_Cfg={
				.DMA=DMA2,
				.Stream=Stream7,
				.dirMode=memory_to_Peripheral,
				.PeriAddress=0x40011004,
				.MemAddress=Buffer,
				.DMA_MemIncMode=incremented,
				.DMA_PerIncMode=fixed,
				.Msize=Byte,
				.Psize=Byte,
				.NofData=size,
				.DMA_Channel= Channele4,
				.DMA_DIR_FIFO_Mode=DirectMode,
				.DMA_FIFOThreshold=Full_FIFO,

		};


		SET_BIT(cpy_USART->USART_CR1,TE);



		DMA_Init(DMA_Cfg);


	}
	else
		status=USART_enuStateNullPTR;
	return status;
}

USART_enuErrorStatus_t  USART_RecieveUsingDMA(UARTX* cpy_USART,u8* Buffer,u32 size)
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	SET_BIT(cpy_USART->USART_CR3,6);
	NVIC_EnableInterrupt(NVIC_enuPeripheral_70);




	if(cpy_USART)
	{

		DMA_Cfg_t DMA_Cfg={
				.DMA=DMA2,
				.Stream=Stream2,
				.dirMode=Peripheral_to_memory,
				.PeriAddress=0x40011004,
				.MemAddress=Buffer,
				.DMA_MemIncMode=incremented,
				.DMA_PerIncMode=fixed,
				.Msize=Byte,
				.Psize=Byte,
				.NofData=size,
				.DMA_Channel= Channele4,
				.DMA_DIR_FIFO_Mode=FIFOMode,
				.DMA_FIFOThreshold=Quarter_FIFO,
				.priority=priorityHigh,
				//.DMA_Cbf=recieve_Cbf,
		};

		SET_BIT(cpy_USART->USART_CR1,RE);


		DMA_Init(DMA_Cfg);




	}
	else
		status=USART_enuStateNullPTR;

	return status;
}






void Transmit_Recieve_CallBackFun(){


	u8 txDone;
	u8 rxDone;
	txDone=GET_BIT(USART1->USART_SR,TC);
	rxDone=GET_BIT(USART1->USART_SR,RXNE);

	if(txDone)
	{

		if(txIdx<txSize)
		{

			USART1->USART_DR =txBuffer[txIdx];
			txIdx++;

		}
		else
		{

			txIdx=USART_enuStateIdle;
			CLR_BIT(USART1->USART_CR1,TCIE);
			CLR_BIT(USART1->USART_CR1,TE);
			//Notifyyyyy
		}

	}

	//Receive
	if(rxDone &&rx_state==USART_enuStateBusy)
	{	trace_printf("Done\n");



			rxBuffer[rxIdx]=USART1->USART_DR ;
			trace_printf("%c\n",rxBuffer[rxIdx]);
			rxIdx++;
			if(rxIdx==rxSize)
			{
				rx_state=USART_enuStateIdle;
				//Disable interrupt
				CLR_BIT(USART1->USART_CR1,RXNEIE);
				//Notifyyyyyy
			}


	}
	else{


	}

}

USART1_IRQHandler(void){
	static i=0;

	u8 rxDone;
	trace_printf("idle\n");
	//trace_printf("%c\n",rxBuffer[i++]);





	//

	//UARTCBF();
}

USART2_IRQHandler(void){


}
USART6_IRQHandler(void){


}


/*
USART_enuErrorStatus_t test(UARTX* cpy_USART ,u8* Buffer,u32 size )
{
	USART_enuErrorStatus_t status=USART_enuStateBusy;
	u8 i=0;
	cpy_USART->USART_SR=0;
	SET_BIT(cpy_USART->USART_CR1,TE);
	while(i<size)
	{
		cpy_USART->USART_DR=Buffer[i];
		trace_printf("ffffff%c",Buffer[i]);
		while ( GET_BIT(USART1->USART_SR,TC)==0);
		i++;

	}
}


USART_enuErrorStatus_t test2(UARTX* cpy_USART ,u8* Buffer,u32 size )
{
	USART_enuErrorStatus_t status=USART_enuStateBusy;
	u8 i=0;
	//cpy_USART->USART_SR=0;
	SET_BIT(cpy_USART->USART_CR1,RE);
	while(i<size)
	{
		while ( (USART1->USART_SR&(1<<RXNE))==0);
		Buffer[i]=cpy_USART->USART_DR;
		trace_printf("ffffff%c",Buffer[i]);

		i++;

	}
}


/*

USART_enuErrorStatus_t USART_AsyncConfig(UARTX* cpy_USART ,USART_cfg_t cpy_USART_cfg)
{
	USART_enuErrorStatus_t status=USART_enuStateOK;
	if(cpy_USART)
	{

		if(cpy_USART_cfg.Oversampling_mode==oversampling_by_16)
		{

			CLR_BIT(cpy_USART->USART_CR1,OVER8);

		}
		else
		{
			SET_BIT(cpy_USART->USART_CR1,OVER8);
		}

		if(cpy_USART_cfg.wordLength==DataPins_8)
		{

			CLR_BIT(cpy_USART->USART_CR1,M);

		}
		else
		{
			SET_BIT(cpy_USART->USART_CR1,M);
		}

		if(cpy_USART_cfg.paritySelection==DisableParity)
		{
			CLR_BIT(cpy_USART->USART_CR1,PCE);

		}
		else
		{
			SET_BIT(cpy_USART->USART_CR1,PCE);
			if(cpy_USART_cfg.paritySelection==evenParity)
			{
				CLR_BIT(cpy_USART->USART_CR1,PS);

			}
			else if(cpy_USART_cfg.paritySelection==oddParity)
			{
				SET_BIT(cpy_USART->USART_CR1,PS);
			}

		}
		NVIC_EnableInterrupt(NVIC_enuPeripheral_37 );



		//SET_BIT(cpy_USART->USART_CR1,RE);
		//SET_BIT(cpy_USART->USART_CR1,TE);
		SET_BIT(cpy_USART->USART_CR1,UE);


		cpy_USART->USART_SR=0;






	}
	else
		status=USART_enuStateNullPTR;


	return status;
}
*/



