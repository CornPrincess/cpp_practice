//
// Created by 周天斌 on 2022/3/12.
//
#include <iostream>

using namespace std;

class A {
private:
    int a;
public:
    A(int a) {
        this->a = a;
    }

    void show(int b);
    // error redeclared
    // void show(const int b);
    void display(int *num); // ok
    void display(const int *num); // ok
    void fun(A &a);
    void fun(const A &a);
    void happy(int * h);
    void hour(const int * h);
};

void A::show(int b) {
    cout << "show: " << b << endl;
}

void A::display(int *num) {
    cout << "display:" << *num << endl;
}

void A::display(const int *num) {
    cout << "const display:" << *num << endl;
}

void A::fun(A &obj) {
    cout << "fun: " << obj.a << endl;
}

void A::fun(const A &obj) {
    cout << "const fun: " << obj.a << endl;
}

void A::happy(int *h) {
    cout << "happy:" << *h << endl;
}

void A::hour(const int *h) {
    cout << "const hour:" << *h << endl;
}

int main() {
    A a(1);
    const A a2(11);
    int b1 = 2;
    const int b2 = 3;
    // test overload
    a.show(b1);
    a.show(b2);
    a.display(&b1);
    a.display(&b2);
    a.fun(a);
    a.fun(a2);
    // test const
    a.happy(&b1);
    // a.happy(&b2); // error cannot initialize a parameter of type 'int *' with an rvalue of type 'const int *'
    a.hour(&b1);
    a.hour(&b2);
    return 0;
}

