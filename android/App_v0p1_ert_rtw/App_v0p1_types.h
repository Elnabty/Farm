/*
 * File: App_v0p1_types.h
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

#ifndef RTW_HEADER_App_v0p1_types_h_
#define RTW_HEADER_App_v0p1_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_internal_androidT_T
#define typedef_codertarget_internal_androidT_T

typedef struct {
  int32_T isInitialized;
} codertarget_internal_androidT_T;

#endif                                 /*typedef_codertarget_internal_androidT_T*/

#ifndef typedef_cell_wrap_App_v0p1_T
#define typedef_cell_wrap_App_v0p1_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_App_v0p1_T;

#endif                                 /*typedef_cell_wrap_App_v0p1_T*/

#ifndef typedef_codertarget_internal_androidD_T
#define typedef_codertarget_internal_androidD_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_App_v0p1_T inputVarSize;
} codertarget_internal_androidD_T;

#endif                                 /*typedef_codertarget_internal_androidD_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_App_v0p1_T RT_MODEL_App_v0p1_T;

#endif                                 /* RTW_HEADER_App_v0p1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
