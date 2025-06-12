#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertex, edges;
    cin >> vertex >> edges;

    vector<pair<int, int>> AdjList[vertex];
    int u, v, weight;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;  // FIX: read weight here
        AdjList[u].push_back(make_pair(v, weight));
        AdjList[v].push_back(make_pair(u, weight));
    }

    // Print the adjacency list
    for (int i = 0; i < vertex; i++) {
        cout << i << "--> ";
        for (auto it : AdjList[i]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
