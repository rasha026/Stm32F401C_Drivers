#include "DMA.h"
#include "../RCC/RCC.h"

static DMA_Cbf_t cbf;







DMA_enuErrorStatus_t DMA_Init(DMA_Cfg_t DMA_Cfg){
	DMA_enuErrorStatus_t status=DMA_enuStateOK;
	u32 localMask;

	/*Enable  DMA Clock*/
	if(DMA_Cfg.DMA==DMA1)
		RCC_AHB1EnablePeripheral(RCC_AHB1_DMA1 ,ENABLE);

	else if(DMA_Cfg.DMA==DMA2)
		RCC_AHB1EnablePeripheral(RCC_AHB1_DMA2 ,ENABLE);

		/*MAKE Sure Stream is Disabled*/


			localMask=DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR;
			localMask&=0xF1FFFFFF;

			/*Select channel*/
			localMask|=DMA_Cfg.DMA_Channel<<25;


			/*MSIZE*/
			localMask&=0xFFFF9FFF;
			localMask|=DMA_Cfg.Msize<<13;


			/*Psize*/

			localMask&=0xFFFFE7FF;
			localMask|=DMA_Cfg.Psize<<11;



			/*Select priority*/
			localMask&=0xFFFCFFFF;
			localMask|=DMA_Cfg.priority<<16;

			/*Set Direction*/
			localMask&=0xFFFFFF3F;
			localMask|=DMA_Cfg.dirMode<<6;

			DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR=localMask;

			//MEMORY Increment Mode
			if(DMA_Cfg.DMA_MemIncMode)
				SET_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR,10);
			else
				CLR_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR,10);

			//Peripheral Increment Mode
			if(DMA_Cfg.DMA_PerIncMode)
				SET_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR,9);
			else
				CLR_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR,9);


			SET_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR,4);


			//No Of Data
			DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxNDTR=DMA_Cfg.NofData;
			DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxPAR=DMA_Cfg.PeriAddress;
			DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxM0AR=DMA_Cfg.MemAddress;

			if(DMA_Cfg.DMA_DIR_FIFO_Mode==DirectMode)
			{
				CLR_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxFCR,2);

			}
			else if(DMA_Cfg.DMA_DIR_FIFO_Mode==FIFOMode)
			{
				SET_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxFCR,2);
				localMask=DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxFCR;
				localMask&=0XFFFFFFFC;
				localMask|=DMA_Cfg.DMA_FIFOThreshold;
				DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxFCR=localMask;

			}

			//Enable
			SET_BIT(DMA_Cfg.DMA->Cfg_Reg[DMA_Cfg.Stream].DMA_SxCR,0);







	return status;

}











void DMA1_Stream0_IRQHandler(void)
{



}

void DMA1_Stream1_IRQHandler(void)
{

}

void DMA1_Stream2_IRQHandler(void)
{

}

void DMA1_Stream3_IRQHandler(void)
{

}

void DMA1_Stream4_IRQHandler(void)
{

}



void DMA1_Stream6_IRQHandler(void)
{

}

void DMA1_Stream7_IRQHandler(void)
{

}


/*****DMA2 Handler**************/


void DMA2_Stream2_IRQHandler(void)
{

	trace_printf("Receive work\n");



}


void DMA2_Stream7_IRQHandler(void)
{trace_printf("Dma work\n");

	u8 txDone;
	trace_printf("Dma work\n");
	txDone =GET_BIT(DMA2->DMA_HISR,27);
	if(txDone)
	{
		CLR_BIT(DMA2->Cfg_Reg[7].DMA_SxCR,4);
		trace_printf("Byeee\n");
	}


}




void DMA2_Stream5_IRQHandler(void)
{


}
void DMA2_Stream4_IRQHandler(void)
{



}

