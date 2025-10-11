#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string cleaned = "";
    
    for (char c : s) {
        if (isalnum(c)) 
            cleaned += tolower(c);
    }
    
    string rev = cleaned;
    reverse(rev.begin(), rev.end());
    
    if (cleaned == rev)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    
    return 0;
}