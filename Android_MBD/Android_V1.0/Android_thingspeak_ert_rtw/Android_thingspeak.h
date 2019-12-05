/*
 * File: Android_thingspeak.h
 *
 * Code generated for Simulink model 'Android_thingspeak'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov  5 22:50:36 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Android_thingspeak_h_
#define RTW_HEADER_Android_thingspeak_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Android_thingspeak_COMMON_INCLUDES_
# define Android_thingspeak_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_thingspeak_read.h"
#include "driver_android_thingspeak_write.h"
#include "driver_android_datainput.h"
#include "driver_android_button.h"
#include "driver_android_datadisplay.h"
#endif                                 /* Android_thingspeak_COMMON_INCLUDES_ */

#include "Android_thingspeak_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T y;
  real_T y_m;
} B_Android_thingspeak_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidD_T obj_i;/* '<Root>/Syring1' */
  codertarget_internal_androidD_T obj_n;/* '<Root>/Syring2' */
  codertarget_internal_androidD_T obj_ix;/* '<Root>/Syring1 control' */
  codertarget_internal_androidD_T obj_j;/* '<Root>/Syring2 control' */
} DW_Android_thingspeak_T;

/* Real-time Model Data Structure */
struct tag_RTM_Android_thingspeak_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Android_thingspeak_T Android_thingspeak_B;

/* Block states (default storage) */
extern DW_Android_thingspeak_T Android_thingspeak_DW;

/* Model entry point functions */
extern void Android_thingspeak_initialize(void);
extern void Android_thingspeak_step(void);
extern void Android_thingspeak_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Android_thingspeak_T *const Android_thingspeak_M;

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
 * '<Root>' : 'Android_thingspeak'
 * '<S1>'   : 'Android_thingspeak/Fill Tank'
 * '<S2>'   : 'Android_thingspeak/Humidity'
 * '<S3>'   : 'Android_thingspeak/Main water'
 * '<S4>'   : 'Android_thingspeak/Tank Drain'
 * '<S5>'   : 'Android_thingspeak/Tank vulve'
 * '<S6>'   : 'Android_thingspeak/Tempreture'
 * '<S7>'   : 'Android_thingspeak/Water Level'
 */
#endif                                 /* RTW_HEADER_Android_thingspeak_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
