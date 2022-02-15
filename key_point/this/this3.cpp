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
    Test (int x = 0, int y = 0) { this->x = x; this->y = y; }
    Test setX(int a) { x = a; return *this; }
    Test setY(int b) { y = b; return *this; }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

class B {
private:
    int x;
    int y;
public:
    B(int x = 0, int y = 0) { this->x = x; this->y = y; }
    B& setX(int a) { x = a; return *this;}
    B& setY(int b) { y = b; return *this;}
    void print() { cout << "x = " << x << " y = " << y << endl; }
};


int main() {
    Test obj1;
    obj1.setX(10).setY(20);
    obj1.print(); // x = 10 y = 0

    Test obj2;
    obj2.setX(10);
    obj2.setY(20);
    obj2.print(); // x = 10 y = 20
    cout << "===============================" << endl;

    B b1;
    b1.setX(10).setY(20);
    b1.print(); // x = 10 y = 0

    B b2;
    b2.setX(10);
    b2.setY(20);
    b2.print(); // x = 10 y = 20
    return 0;
}
