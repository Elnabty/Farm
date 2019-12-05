/*
 * File: App_v0p2.c
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

#include "App_v0p2.h"
#include "App_v0p2_private.h"

/* Block signals (default storage) */
B_App_v0p2_T App_v0p2_B;

/* Block states (default storage) */
DW_App_v0p2_T App_v0p2_DW;

/* Real-time model */
RT_MODEL_App_v0p2_T App_v0p2_M_;
RT_MODEL_App_v0p2_T *const App_v0p2_M = &App_v0p2_M_;

/* Forward declaration for local functions */
static void App_v0p2_SystemCore_release(const codertarget_internal_androidD_T
  *obj);
static void App_v0p2_SystemCore_delete(const codertarget_internal_androidD_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_internal_androidD_T *obj);
static void rate_scheduler(void);
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
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (App_v0p2_M->Timing.TaskCounters.TID[1])++;
  if ((App_v0p2_M->Timing.TaskCounters.TID[1]) > 29) {/* Sample time: [3.0s, 0.0s] */
    App_v0p2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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

static void App_v0p2_SystemCore_release(const codertarget_internal_androidD_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    DATAINPUT_TERMINATE();
  }
}

static void App_v0p2_SystemCore_delete(const codertarget_internal_androidD_T
  *obj)
{
  App_v0p2_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_internal_androidD_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    App_v0p2_SystemCore_delete(obj);
  }
}

