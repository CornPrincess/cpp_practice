//
// Created by 周天斌 on 2022/4/3.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    vector<int> nums = {2, 3, 2};
    int bagWeight = 10;

    // core  把多重背包摊平，转为01背包问题
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] > 1) {
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }

    vector<int> bag(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) {
        for (int j = bagWeight; j >= weight[i]; j--) {
            bag[j] = max(bag[j], bag[j - weight[i]] + value[i]);
        }
        for (int j = 0; j <= bagWeight; j++) {
            cout << bag[j] << " ";
        }
        cout << endl;
    }
    return 0;
}