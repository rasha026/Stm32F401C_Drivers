
#include "UART_cfg.h"



//Please edit GPIO_Pin_Pin and PORTX only Based on your connection
GPIO_Cfg_t tx_Pin={
		.GPIO_Pin_Pin=GPIO_enuPIN9,
		.GPIO_Pin_Speed=HIGH_SPEED,
		.GPIO_Pin_Mode=GPIO_enuModes_AF_push_pull,
		.PORTX=GPIOA,

};
GPIO_Cfg_t rx_Pin={
		.GPIO_Pin_Pin=GPIO_enuPIN10,
		.GPIO_Pin_Speed=HIGH_SPEED,
		.GPIO_Pin_Mode=GPIO_enuModes_AF_push_pull,
		.PORTX=GPIOA,
};





