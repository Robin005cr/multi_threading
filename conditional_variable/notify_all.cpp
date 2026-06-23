/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : notify_all.cpp
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
#include <vector>
#include <iostream>

std::mutex mtx;
std::condition_variable cv;
bool start = false;

void runner(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return start; });
    lock.unlock();
    std::cout << "Thread " << id << " running\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.emplace_back(runner, i);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    {
        std::lock_guard<std::mutex> lock(mtx);
        start = true;
    }
    cv.notify_all();   // release all 5 at once

    for (auto& t : threads) t.join();
}