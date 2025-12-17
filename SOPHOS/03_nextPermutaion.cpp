#include <bits/stdc++.h>
using namespace std;

void nextPermutation(string& s) {
    int n = s.length();
    if (n <= 1) return;
    
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    
    if (i >= 0) {
        int j = n - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        
        swap(s[i], s[j]);
    }
    
    reverse(s.begin() + i + 1, s.end());
}

int main() {
    string s;
    cout << "enter a string: ";
    cin >> s;
    
    nextPermutation(s);
    
    cout << "Next lexicographical permutation: " << s << "\n";
    
    return 0;
}