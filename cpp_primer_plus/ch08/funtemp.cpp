//
// Created by 周天斌 on 2021/12/2.
// using a function template

#include <iostream>

// function template prototype
template<typename T>
void Swap(T &a, T &b);

int main() {
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);  // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x, y);  // generate void Swap(double &, double &);
    cout << "Now x, y = " << x << ", " << y << ".\n";
    // cin.get();
    return 0;
}

// function template definition
// core 模版并不创建任何函数，而只是告诉编译器如何定义函数
// core 需要交换 int 的函数时，编译器将按模版模式创建怎样的函数
// core 模版不能缩短可执行程序，最终仍有两个独立的函数定义，就行手工方式定义了这些函数一样
template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}
