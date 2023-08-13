//
// Created by zippozeng on 2023/8/2.
//
#include "ffmpeg_player.hpp"
#include "logger.h"
#include "ff_read_thread.hpp"

extern "C" {
#include "libavutil/avutil.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
}

FFmpegPlayer::~FFmpegPlayer() {

}

void FFmpegPlayer::SetDataSource(const std::string &_path) {
    this->path = _path;
}

status_t FFmpegPlayer::Prepare() {
    LOGI("===== versions =====\n");
    LOGI("FFmpeg: %s", av_version_info())
    ShowVersionInt("libavutil", avutil_version());
    ShowVersionInt("libavcodec", avcodec_version());
    ShowVersionInt("libavformat", avformat_version());
    ShowVersionInt("libswscale", swscale_version());
    ShowVersionInt("libswresample", swresample_version());
    LOGI("===================\n");
    // 创建队列
    // 创建时钟
    // 创建read线程
    FFReadThread *readThread = new FFReadThread();
//    readThread->Start();

    // 创建音视频同步线程
    return 0;
}

status_t FFmpegPlayer::Start() {
//    AVFormatContext *formatContext = avformat_alloc_context();
//    if (formatContext == nullptr) {
//        return STATE_ERROR;
//    }
//    int ret = avformat_open_input(&formatContext, path.c_str(), nullptr, nullptr);
//    if (!ret) {
//        avformat_find_stream_info(formatContext, nullptr);
//    }
    int ret = 0;
    return ret;
}

status_t FFmpegPlayer::Pause() {
    return 0;
}

status_t FFmpegPlayer::Stop() {

    return 0;
}

status_t FFmpegPlayer::SeekTo(long duration, int mode) {
    return 0;
}

bool FFmpegPlayer::IsPlaying() {
    return false;
}

status_t FFmpegPlayer::GetVideoWidth(int *w) {
    return 0;
}

status_t FFmpegPlayer::GetVideoHeight(int *h) {
    return 0;
}

status_t FFmpegPlayer::GetCurrentPosition(int *msec) {
    return 0;
}

status_t FFmpegPlayer::GetDuration(int *msec) {
    return 0;
}

bool FFmpegPlayer::IsLooping() {
    return false;
}

status_t FFmpegPlayer::SetLooping(bool loop) {
    return 0;
}

void FFmpegPlayer::ShowVersionInt(char *_module, uint32_t version) {
    uint32_t major = (version >> 16) & 0xFF;
    uint32_t minor = (version >> 8) & 0xFF;
    uint32_t micro = version & 0xFF;
    LOGI("%-*s: %u.%u.%u\n", FFP_VERSION_MODULE_NAME_LENGTH, _module, major, minor, micro);
}
