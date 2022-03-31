//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
int main() {
    using namespace std;
    // 必须是int， 因为EOF是-1，在有些系统中没有无符号的char
    int ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    while ((ch = cin.get()) != EOF) {
        cout << (char)ch;
        ++count;
    }
    cout << endl << count << " characters read\n";
    return 0;
}