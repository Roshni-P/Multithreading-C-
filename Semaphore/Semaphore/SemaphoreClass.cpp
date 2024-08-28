#include "SemaphoreClass.h"
#include <condition_variable>
#include <mutex>
#include <iostream>

using namespace std;

Semaphore::Semaphore() :counter(0)
{
}

Semaphore::~Semaphore()
{
}

void Semaphore::wait()
{
    std::unique_lock<mutex> lock(mt);
    if (counter == 0)
    {
        cout << "Inside wait, waiting..." << endl;
        cv.wait(lock);
    }
    counter--;
    cout << "Decremented counter - " << counter << endl;
}

void Semaphore::post()
{
    std::unique_lock<mutex> lock(mt);
    cout << "Inside post" << endl;
    counter++;
    cout << "Incremented counter - " << counter << endl;

    cv.notify_one();
}
