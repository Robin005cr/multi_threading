#include <iostream>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono;

int main()
{

    int seconds = 5; // Change this value to adjust the duration of sleep

    cout << "Sleeping for " << seconds << " seconds..." << endl;

    // Sleep for the specified number of seconds
    this_thread::sleep_for(chrono::seconds(seconds));

    cout << "Awake after sleeping for " << seconds << " seconds!" << endl;

    return 0;
}
