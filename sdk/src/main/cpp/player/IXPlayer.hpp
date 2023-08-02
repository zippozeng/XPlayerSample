//
// Created by zippozeng on 2023/7/22.
//

#ifndef XPLAYER_IXPLAYER_HPP
#define XPLAYER_IXPLAYER_HPP

#include <cstdint>
#include <string>

typedef int32_t status_t;

enum xplayer_player_states {
    STATE_ERROR = 0,
    IDLE = 1 << 0,
    INITIALIZED = 1 << 1,
    PREPARING = 1 << 2,
    PREPARED = 1 << 3,
    STARTED = 1 << 4,
    PAUSED = 1 << 5,
    STOPPED = 1 << 6,
    COMPLETE = 1 << 7
};

class IXPlayer {
public:

//    virtual ~IXPlayer() = 0;

    virtual void SetDataSource(const std::string &_path) = 0;

    virtual status_t Prepare() = 0;

    virtual status_t Start() = 0;

    virtual status_t Stop() = 0;

    virtual status_t Pause() = 0;

    virtual status_t SeekTo(long duration, int mode) = 0;

    virtual bool IsPlaying() = 0;

    virtual status_t GetVideoWidth(int *w) = 0;

    virtual status_t GetVideoHeight(int *h) = 0;

    virtual status_t GetCurrentPosition(int *msec) = 0;

    virtual status_t GetDuration(int *msec) = 0;

    virtual bool IsLooping() = 0;

    virtual status_t SetLooping(bool loop) = 0;
};

#endif //XPLAYER_IXPLAYER_HPP

