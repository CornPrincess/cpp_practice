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
    Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
    void setX(int a) { x = a; }
    void setY(int b) { y = b; }
    void destroy() { delete this; }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

int main() {
    Test obj;
    obj.destroy(); //  error for object 0x7ffee0c81810: pointer being freed was not allocated
    obj.print();
    return 0;
}
