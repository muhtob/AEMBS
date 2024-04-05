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


static void mainTask(void *pv){
    LEDS_Leds_e led = (LEDS_Leds_e)pv;

    for(;;){
        McuSystemView_Print((const char*)"measure Time for toggle\r\n");
        McuSystemView_OnUserStart(1); // using ID 1 -> measure time from start to stop
        Leds_Neg(led);
        McuSystemView_OnUserStop(1); // using ID 1
        vTaskDelay(pdMS_TO_TICKS(500));

    }
}

static void buttonTask(void *pv){
    //BTN_Buttons_e button = (BTN_Buttons_e)pv;
    extern BTN_Buttons_e pressedButton;
    extern McuDbnc_EventKinds btnEvent;
    for(;;){

        if(pressedButton == BTN_NAV_CENTER && btnEvent == (MCUDBNC_EVENT_RELEASED || MCUDBNC_EVENT_LONG_RELEASED)){
            Leds_Neg(LEDS_BLUE);
            //Leds_Neg(LEDS_RED);
            //Leds_Neg(LEDS_GREEN);
            McuSystemView_Print((const char*)"Button CENTER pressed\r\n");
            // reset Button
            pressedButton = BTN_NOF_BUTTONS;
        }
        vTaskDelay(pdMS_TO_TICKS(50)); // wait for 500 ms
        
    }
}


int main(void)
{
    PL_Init();

    // Startup Parameter
    LEDS_Leds_e led = LEDS_GREEN;

    if (xTaskCreate(buttonTask, "buttonTask", 208/sizeof(StackType_t), (void *)NULL, tskIDLE_PRIORITY+1, (TaskHandle_t *)NULL) != pdPASS)
    {               
        for(;;){}   
    } 
    
    vTaskStartScheduler();
}