/* Model step function */
void App_v0p2_step(void)
{
  boolean_T rtb_Button_0;
  boolean_T rtb_Button_o_0;
  boolean_T rtb_Button_k_0;
  boolean_T rtb_Button_m_0;
  real_T y;
  real_T y_0;
  uint32_T sendPost;
  real32_T Data;
  int16_T Status;
  int64m_T outData;
  char_T tmp[3];
  int64m_T tmp_0;
  int64m_T tmp_1;
  int8_T tmp_2;
  static int64m_T tmp_3 = { { 0U, 2147483648U }/* chunks */
  };

  static int64m_T tmp_4 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  /* MATLABSystem: '<S5>/Button' */
  rtb_Button_0 = BUTTON_GETSTATE(4.0);

  /* MATLABSystem: '<S3>/Button' */
  rtb_Button_o_0 = BUTTON_GETSTATE(2.0);

  /* MATLABSystem: '<S1>/Button' */
  rtb_Button_k_0 = BUTTON_GETSTATE(1.0);

  /* MATLABSystem: '<S4>/Button' */
  rtb_Button_m_0 = BUTTON_GETSTATE(3.0);

  /* MATLABSystem: '<Root>/Syring1' */
  DATAINPUT_GETVAL(1.0, &App_v0p2_B.y, 0.0, 4.0);

  /* MATLABSystem: '<Root>/Syring2' */
  DATAINPUT_GETVAL(3.0, &App_v0p2_B.y_m, 0.0, 4.0);

  /* MATLABSystem: '<Root>/Syring1 control' */
  DATAINPUT_GETVAL(2.0, &y, 0.0, 4.0);

  /* MATLABSystem: '<Root>/Syring2 control' */
  DATAINPUT_GETVAL(4.0, &y_0, 0.0, 4.0);

  /* MATLABSystem: '<Root>/ThingSpeak Write' incorporates:
   *  MATLABSystem: '<S1>/Button'
   *  MATLABSystem: '<S3>/Button'
   *  MATLABSystem: '<S4>/Button'
   *  MATLABSystem: '<S5>/Button'
   */
  CHECK_UPDATE_INTERVAL(1.0, &sendPost);
  if (sendPost == 1U) {
    ADD_FIELD(1.0, 1, (real_T)rtb_Button_0);
    ADD_FIELD(1.0, 2, (real_T)rtb_Button_o_0);
    ADD_FIELD(1.0, 3, (real_T)rtb_Button_k_0);
    ADD_FIELD(1.0, 4, (real_T)rtb_Button_m_0);

    /* MATLABSystem: '<Root>/Syring1' incorporates:
     *  MATLABSystem: '<S1>/Button'
     *  MATLABSystem: '<S3>/Button'
     *  MATLABSystem: '<S4>/Button'
     *  MATLABSystem: '<S5>/Button'
     */
    App_v0p2_B.y = rt_roundd_snf(App_v0p2_B.y);
    if (App_v0p2_B.y < 128.0) {
      if (App_v0p2_B.y >= -128.0) {
        tmp_2 = (int8_T)App_v0p2_B.y;
      } else {
        tmp_2 = MIN_int8_T;
      }
    } else {
      tmp_2 = MAX_int8_T;
    }

    ADD_FIELD(1.0, 5, (real_T)tmp_2);

    /* MATLABSystem: '<Root>/Syring2' */
    App_v0p2_B.y = rt_roundd_snf(App_v0p2_B.y_m);
    if (App_v0p2_B.y < 128.0) {
      if (App_v0p2_B.y >= -128.0) {
        tmp_2 = (int8_T)App_v0p2_B.y;
      } else {
        tmp_2 = MIN_int8_T;
      }
    } else {
      tmp_2 = MAX_int8_T;
    }

    ADD_FIELD(1.0, 6, (real_T)tmp_2);

    /* MATLABSystem: '<Root>/Syring1 control' */
    App_v0p2_B.y = rt_roundd_snf(y);
    if (App_v0p2_B.y < 128.0) {
      if (App_v0p2_B.y >= -128.0) {
        tmp_2 = (int8_T)App_v0p2_B.y;
      } else {
        tmp_2 = MIN_int8_T;
      }
    } else {
      tmp_2 = MAX_int8_T;
    }

    ADD_FIELD(1.0, 7, (real_T)tmp_2);

    /* MATLABSystem: '<Root>/Syring2 control' */
    App_v0p2_B.y = rt_roundd_snf(y_0);
    if (App_v0p2_B.y < 128.0) {
      if (App_v0p2_B.y >= -128.0) {
        tmp_2 = (int8_T)App_v0p2_B.y;
      } else {
        tmp_2 = MIN_int8_T;
      }
    } else {
      tmp_2 = MAX_int8_T;
    }

    ADD_FIELD(1.0, 8, (real_T)tmp_2);
    SEND_POST_REQUEST(1.0);
  }

  /* End of MATLABSystem: '<Root>/ThingSpeak Write' */
  if (App_v0p2_M->Timing.TaskCounters.TID[1] == 0) {
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
        outData = tmp_3;
      }
    } else {
      outData = tmp_4;
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

    /* End of MATLABSystem: '<S7>/DataDisplay' */
  }

  rate_scheduler();
}

