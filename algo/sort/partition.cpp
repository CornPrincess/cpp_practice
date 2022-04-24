//
// Created by 周天斌 on 2022/4/20.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int left, int right);
void test(vector<int>& nums);

int main() {
    vector<int> nums1 = {1, 2, 4, 56, 67, 23, 67, 62, 24, 5, 76};
    vector<int> nums2 = {8, 2, 4, 56, 67, 23, 67, 62, 24, 5, 76, 8};
    vector<int> nums3 = {100, 2, 4, 56, 67, 23, 67, 62, 24, 5, 76};
    test(nums1);
    test(nums2);
    test(nums3);
    return 0;
}

void test(vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }
    cout << endl;
    int pivot = partition(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << ", ";
    }
    cout << endl;
    cout << endl;
}

int partition(vector<int> &nums, int left, int right) {
    int lt = left;
    int val = nums[left];
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < val) {
            lt++;
            swap(nums[lt], nums[i]);
        }
    }
    swap(nums[lt], nums[left]);
    cout << "pivot: " << lt << ", val: " << val << endl;
    return lt;
}