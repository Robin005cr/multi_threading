/*
 * project   : https://github.com/Robin005cr/multi_threading
 * file name : std_mutex_try_lock_2.cpp
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

// Analysis of Behavior and Predicted Output
// 1. The use of try_lock() leads to a specific, non-deterministic behavior.
// 2. Race for the Lock: Both threads, t1 and t2, are in a "race" to acquire the mutex. In each of their 1000 loop iterations, they will try to lock it.
// 3. "Lost" Increments: When t1 successfully locks the mutex, t2's call to try_lock() at that same moment will fail. When it fails, t2 skips the increment and moves on. This means an opportunity to increment the counter is "lost" for t2. The same happens in reverse when t2 holds the lock.
// 4. Unpredictable Output: Because the operating system's thread scheduler determines which thread runs at any given microsecond, the number of times each thread successfully acquires the lock is unpredictable. The final result will depend entirely on this timing.
// 5. Therefore, the final value of counter will be:
// Almost certainly less than 2000. (2000 would only be possible if there were zero contention, meaning one thread finished its entire loop before the other one started, which is highly unlikely).
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
int counter = 0;
mutex myMutex;

void myFunction(int id)
{
    // Attempt to acquire the lock without blocking
    for (int i = 0; i < 1000; i++)
        if (myMutex.try_lock())
        {
            ++counter;
            myMutex.unlock();
        }
}

int main()
{
    thread t1(myFunction, 1);
    thread t2(myFunction, 2);

    t1.join();
    t2.join();
    cout << "Counter :" << counter;
    return 0;
}
