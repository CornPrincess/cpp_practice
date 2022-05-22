//
// Created by 周天斌 on 2022/5/17.
//
#include <vector>

using namespace std;
class WeightedQuickUnionUF {
private:
    vector<int> id;
    vector<int> sz;
    int count;
public:
    WeightedQuickUnionUF() = default;
    WeightedQuickUnionUF(int N) {
        id.resize(N);
        sz.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        count = N;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    void union0(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        // core 优化点，将小的树挂在大的树上
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = id[i];
            sz[i] += sz[j];
        }
        count--;
    }
};