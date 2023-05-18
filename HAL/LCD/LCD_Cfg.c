#include "LCD.h"
/*
 	u8 no_of_lines;//N  0 One line 1 Two lines
	u8 size;  //F  0  5X8    1 5X11
	u8 Display;//D	0 Disable 1 Enable
	u8 cursor;//C =0  Disable  1 Enable
	u8 blink; //B  0 Disable  1 Enable
 */




/*
	u8 no_of_lines;//N  0 One line 1 Two lines
	u8 size;  //F  0  5X8    1 5X11
	u8 display;//D	0 Disable 1 Enable
	u8 cursor;//C =0  Disable  1 Enable
	u8 blink; //B  0 Disable  1 Enable
*/





 LCD_Cfg_t LCD_Cfg={

/*		 .LCD_operation={
					.no_of_lines=1,
					.size=1,
					.display=1,
					.cursor=1,
					.blink=1,
		 },
 */
		 .Enable={
				 .GPIO_Pin_Pin=GPIO_enuPIN0,
				 .GPIO_Pin_Speed=HIGH_SPEED,
				 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
				 .PORTX=GPIOA,

		 },
		 .RS={
				 .GPIO_Pin_Pin=GPIO_enuPIN1,
				 .GPIO_Pin_Speed=HIGH_SPEED,
				 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
				 .PORTX=GPIOA,

		 },
		 .RW={
				 .GPIO_Pin_Pin=GPIO_enuPIN2,
				 .GPIO_Pin_Speed=HIGH_SPEED,
				 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
				 .PORTX=GPIOA,

		 },
		 .data={
				 [0]{
					 .GPIO_Pin_Pin=GPIO_enuPIN3,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,

				 },
				 [1]{
					 .GPIO_Pin_Pin=GPIO_enuPIN4,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },
				 [2]{
					 .GPIO_Pin_Pin=GPIO_enuPIN5,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },
				 [3]{
					 .GPIO_Pin_Pin=GPIO_enuPIN6,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },
				 [4]{
					 .GPIO_Pin_Pin=GPIO_enuPIN7,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },
				 [5]{
					 .GPIO_Pin_Pin=GPIO_enuPIN8,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },
				 [6]{
					 .GPIO_Pin_Pin=GPIO_enuPIN9,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },
				 [7]{
					 .GPIO_Pin_Pin=GPIO_enuPIN10,
					 .GPIO_Pin_Speed=HIGH_SPEED,
					 .GPIO_Pin_Mode=GPIO_enuModes_Output_open_drainPullUP,
					 .PORTX=GPIOA,
				 },

		 },

 };
