//
// Created by qwskyz on 2022/2/20.
//

#include <iostream>

using namespace std;
int main() {
    int arr[10] = {0};
    cout << sizeof arr << endl;
    cout << arr << endl;
    for (int num: arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}