
#include "../SysTick/SysTick.h"
#include "SCHED.h"

u8 schedFlag=0;

static void sched(void){
	u8 idx;
	for(idx=0;idx<RUNNABLE_NUM;idx++)
	{
		if(task[idx].taskInfo)
		{
			if(task[idx].remainTime==0)
			{
				task[idx].taskInfo->runnable_cbf();
				task[idx].remainTime=task[idx].taskInfo->period_ms;

			}
			else
			{
				task[idx].remainTime-=TICK_TIME;
			}
		}
	}


}

void SCHED_init(){
	STK_init();
	STK_SetCBF(&SCHED_TickCBF);
	STK_StopTimer();
	STK_SetPeriod_ms(TICK_TIME);

	for(int idx=0;idx<RUNNABLE_NUM;idx++)
	{
		 task[idx].taskInfo=&task_info[idx];
		 task[idx].remainTime=task_info[idx].start_delay_ms;

	}



}

void SCHED_TickCBF(){
	if(schedFlag==0)
	{
		schedFlag=1;
	}
	else
	{
		//ERROR->CPU 100%
	}

}

void SCHED_start(){
	STK_StartTimer();
	while(1){
		sched();
		schedFlag=0;

	}

}


