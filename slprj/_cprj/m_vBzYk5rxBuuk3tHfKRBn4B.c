/* Include files */

#include "modelInterface.h"
#include "m_vBzYk5rxBuuk3tHfKRBn4B.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const mxArray *eml_mx;
static const mxArray *b_eml_mx;
static emlrtRSInfo emlrtRSI = { 1,     /* lineNo */
  "androidButton",                     /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2018b\\toolbox\\target\\supportpackages\\android\\+codertarget\\+internal\\androidButton.p"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 1,   /* lineNo */
  "androidSampleTime",                 /* fcnName */
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2018b\\toolbox\\target\\supportpackages\\android\\+codertarget\\+internal\\androidSampleTime.p"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 1,   /* lineNo */
  "System",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\System.p"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 1,   /* lineNo */
  "SystemProp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemProp.p"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 1,   /* lineNo */
  "SystemCore",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 1,   /* lineNo */
  "SampleTime",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+mixin\\+coder\\+internal\\SampleTime.p"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 1,   /* lineNo */
  "CustomIcon",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\matlab\\system\\+matlab\\+system\\+mixin\\CustomIcon.p"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 43,  /* lineNo */
  "ExternalDependency",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\shared\\coder\\coder\\+coder\\ExternalDependency.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 9,   /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 22,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 24,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 29,  /* lineNo */
  "",                                  /* fcnName */
  ""                                   /* pathName */
};

static emlrtMCInfo emlrtMCI = { 1,     /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2018b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"/* pName */
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);
static void mw__internal__system__init__fcn(void);
static void mw__internal__call__setup(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance, const emlrtStack *sp);
static void mw__internal__call__reset(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance, const emlrtStack *sp);
static boolean_T mw__internal__call__step(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *
  moduleInstance, const emlrtStack *sp);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance);
static codertarget_internal_androidButton emlrt_marshallIn(const emlrtStack *sp,
  const mxArray *b_sysobj, const char_T *identifier);
static codertarget_internal_androidButton b_emlrt_marshallIn(const emlrtStack
  *sp, const mxArray *u, const emlrtMsgIdentifier *parentId);
