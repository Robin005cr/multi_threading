/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : conditional_variable.cpp
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
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

bool ready = false;

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);

    // Wait until ready becomes true
    cv.wait(lock, [] { return ready; });

    std::cout << "Consumer: Data is ready!\n";
}

void producer() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }

    std::cout << "Producer: Data prepared.\n";

    cv.notify_one();
}

int main() {
    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}