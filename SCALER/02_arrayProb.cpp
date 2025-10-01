#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int K) {
    unordered_map<int, int> prefixIndex;
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == K) {
            maxLen = max(maxLen, i + 1);
        }

        if (prefixIndex.find(prefixSum - K) != prefixIndex.end()) {
            int len = i - prefixIndex[prefixSum - K];
            maxLen = max(maxLen, len);
        }

        if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
            prefixIndex[prefixSum] = i;
        }
    }
    return maxLen;
}

int main() {
    int n, K;
    cout << "enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of K: ";
    cin >> K;

    int ans = longestSubarrayWithSumK(arr, K);
    cout << "Length of longest subarray with sum " << K << " = " << ans << "\n";
    
    return 0;
}