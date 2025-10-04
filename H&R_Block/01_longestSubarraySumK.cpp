#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumK(vector<int>& arr, int K) {
    unordered_map<int, int> prefixIndex;
    int prefixSum = 0, maxLen = 0;
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
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int K = 15;
    cout << "Longest Subarray Length = " << longestSubarraySumK(arr, K) << "\n";
    return 0;
}