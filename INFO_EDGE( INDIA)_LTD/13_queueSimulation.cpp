#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string cmd; cin >> cmd;
        if (cmd == "ENQUEUE") {
            int x; cin >> x;
            q.push(x);
        } else if (cmd == "DEQUEUE" && !q.empty()) {
            q.pop();
        }
    }
    if (q.empty()) cout << "Empty";
    else {
        while (!q.empty()) {
            cout << q.front();
            q.pop();
            if (!q.empty()) cout << " ";
        }
    }
    return 0;
}