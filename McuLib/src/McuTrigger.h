/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuTrigger.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : Trigger
**     Version     : Component 01.069, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-09-18, 09:57, # CodeGen: 748
**     Abstract    :
**
This component implements triggers.
Triggers are callbacks with a time when they should be executed.
**     Settings    :
**          Component name                                 : McuTrigger
**          Trigger Events                                 : (string list)
**          Low Power                                      : Disabled
**          TickPeriodMs                                   : 10
**          RTOS                                           : Enabled
**            RTOS                                         : McuRTOS
**          Initialize on Init                             : yes
**     Contents    :
**         AddTrigger        - void McuTrigger_AddTrigger(uint8_t trigger, uint16_t incTicks, void...
**         AddTick           - void McuTrigger_AddTick(void);
**         AnyTriggerPending - bool McuTrigger_AnyTriggerPending(void);
**         TriggerPending    - bool McuTrigger_TriggerPending(uint8_t trigger);
**
** * Copyright (c) 2013-2021, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuTrigger.h
** @version 01.00
** @brief
**
This component implements triggers.
Triggers are callbacks with a time when they should be executed.
*/         
/*!
**  @addtogroup McuTrigger_module McuTrigger module documentation
**  @{
*/         

#ifndef __McuTrigger_H
#define __McuTrigger_H

/* MODULE McuTrigger. */
#include "McuLib.h" /* SDK and API used */
#include "McuTriggerconfig.h" /* configuration */

#define McuTrigger_TICK_PERIOD_MS  McuTrigger_CONFIG_TICK_PERIOD_MS  /* trigger period in milli-seconds */

/* Include inherited components */
#include "McuCriticalSection.h"
#include "McuLib.h"
#include "McuRTOS.h"



#ifdef __cplusplus
extern "C" {
#endif




void McuTrigger_AddTrigger(uint8_t trigger, uint16_t incTicks, void (*callback)(void));
/*
** ===================================================================
**     Method      :  AddTrigger (component Trigger)
**
**     Description :
**         Adds a trigger
**     Parameters  :
**         NAME            - DESCRIPTION
**         trigger         - The trigger to be added
**         incTicks        - Trigger time, in trigger ticks.
**                           The time will is relative to the current
**                           tick time
**         callback        - Callback to be called when the
**                           trigger fires
**     Returns     : Nothing
** ===================================================================
*/

void McuTrigger_AddTick(void);
/*
** ===================================================================
**     Method      :  AddTick (component Trigger)
**
**     Description :
**         Called by a timer function to add a tick.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuTrigger_Init(void);
/*
** ===================================================================
**     Method      :  McuTrigger_Init (component Trigger)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool McuTrigger_AnyTriggerPending(void);
/*
** ===================================================================
**     Method      :  AnyTriggerPending (component Trigger)
**
**     Description :
**         Return true if there are any triggers pending.
**     Parameters  : None
**     Returns     :
**         ---             - true in case any triggers are pending
** ===================================================================
*/

bool McuTrigger_TriggerPending(uint8_t trigger);
/*
** ===================================================================
**     Method      :  TriggerPending (component Trigger)
**
**     Description :
**         Determines if the given trigger is set and pending
**     Parameters  :
**         NAME            - DESCRIPTION
**         trigger         - The trigger to check
**     Returns     :
**         ---             - True if this trigger is pending, false
**                           otherwise.
** ===================================================================
*/

#ifdef __cplusplus
}  /* extern "C" */
#endif
/* END McuTrigger. */

#endif
/* ifndef __McuTrigger_H */
/*!
** @}
*/
