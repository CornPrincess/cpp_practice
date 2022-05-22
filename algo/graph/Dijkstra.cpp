//
// Created by 周天斌 on 2022/5/17.
//
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
private:
    // 点的个数
    int N = 110;
    // 边的个数
    int M = 6010;
    int INF = INT_MAX / 2;

public:
    int networkDelayTime(vector<vector<int>> ts, int n, int k) {
        // 初始化图
        vector<vector<int>> graph(N, vector<int>(N, INF));
        for (vector<int> vec: ts) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            graph[u][v] = w;
        }
        // 计算从k点开始到各个点的最短路径
        vector<int> dist = dijkstra(graph, k);
        // 遍历答案
        int maxVal = 0;
        for (int num: dist) {
            maxVal = max(maxVal, num);
        }
        return maxVal;
    }

    vector<int> dijkstra(vector<vector<int>>& graph, int k) {
        vector<bool> marked(N, false);
        vector<int> dist(N, INF);
        // 从 k 开始
        dist[k] = 0;
        for (int i = 1; i < dist.size(); i++) {
            int t = -1;
            // 寻找已标记点中距离最短的的点
            for (int j = 1; j < dist.size(); j++) {
                if (marked[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            marked[t] = true;
            // 用t的最小距离更新其他点
            for (int _k = 1; _k <= dist.size(); _k++) {
                dist[i] = min(dist[i], dist[t] + graph[t][_k]);
            }
        }
        return dist;
    }
};

class Solution2 {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int INF = INT_MAX;
        // pair: (vertex, weight)
        vector<vector<pair<int, int>>> graph(n);
        for (auto &t: times) {
            int u = t[0] - 1;
            int v = t[1] - 1;
            graph[u].push_back({v, t[2]});
        }
        // {weight, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        vector<int> dist(n, INF);
        vector<bool> marked(n, false);
        dist[k-1] = 0;
        que.push({0, k-1});
        while (!que.empty()) {
            auto p = que.top();
            int weight = p.first;
            int vertex = p.second;
            if (marked[vertex]) {
                continue;
            }
            marked[vertex] = true;
            for (auto &gu: graph[vertex]) {
                int v = gu.first;
                int t = gu.second;
                if (dist[v] > weight + t) {
                    dist[v] = weight + t;
                    que.push({weight + t, v});
                }
            }
        }
    }
};