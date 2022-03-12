//
// Created by 周天斌 on 2022/3/12.
//

#include <iostream>
using namespace std;

class A {
private:
    int a;
    int b;
public:
    A() {
        cout << "default construct" << endl;
        a = 1;
        b = 1;
    }
    A(int a, int b = 0): a(a), b(b) {
        cout << "two arguments constructor" << endl;
    }
    void show() const;
};

void A::show() const {
    cout << a << ", " << b << endl;
}

int main() {
    A a1;
    a1.show();
    A a2(9);
    a2.show();
    return 0;
}