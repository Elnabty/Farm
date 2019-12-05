#ifndef __TmhUzaTizl4mODx5ncv8iC_h__
#define __TmhUzaTizl4mODx5ncv8iC_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
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

#ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH
#define typedef_skA4KFEZ4HPkJJBOYCrevdH

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH;

#endif                                 /*typedef_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct {
  uint32_T f1[8];
} cell_wrap;

#endif                                 /*typedef_cell_wrap*/

#ifndef typedef_codertarget_internal_androidThingSpeakWrite
#define typedef_codertarget_internal_androidThingSpeakWrite

typedef struct {
  int32_T isInitialized;
  cell_wrap inputVarSize[8];
} codertarget_internal_androidThingSpeakWrite;

#endif                                 /*typedef_codertarget_internal_androidThingSpeakWrite*/

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

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E
#define typedef_sJCxfmxS8gBOONUZjbjUd9E

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E;

#endif                                 /*typedef_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_InstanceStruct_TmhUzaTizl4mODx5ncv8iC
#define typedef_InstanceStruct_TmhUzaTizl4mODx5ncv8iC

typedef struct {
  SimStruct *S;
  codertarget_internal_androidThingSpeakWrite sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  uint8_T *u0;
  uint8_T *u1;
  uint8_T *u2;
  uint8_T *u3;
  int8_T *u4;
  int8_T *u5;
  int8_T *u6;
  int8_T *u7;
} InstanceStruct_TmhUzaTizl4mODx5ncv8iC;

#endif                                 /*typedef_InstanceStruct_TmhUzaTizl4mODx5ncv8iC*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_TmhUzaTizl4mODx5ncv8iC(SimStruct *S, int_T method,
  void* data);

#endif
