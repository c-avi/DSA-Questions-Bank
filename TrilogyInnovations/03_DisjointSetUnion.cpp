#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    } 

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[py] < rank[px])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 7;
    DSU dsu(n);

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(5, 6);
    dsu.unite(4, 5);

    cout << "Are 0 and 2 connected? " << (dsu.connected(0, 2) ? "Yes" : "No") << "\n";
    cout << "Are 0 and 4 connected? " << (dsu.connected(0, 4) ? "Yes" : "No") << "\n";
    cout << "Are 3 and 6 connected? " << (dsu.connected(3, 6) ? "Yes" : "No") << "\n";
    
    return 0;

}