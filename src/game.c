#include "game.h"
#include "buttons.h"
#include "debounce.h"
#include "McuDebounce.h"
#include "queue_lib.h"

// global vars
volatile BTN_Buttons_e pressedButton;
volatile McuDbnc_EventKinds btnEvent;

void game_Init(void){

}

void game_Denit(void){
    
}

void OnButtonEvent(BTN_Buttons_e button, McuDbnc_EventKinds kind){
    pressedButton = button;
    btnEvent = kind;
}
