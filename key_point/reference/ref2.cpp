//
// Created by 周天斌 on 2022/2/10.
//

#include <iostream>

int main() {
    using namespace std;
    int rats = 101;
    // rodents is an reference
    int &rodents = rats;
    int * pt = &rats;

    cout << "Before reassign: \n";
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents;
    cout << ", pt = " << *pt << endl;
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents;
    cout << ", pt address = " << pt << endl;

    int bunnies = 50;
    // can we change the reference?
    // core 可以通过初始化来设置引用，但不能使用赋值来设置，以下语句意味着将 bunnies 的值赋给 rats
    rodents = bunnies;
    pt = &bunnies;
    cout << "After reassign:\n";
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents;
    cout << ", pt = " << *pt << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rats address = " << &rats;
    cout << ", rodents address = " << &rodents;
    cout << ", pt address = " << pt << endl;

    int a = 10;
    int *ptr = &a;
    int & rf = *ptr;
    cout << "Before:\n";
    cout << "a = " << a << ", (" << &a << ")\n";
    cout << "ptr = " << *ptr << ", (" << ptr << ")\n";
    cout << "rf = " << rf << ", (" << &rf << ")\n";
    int b = 20;
    ptr = &b;
    cout << "After:\n";
    cout << "a = " << a << ", (" << &a << ")\n";
    cout << "b = " << b << ", (" << &b << ")\n";
    cout << "ptr = " << *ptr << ", (" << ptr << ")\n";
    cout << "rf = " << rf << ", (" << &rf << ")\n";

    return 0;
}