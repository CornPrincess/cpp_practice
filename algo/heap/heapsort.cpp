//
// Created by 周天斌 on 2022/5/15.
//
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;
void heapify(vector<int>& vec, int i, int n);
void buildHeap(vector<int>& vec);
void sort(vector<int>& vec);

void buildHeap(vector<int>& vec) {
    int size = vec.size();
    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(vec, i, size - 1);
    }
}

void sort(vector<int>& vec) {
    buildHeap(vec);
    int n = vec.size() - 1;
    while (n > 0) {
        swap(vec[0], vec[n]);
        n--;
        heapify(vec, 0, n);
    }
}

void heapify(vector<int>& vec, int i, int n) {
    while (true) {
        int maxpos = i;
        if (i * 2 + 1 <= n && vec[i * 2 + 1] > vec[maxpos]) {
            maxpos = i * 2 + 1;
        }
        if (i * 2 + 2 <= n && vec[i * 2 + 2] > vec[maxpos]) {
            maxpos = i * 2 + 2;
        }
        if (maxpos == i) {
            break;
        }
        swap(vec[i], vec[maxpos]);
        i = maxpos;
    }
}

int main() {
    vector<int> vec = {1,34,57,23,56,48,2345569,245,77,90,3546,8,2445,567};
    sort(vec);
    for (auto num : vec) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

