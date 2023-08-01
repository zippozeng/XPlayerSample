//
// Created by zippozeng on 2023/7/15.
//

#ifndef XPLAYER_XPLAYER_HPP
#define XPLAYER_XPLAYER_HPP


#include <cstdint>
#include <string>
#include <android/native_window.h>
#include "IXPlayer.hpp"

class XPlayer : IXPlayer {
public:
    XPlayer();

private:
//    ~XPlayer() override;
    ~XPlayer();

public:
    void SetDataSource(const std::string &_path) override;

    status_t Prepare() override;

    status_t PrepareAsync() override;

    status_t Start() override;

    status_t Stop() override;

    status_t Pause() override;

    status_t SeekTo(long duration, int mode) override;

    bool IsPlaying() override;

    status_t GetVideoWidth(int *w) override;

    status_t GetVideoHeight(int *h) override;

    status_t GetCurrentPosition(int *msec) override;

    status_t GetDuration(int *msec) override;

    bool IsLooping() override;

    status_t SetLooping(bool loop) override;

private:
    std::string path;
    IXPlayer *m_player = nullptr;
};


#endif //XPLAYER_XPLAYER_HPP
