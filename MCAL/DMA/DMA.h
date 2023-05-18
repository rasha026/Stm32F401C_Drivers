#ifndef DMA_H_
#define DMA_H_

#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"




#define DMA1_BASE_ADDRESS 				0x40026000
#define DMA2_BASE_ADDRESS 				0x40026400
typedef struct{
	u32 DMA_LISR;
	u32 DMA_HISR;
	u32 DMA_LIFCR;
	u32 DMA_HIFCR;

	struct
		{
			u32 DMA_SxCR;
			u32 DMA_SxNDTR;
			u32 DMA_SxPAR;
			u32 DMA_SxM0AR;
			u32 DMA_SxM1AR;
			u32 DMA_SxFCR;
		}Cfg_Reg[8];
}DMA_StructReg;


#define DMA1 				((DMA_StructReg*)(DMA1_BASE_ADDRESS))
#define DMA2				((DMA_StructReg*)(DMA2_BASE_ADDRESS))



typedef void (*DMA_Cbf_t)(void);

typedef enum{
	DMA_enuStateOK= 0,
	DMA_enuStateNOTOK,
	DMA_enuStateNullPTR,
	DMA_enuStateBusy,
	DMA_enuStateIdle,
}DMA_enuErrorStatus_t;


typedef enum{
	Stream0=0,
	Streaml1,
	Stream2,
	Stream3,
	Stream4,
	Stream5,
	Stream6,
	Stream7,

}DMA_Stream_t;

typedef enum{
	Channel0=0,
	Channel1,
	Channel2,
	Channele3,
	Channele4,
	Channele5,
	Channele6,
	Channele7,

}DMA_Channel_t;


typedef enum{
	priorityLow,
	priorityMedium ,
	priorityHigh,
	priorityVeryHigh,

}DMA_priority_t;

typedef enum{
	DMAChannel1=0,
	DMAChannel2,


}DMA_DMANum_t;

typedef enum{
	Peripheral_to_memory=0,
	memory_to_Peripheral,
	memory_to_memory,
}DMA_DirMode_t;

typedef enum{
	PointerIncrementation=0,
	Circular,
	DoubleBuffer,
}DMA_BufferMode_t;


typedef enum{
	Byte=0,
	HalfWord,
	Word,
}DMA_Size_t;

typedef enum{
	fixed=0,
	incremented,
}DMA_IncMode_t;


typedef enum{
	DirectMode=0,
	FIFOMode,
}DMA_DIR_FIFO_Mode_t;

typedef enum{
	//00: 1/4 full FIFO 01: 1/2 full FIFO 10: 3/4 full FIFO 11: full FIFO
	Quarter_FIFO=0,
	Half_FIFO,
	Quarter_Half_FIFO,
	Full_FIFO

}DMA_FIFOThreshold_t;

typedef struct{
	DMA_StructReg* DMA;
	DMA_Stream_t Stream;
	DMA_Channel_t DMA_Channel;
	DMA_DirMode_t dirMode;
	DMA_DIR_FIFO_Mode_t DMA_DIR_FIFO_Mode;
	DMA_FIFOThreshold_t DMA_FIFOThreshold;
	DMA_Cbf_t DMA_Cbf;

	DMA_BufferMode_t DMA_BufferMode;
	u32 PeriAddress;
	u32 MemAddress;
	DMA_Size_t Msize;
	DMA_Size_t Psize;

	u32 NofData;
	DMA_IncMode_t DMA_MemIncMode;
	DMA_IncMode_t DMA_PerIncMode;
	DMA_priority_t priority;

}DMA_Cfg_t;



#endif
