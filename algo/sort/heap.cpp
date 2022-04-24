//
// Created by 周天斌 on 2022/4/21.
//
#include <vector>
#include <iostream>

using namespace std;

vector<int> sort(vector<int> &nums);

void buildHeap(vector<int> &nums);

void heapify(vector<int> &nums, int i, int end);

void print(vector<int> &nums);

int main() {
    vector<int> nums = {1, 2, 4, 7, 55, 33, 90, 55, 55, 77, 34544, 13};
    vector<int> res = sort(nums);

    return 0;
}

vector<int> sort(vector<int> &nums) {
    buildHeap(nums);
    int k = nums.size() - 1;
    while (k > 0) {
        swap(nums[0], nums[k]);
        k--;
        heapify(nums, 0, k);
    }
    cout << "sort finish" << endl;
    print(nums);
    return nums;
}

void buildHeap(vector<int> &nums) {
    int n = nums.size();
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(nums, i, n - 1);
    }
    cout << "build heap finish" << endl;
    print(nums);
}

/**
 * 从上往下堆化
 * @param nums 数组，下标从0开始
 * @param i 要堆化的元素下标
 * @param end 数组最后一个元素的下标
 */
void heapify(vector<int> &nums, int i, int end) {
    while (true) {
        int maxPtr = i;
        if ((2 * i + 1) <= end && nums[2 * i + 1] > nums[i]) {
            maxPtr = 2 * i + 1;
        }
        if ((2 * i + 2) <= end && nums[2 * i + 2] > nums[maxPtr]) {
            maxPtr = 2 * i + 2;
        }
        if (maxPtr == i) break;
        swap(nums[i], nums[maxPtr]);
        i = maxPtr;
    }
}

void print(vector<int> &nums) {
    for (int num: nums) {
        cout << num << ", ";
    }
    cout << endl;
}
