//
// Created by 周天斌 on 2021/12/13.
//

#include "string1.h"
#include <iostream>
void test(const int & t);

const int ArSize = 10;
const int MaxLen = 81;

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;
    cout << name << ", please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";
    // array of objects
    String sayings[ArSize];
    // temporary string storage
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n') {
            continue;
        }
        if (!cin || temp[0] == '\0') {
            break;
        } else {
            // core overload assignment
            sayings[i] = temp;
        }
    }
    int total = i;
    if (total > 0) {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++) {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }
        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++) {
            if (sayings[i].length() < sayings[shortest].length()) {
                shortest = i;
            }
            if (sayings[i] < sayings[first]) {
                first = i;
            }
        }
        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabeticaly:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany()
             << " String objects. Bye.\n";
    } else {
        cout << "No input! Bye. total=" << total <<"\n";
    }
    int tt = 10000;
    test(tt);
    return 0;
}

void test(const int & t) {
    std::cout << t;
}