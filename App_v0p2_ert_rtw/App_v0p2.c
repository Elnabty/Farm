/*
 * File: App_v0p2.c
 *
 * Code generated for Simulink model 'App_v0p2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov  5 22:22:59 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "App_v0p2.h"
#include "App_v0p2_private.h"

/* Real-time model */
RT_MODEL_App_v0p2_T App_v0p2_M_;
RT_MODEL_App_v0p2_T *const App_v0p2_M = &App_v0p2_M_;
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
void App_v0p2_step(void)
{
  real32_T Data;
  int16_T Status;
  int64m_T outData;
  char_T tmp[3];
  int64m_T tmp_0;
  int64m_T tmp_1;
  static int64m_T tmp_2 = { { 0U, 2147483648U }/* chunks */
  };

  static int64m_T tmp_3 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  /* MATLABSystem: '<Root>/ThingSpeak Read1' */
  READ_THINGSPEAK_DATA(873337U, &Data, &Status, 2);

  /* MATLABSystem: '<S2>/DataDisplay' incorporates:
   *  MATLABSystem: '<Root>/ThingSpeak Read1'
   */
  Data = rt_roundf_snf(Data);
  if (Data < 9.22337204E+18F) {
    if (Data >= -9.22337204E+18F) {
      Single2MultiWord(Data, &outData.chunks[0U], 2);
    } else {
      outData = tmp_2;
    }
  } else {
    outData = tmp_3;
  }

  tmp[0] = '%';
  tmp[1] = 'd';
  tmp[2] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 1.0, 7, 1, tmp);

  /* End of MATLABSystem: '<S2>/DataDisplay' */

  /* MATLABSystem: '<Root>/ThingSpeak Read' */
  READ_THINGSPEAK_DATA(873337U, &Data, &Status, 1);

  /* MATLABSystem: '<S6>/DataDisplay' incorporates:
   *  MATLABSystem: '<Root>/ThingSpeak Read'
   */
  Data = rt_roundf_snf(Data);
  if (Data < 9.22337204E+18F) {
    if (Data >= -9.22337204E+18F) {
      Single2MultiWord(Data, &tmp_1.chunks[0U], 2);
    } else {
      tmp_1 = tmp_2;
    }
  } else {
    tmp_1 = tmp_3;
  }

  outData = tmp_1;
  tmp[0] = '%';
  tmp[1] = 'd';
  tmp[2] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 2.0, 7, 1, tmp);

  /* End of MATLABSystem: '<S6>/DataDisplay' */

  /* MATLABSystem: '<Root>/ThingSpeak Read2' */
  READ_THINGSPEAK_DATA(873337U, &Data, &Status, 3);

  /* MATLABSystem: '<S7>/DataDisplay' incorporates:
   *  MATLABSystem: '<Root>/ThingSpeak Read2'
   */
  Data = rt_roundf_snf(Data);
  if (Data < 9.22337204E+18F) {
    if (Data >= -9.22337204E+18F) {
      Single2MultiWord(Data, &tmp_0.chunks[0U], 2);
    } else {
      tmp_0 = tmp_2;
    }
  } else {
    tmp_0 = tmp_3;
  }

  outData = tmp_0;
  tmp[0] = '%';
  tmp[1] = 'd';
  tmp[2] = '\x00';
  PUT_DATADISPLAY_DATA(&outData, 3.0, 7, 1, tmp);

  /* End of MATLABSystem: '<S7>/DataDisplay' */
}

/* Model initialize function */
void App_v0p2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(App_v0p2_M, (NULL));

  {
    static const char_T tmp[17] = { 'F', 'I', 'G', '9', 'S', 'N', 'R', '4', '6',
      'R', '1', 'P', 'T', 'Q', 'F', 'B', '\x00' };

    char_T tmp_0[17];
    int32_T i;

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read1' */
    for (i = 0; i < 17; i++) {
      tmp_0[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(873337.0, tmp_0, '2');

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read1' */

    /* Start for MATLABSystem: '<S2>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read' */
    for (i = 0; i < 17; i++) {
      tmp_0[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(873337.0, tmp_0, '1');

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read' */

    /* Start for MATLABSystem: '<S6>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read2' */
    for (i = 0; i < 17; i++) {
      tmp_0[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(873337.0, tmp_0, '3');

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read2' */

    /* Start for MATLABSystem: '<S7>/DataDisplay' */
    INITIALIZE_DATADISPLAY();
  }
}

/* Model terminate function */
void App_v0p2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
