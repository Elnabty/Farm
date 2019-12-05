#ifndef __yZHQAeALt4OuuN5DI39hDH_h__
#define __yZHQAeALt4OuuN5DI39hDH_h__

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

#ifndef typedef_InstanceStruct_yZHQAeALt4OuuN5DI39hDH
#define typedef_InstanceStruct_yZHQAeALt4OuuN5DI39hDH

typedef struct {
  SimStruct *S;
  codertarget_internal_androidButton sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  boolean_T *b_y0;
} InstanceStruct_yZHQAeALt4OuuN5DI39hDH;

#endif                                 /*typedef_InstanceStruct_yZHQAeALt4OuuN5DI39hDH*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_yZHQAeALt4OuuN5DI39hDH(SimStruct *S, int_T method,
  void* data);

#endif
