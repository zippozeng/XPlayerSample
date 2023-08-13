//
// Created by zippozeng on 2023/8/13.
//

#ifndef XPLAYERSAMPLE_FF_READ_THREAD_HPP
#define XPLAYERSAMPLE_FF_READ_THREAD_HPP

#include <thread/thread.hpp>

class FFReadThread : Thread {
public:

    FFReadThread();

    ~FFReadThread();

    virtual void Run() override;

private:

};


#endif //XPLAYERSAMPLE_FF_READ_THREAD_HPP
