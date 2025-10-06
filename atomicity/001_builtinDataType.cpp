/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : 001_builtinDataType.cpp
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
#include <atomic>
using namespace std;

// Atomics is possible with all basic built in datatypes (bool, int, float) except std::string.
int main()
{
    // atomic<int> a = 48; // Direct assignment will lead to error
    atomic<int> a {30};
    atomic_int a_ (56);
    
    atomic<bool> status (true);
    atomic_bool status_ {false};
    
    
    cout<<a<<" "<<a_<<endl;
    cout<<status<<" "<<status_<<endl;
   

    return 0;
}