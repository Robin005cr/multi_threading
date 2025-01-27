#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;
int myvariable = 0;
// Function to be executed by the thread
void Function()
{
    m.lock();
    ++myvariable;
    m.unlock();
}

int main()
{
    cout << "Hello from main\n";

    // Create a thread and launch it
    thread Thread1(Function);
    thread Thread2(Function);

    // Wait for the thread to finish
    Thread1.join();
    Thread2.join();
    cout << "The value of myvariable after thread execution:" << myvariable;
    return 0;
}
