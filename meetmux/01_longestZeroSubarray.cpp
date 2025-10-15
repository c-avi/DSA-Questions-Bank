#include <bits/stdc++.h>
using namespace std;

int longestZeroSumSubarray(vector<int> &arr) {
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        if (sum == 0)
            maxLen = i + 1;
            
        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    
    return maxLen;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << longestZeroSumSubarray(arr);
    return 0; 
}