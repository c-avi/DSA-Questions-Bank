#include <bits/stdc++.h>
using namespace std;

int minMovesToSort(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n, 0);
    stack<int> st; // will store indices
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int moves = 0;
        while (!st.empty() && a[i] >= a[st.top()]) {
            moves = max(moves, dp[st.top()]);
            st.pop();
        }

        if (!st.empty()) {
            dp[i] = moves + 1;
            ans = max(ans, dp[i]);
        }

        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> a = {5, 3, 4, 6, 2, 7};
    cout << minMovesToSort(a) << "\n"; // Output: 2
    return 0;
}