//
// Created by 周天斌 on 2022/2/16.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1 = {1,2};
    vector<vector<int>> v2 = {{}};
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    cout << v2[0].size() << endl;
    return 0;
}