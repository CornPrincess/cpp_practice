//
// Created by 周天斌 on 2022/4/6.
//

#include <iostream>

using namespace std;

class B {};
class C {
public:
    virtual ~C(){}
};
class D {
public:
    D() {}
};
int main() {
    B b;
    C c;
    D d;
    cout << sizeof b << endl;
    cout << sizeof c << endl;
    cout << sizeof d << endl;
    return 0;
}