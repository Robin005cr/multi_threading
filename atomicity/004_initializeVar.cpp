/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : 004_initializeVar.cpp
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
    atomic<int> DemVar = {9};
    atomic<bool> status{true};
    atomic<float> temperature(89.9);

    return 0;
}