/*
 * File: Android_thingspeak_types.h
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

#ifndef RTW_HEADER_Android_thingspeak_types_h_
#define RTW_HEADER_Android_thingspeak_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_internal_androidT_T
#define typedef_codertarget_internal_androidT_T

typedef struct {
  int32_T isInitialized;
} codertarget_internal_androidT_T;

#endif                                 /*typedef_codertarget_internal_androidT_T*/

#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 /*struct_tag_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH_Andro_T
#define typedef_skA4KFEZ4HPkJJBOYCrevdH_Andro_T

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH_Andro_T;

#endif                                 /*typedef_skA4KFEZ4HPkJJBOYCrevdH_Andro_T*/

#ifndef typedef_codertarget_internal_androidD_T
#define typedef_codertarget_internal_androidD_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_internal_androidD_T;

#endif                                 /*typedef_codertarget_internal_androidD_T*/

#ifndef typedef_codertarget_internal_androidB_T
#define typedef_codertarget_internal_androidB_T

typedef struct {
  int32_T isInitialized;
} codertarget_internal_androidB_T;

#endif                                 /*typedef_codertarget_internal_androidB_T*/

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E_Andro_T
#define typedef_sJCxfmxS8gBOONUZjbjUd9E_Andro_T

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E_Andro_T;

#endif                                 /*typedef_sJCxfmxS8gBOONUZjbjUd9E_Andro_T*/

#ifndef typedef_cell_wrap_Android_thingspeak_T
#define typedef_cell_wrap_Android_thingspeak_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_Android_thingspeak_T;

#endif                                 /*typedef_cell_wrap_Android_thingspeak_T*/

#ifndef typedef_codertarget_internal_androi_n_T
#define typedef_codertarget_internal_androi_n_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_Android_thingspeak_T inputVarSize[8];
} codertarget_internal_androi_n_T;

#endif                                 /*typedef_codertarget_internal_androi_n_T*/

#ifndef typedef_codertarget_internal_andro_nh_T
#define typedef_codertarget_internal_andro_nh_T

typedef struct {
  int32_T isInitialized;
  cell_wrap_Android_thingspeak_T inputVarSize;
} codertarget_internal_andro_nh_T;

#endif                                 /*typedef_codertarget_internal_andro_nh_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_Android_thingspeak_T RT_MODEL_Android_thingspeak_T;

#endif                                 /* RTW_HEADER_Android_thingspeak_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
