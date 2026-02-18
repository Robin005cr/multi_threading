/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : deadlock1.cpp
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
using namespace std;
// Two global mutexes that will be our shared resources
mutex mutex1;
mutex mutex2;

void worker_thread_1()
{
    cout << "Worker 1: Trying to lock mutex1..." << endl;
    mutex1.lock();
    cout << "Worker 1: Locked mutex1." << endl;
    // Introduce a small delay to make the deadlock more likely to occur
    // This gives Thread 2 a chance to lock mutex2 before Thread 1 proceeds
    this_thread::sleep_for(std::chrono::milliseconds(50));
    cout << "Worker 1: Trying to lock mutex2..." << endl;
    mutex2.lock(); // <-- DEADLOCK HAPPENS HERE
    cout << "Worker 1: Locked mutex2." << endl;
    // (Imagine some work is done here)
    mutex2.unlock();
    mutex1.unlock();
}
// This function is also designed to cause a deadlock
void worker_thread_2()
{
    cout << "Worker 2: Trying to lock mutex2..." << endl;
    mutex2.lock();
    cout << "Worker 2: Locked mutex2." << endl;
    this_thread::sleep_for(std::chrono::milliseconds(50));
    cout << "Worker 2: Trying to lock mutex1..." << endl;
    mutex1.lock(); // <-- DEADLOCK HAPPENS HERE
    cout << "Worker 2: Locked mutex1." << endl;
    // (Imagine some work is done here)
    mutex1.unlock();
    mutex2.unlock();
}
int main()
{
    cout << "Starting threads to demonstrate deadlock..." << endl;
    thread t1(worker_thread_1);
    thread t2(worker_thread_2);

    t1.join();
    t2.join();
    cout << "Finished. (This message will never be printed)" << endl;
    return 0;
}
