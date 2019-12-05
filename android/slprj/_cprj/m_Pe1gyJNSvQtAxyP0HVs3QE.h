#ifndef __Pe1gyJNSvQtAxyP0HVs3QE_h__
#define __Pe1gyJNSvQtAxyP0HVs3QE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_codertarget_internal_androidThingSpeakRead
#define typedef_codertarget_internal_androidThingSpeakRead

typedef struct {
  int32_T isInitialized;
} codertarget_internal_androidThingSpeakRead;

#endif                                 /*typedef_codertarget_internal_androidThingSpeakRead*/

#ifndef typedef_InstanceStruct_Pe1gyJNSvQtAxyP0HVs3QE
#define typedef_InstanceStruct_Pe1gyJNSvQtAxyP0HVs3QE

typedef struct {
  SimStruct *S;
  codertarget_internal_androidThingSpeakRead sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  real32_T *b_y0;
  int16_T *b_y1;
} InstanceStruct_Pe1gyJNSvQtAxyP0HVs3QE;

#endif                                 /*typedef_InstanceStruct_Pe1gyJNSvQtAxyP0HVs3QE*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_Pe1gyJNSvQtAxyP0HVs3QE(SimStruct *S, int_T method,
  void* data);

#endif
