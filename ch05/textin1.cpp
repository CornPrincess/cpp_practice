//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>

int main() {
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;
    while (ch != '#') {
        cout << "'" << ch << "' " << "write in" << endl;;
        ++count;
        // 忽略空格和换行符
        // 发送给 cin 的输入被缓冲
        cin >> ch;
    }
    cout << endl << count << " characters read\n";
    return 0;
}