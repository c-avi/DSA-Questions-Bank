#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    
    if (s.empty()) {
        cout << "";
        return 0;
    }
    
    string result;
    int count = 1;
    
    for (size_t i = 1; i <= s.size(); i++) {
        if (i < s.size() && s[i] == s[i - 1])
            ++count;
        else {
            result.push_back(s[i-1]);
            if (count > 1) result += to_string(count);
            count = 1;
        }
    }
    
    cout << result << '\n';
    
    return 0;  
}