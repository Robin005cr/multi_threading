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
    Vehicle* ptr;

    Vehicle v;
    ptr = &v;

    // Using a lambda to call display() on object v
    thread threadname([ptr]() {
        ptr->display("Bolero");
        });

    threadname.join(); // Wait for the thread to finish

    return 0;
}
