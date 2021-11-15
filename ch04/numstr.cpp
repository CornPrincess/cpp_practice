//
// Created by 周天斌 on 2021/11/15.
//

#include <iostream>
int main() {
    using namespace std;
    cout << "What year was your house build?\n";
    int year;
    // 当 cin 读取时，将回车键生成的换行符留在了输入队列中，后面getline直接认为是换行，不能输入地址
    (cin >> year).get();
    // cin.get();
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    return 0;
}