/* Model initialize function */
void App_v0p2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)App_v0p2_M, 0,
                sizeof(RT_MODEL_App_v0p2_T));

  /* states (dwork) */
  (void) memset((void *)&App_v0p2_DW, 0,
                sizeof(DW_App_v0p2_T));

  {
    static const char_T tmp[17] = { 'F', 'I', 'G', '9', 'S', 'N', 'R', '4', '6',
      'R', '1', 'P', 'T', 'Q', 'F', 'B', '\x00' };

    static const char_T tmp_0[17] = { 'D', '0', 'F', 'Y', 'Y', 'A', 'J', '2',
      '5', 'Y', 'P', 'K', 'U', 'U', '0', 'I', '\x00' };

    char_T tmp_1[17];
    real_T tmp_2[2];
    int32_T i;

    /* Start for MATLABSystem: '<S5>/Button' */
    BUTTON_INIT(4.0);

    /* Start for MATLABSystem: '<S3>/Button' */
    BUTTON_INIT(2.0);

    /* Start for MATLABSystem: '<S1>/Button' */
    BUTTON_INIT(1.0);

    /* Start for MATLABSystem: '<S4>/Button' */
    BUTTON_INIT(3.0);

    /* Start for MATLABSystem: '<Root>/Syring1' */
    App_v0p2_DW.obj_j.matlabCodegenIsDeleted = true;
    App_v0p2_DW.obj_j.isInitialized = 0;
    App_v0p2_DW.obj_j.matlabCodegenIsDeleted = false;
    App_v0p2_DW.obj_j.isSetupComplete = false;
    App_v0p2_DW.obj_j.isInitialized = 1;
    tmp_2[0] = 1.0;
    tmp_2[1] = 0.0;
    DATAINPUT_INIT(1.0, tmp_2, 1.0, 2);
    App_v0p2_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Syring2' */
    App_v0p2_DW.obj_lf.matlabCodegenIsDeleted = true;
    App_v0p2_DW.obj_lf.isInitialized = 0;
    App_v0p2_DW.obj_lf.matlabCodegenIsDeleted = false;
    App_v0p2_DW.obj_lf.isSetupComplete = false;
    App_v0p2_DW.obj_lf.isInitialized = 1;
    tmp_2[0] = 1.0;
    tmp_2[1] = 0.0;
    DATAINPUT_INIT(3.0, tmp_2, 1.0, 2);
    App_v0p2_DW.obj_lf.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Syring1 control' */
    App_v0p2_DW.obj_h0.matlabCodegenIsDeleted = true;
    App_v0p2_DW.obj_h0.isInitialized = 0;
    App_v0p2_DW.obj_h0.matlabCodegenIsDeleted = false;
    App_v0p2_DW.obj_h0.isSetupComplete = false;
    App_v0p2_DW.obj_h0.isInitialized = 1;
    tmp_2[0] = 1.0;
    tmp_2[1] = 0.0;
    DATAINPUT_INIT(2.0, tmp_2, 1.0, 2);
    App_v0p2_DW.obj_h0.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Syring2 control' */
    App_v0p2_DW.obj_b.matlabCodegenIsDeleted = true;
    App_v0p2_DW.obj_b.isInitialized = 0;
    App_v0p2_DW.obj_b.matlabCodegenIsDeleted = false;
    App_v0p2_DW.obj_b.isSetupComplete = false;
    App_v0p2_DW.obj_b.isInitialized = 1;
    tmp_2[0] = 1.0;
    tmp_2[1] = 0.0;
    DATAINPUT_INIT(4.0, tmp_2, 1.0, 2);
    App_v0p2_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/ThingSpeak Write' */
    for (i = 0; i < 17; i++) {
      tmp_1[i] = tmp_0[i];
    }

    INIT_THINGSPEAK_WRITE(1.0, 903379.0, tmp_1, 3.0);

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Write' */

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read1' */
    for (i = 0; i < 17; i++) {
      tmp_1[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(873337.0, tmp_1, '2');

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read1' */

    /* Start for MATLABSystem: '<S2>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read' */
    for (i = 0; i < 17; i++) {
      tmp_1[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(873337.0, tmp_1, '1');

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read' */

    /* Start for MATLABSystem: '<S6>/DataDisplay' */
    INITIALIZE_DATADISPLAY();

    /* Start for MATLABSystem: '<Root>/ThingSpeak Read2' */
    for (i = 0; i < 17; i++) {
      tmp_1[i] = tmp[i];
    }

    INIT_THINGSPEAK_READ(873337.0, tmp_1, '3');

    /* End of Start for MATLABSystem: '<Root>/ThingSpeak Read2' */

    /* Start for MATLABSystem: '<S7>/DataDisplay' */
    INITIALIZE_DATADISPLAY();
  }
}

/* Model terminate function */
void App_v0p2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Syring1' */
  matlabCodegenHandle_matlabCodeg(&App_v0p2_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Syring2' */
  matlabCodegenHandle_matlabCodeg(&App_v0p2_DW.obj_lf);

  /* Terminate for MATLABSystem: '<Root>/Syring1 control' */
  matlabCodegenHandle_matlabCodeg(&App_v0p2_DW.obj_h0);

  /* Terminate for MATLABSystem: '<Root>/Syring2 control' */
  matlabCodegenHandle_matlabCodeg(&App_v0p2_DW.obj_b);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
