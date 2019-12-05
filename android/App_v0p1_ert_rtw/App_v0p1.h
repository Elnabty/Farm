/*
 * File: App_v0p1.h
 *
 * Code generated for Simulink model 'App_v0p1'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov  5 10:47:11 2019
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
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef App_v0p1_COMMON_INCLUDES_
# define App_v0p1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_thingspeak_read.h"
#include "driver_android_datadisplay.h"
#endif                                 /* App_v0p1_COMMON_INCLUDES_ */

#include "App_v0p1_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<Root>/ThingSpeak Humidity' */
typedef struct {
  real32_T ThingSpeakHumidity_o1;      /* '<Root>/ThingSpeak Humidity' */
} B_ThingSpeakHumidity_App_v0p1_T;

/* Block states (default storage) for system '<Root>/ThingSpeak Humidity' */
typedef struct {
  codertarget_internal_androidT_T obj; /* '<Root>/ThingSpeak Humidity' */
  boolean_T objisempty;                /* '<Root>/ThingSpeak Humidity' */
} DW_ThingSpeakHumidity_App_v0p_T;

/* Block signals (default storage) */
typedef struct {
  B_ThingSpeakHumidity_App_v0p1_T ThingSpeakReadTemprature;/* '<Root>/ThingSpeak Humidity' */
  B_ThingSpeakHumidity_App_v0p1_T ThingSpeakwaterlevel;/* '<Root>/ThingSpeak Humidity' */
  B_ThingSpeakHumidity_App_v0p1_T ThingSpeakHumidity;/* '<Root>/ThingSpeak Humidity' */
} B_App_v0p1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_ThingSpeakHumidity_App_v0p_T ThingSpeakReadTemprature;/* '<Root>/ThingSpeak Humidity' */
  DW_ThingSpeakHumidity_App_v0p_T ThingSpeakwaterlevel;/* '<Root>/ThingSpeak Humidity' */
  DW_ThingSpeakHumidity_App_v0p_T ThingSpeakHumidity;/* '<Root>/ThingSpeak Humidity' */
} DW_App_v0p1_T;

/* Real-time Model Data Structure */
struct tag_RTM_App_v0p1_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_App_v0p1_T App_v0p1_B;

/* Block states (default storage) */
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
 * '<S1>'   : 'App_v0p1/Data Display'
 * '<S2>'   : 'App_v0p1/Data Display1'
 * '<S3>'   : 'App_v0p1/Data Display2'
 */
#endif                                 /* RTW_HEADER_App_v0p1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
