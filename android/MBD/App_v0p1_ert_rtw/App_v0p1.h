/*
 * File: App_v0p1.h
 *
 * Code generated for Simulink model 'App_v0p1'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Nov  3 12:41:31 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_App_v0p1_h_
#define RTW_HEADER_App_v0p1_h_
#include <stddef.h>
#include <string.h>
#ifndef App_v0p1_COMMON_INCLUDES_
# define App_v0p1_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "driver_android_thingspeak_write.h"
#endif                                 /* App_v0p1_COMMON_INCLUDES_ */

#include "App_v0p1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidT_T obj; /* '<Root>/ThingSpeak Write' */
} DW_App_v0p1_T;

/* Parameters (auto storage) */
struct P_App_v0p1_T_ {
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_App_v0p1_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_App_v0p1_T App_v0p1_P;

/* Block states (auto storage) */
extern DW_App_v0p1_T App_v0p1_DW;

/* Model entry point functions */
extern void App_v0p1_initialize(void);
extern void App_v0p1_step(void);
extern void App_v0p1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_App_v0p1_T *const App_v0p1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'App_v0p1'
 */
#endif                                 /* RTW_HEADER_App_v0p1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
