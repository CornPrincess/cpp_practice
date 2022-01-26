//
// Created by 周天斌 on 2021/12/6.
//

#include <iostream>

// constants
const int ArSize = 10;

// function prototype
void strcount(const char *str);

int main() {
    using namespace std;
    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin) {
        cin.get(next);
        while (next != '\n')    // string didn't fit!
            cin.get(next);      // dispose of remainder
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const char *str) {
    using namespace std;
    static int total = 0;       // static local variable 只被初始化一次
    int count = 0;              // automatic local variable

    cout << "\"" << str << "\" contains ";
    while (*str++)              // go to end of string
        count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}