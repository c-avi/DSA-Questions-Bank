#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c: s) {
        if (pairs.find(c) == pairs.end()) {
            st.push(c);
        } else {
            if (st.empty() || st.top() != pairs[c])
                return "Not Balanced";
            st.pop();
        }
    }
    return st.empty() ? "Balanced" : "Not Balanced";
}

int main() {
    string s;
    cin >> s;
    cout << isBalanced(s);
    return 0;
} 