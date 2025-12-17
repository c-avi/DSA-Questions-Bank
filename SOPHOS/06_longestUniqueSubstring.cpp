#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string s) {
    int n  = s.length();
    int left = 0, max_len = 0; 
    unordered_map<char, int> char_map;
    
    for (int right = 0; right < n; right++) {
        if (char_map.find(s[right]) != char_map.end()) {
            left = max(left, char_map[s[right]] + 1);
        }
        
        char_map[s[right]] = right;
        max_len = max(max_len, right - left + 1);
    }
    
    return max_len;
}

int main() {
    string s;
    cin >> s;
    
    cout << longestUniqueSubstring(s);
    
    return 0;
}