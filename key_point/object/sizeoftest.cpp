//
// Created by 周天斌 on 2022/4/23.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool a = true;
    cout << a << " sizeof bool: " << sizeof a << endl;
    bool arr[10];
    cout << arr << " sizeof bool arr: " << sizeof arr << endl;
    bool arr2[2][3];
    cout << arr2 << " sizeof bool arr: " << sizeof arr2 << endl;
    vector<int> ve = {1, 2, 3, 4};
    vector<int> ve2(ve.begin() + 1, ve.begin() + 2);
    for (int num : ve2) {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}