static int32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_sysobj_not_empty, const char_T *identifier);
static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void cgxe_mdl_set_sim_state(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance, const mxArray *st);
static const mxArray *message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static const mxArray *getString(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);
static void error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  emlrtMCInfo *location);
static int32_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void init_simulink_io_address(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  init_simulink_io_address(moduleInstance);
  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__system__init__fcn();
  mw__internal__call__setup(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_initialize(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  mw__internal__call__reset(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_outputs(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = moduleInstance->emlrtRootTLSGlobal;
  cgxertSetGcb(moduleInstance->S, -1, -1);
  *moduleInstance->b_y0 = mw__internal__call__step(moduleInstance, &st);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void cgxe_mdl_update(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  emlrtDestroyArray(&b_eml_mx);
  emlrtDestroyArray(&eml_mx);
  cgxertSetGcb(moduleInstance->S, -1, -1);
  cgxertRestoreGcb(moduleInstance->S, -1, -1);
}

static void mw__internal__system__init__fcn(void)
{
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 0, 0 };

  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtAssignP(&b_eml_mx, m0);
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtAssignP(&eml_mx, m0);
}

static void mw__internal__call__setup(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance, const emlrtStack *sp)
{
  emlrtStack st;
  emlrtStack b_st;
  codertarget_internal_androidButton *obj;
  emlrtStack c_st;
  char_T u[51];
  emlrtStack d_st;
  int32_T i0;
  emlrtStack e_st;
  const mxArray *y;
  static char_T b_u[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *m1;
  static const int32_T iv2[2] = { 1, 51 };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 51 };

  char_T c_u[5];
  const mxArray *c_y;
  static char_T d_u[5] = { 's', 'e', 't', 'u', 'p' };

  static const int32_T iv4[2] = { 1, 5 };

  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &i_emlrtRSI;
    obj = &moduleInstance->sysobj;
    b_st.site = &emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    e_st.site = &d_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    obj->isInitialized = 0;
    e_st.site = &e_emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &g_emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &h_emlrtRSI;
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &j_emlrtRSI;
  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized != 0) {
    for (i0 = 0; i0 < 51; i0++) {
      u[i0] = b_u[i0];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(&st, 51, m1, &u[0]);
    emlrtAssign(&y, m1);
    for (i0 = 0; i0 < 51; i0++) {
      u[i0] = b_u[i0];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(&st, 51, m1, &u[0]);
    emlrtAssign(&b_y, m1);
    for (i0 = 0; i0 < 5; i0++) {
      c_u[i0] = d_u[i0];
    }

    c_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(&st, 5, m1, &c_u[0]);
    emlrtAssign(&c_y, m1);
    b_st.site = &e_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, b_y, c_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }

  obj->isInitialized = 1;
}

static void mw__internal__call__reset(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance, const emlrtStack *sp)
{
  emlrtStack st;
  emlrtStack b_st;
  codertarget_internal_androidButton *obj;
  char_T u[45];
  emlrtStack c_st;
  int32_T i1;
  emlrtStack d_st;
  emlrtStack e_st;
  const mxArray *y;
  static char_T b_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *m2;
  static const int32_T iv5[2] = { 1, 45 };

  const mxArray *b_y;
  static const int32_T iv6[2] = { 1, 45 };

  char_T c_u[5];
  const mxArray *c_y;
  static char_T d_u[5] = { 'r', 'e', 's', 'e', 't' };

  static const int32_T iv7[2] = { 1, 5 };

  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &i_emlrtRSI;
    obj = &moduleInstance->sysobj;
    b_st.site = &emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    e_st.site = &d_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    obj->isInitialized = 0;
    e_st.site = &e_emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &g_emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &h_emlrtRSI;
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &k_emlrtRSI;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i1 = 0; i1 < 45; i1++) {
      u[i1] = b_u[i1];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(&st, 45, m2, &u[0]);
    emlrtAssign(&y, m2);
    for (i1 = 0; i1 < 45; i1++) {
      u[i1] = b_u[i1];
    }

    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(&st, 45, m2, &u[0]);
    emlrtAssign(&b_y, m2);
    for (i1 = 0; i1 < 5; i1++) {
      c_u[i1] = d_u[i1];
    }

    c_y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    emlrtInitCharArrayR2013a(&st, 5, m2, &c_u[0]);
    emlrtAssign(&c_y, m2);
    b_st.site = &e_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, b_y, c_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }
}

static boolean_T mw__internal__call__step(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *
  moduleInstance, const emlrtStack *sp)
{
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  codertarget_internal_androidButton *obj;
  char_T u[45];
  int32_T i2;
  emlrtStack e_st;
  const mxArray *y;
  static char_T b_u[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *m3;
  static const int32_T iv8[2] = { 1, 45 };

  static char_T d_u[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  static const int32_T iv9[2] = { 1, 51 };

  const mxArray *b_y;
  static const int32_T iv10[2] = { 1, 45 };

  char_T e_u[4];
  static const int32_T iv11[2] = { 1, 51 };

  const mxArray *c_y;
  static char_T f_u[4] = { 's', 't', 'e', 'p' };

  char_T g_u[5];
  static const int32_T iv12[2] = { 1, 4 };

  static char_T h_u[5] = { 's', 'e', 't', 'u', 'p' };

  static const int32_T iv13[2] = { 1, 5 };

  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (!moduleInstance->sysobj_not_empty) {
    st.site = &i_emlrtRSI;
    obj = &moduleInstance->sysobj;
    b_st.site = &emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    e_st.site = &d_emlrtRSI;
    d_st.site = &c_emlrtRSI;
    obj->isInitialized = 0;
    e_st.site = &e_emlrtRSI;
    c_st.site = &b_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &g_emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &h_emlrtRSI;
    moduleInstance->sysobj_not_empty = true;
  }

  st.site = &l_emlrtRSI;
  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i2 = 0; i2 < 45; i2++) {
      u[i2] = b_u[i2];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv8);
    emlrtInitCharArrayR2013a(&st, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i2 = 0; i2 < 45; i2++) {
      u[i2] = b_u[i2];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    emlrtInitCharArrayR2013a(&st, 45, m3, &u[0]);
    emlrtAssign(&b_y, m3);
    for (i2 = 0; i2 < 4; i2++) {
      e_u[i2] = f_u[i2];
    }

    c_y = NULL;
    m3 = emlrtCreateCharArray(2, iv12);
    emlrtInitCharArrayR2013a(&st, 4, m3, &e_u[0]);
    emlrtAssign(&c_y, m3);
    b_st.site = &e_emlrtRSI;
    error(&b_st, y, getString(&b_st, message(&b_st, b_y, c_y, &emlrtMCI),
           &emlrtMCI), &emlrtMCI);
  }

  if (obj->isInitialized != 1) {
    b_st.site = &e_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    if (obj->isInitialized != 0) {
      for (i2 = 0; i2 < 51; i2++) {
        c_u[i2] = d_u[i2];
      }

      y = NULL;
      m3 = emlrtCreateCharArray(2, iv9);
      emlrtInitCharArrayR2013a(&c_st, 51, m3, &c_u[0]);
      emlrtAssign(&y, m3);
      for (i2 = 0; i2 < 51; i2++) {
        c_u[i2] = d_u[i2];
      }

      b_y = NULL;
      m3 = emlrtCreateCharArray(2, iv11);
      emlrtInitCharArrayR2013a(&c_st, 51, m3, &c_u[0]);
      emlrtAssign(&b_y, m3);
      for (i2 = 0; i2 < 5; i2++) {
        g_u[i2] = h_u[i2];
      }

      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv13);
      emlrtInitCharArrayR2013a(&c_st, 5, m3, &g_u[0]);
      emlrtAssign(&c_y, m3);
      d_st.site = &e_emlrtRSI;
      error(&d_st, y, getString(&d_st, message(&d_st, b_y, c_y, &emlrtMCI),
             &emlrtMCI), &emlrtMCI);
    }

    obj->isInitialized = 1;
  }

  return true;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  int32_T hoistedGlobal_isInitialized;
  const mxArray *b_y;
  static const char * sv0[1] = { "isInitialized" };

  const mxArray *c_y;
  const mxArray *m4;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  hoistedGlobal_isInitialized = moduleInstance->sysobj.isInitialized;
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 1, sv0));
  c_y = NULL;
  m4 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m4) = hoistedGlobal_isInitialized;
  emlrtAssign(&c_y, m4);
  emlrtSetFieldR2017b(b_y, 0, "isInitialized", c_y, 0);
  emlrtSetCell(y, 0, b_y);
  b_y = NULL;
  m4 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&b_y, m4);
  emlrtSetCell(y, 1, b_y);
  emlrtAssign(&st, y);
  return st;
}

