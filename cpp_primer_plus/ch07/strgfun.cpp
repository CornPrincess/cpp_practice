//
// Created by 周天斌 on 11/28/21.
//

#include <iostream>

unsigned int c_in_str(const char *str, char ch);

int main() {
    using namespace std;
    char mmm[15] = "minimum";   // string in an array
// some systems require preceding char with static to
// enable array initialization

    char *wail = "ululate";

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    return 0;
}

// this function counts the number of ch characters
// in the string str
unsigned int c_in_str(const char* str, char ch) {
    unsigned int count = 0;

    // quit when *str is '\0'
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}