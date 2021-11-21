//
// Created by 周天斌 on 11/21/21.
//

#include <iostream>
#include <ctime>    // describes clock() function, clock_t type

int main() {
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";
    clock_t  start = clock();
    // wait until time elapses
    while (clock() - start < delay)
        ;
    cout << "done \a\n";
    return 0;
}