//
// Created by 周天斌 on 2021/11/29.
//

#include <iostream>

int main() {
    using namespace std;
    int rats = 101;
    // rodents is an reference
    int & rodents = rats;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    // some implementations require type casting the following
    // addresses to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    return 0;
}