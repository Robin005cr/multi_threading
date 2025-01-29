//Scenario: Here we are having a function with parameters if we want to pass the parameters to 
// the thread we need to use lambda function

#include <iostream>
#include <thread>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Create a variable to store the result of the add function
    int result = 0;

    // Create a thread and pass the reference to the result variable to capture the return value
    thread threadname([&result]() {
        result = add(2, 3);
        });


    threadname.join();

    cout << "The result of addition is: " << result << endl;

    return 0;
}
