/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : deadlock.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
// Two global mutexes that will be our shared resources
std::mutex mutex1;
std::mutex mutex2;
// This function is designed to cause a deadlock
void worker_thread_1()
{
    std::cout << "Worker 1: Trying to lock mutex1..." << std::endl;
    mutex1.lock();
    std::cout << "Worker 1: Locked mutex1." << std::endl;
    // Introduce a small delay to make the deadlock more likely to occur
    // This gives Thread 2 a chance to lock mutex2 before Thread 1 proceeds
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Worker 1: Trying to lock mutex2..." << std::endl;
    mutex2.lock(); // <-- DEADLOCK HAPPENS HERE
    std::cout << "Worker 1: Locked mutex2." << std::endl;
    // (Imagine some work is done here)
    mutex2.unlock();
    mutex1.unlock();
}
// This function is also designed to cause a deadlock
void worker_thread_2()
{
    std::cout << "Worker 2: Trying to lock mutex2..." << std::endl;
    mutex2.lock();
    std::cout << "Worker 2: Locked mutex2." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Worker 2: Trying to lock mutex1..." << std::endl;
    mutex1.lock(); // <-- DEADLOCK HAPPENS HERE
    std::cout << "Worker 2: Locked mutex1." << std::endl;
    // (Imagine some work is done here)
    mutex1.unlock();
    mutex2.unlock();
}
int main()
{
    std::cout << "Starting threads to demonstrate deadlock..." << std::endl;
    std::thread t1(worker_thread_1);
    std::thread t2(worker_thread_2);
    // Wait for the threads to finish
    t1.join();
    t2.join();
    std::cout << "Finished. (This message will never be printed)" << std::endl;
    return 0;
}
