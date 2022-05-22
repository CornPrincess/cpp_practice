//
// Created by qwskyz on 22-5-15.
//

#include <iostream>

using namespace std;

void pair_test() {
    pair<string, int> p1("hello", 1);
    cout << p1.first << " " << p1.second << endl;

    pair<int, string> p2 = make_pair(10, "world");
    cout << p2.first << " " << p2.second << endl;
}

int main() {
    pair_test();
    return 0;
}