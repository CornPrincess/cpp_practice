//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
int main() {
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    while (cin.get(ch)) {
        cout << ch;
        ++count;
    }
    cout << endl << count << " characters read\n";
    return 0;
}