#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "platform.h"
#include "McuRTOS.h"
#include "leds.h"
#include "McuSystemView.h"
#include "McuButton.h"
#include "McuDebounce.h"
#include "buttons.h"
#include "debounce.h"
#include "game.h"
//#include "queue.h"
#include "queue_lib.h"

extern QueueHandle_t eventQueue; 

// Task with queue
static void buttonTask(void *pv){
    //extern QueueHandle_t eventQueue;
    for(;;){
        McuDbnc_EventKinds event;
        if(xQueueReceive(eventQueue, &event, pdMS_TO_TICKS(20))!=pdPASS){
#if configUSE_SEGGER_SYSTEM_VIEWER_HOOKS
    //  SEGGER_SYSVIEW_PrintfTarget("Could not receive button event from queue!");
#endif
        }
        if((event == MCUDBNC_EVENT_RELEASED) || (event == MCUDBNC_EVENT_LONG_RELEASED)){
            Leds_Neg(LEDS_BLUE);
        }
        event = MCUDBNC_EVENT_END;
        vTaskDelay(pdMS_TO_TICKS(50)); // wait for 500 ms
        }
}


int main(void)
{
    PL_Init();

    if (xTaskCreate(buttonTask, "buttonTask", 208/sizeof(StackType_t), (void *)NULL, tskIDLE_PRIORITY+1, (TaskHandle_t *)NULL) != pdPASS)
    {               
        for(;;){}   
    } 
    vTaskStartScheduler();
}