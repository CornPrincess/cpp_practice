//
// Created by 周天斌 on 2022/4/6.
//

#include <iostream>

using namespace std;

class Base {
private:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};

class Derive: public Base {
    void f() { cout << "Derive::f" << endl; }
};

int main() {
    typedef void(*Fun)(void);
    Base b;
    cout << "虚函数表地址: " << (long long*)&b << endl;
    cout << "虚函数表第一个函数地址" << (long long*)*(long long*)(&b) << endl;

    Fun p1 = (Fun)*((long long*)*(long long*)(&b)+0);  // Base::f()
    Fun p2 = (Fun)*((long long*)*(long long*)(&b)+1);  // Base::g()
    Fun p3 = (Fun)*((long long*)*(long long*)(&b)+2);  // Base::h()
    p1();
    p2();
    p3();

    Derive d;
    Fun p4 = (Fun)*(((long long*)*(long long*)(&d) + 0));
    p4();
    Fun p5 = (Fun)*((long long*)((long long*)(&d))[0]);
    p5();
    return 0;
}