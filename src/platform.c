#include "platform.h"
#include "McuWait.h"
#include "McuGPIO.h"
#include "McuUtility.h"
#include "McuLED.h"
#include "McuRTOS.h"
#include "McuRTT.h"
#include "McuSystemView.h"
#include "McuButton.h"
#include "leds.h"
#include "buttons.h"
#include "debounce.h"
#include "game.h"
#include "queue_lib.h"
#include "McuGenericI2C.h"
#include "McuI2cLib.h"
#include "McuSHT31.h"
#include "sensor.h"
//#include "queue.h"

uint32_t SystemCoreClock = 120000000;

void PL_Init(void){
    McuLib_Init();
    McuRTOS_Init();
    McuRTT_Init();
    #if configUSE_SEGGER_SYSTEM_VIEWER_HOOKS
        McuSystemView_Init();
    #endif
    McuWait_Init();
    McuGPIO_Init();
    McuGenericI2C_Init();
    McuI2cLib_Init();
    BTN_Init();
    Debounce_Init();
    McuBtn_Init();    
    McuDbnc_Init();
    Queue_Init();
    Leds_Init();
    McuSHT31_Init();
    Sensor_Init();
    game_Init();

}

void PL_Deinit(void){ // Deinit in umgekehrter Reihenfolge zu Init
    game_Deinit();
    Sensor_Deinit();
    McuSHT31_Deinit();
    Leds_Deinit();
    Queue_Deinit();
    McuDbnc_Deinit();
    McuBtn_Deinit();
    Debounce_Deinit();
    BTN_Deinit();
    McuI2cLib_Deinit();
    McuGenericI2C_Deinit();
    McuGPIO_Deinit();
    McuWait_Deinit();
    #if configUSE_SEGGER_SYSTEM_VIEWER_HOOKS
        McuSystemView_Deinit();
    #endif
    McuRTT_Deinit();
    McuRTOS_Deinit();
    McuLib_Deinit();
}
