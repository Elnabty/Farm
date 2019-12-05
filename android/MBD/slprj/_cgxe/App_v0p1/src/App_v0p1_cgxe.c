/* Include files */

#include "App_v0p1_cgxe.h"
#include "m_unN3reohie2VbRJ8Gdn4vD.h"
#include "m_SwN96TPgYAdIgseV4TUFDC.h"

unsigned int cgxe_App_v0p1_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 1865285078 &&
      ssGetChecksum1(S) == 3736053294 &&
      ssGetChecksum2(S) == 489879641 &&
      ssGetChecksum3(S) == 609314347) {
    method_dispatcher_unN3reohie2VbRJ8Gdn4vD(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2240369359 &&
      ssGetChecksum1(S) == 1244492706 &&
      ssGetChecksum2(S) == 1970655317 &&
      ssGetChecksum3(S) == 3706173189) {
    method_dispatcher_SwN96TPgYAdIgseV4TUFDC(S, method, data);
    return 1;
  }

  return 0;
}
