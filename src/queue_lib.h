#ifndef QUEUE_LIB__H_
#define QUEUE_LIB__H_

#include "buttons.h"
#include "debounce.h"
#include "McuButton.h"
#include "McuDebounce.h"

typedef struct event{
    BTN_Buttons_e button;
    McuDbnc_EventKinds btnEvent;
}event_t;

void Queue_Init(void);

void Queue_Deinit(void);

#endif // QUEUE_LIB__H_