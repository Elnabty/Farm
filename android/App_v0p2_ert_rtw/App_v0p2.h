/*
 * File: App_v0p2.h
 *
 * Code generated for Simulink model 'App_v0p2'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov 18 17:28:15 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_App_v0p2_h_
#define RTW_HEADER_App_v0p2_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef App_v0p2_COMMON_INCLUDES_
# define App_v0p2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_thingspeak_read.h"
#include "driver_android_thingspeak_write.h"
#include "driver_android_datainput.h"
#include "driver_android_button.h"
#include "driver_android_datadisplay.h"
#endif                                 /* App_v0p2_COMMON_INCLUDES_ */

#include "App_v0p2_types.h"

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
} B_App_v0p2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidD_T obj_j;/* '<Root>/Syring1' */
  codertarget_internal_androidD_T obj_lf;/* '<Root>/Syring2' */
  codertarget_internal_androidD_T obj_h0;/* '<Root>/Syring1 control' */
  codertarget_internal_androidD_T obj_b;/* '<Root>/Syring2 control' */
} DW_App_v0p2_T;

/* Real-time Model Data Structure */
struct tag_RTM_App_v0p2_T {
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
extern B_App_v0p2_T App_v0p2_B;

/* Block states (default storage) */
extern DW_App_v0p2_T App_v0p2_DW;

/* Model entry point functions */
extern void App_v0p2_initialize(void);
extern void App_v0p2_step(void);
extern void App_v0p2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_App_v0p2_T *const App_v0p2_M;

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
 * '<Root>' : 'App_v0p2'
 * '<S1>'   : 'App_v0p2/Fill Tank'
 * '<S2>'   : 'App_v0p2/Humidity'
 * '<S3>'   : 'App_v0p2/Main water'
 * '<S4>'   : 'App_v0p2/Tank Drain'
 * '<S5>'   : 'App_v0p2/Tank vulve'
 * '<S6>'   : 'App_v0p2/Tempreture'
 * '<S7>'   : 'App_v0p2/Water Level'
 */
#endif                                 /* RTW_HEADER_App_v0p2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
