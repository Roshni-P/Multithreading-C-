// Semaphore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include "SemaphoreClass.h"

using namespace std;


void fnRead(Semaphore& sem)
{
    for (int i = 0; i < 3; i++)
    {
    cout << "Inside Read function" << endl;
    sem.wait();
    }
}
void fnWrite(Semaphore &sem)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Inside Write function" << endl;
        sem.post();
    }
}

int main()
{
    Semaphore sem;
    std::thread tRead(fnRead,std::ref(sem));
    thread tWrite(fnWrite,std::ref(sem));

    tRead.join();
    tWrite.join();
}
