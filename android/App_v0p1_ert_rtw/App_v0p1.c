/*
 * File: App_v0p1.c
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

#include "App_v0p1.h"
#include "App_v0p1_private.h"

/* Block signals (default storage) */
B_App_v0p1_T App_v0p1_B;

/* Block states (default storage) */
DW_App_v0p1_T App_v0p1_DW;

/* Real-time model */
RT_MODEL_App_v0p1_T App_v0p1_M_;
RT_MODEL_App_v0p1_T *const App_v0p1_M = &App_v0p1_M_;
void Single2MultiWord(real32_T u1, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T currExp;
  int32_T prevExp;
  int32_T msl;
  real32_T yn;
  real32_T yd;
  boolean_T isNegative;
  uint32_T u1i;
  uint32_T cb;
  isNegative = (u1 < 0.0F);
  yn = (real32_T)frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : div_s32(currExp - 1, 32);
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = (real32_T)ldexp(yn, currExp - prevExp);
    yd = (real32_T)floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T tempAbsQuotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    tempAbsQuotient = (numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
                       numerator) / (denominator < 0 ? ~(uint32_T)denominator +
      1U : (uint32_T)denominator);
    quotient = (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

/*
 * Start for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void App_v0_ThingSpeakHumidity_Start(DW_ThingSpeakHumidity_App_v0p_T *localDW)
{
  static const char_T tmp[17] = { 'F', 'I', 'G', '9', 'S', 'N', 'R', '4', '6',
    'R', '1', 'P', 'T', 'Q', 'F', 'B', '\x00' };

  char_T tmp_0[17];
  int32_T i;

  /* Start for MATLABSystem: '<Root>/ThingSpeak Humidity' */
  localDW->obj.isInitialized = 0;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  for (i = 0; i < 17; i++) {
    tmp_0[i] = tmp[i];
  }

  INIT_THINGSPEAK_READ(873337.0, tmp_0, '1');

  /* End of Start for MATLABSystem: '<Root>/ThingSpeak Humidity' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 *    synthesized block
 */
void App_v0p1_ThingSpeakHumidity(B_ThingSpeakHumidity_App_v0p1_T *localB)
{
  int16_T Status;

  /* MATLABSystem: '<Root>/ThingSpeak Humidity' */
  READ_THINGSPEAK_DATA(873337U, &localB->ThingSpeakHumidity_o1, &Status, 1);
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void App_v0p1_step(void)
{
  int64m_T outData;
  char_T tmp[3];
  int64m_T tmp_0;
  int64m_T tmp_1;
  real32_T tmp_2;
  static int64m_T tmp_3 = { { 0U, 2147483648U }/* chunks */
  };

  static int64m_T tmp_4 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  App_v0p1_ThingSpeakHumidity(&App_v0p1_B.ThingSpeakReadTemprature);

  /* MATLABSystem: '<S1>/DataDisplay' */
  tmp_2 = rt_roundf_snf
    (App_v0p1_B.ThingSpeakReadTemprature.ThingSpeakHumidity_o1);
  if (tmp_2 < 9.22337204E+18F) {
    if (tmp_2 >= -9.22337204E+18F) {
      Single2MultiWord(tmp_2, &outData.chunks[0U], 2);
    } else {
      outData = tmp_3;
    }
  } else {
    outData = tmp_4;
  }

  tmp[0] = '%';
  tmp[1] = 'd';
  tmp[2] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 1.0, 7, 1, tmp);

  /* End of MATLABSystem: '<S1>/DataDisplay' */
  App_v0p1_ThingSpeakHumidity(&App_v0p1_B.ThingSpeakwaterlevel);

  /* MATLABSystem: '<S2>/DataDisplay' */
  tmp_2 = rt_roundf_snf(App_v0p1_B.ThingSpeakwaterlevel.ThingSpeakHumidity_o1);
  if (tmp_2 < 9.22337204E+18F) {
    if (tmp_2 >= -9.22337204E+18F) {
      Single2MultiWord(tmp_2, &tmp_1.chunks[0U], 2);
    } else {
      tmp_1 = tmp_3;
    }
  } else {
    tmp_1 = tmp_4;
  }

  outData = tmp_1;
  tmp[0] = '%';
  tmp[1] = 'd';
  tmp[2] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 2.0, 7, 1, tmp);

  /* End of MATLABSystem: '<S2>/DataDisplay' */

  /* MATLABSystem: '<Root>/ThingSpeak Humidity' */
  App_v0p1_ThingSpeakHumidity(&App_v0p1_B.ThingSpeakHumidity);

  /* MATLABSystem: '<S3>/DataDisplay' */
  tmp_2 = rt_roundf_snf(App_v0p1_B.ThingSpeakHumidity.ThingSpeakHumidity_o1);
  if (tmp_2 < 9.22337204E+18F) {
    if (tmp_2 >= -9.22337204E+18F) {
      Single2MultiWord(tmp_2, &tmp_0.chunks[0U], 2);
    } else {
      tmp_0 = tmp_3;
    }
  } else {
    tmp_0 = tmp_4;
  }

  outData = tmp_0;
  tmp[0] = '%';
  tmp[1] = 'd';
  tmp[2] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 3.0, 7, 1, tmp);

  /* End of MATLABSystem: '<S3>/DataDisplay' */
}

/* Model initialize function */
void App_v0p1_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(App_v0p1_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &App_v0p1_B), 0,
                sizeof(B_App_v0p1_T));

  /* states (dwork) */
  (void) memset((void *)&App_v0p1_DW, 0,
                sizeof(DW_App_v0p1_T));
  App_v0_ThingSpeakHumidity_Start(&App_v0p1_DW.ThingSpeakReadTemprature);

  /* Start for MATLABSystem: '<S1>/DataDisplay' */
  INITIALIZE_DATADISPLAY();
  App_v0_ThingSpeakHumidity_Start(&App_v0p1_DW.ThingSpeakwaterlevel);

  /* Start for MATLABSystem: '<S2>/DataDisplay' */
  INITIALIZE_DATADISPLAY();

  /* Start for MATLABSystem: '<Root>/ThingSpeak Humidity' */
  App_v0_ThingSpeakHumidity_Start(&App_v0p1_DW.ThingSpeakHumidity);

  /* Start for MATLABSystem: '<S3>/DataDisplay' */
  INITIALIZE_DATADISPLAY();
}

/* Model terminate function */
void App_v0p1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
