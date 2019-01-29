//
// Created by matao on 2019/1/29.
//
#include "com_matao_ndk_MainActivity.h"
#include "android_log_print.h"
#include <stdio.h>

void callJavaMethod(JNIEnv *env, jobject thiz) {
    jclass clazz = env->FindClass("com/matao/ndk/MainActivity");
    if(clazz == NULL) {
        LOGD("find class MainActivity error!");
        return;
    }
    jmethodID id = env->GetStaticMethodID(clazz, "methodCalledByJni", "(Ljava/lang/String;)V");
    if(id == NULL) {
        LOGD("find method methodCalledByJni error!");
    }
    jstring msg = env-> NewStringUTF("msg send by callJavaMethod in test.cpp");
    env->CallStaticVoidMethod(clazz, id, msg);
}

/*
 * Class:     com_matao_ndk_MainActivity
 * Method:    get
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_matao_ndk_MainActivity_get(JNIEnv *env, jobject thiz) {
    LOGD("invoke get in c++\n");
    callJavaMethod(env, thiz);
    return env->NewStringUTF("Hello from JNI in libjni-test.so !");
}

/*
 * Class:     com_matao_ndk_MainActivity
 * Method:    set
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_matao_ndk_MainActivity_set(JNIEnv *env, jobject thiz, jstring string){
    LOGD("invoke set in c++\n");
    char* str = (char*)env->GetStringUTFChars(string, NULL);
    LOGD("%s\n", str);
    env->ReleaseStringUTFChars(string, str);
}
