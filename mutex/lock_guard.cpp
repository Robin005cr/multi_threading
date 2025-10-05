/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : lock_guard.cpp
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
using namespace std;

mutex m;
int myvariable = 0;
// Function to be executed by the thread
void Function()
{
    lock_guard<mutex> guard(m);

    for (int i = 0; i < 35; i++)
    {
        cout << myvariable << endl;
        ++myvariable;
    }
}

int main()
{

    // Create a thread and launch it
    thread Thread1(Function);
    thread Thread2(Function);

    // Wait for the thread to finish
    Thread1.join();
    Thread2.join();
    cout << "The value of myvariable after thread execution : " << myvariable;
    return 0;
}