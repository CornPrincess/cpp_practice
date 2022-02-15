//
// Created by 周天斌 on 2022/2/15.
//

#include<iostream>

using namespace std;

class Test {
private:
    int x;
    int y;
public:
    Test(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    static void fun1() { cout << "Inside fun1()"; }
    static void fun2() {
        cout << "Inside fun2()";
        this->fun1(); // Error invalid use of 'this' outside of a non-static member function
    }
};

int main() {
    Test obj;
    obj.fun2();
    return 0;
}
