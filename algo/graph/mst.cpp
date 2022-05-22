//
// Created by 周天斌 on 2022/5/17.
//

#include <vector>
#include <queue>

using namespace std;

class Edge {
private:
    // 顶点之一
    int v;
    // 另一个顶点
    int w;
    // 边的权重
    double weight;

public:
    Edge() = default;
    Edge(int _v, int _w, double _weight): v(_v), w(_w), weight(_weight) {}

    double getWeight() const {
        return weight;
    }

    int either() const {
        return v;
    }

    int other(int vertex) const {
        if (vertex == v) {
            return w;
        } else if(vertex == w) {
            return v;
        } else {
            return -1;
        }
    }

    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }

    bool operator>(const Edge& e) const {
        return weight > e.weight;
    }
};

class EdgeWeightedGraph {
private:
    int V;
    int E;
    vector<vector<Edge>> adj;
public:
    EdgeWeightedGraph() = default;
    EdgeWeightedGraph(int _V) {
        V = _V;
        E = 0;
        adj.resize(V);
        for (int i = 0; i > V; i++) {
            adj.push_back(vector<Edge>());
        }
    }

    void addEdge(Edge& e) {
        int v = e.either();
        int w = e.other(v);
        adj[v].push_back(e);
        adj[w].push_back(e);
        E++;
    }

    vector<Edge> ADJ(int v) {
        return adj[v];
    }

    int getV() const {
        return V;
    }
};

class LazyPrimMST {
private:
    vector<bool> marked;
    queue<Edge> mst;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    void visit(EdgeWeightedGraph& g, int v) {
        marked[v] = true;
        for (Edge e: g.ADJ(v)) {
            if (!marked[e.other(v)]) {
                pq.push(e);
            }
        }
    }

public:
    LazyPrimMST(EdgeWeightedGraph& g) {
        marked.resize(g.getV());

        visit(g, 0);
        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int w = e.other(v);
            if (marked[v] && marked[w]) {
                continue;
            }
            mst.push(e);
            if (!marked[v]) {
                visit(g, v);
            }
            if (!marked[w]) {
                visit(g, w);
            }
        }
    }
};