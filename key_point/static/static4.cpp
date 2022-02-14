#include <iostream>

using namespace std;

class A {
public:
    int x;

    A() { cout << "A's constructor called " << endl; }
};

class B {
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }

    static A getA() { return a; }
};

A B::a; // definition of a
int main() {
    B b1, b2, b3;
    A a = b1.getA();
    cout << a.x << endl; // 0
    return 0;
}
