/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : sleep.cpp
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
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono;

int main()
{

    int seconds = 5; // Change this value to adjust the duration of sleep

    cout << "Sleeping for " << seconds << " seconds..." << endl;

    // Sleep for the specified number of seconds
    this_thread::sleep_for(chrono::seconds(seconds));

    cout << "Awake after sleeping for " << seconds << " seconds!" << endl;

    return 0;
}
