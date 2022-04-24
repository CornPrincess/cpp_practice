//
// Created by 周天斌 on 2022/4/7.
//
#include <iostream>
class A {
private:
    int value;
public:
    A(int n) {value = n;}
    A(A other)  {value = other.value;}
    void print() {std::cout << value << std::endl;}
};

int main() {
    A a = 10;
    A b = a;
    a.print();
    b.print();
    return 0;
}
