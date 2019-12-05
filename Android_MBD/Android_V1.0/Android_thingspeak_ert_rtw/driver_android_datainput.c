/*
 * driver_android_datainput.c
 *
 * Driver code
 *
 * Copyright 2017 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <android/log.h>
#include "driver_android_datainput.h"

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;

void initDataInput(int id, void* data, int size, int dataType)
{
    JNIEnv *pEnv;
    jmethodID initDataInputID;
    jbyteArray charVector;
    double value;
    
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    if( dataType == 0)
        initDataInputID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "initDataInput","(I[B)V");
    else
        initDataInputID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "initDataInput","(IDI)V");
    
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_datainput",
                "Exception: on getting method id for setDataInputValue.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
    
    /* Initialize datainput value */
    if (initDataInputID != NULL)
    {
        if( dataType == 0) {
            charVector = (*pEnv)->NewByteArray(pEnv, size);
            (*pEnv)->SetByteArrayRegion(pEnv, charVector, 0, size, data);
            (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, initDataInputID, id, charVector);
            (*pEnv)->DeleteLocalRef(pEnv, charVector);
        } else {
            value = *((double *)data);
            (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, initDataInputID, id, value, dataType);
        }
        
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_datainput",
                    "Exception: on calling void method setDataInputValue.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }
    }
}

void getDataInputValue(int id, void *data, int isCharVector, int maxSize)
{
    JNIEnv *pEnv;
    jmethodID getDataInputValueID;
    jdouble value;
    jarray ret;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    if( isCharVector == 0) {
        getDataInputValueID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "getDataInputValue","(I)D");
    } else {
        getDataInputValueID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "getDataInputValue","(II)[B");
    }
    
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_datainput",
                "Exception: on getting method id for getDataInputValue.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
    }
    
    /* Read current datainput value */
    if (getDataInputValueID != NULL)
    {
        if( isCharVector == 0) {
            value = (jdouble)(*pEnv)->CallDoubleMethod(pEnv, cachedActivityObj, getDataInputValueID,id);
            memcpy(data, &value, sizeof(double));
        } else {
            ret = (*pEnv)->CallObjectMethod(pEnv, cachedActivityObj, getDataInputValueID,id,maxSize);
            int length = (*pEnv)->GetArrayLength(pEnv, ret);
            (*pEnv)->GetByteArrayRegion(pEnv, ret, 0, length, (jbyte*)data);
            (*pEnv)->DeleteLocalRef(pEnv, ret);
        }
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_datainput",
                    "Exception: on calling void method getDataInputValue.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }
    }
}

void terminateDataInput()
{
}