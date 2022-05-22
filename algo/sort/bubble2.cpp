//
// Created by 周天斌 on 2022/4/20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> &nums);

int main() {
    vector<int> nums = {1, 2, 4, 7, 55, 33, 90, 55, 55, 77, 34544, 13};
    vector<int> res = sort(nums);
    for (int num: nums) {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}

vector<int> sort(vector<int> &nums) {
    if (nums.size() < 2) return nums;
    for (int i = 0; i < nums.size(); i++) {
        bool flag = false;
        for (int j = 0; j < nums.size() - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        // core 优化，如果本轮没有交换，那么就直接结束
        if (!flag) {
            break;
        }
    }
    return nums;
}