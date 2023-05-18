#include "LCD.h"




u8 initState=0;
u8 currentStrIdx;
LCD_enuErrorStatus_t LCD_GlobalStatus=LCD_enuStateNotInit;
void  LCD_initPin (){

		GPIO_InitPin(&LCD_Cfg.Enable);
		GPIO_InitPin(&LCD_Cfg.RS);
		GPIO_InitPin(&LCD_Cfg.RW);
		for(int i=0;i<LCD_NO_OF_LINES;i++)
		{
			GPIO_InitPin(&LCD_Cfg.data[i]);
		}
}



void LCD_SendCommand(u8 cpy_data){
	u8 resultOut;

	GPIO_OutputPin(LCD_Cfg.RS.PORTX,LCD_Cfg.RS.GPIO_Pin_Pin,0);
	GPIO_OutputPin(LCD_Cfg.RW.PORTX,LCD_Cfg.RW.GPIO_Pin_Pin,0);
	for(int i=0;i<LCD_NO_OF_LINES;i++)
	{
		resultOut=(cpy_data>>i)&1;
		GPIO_OutputPin(LCD_Cfg.data[i].PORTX,LCD_Cfg.data[i].GPIO_Pin_Pin,resultOut);
	}

	GPIO_OutputPin(LCD_Cfg.Enable.PORTX,LCD_Cfg.Enable.GPIO_Pin_Pin,1);
	GPIO_OutputPin(LCD_Cfg.Enable.PORTX,LCD_Cfg.Enable.GPIO_Pin_Pin,0);

}

void  LCD_SendData(u8 cpy_data){

	u8 resultOut;

	GPIO_OutputPin(LCD_Cfg.RS.PORTX,LCD_Cfg.RS.GPIO_Pin_Pin,1);
	GPIO_OutputPin(LCD_Cfg.RW.PORTX,LCD_Cfg.RW.GPIO_Pin_Pin,0);
	for(int i=0;i<LCD_NO_OF_LINES;i++)
	{
		resultOut=(cpy_data>>i)&1;
		GPIO_OutputPin(LCD_Cfg.data[i].PORTX,LCD_Cfg.data[i].GPIO_Pin_Pin,resultOut);
	}
	GPIO_OutputPin(LCD_Cfg.Enable.PORTX,LCD_Cfg.Enable.GPIO_Pin_Pin,1);
	GPIO_OutputPin(LCD_Cfg.Enable.PORTX,LCD_Cfg.Enable.GPIO_Pin_Pin,0);



}







void LCD_init(){
	LCD_enu_initSeq_t static  LCD_enu_initSeq=functionSet;

	switch (LCD_enu_initSeq)
	{
	case functionSet :
		LCD_SendCommand( LCD_FUNCTION_SET);
		LCD_enu_initSeq=DisplayControl;
		break;
	case DisplayControl :
		LCD_SendCommand( LCD_ON_EN_CURSOR_NON_BLINKED);
		LCD_enu_initSeq=DisplayClear;
		break;
	case DisplayClear :
		LCD_SendCommand( LCD_DISPLAY_CLEAR);
		LCD_enu_initSeq=EntryMode;
		break;
	case EntryMode :
		LCD_SendCommand( LCD_ENTRYMODE);
		LCD_enu_initSeq=EndInit;
		break;
	case EndInit:
		initState=1;
		LCD_GlobalStatus =LCD_enuStateIdle;
		break;

	}

}



void  LCD_enuGotoXY (u8 Copy_u8XPos, u8 Copy_u8YPos)
{

	u8 result;
	if(Copy_u8XPos==0)
	{
		result=Copy_u8YPos;
	}
	else
	{
		result=Copy_u8YPos+1;
	}
	/*  SET ADDRESS DDRAM ==>0 0 1 AC6 AC5 AC4 AC3 AC2 AC1 AC0   */
	SET_BIT(result,7);
	LCD_SendCommand(result);

}


LCD_enuErrorStatus_t LCD_AsyncWriteString(const char* str ,u8 len,u8 xPos,u8 yPos,u8 idx)
{
	LCD_enuErrorStatus_t status=LCD_enuStateIdle;
	if (LCD_GlobalStatus==LCD_enuStateIdle)
	{
		status=LCD_enuStateBusy;
		LCD_GlobalStatus=LCD_enuStateBusy;
		reqString.str=str;
		reqString.char_idx=idx;
		reqString.len=len;
		reqString.pos_x=xPos;
		reqString.pos_y=yPos;

		LCD_enuGotoXY ( xPos,  yPos);
		currentStrIdx=0;

		LCD_GlobalStatus=LCD_enuStateIdle;
		status=LCD_enuStateOK;
	}
	else if(LCD_GlobalStatus==LCD_enuStateNotInit)
	{
		status=LCD_enuStateNotInit;

	}

	return status;

}


void   writeSeq(){

	if(currentStrIdx<reqString.len)
	{
		 LCD_SendData(reqString.str[currentStrIdx]);
		 currentStrIdx++;
	}
	else{
		LCD_GlobalStatus=LCD_enuStateIdle;
		ReqType=ReqType_Done;

	}


}

void ClearSeq(){
	LCD_SendCommand(LCD_DISPLAY_CLEAR);

}







