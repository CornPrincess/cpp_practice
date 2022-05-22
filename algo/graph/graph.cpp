//
// Created by 周天斌 on 2022/5/17.
//

#include <vector>
#include <stack>
#include <queue>

using namespace std;

// 无向图
class Graph {
private:
    // 节点个数
    int v;
    // 边的数目
    int e;
    vector<vector<int>> adj;
public:
    Graph() = default;
    Graph(int _v): v(_v) {
        for (int i = 0; i < _v; i++) {
            adj.push_back(vector<int>());
        }
    }

    // 无向图一条边存两次
    void addEdge(int s, int t) {
        adj[s].push_back(t);
        adj[t].push_back(s);
        e++;
    }

    int V() const {
        return v;
    }

    int E() const {
        return e;
    }

    vector<int> ADJ(int _v) {
        return adj[_v];
    }
};

class DepthFirstSearch {
private:
    vector<bool> marked;
    int count;
public:
    DepthFirstSearch() = default;
    DepthFirstSearch(Graph& g, int s) {
        marked.resize(g.V());
        dfs(g, s);
    }

    void dfs(Graph& g, int v) {
        marked[v] = true;
        count++;
        for (int w: g.ADJ(v)) {
            if (!marked[w]) {
                dfs(g, w);
            }
        }
    }

    bool isMarked(int w) {
        return marked[w];
    }

    int getCount() {
        return count;
    }
};

class DepthFirstPath {
private:
    vector<bool> marked;
    // 记录路径中的上一个点
    vector<int> edgeTo;
    // 起点
    int s;

    void dfs(Graph g, int v) {
        marked[v] = true;
        for (int w: g.ADJ(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(g, w);
            }
        }
    }
public:
    DepthFirstPath() = default;
    DepthFirstPath(Graph& g, int _s) {
        marked.resize(g.V());
        edgeTo.resize(g.V());
        s = _s;
        dfs(g, s);
    }

    bool hasPathTo(int v) {
        return marked[v];
    }

    vector<int> pathToV(int v) {
        vector<int> res;
        if (!hasPathTo(v)) {
            return res;
        }
        stack<int> sta;
        for (int x = v; v != s; x = edgeTo[x]) {
            sta.push(x);
        }
        sta.push(s);
        return res;
    }
};

class BreadFirstPaths {
private:
    vector<bool> marked;
    vector<int> edgeTo;
    // 起点
    int s;

    void bfs(Graph& g, int _s) {
        queue<int> que;
        que.push(_s);
        marked[_s] = true;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int w: g.ADJ(v)) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    marked[w] = true;
                    que.push(w);
                }
            }
        }
    }

    // 判断是否存在从s的路径
    bool hasPathTo(int v) {
        return marked[v];
    }
public:
    BreadFirstPaths() = default;
    BreadFirstPaths(Graph& g, int _s) {
        marked.resize(g.V());
        edgeTo.resize(g.V());
        this->s = _s;
        bfs(g, s);
    }
};

class CC {
private:
    vector<bool> marked;
    // v 所在的连通分量标识符，这个标识符其实就是count
    vector<int> id;
    // 连通分量数，即子图数
    int count;
public:
    CC(Graph& g) {
        marked.resize(g.V());
        id.resize(g.V());
        for (int s = 0; s < g.V(); s++) {
            if (!marked[s]) {
                dfs(g, s);
                count++;
            }
        }
    }

    void dfs(Graph& g, int v) {
        marked[v] = true;
        // core 标识这个点属于哪个连通分量
        id[v] = count;
        for (int w: g.ADJ(v)) {
            if (!marked[w]) {
                dfs(g, w);
            }
        }
    }

    bool connected(int v, int w) {
        // 其实就是检查是否在同一个连通分量中
        return id[v] == id[w];
    }

    int geId(int v) {
        return id[v];
    }

    int getCount() {
        return count;
    }
};

class Cycle {
private:
    vector<bool> marked;
    bool hasCycle;

    void dfs(Graph& g, int v, int u) {
        marked[v] = true;
        for (int w : g.ADJ(v)) {
            if (!marked[w]) {
                // core 这里的入参，最后一个放自己的上一个节点
                dfs(g, w, v);
            } else if (w != u) {
                // core 这里很重要，如果已经访问过的点不是自己的邻节点，那么就有环
                hasCycle = true;
            }
        }
    }
public:
    Cycle() = default;
    Cycle(Graph& g) {
        marked.resize(g.V());
        // 遍历一遍
        for (int s = 0; s < g.V(); s++) {
            if (!marked[s]) {
                // 头节点也是自己，所以 s， s
                dfs(g, s, s);
            }
        }
    }
};

class TwoColor {
private:
    vector<bool> marked;
    vector<bool> color;
    bool isTwoColorable = true;

    void dfs(Graph& g, int v) {
        marked[v] = true;
        for (int w: g.ADJ(v)) {
            if (!marked[w]) {
                // core dfs 过程中标色
                color[w] = !color[v];
                dfs(g, w);
            } else if (color[w] == color[v]) {
                // core 走到这里说明邻节点已经标过色了，可以直接判断
                isTwoColorable = false;
            }
        }
    }
public:
    TwoColor() = default;
    TwoColor(Graph& g) {
        marked.resize(g.V());
        color.resize(g.V());
        for (int s = 0; s < g.V(); s++) {
            if (!marked[s]) {
                dfs(g, s);
            }
        }
    }
};