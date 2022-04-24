//
// Created by 周天斌 on 2022/3/31.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 1.确定dp数组（dp table）以及下标的含义
    // dp[j] 表示在容量为j的背包中，所背物品价值可以最大为  dp[j]

    // 2.确定递推公式
    // 这里也是有两种选择，放入第i个物品，或者不放入第i个物品
    // 这里的 dp[j] 相当于二维数组的 dp[i-1][j]
    // dp[j] = max(dp[j], dp[j-weight[i]] + value[i])
    vector<int> bag(bagWeight + 1, 0);.

    // 3.dp数组如何初始化
    // 都初始化为0即可

    // 4.确定遍历顺序
    // core 这里的遍历顺序是关键，一维数组的遍历顺序是固定，并且有两个注意点
    // 1 只能按照先遍历物品再嵌套遍历背包容量
    // 2 背包容量需要从大往小遍历
    for (int i = 0; i < weight.size(); i++) {
        for (int j = bagWeight; j >= weight[i]; j--) {
            bag[j] = max(bag[j], bag[j - weight[i]] + value[i]);
            cout << bag[j] << " ";
        }
        cout << endl;
    }

    // 5.举例推导dp数组

    return 0;
}