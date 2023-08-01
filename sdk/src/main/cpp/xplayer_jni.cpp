//
// Created by zippozeng on 2023/8/1.
//
#pragma once

#include <jni.h>
#include <string>
#include <logger.h>
#include "player/xplayer.hpp"

extern "C" {
#include <libavutil/avutil.h>
}

jlong nativeSetup([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz) {
    auto *player = new XPlayer();
    return reinterpret_cast<jlong>(player);
}

void
setDataSource(JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context, jstring _path) {
    if (_native_context == 0) {
        LOGE("native context is null")
        return;
    }
    const char *str = reinterpret_cast<const char *>(env->GetStringUTFChars(_path, nullptr));
    std::string path(str);
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    player->SetDataSource(path);
}

void prepare([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        player->Prepare();
    }
}

void start([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        player->Start();
    }
}

void pause([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        player->Pause();
    }
}

void stop([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        player->Stop();
    }
}

void seekTo([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context,
            jlong _duration, jint _mode) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        player->SeekTo(_duration, _mode);
    }
}

jboolean
isLooping([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        return player->IsLooping();
    }
    return false;
}

void setLooping([[maybe_unused]] JNIEnv *env, [[maybe_unused]] jobject thiz, jlong _native_context,
                jboolean _looping) {
    auto player = reinterpret_cast<XPlayer *>(_native_context);
    if (player != nullptr) {
        player->SetLooping(_looping);
    }
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
        {"_prepare",       "(J)V",                   (void *) prepare},
        {"_start",         "(J)V",                   (void *) start},
        {"_pause",         "(J)V",                   (void *) pause},
        {"_stop",          "(J)V",                   (void *) stop},
        {"_seekTo",        "(JJI)V",                 (void *) seekTo},
        {"_isLooping",     "(J)Z",                   (void *) isLooping},
        {"_setLooping",    "(JZ)V",                  (void *) setLooping},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, [[maybe_unused]] void *reserved) {
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