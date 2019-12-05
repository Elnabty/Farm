#ifndef __vBzYk5rxBuuk3tHfKRBn4B_h__
#define __vBzYk5rxBuuk3tHfKRBn4B_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_codertarget_internal_androidButton
#define typedef_codertarget_internal_androidButton

typedef struct {
  int32_T isInitialized;
} codertarget_internal_androidButton;

#endif                                 /*typedef_codertarget_internal_androidButton*/

#ifndef typedef_InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
#define typedef_InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B

typedef struct {
  SimStruct *S;
  codertarget_internal_androidButton sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  boolean_T *b_y0;
} InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B;

#endif                                 /*typedef_InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S, int_T method,
  void* data);

#endif
