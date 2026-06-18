/*
* project   : https://github.com/Robin005cr/multi_threading
* file name : BoundedQueue.cpp
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
#include<iostream>
#include<thread>
#include<string>
#include<queue>
#include<condition_variable>
using namespace std;


template <typename T>
class BoundedQueue {
    std::queue<T> queue_;
    std::mutex mu_;
    std::condition_variable notEmpty_;
    std::condition_variable notFull_;
    size_t maxSize_;

public:
    explicit BoundedQueue(size_t maxSize) : maxSize_(maxSize) {}

    void push(T item) {
        std::unique_lock lock(mu_);
        notFull_.wait(lock, [this] { return queue_.size() < maxSize_; });
        queue_.push(std::move(item));
        notEmpty_.notify_one();
    }

    T pop() {
        std::unique_lock lock(mu_);
        notEmpty_.wait(lock, [this] { return !queue_.empty(); });
        T item = std::move(queue_.front());
        queue_.pop();
        notFull_.notify_one();
        return item;
    }
};

int main() {
    BoundedQueue<std::string> queue(5);

    // Producer thread
    std::thread producer([&queue] {
        for (int i = 0; i < 10; ++i) {
            queue.push("item-" + std::to_string(i));
            cout << "Produced: item-" << i << "\n";
        }
    });

    // Consumer thread
    std::thread consumer([&queue] {
        for (int i = 0; i < 10; ++i) {
            auto item = queue.pop();
            cout << "Consumed: " << item << "\n";
        }
    });

    producer.join();
    consumer.join();
}