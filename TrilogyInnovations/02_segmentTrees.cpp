#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int a[MAXN], tree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l , r);
    return p1 + p2;
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int main() {
    int n = 5;
    a[0] = 1, a[1] = 3, a[2] = 5, a[3] = 7, a[4] = 9;
    build(1, 0, n - 1);
    cout << "Sum of [1, 3]: " << query(1, 0, n -1, 1, 3) << "\n"; // Output: 15

    update(1, 0, n - 1, 2, 6);// a[2] = 6
    cout << "Sum of [1, 3]: " << query(1, 0, n - 1, 1, 3) << "\n"; // Output: 16
}