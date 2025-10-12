#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int sum = 0, above = 0;
    int fast = INT_MAX, slow = INT_MIN;
    
    for (int x : a) {
        sum += x;
        if (x > 1000) above++;
        fast = min(fast, x);
        slow = max(slow, x);
        
    }
    
    cout << "Average: " << sum / n << "\n";
    cout << "Above 1000: " << above << "\n";
    cout << "Fastest: " << fast << "\n";
    cout << "Slowest: " << slow << "\n";
    
    return 0;
}