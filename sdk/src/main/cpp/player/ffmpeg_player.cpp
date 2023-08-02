//
// Created by zippozeng on 2023/8/2.
//

#include "ffmpeg_player.hpp"

extern "C" {
#include <libavutil/avutil.h>
#include <libavformat/avformat.h>
}

FFmpegPlayer::~FFmpegPlayer() {

}

void FFmpegPlayer::SetDataSource(const std::string &_path) {
    this->path = _path;
}

status_t FFmpegPlayer::Prepare() {
    return 0;
}

status_t FFmpegPlayer::Start() {
    AVFormatContext *formatContext = avformat_alloc_context();
    if (formatContext == nullptr) {
        return STATE_ERROR;
    }
    int ret = avformat_open_input(&formatContext, path.c_str(), nullptr, nullptr);
    if (!ret) {
        avformat_find_stream_info(formatContext, nullptr);
    }
    return ret;
}

status_t FFmpegPlayer::Stop() {

    return 0;
}

status_t FFmpegPlayer::Pause() {
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