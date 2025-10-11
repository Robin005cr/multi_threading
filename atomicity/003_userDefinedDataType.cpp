/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : 003_userDefinedDataType.cpp
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

class Sample
{
    public:
    int myVar;
    int *ptr;
    
    void func()
    {
        cout<<"Function invoked"<<endl;
    }
    
};

struct Demo
{
    int myVar;
    int *ptr;
    
    void func()
    {
        cout<<"Function invoked"<<endl;
    }
};
int main()
{
    atomic<Demo> DemVar;
    atomic<Sample> SamObj;
    
    // DemVar.myVar  {78}; this will lead to error

    return 0;
}