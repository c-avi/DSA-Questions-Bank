#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int first = INT_MIN, second = INT_MIN;
    
    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num > second && num < first) {
            second = num;
        }
    }
    
    if (second == INT_MIN)
        cout << -1;
    else
        cout << second;

    return 0;
}