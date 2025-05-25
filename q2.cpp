#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    vector<int> traversal;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        traversal.push_back(current);

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return traversal;
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // neighbors of node 0
        {0, 3, 4}, // neighbors of node 1
        {0, 5},    // neighbors of node 2
        {1},       // neighbors of node 3
        {1},       // neighbors of node 4
        {2}        // neighbors of node 5
    };

    vector<int> traversal = bfs(graph, 0);

    for (int node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
