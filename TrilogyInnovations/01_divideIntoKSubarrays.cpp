#include <bits/stdc++.h>
using namespace std;

typedef long long l1;
const l1 INF = 1e18;

int n, k;
vector<l1> a, prefix;
vector<vector<l1>> dp;

l1 cost(int l, int r) {
    l1 sum = prefix[r] - prefix[l];
    return sum * sum;
}

void compute(int level, int l, int r, int optL, int optR) {
    if (l > r) return;

    int mid = (l + r) / 2;
    pair <l1, int> best = {INF, -1};

    for (int i = optL; i <= min(mid - 1, optR); ++i) {
        l1 curr = dp[level - 1][i] + cost(i, mid);
        if (curr < best.first) {
            best = {curr, i};
        }
    }

    dp[level][mid] = best.first;
    int opt = best.second;

    compute(level, l, mid - 1, optL, opt);
    compute(level, mid + 1, r, opt, optR);
}

int main() {
    cin >> n >> k;
    a.resize(n + 1);
    prefix.resize(n + 1, 0);
    dp.assign(k + 1, vector<l1>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    dp[0][0] = 0;

    for (int i = 1; i <= k; ++i) {
        compute(i, 1, n, 0, n - 1);
    }

    cout << dp[k][n] << "\n";

    return 0;
}