//
// Created by zippozeng on 2023/7/16.
//

#ifndef XPLAYER_THREAD_HPP
#define XPLAYER_THREAD_HPP

#include <thread>


class Thread {

public:

    Thread(const std::string &_name);

    ~Thread();

    std::thread::id GetId();

    bool IsInterrupt();

    void Interrupt();

    void Join();

    void Start();

    virtual void Run() = 0;

private:
    std::atomic<bool> started = false;
    std::atomic<bool> isInterrupted = false;
    std::string name;
    std::thread thread;
};


#endif //XPLAYER_THREAD_HPP
