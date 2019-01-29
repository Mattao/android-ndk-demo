//
// Created by matao on 2019/1/29.
//
#include "com_matao_ndk_MainActivity.h"
#include <stdio.h>

/*
 * Class:     com_matao_ndk_MainActivity
 * Method:    get
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_matao_ndk_MainActivity_get(JNIEnv *env, jobject thiz) {
    printf("invoke get in c++\n");
    return env->NewStringUTF("Hello from JNI in libjni-test.so !");
}

/*
 * Class:     com_matao_ndk_MainActivity
 * Method:    set
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_matao_ndk_MainActivity_set(JNIEnv *env, jobject thiz, jstring string){
    printf("invoke set in c++\n");
    char* str = (char*)env->GetStringUTFChars(string, NULL);
    printf("%s\n", str);
    env->ReleaseStringUTFChars(string, str);
}

