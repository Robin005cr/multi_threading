/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : 002_builtinDataTypePtr.cpp
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
#include <atomic>
#include <iostream>
using namespace std;

int main() {

int value1 = 10;
int value2 = 20;

std::atomic<int*> atomicPtr{&value1};
    cout<<(*atomicPtr);

}
