#include <bits/stdc++.h>
using namespace std;


vector<int> preGreaterEle(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> result(n, -1);
    
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            result[i] = st.top();
        }
        
        st.push(arr[i]);
    }
    
    return result;
}
int main() {
    vector<int> arr = {10, 4, 2, 20, 40, 12};
    vector<int> pge = preGreaterEle(arr);
    
    for (int x : pge) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}