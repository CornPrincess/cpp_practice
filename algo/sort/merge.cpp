//
// Created by 周天斌 on 2022/4/20.
// top to down merge sort

#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &nums, int left, int right, vector<int> &help);
void merge(vector<int> &nums, int left, int mid, int right, vector<int> &help);

int main() {
    vector<int> nums = {1, 2, 4, 7, 55, 33, 90, 55, 55, 77, 34544, 13};
    vector<int> help(nums.size());
    sort(nums, 0, nums.size() - 1, help);
    for (int num: nums) {
        cout << num << ", ";
    }
    cout << endl;
    return 1;
}

void sort(vector<int> &nums, int left, int right, vector<int> &help) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    sort(nums, left, mid, help);
    sort(nums, mid + 1, right, help);
    // core 如果两个区间已经有序，不用合并
    if (nums[mid] <= nums[mid + 1]) {
        return;
    }
    merge(nums, left, mid, right, help);
}

void merge(vector<int> &nums, int left, int mid, int right, vector<int> &help) {
    help.clear();
    for (int i = left; i <= right; i++) {
        help[i] = nums[i];
    }

    int i = left;
    int j = mid + 1;
    int k = left;
    while (k <= right) {
        // core 一定要先判断是否越界
        if (i > mid) {
            nums[k++] = help[j++];
        } else if (j > right) {
            nums[k++] = help[i++];
        } else if (help[i] > help[j]) {
            nums[k++] = help[j++];
        } else {
            nums[k++] = help[i++];
        }
    }
}