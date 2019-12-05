LOCAL_PATH := ..
include $(CLEAR_VARS)
LOCAL_MODULE := Android_thingspeak
LOCAL_CFLAGS += -DMODEL=Android_thingspeak -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DPORTABLE_WORDSIZES 
LOCAL_SRC_FILES := ert_main.c Android_thingspeak.c androidinitialize.c driver_android_button.c driver_android_datadisplay.c driver_android_thingspeak_write.c driver_android_datainput.c driver_android_thingspeak_read.c 
LOCAL_C_INCLUDES += E:/farm/ANDROI~1/ANDROI~1.0 C:/PROGRA~3/MATLAB/SUPPOR~1/R2018b/toolbox/target/SUPPOR~1/android/include E:/farm/ANDROI~1/ANDROI~1.0/ANDROI~1 C:/PROGRA~1/MATLAB/R2018b/extern/include C:/PROGRA~1/MATLAB/R2018b/simulink/include C:/PROGRA~1/MATLAB/R2018b/rtw/c/src C:/PROGRA~1/MATLAB/R2018b/rtw/c/src/ext_mode/common C:/PROGRA~1/MATLAB/R2018b/rtw/c/ert 
LOCAL_LDLIBS  +=  -llog -ldl
include $(BUILD_SHARED_LIBRARY)
