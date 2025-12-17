#include <bits/stdc++.h>
using namespace std;


long long maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    
    long long window_sum = 0;
    
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    
    long long max_sum = window_sum;
    
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}
int main() {
    int n, k;
    cout << "Enter array size and window size K: ";
    cin >> n >> k;
    
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Maximum sum of size " << k << " is: " << maxSubarraySum(arr, k) << "\n";
    return 0;
}