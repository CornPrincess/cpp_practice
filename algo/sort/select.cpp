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
    for (int i = 0; i < nums.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
    return nums;
}