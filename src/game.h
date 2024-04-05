#ifndef GAME__H
#define GAME__H

#include "buttons.h"
#include "debounce.h"
#include "McuDebounce.h"

void game_Init(void);

void game_Deinit(void);

void OnButtonEvent(BTN_Buttons_e button, McuDbnc_EventKinds kind);

#endif // GAME__H