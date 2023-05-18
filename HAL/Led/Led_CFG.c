

#include "Led.h"

//#include "../../MCAL/GPIO/GPIO.h"



/*


 ____________________________________________
|   mode     |     State     |(mode^state)out|
|____________|_______________|_______________|
| HIGH    0  |     OFF    0  |      0        |
|____________|_______________|_______________|
| HIGH    0  |     ON     1  |      1        |
|____________|_______________|_______________|
| Low     1  |     OFF    0  |      1        |
|____________|_______________|_______________|
| Low     1  |     ON     1  |      0        |
|____________|_______________|_______________|




 */

LED_Cfg_t LED_cfg[Led_Count]=
{
		[Led_Alarm]=
		{
				.Led_Port=GPIOA  ,
				.Led_Pin=GPIO_enuPIN8  ,
				.Led_Speed=HIGH_SPEED  ,
				.Led_ActiveMode=LED_enu_AvtiveHigh ,
				.Led_InOutputMode=GPIO_enuModes_Output_push_pull_PullUP,
		},


		[Led_Warning]=
		{
				.Led_Port=GPIOA ,
				.Led_Pin= GPIO_enuPIN9 ,
				.Led_Speed=HIGH_SPEED  ,
				.Led_ActiveMode=LED_enu_AvtiveHigh  ,
				.Led_InOutputMode=GPIO_enuModes_Output_push_pull_PullUP,
		},
/*
		[Led_ERROR]=
		{
				.Led_Port=GPIOA  ,
				.Led_Pin=GPIO_enuPIN10 ,
				.Led_Speed=HIGH_SPEED  ,
				.Led_ActiveMode=LED_enu_AvtiveHigh ,
				.Led_InOutputMode=GPIO_enuModes_Output_push_pull_PullUP,
		},

*/
};
