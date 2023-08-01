//
// Created by zippozeng on 2023/8/1.
//
#pragma once

#include <jni.h>
#include <string>
#include <logger.h>

extern "C" {
#include <libavutil/avutil.h>
}

long nativeSetup(JNIEnv *env, jobject thiz) {
    return 0;
}

void setDataSource(JNIEnv *env, jobject thiz, jlong _native_context, jstring _path) {
    if (_native_context == 0) {
        LOGE("native context is null")
        return;
    }
}

void preapre(JNIEnv *env, jobject thiz, jlong _native_context) {
}

void start(JNIEnv *env, jobject thiz, jlong _native_context) {
}

void pause(JNIEnv *env, jobject thiz, jlong _native_context) {
}

void stop(JNIEnv *env, jobject thiz, jlong _native_context) {
}

void seekTo(JNIEnv *env, jobject thiz, jlong _native_context, jlong _duration, jint _mode) {
}

jboolean isLooping(JNIEnv *env, jobject thiz, jlong _native_context) {
}

void setLooping(JNIEnv *env, jobject thiz, jlong _native_context, jboolean _looping) {
}

void printFFmpegVersion() {
    const char *version = av_version_info();
    auto version_int = (int32_t) avutil_version();
    const char *configuration = avutil_configuration();
    int a = version_int / (int) pow(2, 16);
    int b = (int) (version_int - a * pow(2, 16)) / (int) pow(2, 8);
    int c = version_int % (int) pow(2, 8);
    LOGI("version info:%s", version)
    LOGI("version:%d.%d.%d", a, b, c)
    LOGI("configuration:%s", configuration)
}

static JNINativeMethod nativeMethods[] = {
        {"native_setup",   "()J",                    (void *) nativeSetup},
        {"_setDataSource", "(JLjava/lang/String;)V", (void *) setDataSource},
        {"_prepare",       "(J)V",                   (void *) preapre},
        {"_start",         "(J)V",                   (void *) start},
        {"_pause",         "(J)V",                   (void *) pause},
        {"_stop",          "(J)V",                   (void *) stop},
        {"_seekTo",        "(JJI)V",                 (void *) seekTo},
        {"_isLooping",     "(J)Z",                   (void *) isLooping},
        {"_setLooping",    "(JZ)V",                  (void *) setLooping},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    jclass clazz = env->FindClass("com/github/zippozeng/xplayer/sdk/XPlayer");
    if (clazz == nullptr) {
        return JNI_ERR;
    }

    if (env->RegisterNatives(clazz, nativeMethods,
                             sizeof(nativeMethods) / sizeof(JNINativeMethod)) < 0) {
        return JNI_ERR;
    }
    printFFmpegVersion();
    return JNI_VERSION_1_6;
}