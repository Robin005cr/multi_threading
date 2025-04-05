/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : try_lock.cpp
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
#include <mutex>
#include <thread>
using namespace std;

mutex myMutex;

void myFunction(int id)
{
    // Attempt to acquire the lock without blocking
    if (myMutex.try_lock())
    {
        cout << "Thread " << id << " acquired the lock.\n";

        // Do some work that requires the lock

        // Release the lock
        myMutex.unlock();
    }
    else
    {
        cout << "Thread " << id << " couldn't acquire the lock.\n";

        // Perform an alternative action if the lock is not available
    }
}

int main()
{
    thread t1(myFunction, 1);
    thread t2(myFunction, 2);

    t1.join();
    t2.join();

    return 0;
}
