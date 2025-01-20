#include <iostream>
#include <thread>
using namespace std;
// Function to be executed by the thread
void myFunction()
{
    cout << "Thread executing... " << endl;

}

int main()
{
    cout << "Hello from main\n";
    // Create a thread and launch it
    thread Thread1(myFunction);

    // Wait for the thread to finish
    Thread1.join();

    return 0;
}
