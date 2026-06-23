/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : wait_all_wait_untill.cpp
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
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool dataReady = false;

void waitWithTimeout() {
    std::unique_lock<std::mutex> lock(mtx);
    bool success = cv.wait_for(lock, std::chrono::seconds(2),
                                [] { return dataReady; });
    if (success)
        std::cout << "Data arrived in time\n";
    else
        std::cout << "Timed out waiting for data\n";
}

int main() {
    std::thread t(waitWithTimeout);
    // Simulate a producer that's too slow (sleeps 3s, timeout is 2s)
    std::this_thread::sleep_for(std::chrono::seconds(3));
    {
        std::lock_guard<std::mutex> lock(mtx);
        dataReady = true;
    }
    cv.notify_one();
    t.join();
}