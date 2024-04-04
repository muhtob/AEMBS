/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuSystemView.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : SeggerSystemView
**     Version     : Component 01.071, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-04-09, 18:36, # CodeGen: 806
**     Abstract    :
**          This component implements and integrates the SEGGER Systemview library for FreeRTOS.
**     Settings    :
**          Component name                                 : McuSystemView
**          Version                                        : V3.50a
**          Application Name                               : "Demo Application"
**          Device Name                                    : "Cortex"
**          RAM Base                                       : 0x20000000
**          ID Base                                        : 0x10000000
**          ID Shift                                       : 2
**          Number of tasks                                : 10
**          Static Buffer                                  : yes
**          Post Mortem                                    : no
**          Implicit Format for printf()                   : no
**          RTT Channel                                    : 
**            Segger RTT                                   : McuRTT
**            Name                                         : "SysView"
**            Channel Index                                : 1
**            Up Buffer size                               : 1024
**          SDK                                            : McuLib
**          Source Folders                                 : 
**            Source Folder                                : SEGGER_Sysview
**            Config Folder                                : SEGGER_Sysview
**     Contents    :
**         OnUserStart    - void McuSystemView_OnUserStart(unsigned UserId);
**         OnUserStop     - void McuSystemView_OnUserStop(unsigned UserId);
**         RecordEnterISR - void McuSystemView_RecordEnterISR(void);
**         RecordExitISR  - void McuSystemView_RecordExitISR(void);
**         Print          - void McuSystemView_Print(const char *s);
**         PrintfHost     - void McuSystemView_PrintfHost(const char *s, ...);
**         PrintfTarget   - void McuSystemView_PrintfTarget(const char *s, ...);
**         Warn           - void McuSystemView_Warn(const char *s);
**         WarnfHost      - void McuSystemView_WarnfHost(const char *s, ...);
**         WarnfTarget    - void McuSystemView_WarnfTarget(const char *s, ...);
**         Error          - void McuSystemView_Error(const char *s);
**         ErrorfHost     - void McuSystemView_ErrorfHost(const char *s, ...);
**         ErrorfTarget   - void McuSystemView_ErrorfTarget(const char *s, ...);
**         EnableEvents   - void McuSystemView_EnableEvents(uint32_t EnableMask);
**         DisableEvents  - void McuSystemView_DisableEvents(uint32_t DisableMask);
**         Deinit         - void McuSystemView_Deinit(void);
**         Init           - void McuSystemView_Init(void);
**
** * (c) Copyright Segger, 2020
**  * http      : www.segger.com
**  * See separate Segger licensing terms.
**  *
**  * Processor Expert port: Copyright (c) 2016-2019, Erich Styger
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
** @file McuSystemView.h
** @version 01.00
** @brief
**          This component implements and integrates the SEGGER Systemview library for FreeRTOS.
*/         
/*!
**  @addtogroup McuSystemView_module McuSystemView module documentation
**  @{
*/         

#ifndef __McuSystemView_H
#define __McuSystemView_H

/* MODULE McuSystemView. */
#include "McuLib.h" /* SDK and API used */
#include "McuSystemViewconfig.h" /* configuration */

/* Include inherited components */
#include "McuRTT.h"
#include "McuLib.h"

#include "SEGGER_SYSVIEW.h"




