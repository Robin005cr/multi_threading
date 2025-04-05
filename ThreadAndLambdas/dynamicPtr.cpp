/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : dynamicPtr.cpp
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

class Vehicle
{
public:
    void display(string name)
    {
        cout << "Vehicle name : " << name << endl;
    }
};

int main()
{
    Vehicle* ptr = new Vehicle();


    // Using a lambda to call display() on object v
    thread threadname([ptr]() {
        ptr->display("Bolero");
        });

    threadname.join(); // Wait for the thread to finish

    delete ptr;
    return 0;
}
