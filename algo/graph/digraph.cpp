//
// Created by 周天斌 on 2022/5/17.
//

#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Digraph {
private:
    int v;
    int e;
    vector<vector<int>> adj;
public:
    Digraph() = default;
    Digraph(int V) {
        v = V;
        e = 0;
        adj.resize(V);
        for (int i = 0; i < V; i++) {
            adj.push_back(vector<int>());
        }
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        e++;
    }

    int V() const {
        return v;
    }

    vector<int> ADJ(int v) {
        return adj[v];
    }

    Digraph reverse() {
        Digraph R(v);
        for (int i = 0; i < v; i++) {
            for (int w: adj[v]) {
                R.addEdge(w, i);
            }
        }
        return R;
    }
};

class DirectedDFS {
private:
    vector<bool> marked;

    void dfs(Digraph& g, int v) {
         marked[v] = true;
         for (int w: g.ADJ(v)) {
             if (!marked[w]) {
                 dfs(g, w);
             }
         }
    }

public:
    DirectedDFS() = default;
    DirectedDFS(Digraph& g, int s) {
        marked.resize(g.V());
        dfs(g, s);
    }
    DirectedDFS(Digraph& g, vector<int> source) {
        marked.resize(g.V());
        for (int s : source) {
            if (!marked[s]) {
                dfs(g, s);
            }
        }
    }
};

class DirectedCycle {
private:
    vector<bool> marked;
    vector<int> edgeTo;
    // 有向环中的所有顶点
    stack<int> cycle;
    // 递归调用的栈上的所有顶点
    vector<bool> onStack;

    void dfs(Digraph& g, int v) {
        onStack[v] = true;
        marked[v] = true;
        for (int w : g.ADJ(v)) {
            // 检测出环就退出
            if (!cycle.empty()) {
                return;
            } else if (!marked[w]) {
                edgeTo[w] = v;
                dfs(g, w);
            } else if (onStack[w]) {
                // 说明访问过的点已经在栈上了，这个时候有环
                for (int i = v; i != w; i = edgeTo[i]) {
                    cycle.push(i);
                }
                cycle.push(w);
                cycle.push(v);
            }
        }
        onStack[v] = false;
    }
public:
    DirectedCycle() = default;
    DirectedCycle(Digraph& g) {
        onStack.resize(g.V());
        edgeTo.resize(g.V());
        marked.resize(g.V());
        for (int i = 0; i < g.V(); i++) {
            if (!marked[i]) {
                dfs(g, i);
            }
        }
    }

    bool hasCycle() const {
        return !cycle.empty();
    }
};

class DepthFirstOrder {
private:
    vector<bool> marked;
    queue<int> pre;
    queue<int> post;
    stack<int> reversePost;

    void dfs(Digraph& g, int v) {
        pre.push(v);
        marked[v] = true;
        for (int w : g.ADJ(v)) {
            if (!marked[w]) {
                dfs(g, w);
            }
        }
        post.push(v);
        reversePost.push(v);
    }

public:
    vector<int> getReversePost() {
        vector<int> res;
        while (reversePost.empty()) {
            res.push_back(reversePost.top());
            reversePost.pop();
        }
        return res;
    }

public:
    DepthFirstOrder() = default;
    DepthFirstOrder(Digraph&& g) {
        marked.resize(g.V());
        for (int i = 0; i < g.V(); i++) {
            if (!marked[i]) {
                dfs(g, i);
            }
        }
    }
};

class Topological {
private:
    vector<int> order;
public:
    Topological() = default;
    Topological(Digraph& g) {
        DirectedCycle directedCycle;
        if (!directedCycle.hasCycle()) {
            DepthFirstOrder depthFirstOrder;
            order = depthFirstOrder.getReversePost();
        }
    }
};

class KosarajuSCC {
private:
    vector<bool> marked;
    vector<int> id;
    int count = 0;

    void dfs(Digraph& g, int v) {
        marked[v] = true;
        id[v] = count;
        for (int w: g.ADJ(v)) {
            if (!marked[w]) {
                dfs(g, w);
            }
        }
    }
public:
    KosarajuSCC() = default;
    KosarajuSCC(Digraph& g) {
        marked.resize(g.V());
        id.resize(g.V());
        DepthFirstOrder order(g.reverse());
        for (int s: order.getReversePost()) {
            if (!marked[s]) {
                dfs(g, s);
                count++;
            }
        }
    }

    bool strongConnected(int v, int w) {
        return id[v] == id[w];
    }
};