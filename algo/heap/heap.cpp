//
// Created by 周天斌 on 2022/5/15.
//
#include <algorithm>

using namespace std;

class Heap {
private:
    int capacity;
    int count;
    int* arr;
public:
    Heap() = default;
    Heap(int _capacity): capacity(_capacity), count(0) {
        arr = new int[_capacity + 1];
    }

    // 自低向上堆化
    void insert(int data) {
        if (count >= capacity) {
            return;
        }
        count++;
        arr[count] = data;
        int i = count;
        while (i / 2 > 0 && arr[i/2] < arr[i]) {
            swap(arr[i], arr[i/2]);
            i = i / 2;
        }
    }

    // 自上往下堆化
    void removeMax() {
        if (count == 0) {
            return;
        }
        arr[1] = arr[count];
        count--;
    }

    void heapify(int i, int n) {
        while (true) {
            int maxpos = i;
            if (2 * i <= n && arr[2 * i] > arr[maxpos]) maxpos = 2 * i;
            if (2 * i + 1 <= n && arr[2 * i + 1] > arr[maxpos]) maxpos = 2 * i + 1;
            if (i == maxpos) break;
            swap(arr[i], arr[maxpos]);
            i = maxpos;
        }
    }
};