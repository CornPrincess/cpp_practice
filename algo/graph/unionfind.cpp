//
// Created by 周天斌 on 2022/5/17.
//

#include <vector>

using namespace std;
class UF {
private:
    vector<int> id;
    int count;
public:
    UF() = default;
    UF(int N) {
        count = N;
        id.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    int getCount() {
        return count;
    }

    bool connected(int p, int q) {
        return find0(q) == find0(p);
    }


    // quick find
    int find0(int p) {
        return id[p];
    }

    void union0(int p, int q) {
        int pid = find0(p);
        int qid = find0(q);

        if (pid == qid) return;

        for (int i = 0; i < id.size(); i++) {
            if (id[i] == pid) {
                id[i] = qid;
            }
        }
        count--;
    }

    // quick union
    int find2(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    void union2(int p, int q) {
        int pRoot = find2(p);
        int qRoot = find2(q);

        if (pRoot == qRoot) return;

        id[pRoot] = qRoot;
        count--;
    }
};