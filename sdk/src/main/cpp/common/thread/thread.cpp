//
// Created by zippozeng on 2023/7/16.
//

#include "thread.hpp"
#include <logger.h>
#include <pthread.h>

Thread::Thread(const std::string &_name) {
    this->name = _name;
}

Thread::~Thread() {
    if (!this->IsInterrupt()) {
        this->IsInterrupt();
    }
    if (this->thread.joinable()) {
        Join();
    }
}

std::thread::id Thread::GetId() {
    return thread.get_id();
}

bool Thread::IsInterrupt() {
    return this->isInterrupted;
}

void Thread::Interrupt() {
    this->isInterrupted = true;
}

void Thread::Join() {
    thread.join();
}

void Thread::Start() {
    if (started) {
        LOGE("IllegalThreadStateException")
        return;
    }
    std::thread thr([this] {
        pthread_setname_np(pthread_self(), name.c_str());
        Run();
    });
    started = true;
    this->thread = std::move(thr);
}