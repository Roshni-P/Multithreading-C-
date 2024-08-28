#pragma once
#include <condition_variable>
#include <mutex>

class Semaphore
{
public:Semaphore();
      ~Semaphore();
      Semaphore(const Semaphore& obj) {}
      void wait();
      void post();

private:
    unsigned int counter;
    std::mutex mt;
    std::condition_variable cv;
};
