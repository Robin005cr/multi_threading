/*
* project   : https://github.com/Robin005cr/multi_threading
* @file     : passingMutex.cpp
* @author   : Robin CR
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
using namespace std;

mutex mtx;

void printMessage(const string &msg, mutex &m)
{
    lock_guard<mutex> lock(m);
    cout << msg << endl;
}

void printMessagePtr(const string &msg, mutex *m)
{
    lock_guard<mutex> lock(*m);
    cout << msg << endl;
}

int main()
{
    thread t1(printMessage, "Hello from Thread 1", ref(mtx));
    thread t2(printMessage, "Hello from Thread 2", ref(mtx));

    thread t3(printMessagePtr, "Hello from Thread 3", &mtx);
    thread t4(printMessagePtr, "Hello from Thread 4", &mtx);
    t1.join();
    t2.join();

    t3.join();
    t4.join();

    return 0;
}