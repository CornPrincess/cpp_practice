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
    for (int i = 1; i < nums.size(); i++) {
        int tmp = nums[i];
        int j = i;
        while (j > 0 && nums[j - 1] > tmp) {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = tmp;
    }
    return nums;
}