#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "platform.h"
#include "McuRTOS.h"
#include "leds.h"
#include "McuSystemView.h"
#include "McuButton.h"
#include "buttons.h"
#include "debounce.h"


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

void myInterrupt(BTN_Buttons_e button){
    if(button == BUTTONS_PINS_NAVCENTER_PIN){
        McuSystemView_Print((const char*)"Button CENTER pressed\r\n");
    }
    McuSystemView_Print((const char*)"Button pressed\r\n");
}

int main(void)
{
    PL_Init();

    // Startup Parameter
    LEDS_Leds_e led = LEDS_GREEN;

    if (xTaskCreate(mainTask, "blink_measure", 208/sizeof(StackType_t), (void*)led, tskIDLE_PRIORITY+1, (TaskHandle_t *)NULL) != pdPASS)
    {               
        for(;;){}   
    } 


    vTaskStartScheduler();
}