/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : promiseFuture.cpp
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
#include <future>
using namespace std;
void functionExtend(promise<int> promise, int x) {
    unsigned long long int var = 0;
    for(var = 0;var<567888888;var++)
    {
        if(var>567888880)
        {
            cout<<"Taking time"<<endl;
        }
        
    }
    
    promise.set_value(var);  // Set the result
}

int main() {
    std::promise<int> promiseTag;               // Create promise
    std::future<int> futureTag = promiseTag.get_future();  // Get future from promise

    int number = 10;

    
    std::thread Thread1(functionExtend, std::move(promiseTag), number);

    cout << "Waiting for result...\n";
    int result = futureTag.get();  
    cout << "Square of " << number << " is " << result << endl;

    Thread1.join();
    return 0;
}
