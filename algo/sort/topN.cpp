//
// Created by 周天斌 on 2022/4/20.
//

#include <iostream>
#include <vector>

using namespace std;

int randomPartition(vector<int> &nums, int left, int right);

int partition(vector<int> &nums, int left, int right);

int quickSelect(vector<int> &nums, int left, int right, int index);

void test(vector<int> &nums, int k);

int main() {
    srand(time(0));
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    test(nums1, k1);
    test(nums2, k2);
    return 0;
}

void test(vector<int> &nums, int k) {
    int target = nums.size() - k;
    int i = quickSelect(nums, 0, nums.size() - 1, target);
    cout << "i: " << i << ", kth val: " << nums[i] << endl;
}

int quickSelect(vector<int> &nums, int left, int right, int index) {
    while (true) {
        int q = randomPartition(nums, left, right);
        if (q == index) {
            return q;
        } else if (q > index) {
            right = q - 1;
        } else {
            left = q + 1;
        }
    }
}

int randomPartition(vector<int> &nums, int left, int right) {
    int lt = rand() % (right - left + 1) + left;
    swap(nums[left], nums[lt]);
    return partition(nums, left, right);
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
    swap(nums[left], nums[lt]);
    return lt;
}