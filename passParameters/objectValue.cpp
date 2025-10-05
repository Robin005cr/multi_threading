/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : objectValue.cpp
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

class Worker {
public:
    void operator()() {
        cout << "Worker running in thread!" << endl;
        myFunction();
        otherFunction();
    }

    void myFunction() {
        cout << "Executing myFunction" << endl;
    }
    void otherFunction() {
        cout << "Executing otherFunction" << endl;
    }
};

int main() {
    Worker w;  
    thread t(w);  // pass object by value (functor is copied)
    t.join();
    return 0;
}
