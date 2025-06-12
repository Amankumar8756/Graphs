#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];

        // Convert edge list to adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // because it's undirected
        }

        vector<int> color(V, -1); // -1 means unvisited

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter " << E << " edges (0-indexed):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    if (obj.isBipartite(V, edges)) {
        cout << "Yes, the graph is Bipartite." << endl;
    } else {
        cout << "No, the graph is NOT Bipartite." << endl;
    }

    return 0;
}
