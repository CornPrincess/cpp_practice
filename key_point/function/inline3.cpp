//
// Created by 周天斌 on 2022/2/9.
//

#include <iostream>
using namespace std;
class Base {
public:
    inline virtual void show() {
        cout << "I am Base.\n";
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    inline void show() {
        cout << "I am derived.\n";
    }
};

int main() {
    Base b;
    b.show();

    Base *pt = new Derived();
    pt->show();

    delete pt;
    pt = nullptr;

    return 0;
}