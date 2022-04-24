//
// Created by 周天斌 on 2022/4/20.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<int> index;
    vector<int> indexTmp;
    vector<int> res;

    void sort(vector<int>& nums, int left, int right) {
        if (right <= left) return;
        int mid = left + (right - left) / 2;
        sort(nums, left, mid);
        sort(nums, mid + 1, right);
        // core 这里left right mid 都是 index 的索引，不是nums的索引
        if (nums[index[mid]] <= nums[index[mid + 1]]) return;
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            indexTmp[i] = index[i];
        }
        int i = left;
        int j = mid + 1;
        int k = left;
        while (k <= right) {
            if (i > mid) {
                index[k++] = indexTmp[j++];
            } else if (j > right) {
                index[k++] = indexTmp[i];
                res[indexTmp[i]] += (right - mid);
                i++;
            } else if (nums[indexTmp[i]] <= nums[indexTmp[j]]) {
                index[k++] = indexTmp[i];
                res[indexTmp[i]] += (j - mid - 1);
                i++;
            } else {
                index[k++] = indexTmp[j++];
            }
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0};
        index = vector<int>(n);
        indexTmp = vector<int>(n);
        res = vector<int>(n);
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }
        sort(nums, 0, n - 1);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = s.countSmaller(nums);
    for (int num: res) {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}