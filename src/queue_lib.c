#include "platform.h"
#include "McuRTOS.h"
#include "queue.h"
#include "queue_lib.h"
#include "McuButton.h"
#include "McuDebounce.h"
#include "buttons.h"
#include "debounce.h"
#if McuLib_CONFIG_CPU_IS_KINETIS
  #include "fsl_port.h"
#elif McuLib_CONFIG_CPU_IS_LPC
  #include "fsl_pint.h"
  #include "fsl_syscon.h"
#endif
#if configUSE_SEGGER_SYSTEM_VIEWER_HOOKS
  #include "McuSystemView.h"
#endif

#define EVENT_QUEUE_LENGTH  (5)                 // Number of elements in queue
#define EVENT_QUEUE_ELEM_SIZE (sizeof(event_t)) // size of a queue item

QueueHandle_t eventQueue;
QueueHandle_t testQueue;

void Queue_Init(void){
    //static QueueHandle_t eventQueue; // queue handle
    eventQueue = xQueueCreate(EVENT_QUEUE_LENGTH, EVENT_QUEUE_ELEM_SIZE);
    testQueue = xQueueCreate(10,20);
#if configUSE_SEGGER_SYSTEM_VIEWER_HOOKS
    SEGGER_SYSVIEW_PrintfTarget("queue size: %d",sizeof(testQueue));
#endif
    if(eventQueue == NULL){
        for(;;); // out of memory
    }
    vQueueAddToRegistry(eventQueue, "eventQueue");

    //NVIC_SetPriority(IRQ_NUMBER, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
}

void Queue_Deinit(void){

}