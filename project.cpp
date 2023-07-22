#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Edge {
    int v1, v2, weight;
    Edge(int v1, int v2, int weight) : v1(v1), v2(v2), weight(weight) {}
};

struct Data {
    int root, rank;
    Data(int root, int rank) : root(root), rank(rank) {}
};

int vCount;
vector<Edge> graph;
vector<Data> data;

int getRoot(int v) {
    if (data[v].root == v) return v;
    data[v].root = getRoot(data[v].root);
    return data[v].root;
}

void unite(int v1, int v2) {
    int id1 = getRoot(v1);
    int id2 = getRoot(v2);
    if (id1 == id2) return;

    if (data[id1].rank < data[id2].rank) {
        data[id1].root = id2;
    }
    else if (data[id2].rank < data[id1].rank) {
        data[id2].root = id1;
    }
    else {
        data[id1].root = id2;
        data[id2].rank++;
    }
}

int process() {
    sort(graph.begin(), graph.end(), [](const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    });

    int result = 0;
    for (const Edge& edge : graph) {
        int root1 = getRoot(edge.v1);
        int root2 = getRoot(edge.v2);
        if (root1 != root2) {
            result += edge.weight;
            unite(root1, root2);
        }
    }
    return result;
}

int main() {
    auto start = high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin >> vCount;
    int e;
    cin >> e;

    graph.reserve(e);
    data.reserve(vCount);
    for (int i = 0; i < vCount; i++) {
        data.emplace_back(i, 0);
    }

    for (int i = 0; i < e; i++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph.emplace_back(v1 - 1, v2 - 1, weight);
    }

    cout << process() << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count()<< endl; //microsseconds

    return 0;
}