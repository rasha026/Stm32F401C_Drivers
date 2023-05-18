


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


//set_bit
#define SET_BIT(var,bit) (var|=(1<<bit))
//clear_bit
#define CLR_BIT(var,bit) (var&=(~(1<<bit)))
//toggle_bit
#define TOGGLE_BIT(var,bit) (var^=(1<<bit))
//get_bit
#define GET_BIT(var,bit) ((var>>bit)&1)
//byte operations
#define Set_BITS(REG,MSK)			(REG) |=  (MSK)
#define Clr_BITS(REG,MSK)			(REG) &= ~(MSK)
#define Toggle_BITS(REG,MSK)		(REG) ^=  (MSK)

#define Set_ALL_BITS(REG)			(REG) =  (0xFFFFFFFF)
#define Clr_ALL_BITS(REG)			(REG) =  (0x00000000)
#define Toggle_ALL_BITS(REG)		(REG) ^= (0xFFFFFFFF)

#endif
