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