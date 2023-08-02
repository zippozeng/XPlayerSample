//
// Created by zippozeng on 2023/8/2.
//

#ifndef XPLAYERSAMPLE_FFMPEG_PLAYER_HPP
#define XPLAYERSAMPLE_FFMPEG_PLAYER_HPP

#include "IXPlayer.hpp"

class FFmpegPlayer : public IXPlayer {
public:

    ~FFmpegPlayer();

    void SetDataSource(const std::string &_path) override;

    status_t Prepare() override;

    status_t Start() override;

    status_t Stop() override;

    status_t Pause() override;

    bool IsPlaying() override;

    status_t GetVideoWidth(int *w) override;

    status_t GetVideoHeight(int *h) override;

    status_t GetCurrentPosition(int *msec) override;

    status_t GetDuration(int *msec) override;

    bool IsLooping() override;

    status_t SetLooping(bool loop) override;

private:
    std::string path;
};


#endif //XPLAYERSAMPLE_FFMPEG_PLAYER_HPP
