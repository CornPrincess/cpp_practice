//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
int main() {
    using std::cin;     // using declarations
    using std::cout;
    char ch;
    int spaces = 0;
    int total = 0;
    cin.get(ch);
    while (ch != '.') {
        if (ch == ' ') {
            spaces++;
        }
        total++;
        cin.get(ch);
    }
    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    return 0;
}