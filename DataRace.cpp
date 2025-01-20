#include <iostream>
#include <thread>
using namespace std;
// Function to be executed by the thread
void Function()
{
    for (int i = 20; i > 0; i--)
        cout << i << "\n";

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

    return 0;
}
