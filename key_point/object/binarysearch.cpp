//
// Created by 周天斌 on 2022/4/9.
//
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
    while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
        int middle = left + ((right - left) >> 1);
        if (nums[middle] > target) {
            right = middle; // target 在左区间，在[left, middle)中
        } else if (nums[middle] < target) {
            left = middle + 1; // target 在右区间，在[middle + 1, right)中
        } else { // nums[middle] == target
            return middle; // 数组中找到目标值，直接返回下标
        }
    }
    // 未找到目标值
    return -1;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4 ,5 ,6, 7, 8};
    int target = 8;
    int value = search(nums, target);
    cout << value << endl;
    int a = 0000001;
    string b = to_string(a);
    cout << "a=" << a << ", b=" << b << endl;
    cout << b.size() << endl;
    return 0;
}