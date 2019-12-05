#undef F_CPU
#define __AVR_ATmega16__
#if   defined(__AVR_ATmega16__) 
#include "configAtmega16.h"


#elif defined(__AVR_ATmega128__) 
#include "configAtmega128.h"
#else 
#error cpu not specified 
#endif 

