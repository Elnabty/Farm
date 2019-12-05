#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                App_v0p2_cgxe
#include "simstruc.h"
#include "App_v0p2_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_App_v0p2_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(11, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 279372557;
  checksumData[1] = 1275459670;
  checksumData[2] = 711091181;
  checksumData[3] = 2951247548;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 591754915;
  checksumData[1] = 1752830631;
  checksumData[2] = 1172492883;
  checksumData[3] = 3732778455;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1235832311;
  checksumData[1] = 1719556619;
  checksumData[2] = 298458293;
  checksumData[3] = 2220027090;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1501148124;
  checksumData[1] = 3555686117;
  checksumData[2] = 1373096950;
  checksumData[3] = 1375154209;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1720981072;
  checksumData[1] = 1241877930;
  checksumData[2] = 3401619184;
  checksumData[3] = 2989578208;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1865285078;
  checksumData[1] = 3736053294;
  checksumData[2] = 489879641;
  checksumData[3] = 609314347;
  mxSetCell(mxModules, 5, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1910496613;
  checksumData[1] = 3272461964;
  checksumData[2] = 893387025;
  checksumData[3] = 3273350333;
  mxSetCell(mxModules, 6, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2717735848;
  checksumData[1] = 397043411;
  checksumData[2] = 817393165;
  checksumData[3] = 2314915160;
  mxSetCell(mxModules, 7, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2893866641;
  checksumData[1] = 3956395785;
  checksumData[2] = 1406358466;
  checksumData[3] = 449835023;
  mxSetCell(mxModules, 8, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3193493619;
  checksumData[1] = 646722687;
  checksumData[2] = 3978219131;
  checksumData[3] = 4040831530;
  mxSetCell(mxModules, 9, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3573139617;
  checksumData[1] = 1489708139;
  checksumData[2] = 195134065;
  checksumData[3] = 3753063107;
  mxSetCell(mxModules, 10, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 402564362;
    checksumData[1] = 181304244;
    checksumData[2] = 4145149883;
    checksumData[3] = 3613658850;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 1635065977;
    checksumData[1] = 1527198931;
    checksumData[2] = 763554759;
    checksumData[3] = 4283351002;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 0;
    checksumData[1] = 0;
    checksumData[2] = 0;
    checksumData[3] = 0;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 2153528811;
    checksumData[1] = 1627926172;
    checksumData[2] = 994292513;
    checksumData[3] = 4153623629;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_App_v0p2_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE, (void *)
    (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_App_v0p2_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE, (void *)
    prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "q5pXm8srdYxK0T8n4wsZmB") == 0) {
    extern mxArray *cgxe_q5pXm8srdYxK0T8n4wsZmB_BuildInfoUpdate(void);
    plhs[0] = cgxe_q5pXm8srdYxK0T8n4wsZmB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "N7dQiE8dzxoZ3zD5HN1j4") == 0) {
    extern mxArray *cgxe_N7dQiE8dzxoZ3zD5HN1j4_BuildInfoUpdate(void);
    plhs[0] = cgxe_N7dQiE8dzxoZ3zD5HN1j4_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Vcc8ISteIOqGP7Pz5Cs32B") == 0) {
    extern mxArray *cgxe_Vcc8ISteIOqGP7Pz5Cs32B_BuildInfoUpdate(void);
    plhs[0] = cgxe_Vcc8ISteIOqGP7Pz5Cs32B_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "vBzYk5rxBuuk3tHfKRBn4B") == 0) {
    extern mxArray *cgxe_vBzYk5rxBuuk3tHfKRBn4B_BuildInfoUpdate(void);
    plhs[0] = cgxe_vBzYk5rxBuuk3tHfKRBn4B_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "WqYNctr5az53WvPBtSKqtE") == 0) {
    extern mxArray *cgxe_WqYNctr5az53WvPBtSKqtE_BuildInfoUpdate(void);
    plhs[0] = cgxe_WqYNctr5az53WvPBtSKqtE_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "unN3reohie2VbRJ8Gdn4vD") == 0) {
    extern mxArray *cgxe_unN3reohie2VbRJ8Gdn4vD_BuildInfoUpdate(void);
    plhs[0] = cgxe_unN3reohie2VbRJ8Gdn4vD_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "Pe1gyJNSvQtAxyP0HVs3QE") == 0) {
    extern mxArray *cgxe_Pe1gyJNSvQtAxyP0HVs3QE_BuildInfoUpdate(void);
    plhs[0] = cgxe_Pe1gyJNSvQtAxyP0HVs3QE_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "TmhUzaTizl4mODx5ncv8iC") == 0) {
    extern mxArray *cgxe_TmhUzaTizl4mODx5ncv8iC_BuildInfoUpdate(void);
    plhs[0] = cgxe_TmhUzaTizl4mODx5ncv8iC_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "1G2T82xNlaygne7cNWxD7") == 0) {
    extern mxArray *cgxe_1G2T82xNlaygne7cNWxD7_BuildInfoUpdate(void);
    plhs[0] = cgxe_1G2T82xNlaygne7cNWxD7_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "QH2ipmi4AEsKLe0nOk4ysG") == 0) {
    extern mxArray *cgxe_QH2ipmi4AEsKLe0nOk4ysG_BuildInfoUpdate(void);
    plhs[0] = cgxe_QH2ipmi4AEsKLe0nOk4ysG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "yZHQAeALt4OuuN5DI39hDH") == 0) {
    extern mxArray *cgxe_yZHQAeALt4OuuN5DI39hDH_BuildInfoUpdate(void);
    plhs[0] = cgxe_yZHQAeALt4OuuN5DI39hDH_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

static int cgxe_get_fallback_info(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "q5pXm8srdYxK0T8n4wsZmB") == 0) {
    extern mxArray *cgxe_q5pXm8srdYxK0T8n4wsZmB_fallback_info(void);
    plhs[0] = cgxe_q5pXm8srdYxK0T8n4wsZmB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "N7dQiE8dzxoZ3zD5HN1j4") == 0) {
    extern mxArray *cgxe_N7dQiE8dzxoZ3zD5HN1j4_fallback_info(void);
    plhs[0] = cgxe_N7dQiE8dzxoZ3zD5HN1j4_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Vcc8ISteIOqGP7Pz5Cs32B") == 0) {
    extern mxArray *cgxe_Vcc8ISteIOqGP7Pz5Cs32B_fallback_info(void);
    plhs[0] = cgxe_Vcc8ISteIOqGP7Pz5Cs32B_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "vBzYk5rxBuuk3tHfKRBn4B") == 0) {
    extern mxArray *cgxe_vBzYk5rxBuuk3tHfKRBn4B_fallback_info(void);
    plhs[0] = cgxe_vBzYk5rxBuuk3tHfKRBn4B_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "WqYNctr5az53WvPBtSKqtE") == 0) {
    extern mxArray *cgxe_WqYNctr5az53WvPBtSKqtE_fallback_info(void);
    plhs[0] = cgxe_WqYNctr5az53WvPBtSKqtE_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "unN3reohie2VbRJ8Gdn4vD") == 0) {
    extern mxArray *cgxe_unN3reohie2VbRJ8Gdn4vD_fallback_info(void);
    plhs[0] = cgxe_unN3reohie2VbRJ8Gdn4vD_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "Pe1gyJNSvQtAxyP0HVs3QE") == 0) {
    extern mxArray *cgxe_Pe1gyJNSvQtAxyP0HVs3QE_fallback_info(void);
    plhs[0] = cgxe_Pe1gyJNSvQtAxyP0HVs3QE_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "TmhUzaTizl4mODx5ncv8iC") == 0) {
    extern mxArray *cgxe_TmhUzaTizl4mODx5ncv8iC_fallback_info(void);
    plhs[0] = cgxe_TmhUzaTizl4mODx5ncv8iC_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "1G2T82xNlaygne7cNWxD7") == 0) {
    extern mxArray *cgxe_1G2T82xNlaygne7cNWxD7_fallback_info(void);
    plhs[0] = cgxe_1G2T82xNlaygne7cNWxD7_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "QH2ipmi4AEsKLe0nOk4ysG") == 0) {
    extern mxArray *cgxe_QH2ipmi4AEsKLe0nOk4ysG_fallback_info(void);
    plhs[0] = cgxe_QH2ipmi4AEsKLe0nOk4ysG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "yZHQAeALt4OuuN5DI39hDH") == 0) {
    extern mxArray *cgxe_yZHQAeALt4OuuN5DI39hDH_fallback_info(void);
    plhs[0] = cgxe_yZHQAeALt4OuuN5DI39hDH_fallback_info();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_fallback_info") == 0) {
    return cgxe_get_fallback_info(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
