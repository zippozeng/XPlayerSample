#include <jni.h>
#include <string>

extern "C" {
#include <libavutil/avutil.h>
}
#include <logger.h>


extern "C" JNIEXPORT jstring JNICALL
Java_com_github_zippozeng_xplayer_sample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    const char *version = av_version_info();
    std::string hello(version);
    return env->NewStringUTF(hello.c_str());
}