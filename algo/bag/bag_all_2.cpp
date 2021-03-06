//
// Created by 周天斌 on 2022/4/1.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<int> &nums);

int main() {
    // 01背包和完全背包唯一不同就是体现在遍历顺序上
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    // 这里的遍历顺序两种都可以
    for (int j = 0; j <= bagWeight; j++) {
        for (int i = 0; i < weight.size(); i++) {
            if (j >= weight[i]) {
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
        print(dp);
    }
    return 0;
}

void print(vector<int> &nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}