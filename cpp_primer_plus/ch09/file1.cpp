//
// Created by 周天斌 on 2021/12/5.
//

#include <iostream>
#include "coordin.h"
using namespace std;
int main() {
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next tow numbers (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}