#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS
void bfs(int start, vector<vector<int>>& adj,vector<bool>& visited) {
    queue<int>q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " "; // Process the node (Printing)

        // Visit all adjacent nodes
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Driver function
int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    // Input edges (Undirected graph)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    cout << "BFS Traversal: ";
    bfs(1, adj, visited); // Start bfs from node 1

    return 0;
}