//
// Created by zippozeng on 2023/7/15.
//

#include "xplayer.hpp"
#include <logger.h>

XPlayer::XPlayer() {
//    m_player = new FFmpegPlayer(m_controller);
}

XPlayer::~XPlayer() {
    if (m_player != nullptr) {
        delete m_player;
        m_player = nullptr;
    }
}

void XPlayer::SetDataSource(const std::string &_path) {
    if (m_player != nullptr) {
        m_player->SetDataSource(_path);
    }
}

status_t XPlayer::Prepare() {
    if (m_player != nullptr) {
        m_player->Prepare();
    }
    return 0;
}

status_t XPlayer::PrepareAsync() {
    if (m_player != nullptr) {
        m_player->PrepareAsync();
    }
    return 0;
}

status_t XPlayer::Start() {
    if (m_player != nullptr) {
        m_player->Start();
    }
    return 0;
}

status_t XPlayer::Stop() {
    if (m_player != nullptr) {
        m_player->Stop();
    }
    return 0;
}

status_t XPlayer::Pause() {
    if (m_player != nullptr) {
        m_player->Pause();
    }
    return 0;
}

bool XPlayer::IsPlaying() {
    if (m_player != nullptr) {
        m_player->IsPlaying();
    }
    return false;
}

status_t XPlayer::GetVideoWidth(int *w) {
    if (m_player != nullptr) {
        m_player->GetVideoWidth(w);
    }
    return 0;
}

status_t XPlayer::GetVideoHeight(int *h) {
    if (m_player != nullptr) {
        m_player->GetVideoHeight(h);
    }
    return 0;
}

status_t XPlayer::GetCurrentPosition(int *msec) {
    if (m_player != nullptr) {
        m_player->GetCurrentPosition(msec);
    }
    return 0;
}

status_t XPlayer::GetDuration(int *msec) {
    if (m_player != nullptr) {
        m_player->GetDuration(msec);
    }
    return 0;
}

bool XPlayer::IsLooping() {
    if (m_player != nullptr) {
        return m_player->IsLooping();
    }
    return false;
}

status_t XPlayer::SetLooping(bool loop) {
    if (m_player != nullptr) {
        return m_player->SetLooping(loop);
    }
    return 0;
}

status_t XPlayer::SeekTo(long duration, int mode) {
    if (m_player != nullptr) {
        return m_player->SeekTo(duration, mode);
    }
    return 0;
}