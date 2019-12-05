/*
 * File: App_v0p2_private.h
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

#ifndef RTW_HEADER_App_v0p2_private_h_
#define RTW_HEADER_App_v0p2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

extern real32_T rt_roundf_snf(real32_T u);
extern void Single2MultiWord(real32_T u1, uint32_T y[], int32_T n);
extern int32_T div_s32(int32_T numerator, int32_T denominator);

#endif                                 /* RTW_HEADER_App_v0p2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
