/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : 009_load_n_store.cpp
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
std::atomic<int> x {0};
std::atomic<int> y {20};
int main() 
{
    int a = 89;
    x.store(a);
    
    cout<<"X : "<<x<<endl;
    
    cout << "Value of x: " << x.load() << std::endl;
    cout<<"X :"<<x<<endl;
    
    y.store(x);
     cout<<"y : "<<y<<endl;
    
    cout << "Value of y: " << y.load() << std::endl;
    cout<<"y :"<<y<<endl;

}