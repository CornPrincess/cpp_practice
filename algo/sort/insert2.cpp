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
    return 1;
}

vector<int> sort(vector<int> &nums) {
    if (nums.size() < 2) {
        return nums;
    }
    for (int i = 1; i < nums.size(); i++) {
        int val = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > val) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = val;
    }
    return nums;
}