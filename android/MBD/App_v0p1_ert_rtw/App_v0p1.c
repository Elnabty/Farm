/*
 * File: App_v0p1.c
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

#include "App_v0p1.h"
#include "App_v0p1_private.h"
#define App_v0p1_ChannelID             (12345.0)
#define App_v0p1_UpdateInterval        (60.0)

/* Block states (auto storage) */
DW_App_v0p1_T App_v0p1_DW;

/* Real-time model */
RT_MODEL_App_v0p1_T App_v0p1_M_;
RT_MODEL_App_v0p1_T *const App_v0p1_M = &App_v0p1_M_;

/* Model step function */
void App_v0p1_step(void)
{
  uint32_T sendPost;

  /* MATLABSystem: '<Root>/ThingSpeak Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  CHECK_UPDATE_INTERVAL(1.0, &sendPost);
  if (sendPost == 1U) {
    ADD_FIELD(1.0, 1U, (real_T)App_v0p1_P.Constant_Value);
    SEND_POST_REQUEST(1.0);
  }

  /* End of MATLABSystem: '<Root>/ThingSpeak Write' */
}

/* Model initialize function */
void App_v0p1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(App_v0p1_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&App_v0p1_DW, 0,
                sizeof(DW_App_v0p1_T));

  {
    static const char_T tmp[43] = { '<', 'E', 'n', 't', 'e', 'r', ' ', 't', 'h',
      'e', ' ', 'w', 'r', 'i', 't', 'e', ' ', 'A', 'P', 'I', ' ', 'k', 'e', 'y',
      ' ', 'f', 'o', 'r', ' ', 'y', 'o', 'u', 'r', ' ', 'c', 'h', 'a', 'n', 'n',
      'e', 'l', '>', '\x00' };

    char_T tmp_0[43];
    int32_T i;

    /* Start for MATLABSystem: '<Root>/ThingSpeak Write' */
    App_v0p1_DW.obj.isInitialized = 0;
    App_v0p1_DW.obj.isInitialized = 1;
    for (i = 0; i < 43; i++) {
      tmp_0[i] = tmp[i];
    }

    INIT_THINGSPEAK_WRITE(1.0, App_v0p1_ChannelID, tmp_0,
                          App_v0p1_UpdateInterval);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Write' */
  }
}

/* Model terminate function */
void App_v0p1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ThingSpeak Write' */
  if (App_v0p1_DW.obj.isInitialized == 1) {
    App_v0p1_DW.obj.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<Root>/ThingSpeak Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