void McuSystemView_Init(void);
/*
** ===================================================================
**     Method      :  Init (component SeggerSystemView)
**
**     Description :
**         Driver Initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_OnUserStart(UserId) \
  SEGGER_SYSVIEW_OnUserStart(UserId)

/*
** ===================================================================
**     Method      :  OnUserStart (component SeggerSystemView)
**
**     Description :
**         Send a user event start, such as start of a subroutine for
**         profiling.
**     Parameters  :
**         NAME            - DESCRIPTION
**         UserId          - User defined ID for the event
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_OnUserStop(UserId) \
  SEGGER_SYSVIEW_OnUserStop(UserId)

/*
** ===================================================================
**     Method      :  OnUserStop (component SeggerSystemView)
**
**     Description :
**         Send a user event stop, such as return of a subroutine for
**         profiling.
**     Parameters  :
**         NAME            - DESCRIPTION
**         UserId          - User defined ID for the event
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_RecordEnterISR() \
  SEGGER_SYSVIEW_RecordEnterISR()
/*
** ===================================================================
**     Method      :  RecordEnterISR (component SeggerSystemView)
**
**     Description :
**         Records the enter of an ISR. Place this call at the
**         beginning of the interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_RecordExitISR() \
  SEGGER_SYSVIEW_RecordExitISR()
/*
** ===================================================================
**     Method      :  RecordExitISR (component SeggerSystemView)
**
**     Description :
**         Records the end of the ISR. Call this function at the end of
**         the ISR to be recorded.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_Print(s) \
  SEGGER_SYSVIEW_Print(s)
/*
** ===================================================================
**     Method      :  Print (component SeggerSystemView)
**
**     Description :
**         Prints a string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_Warn(s) \
  SEGGER_SYSVIEW_Warn(s)
/*
** ===================================================================
**     Method      :  Warn (component SeggerSystemView)
**
**     Description :
**         Prints a warning string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_Error(s) \
  SEGGER_SYSVIEW_Error(s)
/*
** ===================================================================
**     Method      :  Error (component SeggerSystemView)
**
**     Description :
**         Prints an error string to the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_PrintfHost    SEGGER_SYSVIEW_PrintfHost
/*
** ===================================================================
**     Method      :  PrintfHost (component SeggerSystemView)
**
**     Description :
**         Prints a string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_PrintfTarget   SEGGER_SYSVIEW_PrintfTarget
/*
** ===================================================================
**     Method      :  PrintfTarget (component SeggerSystemView)
**
**     Description :
**         Prints a string using printf() to the host which is
**         processed first on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_WarnfHost  SEGGER_SYSVIEW_WarnfHost
/*
** ===================================================================
**     Method      :  WarnfHost (component SeggerSystemView)
**
**     Description :
**         Prints a warning string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_WarnfTarget   SEGGER_SYSVIEW_WarnfTarget
/*
** ===================================================================
**     Method      :  WarnfTarget (component SeggerSystemView)
**
**     Description :
**         Prints a warning string using printf() to the host which is
**         processed first on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_ErrorfHost   SEGGER_SYSVIEW_ErrorfHost
/*
** ===================================================================
**     Method      :  ErrorfHost (component SeggerSystemView)
**
**     Description :
**         Prints an error string using printf() to the host which is
**         processed on the host
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_ErrorfTarget   SEGGER_SYSVIEW_ErrorfTarget
/*
** ===================================================================
**     Method      :  ErrorfTarget (component SeggerSystemView)
**
**     Description :
**         Prints an error string using printf() to the host which is
**         processed first on the target
**     Parameters  :
**         NAME            - DESCRIPTION
**       * s               - Pointer to string
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_DisableEvents(DisableMask) \
  SEGGER_SYSVIEW_DisableEvents(DisableMask)

/*
** ===================================================================
**     Method      :  DisableEvents (component SeggerSystemView)
**
**     Description :
**         Disable standard SystemView events to not be generated.
**     Parameters  :
**         NAME            - DESCRIPTION
**         DisableMask     - Events to be disabled.
**     Returns     : Nothing
** ===================================================================
*/

#define McuSystemView_EnableEvents(EnableMask) \
  SEGGER_SYSVIEW_EnableEvents(EnableMask)

/*
** ===================================================================
**     Method      :  EnableEvents (component SeggerSystemView)
**
**     Description :
**         Enables standard SystemView events to be generated.
**     Parameters  :
**         NAME            - DESCRIPTION
**         EnableMask      - Events to be enabled
**     Returns     : Nothing
** ===================================================================
*/

void McuSystemView_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component SeggerSystemView)
**
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END McuSystemView. */

#endif
/* ifndef __McuSystemView_H */
/*!
** @}
*/
