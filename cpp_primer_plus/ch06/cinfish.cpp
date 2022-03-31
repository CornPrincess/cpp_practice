//
// Created by 周天斌 on 11/25/21.
//

#include <iostream>

void test();

const int Max = 5;

using namespace std;

int main() {
// get date
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
         << " fish <q to terminate>.\n";
    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i]) {
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }
// calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];
// report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of "
             << i << " fish\n";
    cout << "Done.\n";
    test();
    return 0;
}

void test() {
    int i = 2;
    int j = 2;
    bool res1 = ++i < 2;
    bool res2 = j++ < 2;
    cout << res1 << endl;
    cout << res2 << endl;
};