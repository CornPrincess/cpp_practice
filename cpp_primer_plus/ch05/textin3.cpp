//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
int main() {
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    // use the cin.get(ch) function
    // 注意这里get 会将ch转化为其引用
    cin.get(ch);
    while (!cin.fail()) {
//        cout << "'" << ch << "' " << "write in" << endl;
        cout << ch;
        ++count;
        // 不会忽略空格 制表符 换行符
        // 输入会被缓冲
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";
    return 0;
}