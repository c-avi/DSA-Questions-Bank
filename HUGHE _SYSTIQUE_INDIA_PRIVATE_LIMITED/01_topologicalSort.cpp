#include <bits/stdc++.h>
using namespace std;

int minTimeToCompleteTasks(int n, vector<pair<int,int>> &dependencies) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    vector<int> time(n, 0);

    for (auto &dep : dependencies) {
        int u = dep.second;
        int v = dep.first;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            time[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }

            time[v]  = max(time[v], time[u] + 1);

        }
    }

    return *max_element(time.begin(), time.end());
}

int main() {
    int n, m;
    cout << "Enter number of tasks: ";
    cin >> n;

    cout << "Enter number of dependencies: ";
    cin >> m;

    vector<pair<int, int>> dependencies(m);
    cout << "Enter dependencies as pairs (task depends_on_task):\n";
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dependencies[i] = {a, b};
    }

    cout << "Minimum time to complete all tasks: " << minTimeToCompleteTasks(n, dependencies) << "\n";

    return 0;
}