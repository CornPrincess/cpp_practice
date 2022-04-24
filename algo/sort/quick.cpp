//
// Created by 周天斌 on 2022/4/20.
// top to down merge sort

#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &nums, int left, int right);
int partition(vector<int> &nums, int left, int right);

int main() {
    vector<int> nums = {1, 2, 4, 7, 55, 33, 90, 55, 55, 77, 34544, 13};
    sort(nums, 0, nums.size() - 1);
    for (int num: nums) {
        cout << num << ", ";
    }
    cout << endl;
    return 1;
}

void sort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int pivot = partition(nums, left, right);
    sort(nums, left, pivot - 1);
    sort(nums, pivot + 1, right);
}

int partition(vector<int> &nums, int left, int right) {
    int val = nums[left];
    int lt = left;
    // core 循环不变量规则
    // [left, lt - 1] < val
    // [lt, right] >= val
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < val) {
            lt++;
            swap(nums[i], nums[lt]);
        }
    }
    swap(nums[left], nums[lt]);
    return lt;
}