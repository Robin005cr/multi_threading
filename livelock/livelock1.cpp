/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : livelock1.cpp
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

mutex m1;
mutex m2;

void worker1()
{
    while (true)
    {
        lock_guard<mutex> lock1(m1);

        if (m2.try_lock())
        {
            cout << "Worker 1 acquired both locks.\n";
            m2.unlock();
            break;
        }

        cout << "Worker 1 backs off.\n";
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void worker2()
{
    while (true)
    {
        lock_guard<mutex> lock2(m2);

        if (m1.try_lock())
        {
            cout << "Worker 2 acquired both locks.\n";
            m1.unlock();
            break;
        }

        cout << "Worker 2 backs off.\n";
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int main()
{
    thread t1(worker1);
    thread t2(worker2);

    t1.join();
    t2.join();

    return 0;
}