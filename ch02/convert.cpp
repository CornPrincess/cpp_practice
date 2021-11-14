//
// Created by 周天斌 on 11/13/21.
//
#include <iostream>
int stonetolb(int);

int main() {
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " pounds. " << endl;
    return 0;
}

int stonetolb(int sts) {
    return 14 * sts;
}