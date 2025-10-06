#include <bits/stdc++.h>
using namespace std;

bool isSpecial(const string &s) {
    int n = s.size();
    if (n < 2) return false;

    for (int i = 1; i < n; ++i) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);

        if (all_of(s1.begin(), s1.end(), [&](char c) {return c == s1[0]; }) && 
        all_of(s2.begin(), s2.end(), [&](char c){ return c == s2[0]; })) {
        return true;
        }
    }
    return false;

}

int main () {
    int t;
    cin >> t;
    cin.ignore();
    int count = 0;
    while (t--) {
        string s;
        getline(cin, s);
        if ( isSpecial(s)) count++;
    }
    cout << count << "\n";
    
    return 0;
}