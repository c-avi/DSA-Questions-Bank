#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    unordered_map<int, int> freq;
    int count = 0;
    
    for (int x : arr) {
        if (freq.find(k-x) != freq.end())
            count += freq[k - x];
        freq[x]++;
    }
    
    cout << count;
    return 0;
}