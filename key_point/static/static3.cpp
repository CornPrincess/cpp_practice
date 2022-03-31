//
// Created by 周天斌 on 2022/2/14.
//

#include <iostream>

using namespace std;

class A {
public:
    int x;
    A() {
        cout << "A constructed" << endl;
    }
};

class B {
    static A a;
public:
    B() {
        cout << "B constructed" << endl;
    }
    static A getA() {return a;}
};

class C {
    // static int c = 0; // Error non-const static data member must be initialized out of line
    static int c;
public:
    C() {
        cout << "C constructed" << endl;
    }
    static int getC() {return c;};
};

int main() {
    B b;
    // A a = b.getA(); // Error Compiler Error: undefined reference to `B::a'
    static int n;
    cout << n << endl; // ok 0
    C c;
    // int cc = c.getC(); // Error Compiler Error: undefined reference to `C::c'
    return 0;
}