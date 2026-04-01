/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : 0010_atomic_flag.cpp
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
int main()
{
    atomic_flag flag = ATOMIC_FLAG_INIT;
    // atomic_flag flag1 = true;  // assigining will result error
    cout << "first :" << flag.test_and_set() << endl;
    cout << "second :" << flag.test_and_set() << endl;
    cout << "third :" << flag.test_and_set() << endl;
    flag.clear();
    cout << "fourth :" << flag.test_and_set() << endl;

    return 0;
}