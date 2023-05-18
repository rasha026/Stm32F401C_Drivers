
#include "LCD_Cfg.h"
#include "../../MCAL/GPIO/GPIO.h"
#define LCD_NO_OF_LINES		8

#define LCD_DISPLAY_CLEAR				(0b00000001)

typedef enum{
	LCD_enuStateOK= 0,
	LCD_enuStateNOTOK,
	LCD_enuStateNullPTR,
	LCD_enuStateBusy,
	LCD_enuStateIdle,
	LCD_enuStateNotInit,
}LCD_enuErrorStatus_t;


typedef enum{
	functionSet,
	DisplayControl,
	DisplayClear,
	EntryMode,
	EndInit,
}LCD_enu_initSeq_t;


 enum{
	No_Req,
	ReqType_Write,
	ReqType_Clear,
	ReqType_Done,


}ReqType;

typedef struct{

	u8 no_of_lines;//N  0 One line 1 Two lines
	u8 size;  //F  0  5X8    1 5X11
	u8 display;//D	0 Disable 1 Enable
	u8 cursor;//C =0  Disable  1 Enable
	u8 blink; //B  0 Disable  1 Enable

}LCD_operation_t;


typedef struct{
	//LCD_operation_t LCD_operation;
	GPIO_Cfg_t Enable;
	GPIO_Cfg_t data[8];
	GPIO_Cfg_t RS;
	GPIO_Cfg_t RW;
}LCD_Cfg_t;


struct {
	const char *str;
	u8 len;
	u8 pos_x;
	u8 pos_y;
	u8 char_idx;
}reqString;




extern  LCD_Cfg_t LCD_Cfg;
extern LCD_operation_t LCD_operation;

extern u8 initState;







void  LCD_SendCommand(u8 cpy_data);
void  LCD_SendData(u8 cpy_data);
void LCD_init();
void  LCD_enuGotoXY (u8 Copy_u8XPos, u8 Copy_u8YPos);

LCD_enuErrorStatus_t LCD_AsyncWriteString(const char* str ,u8 len,u8 xPos,u8 yPos,u8 idx);

void   writeSeq();





void ClearSeq();