static codertarget_internal_androidButton emlrt_marshallIn(const emlrtStack *sp,
  const mxArray *b_sysobj, const char_T *identifier)
{
  codertarget_internal_androidButton y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_sysobj), &thisId);
  emlrtDestroyArray(&b_sysobj);
  return y;
}

static codertarget_internal_androidButton b_emlrt_marshallIn(const emlrtStack
  *sp, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  codertarget_internal_androidButton y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[1] = { "isInitialized" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 1, fieldNames, 0U, &dims);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u,
    0, 0, "isInitialized")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *b_sysobj_not_empty, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance, const mxArray *st)
{
  emlrtStack b_st = { NULL,            /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *u;
  b_st.tls = moduleInstance->emlrtRootTLSGlobal;
  u = emlrtAlias(st);
  moduleInstance->sysobj = emlrt_marshallIn(&b_st, emlrtAlias(emlrtGetCell(&b_st,
    "sysobj", u, 0)), "sysobj");
  moduleInstance->sysobj_not_empty = d_emlrt_marshallIn(&b_st, emlrtAlias
    (emlrtGetCell(&b_st, "sysobj_not_empty", u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 2, pArrays, "message", true, location);
}

static const mxArray *getString(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m6;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 1, &pArray, "getString", true,
    location);
}

static void error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

static int32_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 0U, &dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "logical", false, 0U, &dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void init_simulink_io_address(InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->b_y0 = (boolean_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S, int_T tid)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S, int_T tid)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
  InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *moduleInstance =
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B *)calloc(1, sizeof
    (InstanceStruct_vBzYk5rxBuuk3tHfKRBn4B));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_vBzYk5rxBuuk3tHfKRBn4B);
  ssSetmdlInitializeConditions(S, mdlInitialize_vBzYk5rxBuuk3tHfKRBn4B);
  ssSetmdlUpdate(S, mdlUpdate_vBzYk5rxBuuk3tHfKRBn4B);
  ssSetmdlTerminate(S, mdlTerminate_vBzYk5rxBuuk3tHfKRBn4B);
  ssSetmdlEnable(S, mdlEnable_vBzYk5rxBuuk3tHfKRBn4B);
  ssSetmdlDisable(S, mdlDisable_vBzYk5rxBuuk3tHfKRBn4B);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S)
{
}

void method_dispatcher_vBzYk5rxBuuk3tHfKRBn4B(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_vBzYk5rxBuuk3tHfKRBn4B(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_vBzYk5rxBuuk3tHfKRBn4B(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_vBzYk5rxBuuk3tHfKRBn4B(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_vBzYk5rxBuuk3tHfKRBn4B(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: vBzYk5rxBuuk3tHfKRBn4B.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_vBzYk5rxBuuk3tHfKRBn4B_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxArray * elem_10;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,1);
  elem_9 = mxCreateString("codertarget.internal.androidButton");
  mxSetCell(elem_8,0,elem_9);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_10 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_10);
  return mxBIArgs;
}

mxArray *cgxe_vBzYk5rxBuuk3tHfKRBn4B_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("thirdPartyLibs");
  mxArray* incompatibleSymbol = mxCreateString(
    "codertarget.internal.androidButton");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
