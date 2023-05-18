

#include "../../LIB/Stdtypes.h"
#include "../../LIB/BIT_MATH.h"




/*
TickTime=1/16000000
ReqTime=1ms
N=ReReqTime/TickTime =16000
			N-1
*/

#define RUNNABLE_NUM 				1
//#define TICK_TIME 				(15999)
#define TICK_TIME 					1



typedef void (*runnable_cbft)(void);
void SCHED_TickCBF(void);
typedef struct{
	char*name;
	runnable_cbft runnable_cbf;
	u32 period_ms;
	u32 start_delay_ms;

}task_info_t;



typedef struct {
	task_info_t *taskInfo;
	u32 remainTime;
}task_t;

task_t task[RUNNABLE_NUM];

extern const task_info_t  task_info[RUNNABLE_NUM];

typedef enum{
	SCHED_enuStateOK= 0,
	SCHED_enuStateNOTOK,
	SCHED_enuStateNullPTR,
}SCHED_enuErrorStatus_t;

void SCHED_init();
void SCHED_start();
void SCHED_stopRunnable(u32 add,u32 delay);

