/*
 * File: App_v0p1_private.h
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

#ifndef RTW_HEADER_App_v0p1_private_h_
#define RTW_HEADER_App_v0p1_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "App_v0p1.h"

extern real32_T rt_roundf_snf(real32_T u);
extern void Single2MultiWord(real32_T u1, uint32_T y[], int32_T n);
extern int32_T div_s32(int32_T numerator, int32_T denominator);
extern void App_v0_ThingSpeakHumidity_Start(DW_ThingSpeakHumidity_App_v0p_T
  *localDW);
extern void App_v0p1_ThingSpeakHumidity(B_ThingSpeakHumidity_App_v0p1_T *localB);

#endif                                 /* RTW_HEADER_App_v0p1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
