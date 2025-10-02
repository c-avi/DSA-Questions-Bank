#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0, minLen = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main () {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;
    
    int result = minSubArrayLen(target, arr);
    if (result == 0)
        cout << "No subarray with sum >= " << target << " exists.\n";
    else 
        cout << "Minimal leb=ngth of subarray = " << result << "\n";

    return 0;
}