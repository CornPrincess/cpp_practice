//
// Created by 周天斌 on 2022/2/14.
//

#include <iostream>

using namespace std;
class A {
    int x;
public:
    void show() {
        cout << this << endl;
    }
};

class B {};
class C {
    char c;
};

int main() {
    A *a1 = new A();
    A *a2 = new A();
    a1->show();
    cout << a1 << endl;
    a2->show();
    cout << a2 << endl;
    cout << sizeof(B) << endl; // 1
    cout << sizeof(C) << endl; // 1
    return 0;
}