/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : CreateThreadFunctionPointer.cpp
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
using namespace std;
// Function to be executed by the thread
void myFunction()
{
    cout << "Thread executing... " << endl;

}

int main()
{
    cout << "Hello from main\n";
    // Create a thread and launch it
    thread Thread1(myFunction);

    // Wait for the thread to finish
    Thread1.join();

    return 0;
}
