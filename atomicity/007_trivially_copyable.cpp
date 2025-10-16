#include <iostream>
#include <type_traits>
using namespace std;

struct A {
    int x;
    float y;
};  // ✅ trivially copyable

struct B {
    int x;
    B() {}  // ❌ user-defined constructor
};

struct C {
    int* p;
    ~C() {} // ❌ non-trivial destructor
};

int main() {
    cout << boolalpha; // print true/false instead of 1/0
    cout << "A: " << is_trivially_copyable<A>::value << endl;
    cout << "B: " << is_trivially_copyable<B>::value << endl;
    cout << "C: " << is_trivially_copyable<C>::value << endl;
}
