//
// Created by 周天斌 on 2021/11/29.
//

#include <iostream>

int main() {
    using namespace std;
    int rats = 101;
    // rodents is an reference
    int &rodents = rats;

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    // can we change the reference?
    // core 可以通过初始化来设置引用，但不能使用赋值来设置，以下语句意味着将 bunnies 的值赋给 rats
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;
    return 0;
}