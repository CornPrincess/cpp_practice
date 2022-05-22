//
// Created by 周天斌 on 2022/3/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;


    // 1.确定dp数组（dp table）以及下标的含义
    // dp[i][j] 表示在下标为 [0, 1] 范围内的商品，且背包容量为 j 时背包中物品的最大价值
    vector<vector<int>> bag(weight.size(), vector<int>(bagweight + 1, 0));

    // 2.确定递推公式
    // 这里关键的地方在于对第i块石头的判断，是取这块石头，还是不取这块石头
    // dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])

    // 3.dp数组如何初始化
    // dp[0][j] 初始化第一行
    // dp[i][0] 初始化第一列，都为0，因为背包没有容量
    for (int j = weight[0]; j <= bagweight; j++) {
        bag[0][j] = value[0];
    }

    // 4.确定遍历顺序
    // 先遍历商品，再遍历背包
    for (int i = 1; i < weight.size(); i++) {
        for (int j = 1; j <= bagweight; j++) {
            // core 一定要判断
            if (j < weight[i]) {
                bag[i][j] = bag[i-1][j];
            } else {
                bag[i][j] = max(bag[i-1][j], bag[i-1][j - weight[i]] + value[i]);
            }
        }
    }

    // 5.举例推导dp数组
    for (int i = 0; i < weight.size(); i++) {
        for (int j = 0; j <= bagweight; j++) {
            cout << bag[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void test() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
    for (int i = weight[0]; i <= bagweight; i++) {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) {
        for (int j = 1; j <= bagweight; j++) {
            if (j < weight[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
            }
        }
    }
}