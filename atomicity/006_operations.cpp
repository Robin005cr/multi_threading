/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : 006_operations.cpp
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
#include<atomic>
using namespace std;
int main()
{
    atomic<int> at_x {85};
    atomic<int> at_y {9};
    
    at_x++; // post increment
    ++at_x; // pre increment
    at_x+=1; // common increment
    at_x|=1; // bit set
    int y = at_x*2; // atomic read of at_x
    at_x = y+1; // atomic write of at_x
    
    at_x = at_x+1; // atomic read followed by atomic write
    
    
    //at_x*=2; atomic multiplication is not possible
   // at_x/ = 2; atomic division is not possible
    
    return 0;
} 