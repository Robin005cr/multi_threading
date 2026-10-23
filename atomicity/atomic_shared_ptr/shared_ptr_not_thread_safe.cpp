/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : shared_ptr_not_thread_safe.cpp
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
#include <atomic>
#include <iostream>
#include <memory>
#include <thread>
using namespace std;

atomic<int> constructed{0};
atomic<int> destroyed{0};

class Animal
{
public:
    Animal()  { ++constructed; }   // counters instead of cout, so output isn't flooded
    ~Animal() { ++destroyed; }
};

shared_ptr<Animal> shPtr1 = make_shared<Animal>();   // shared by both threads

int main()
{
    thread writer([] {
        for (int i = 0; i < 1'000'000; ++i)
            shPtr1 = make_shared<Animal>();          // modifies shPtr1 (drops old Animal)
    });

    thread reader([] {
        for (int i = 0; i < 1'000'000; ++i) {
            shared_ptr<Animal> shPtr2 = shPtr1;      // copies shPtr1 while it may be changing
            (void)shPtr2.get();
        }
    });

    writer.join();
    reader.join();

    shPtr1.reset();
    cout << "constructed: " << constructed << "\n";
    cout << "destroyed:   " << destroyed   << "\n";
    cout << (constructed == destroyed ? "balanced (got lucky)" : "MISMATCH: leak or double destroy") << "\n";
}