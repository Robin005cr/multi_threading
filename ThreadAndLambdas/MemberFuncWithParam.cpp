// Scenario: Passing the member function of a class to thread


#include <iostream>
#include <thread>
using namespace std;

class Vehicle
{
public:
    void display(string name)
    {
        cout << "Vehicle name : " << name << endl;
    }
};

int main()
{
    Vehicle v;


    // Using a lambda to call display() on object v
    thread threadname([&v]() {
        v.display("Bolero");
        });

    threadname.join(); // Wait for the thread to finish

    return 0;
}
