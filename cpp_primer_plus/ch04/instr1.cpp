//
// Created by 周天斌 on 2021/11/15.
//

#include <iostream>

int main() {
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name: \n";
    // core 注意，cin使用空白（空格、制表符和换行符）来确定字符串结束的位置
    cin >> name;
    cout << "Enter your favourite dessert: \n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ". \n";
    return 0;
}