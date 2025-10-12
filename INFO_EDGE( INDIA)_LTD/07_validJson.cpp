// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isDigit(char c) { return c >= '0' && c <= '9'; }

int parseString(const string &s, int i) {
    int n = s.size();
    if (i >= n || s[i] != '"') return -1;
    i++;
    while (i < n) {
        if (s[i] == '"') return i + 1;
        i++;
    }
    return -1;
}

int parseNumber(const string &s, int i) {
    int n = s.size();
    if (i >= n) return -1;
    
    if (s[i] == '-') i++;
    bool hasDigits = false;
    while (i < n && isDigit(s[i])) { i++; hasDigits = true; }
    if ( i < n && s[i] == '.') {
        i++;
        bool fracDigits = false;
        while (i < n && isDigit(s[i])) {i++; fracDigits = true; }
        if (!fracDigits && !hasDigits) return -1;
    }
    return hasDigits ? i : -1;
}

void skipSpaces(const string &s, int &i) {
    int n = s.size();
    while (i < n && isspace((unsigned char)s[i])) i++;
}

bool validateObject(const string &s) {
    int n = s.size();
    int i = 0;
    skipSpaces(s, i);
    if (i >= n || s[i] != '{') return false;
    i++;
    skipSpaces(s, i);
    
    if (i < n && s[i] == '}') {i++; skipSpaces(s, i); return i == n; }
    
    while (i < n) {
        skipSpaces(s, i);
        
        int next = parseString(s, i);
        if (next == -1) return false;
        i = next;
        skipSpaces(s, i);
        
        if ( i >= n  || s[i] != ':') return false;
        i++;
        skipSpaces(s, i);
        
        if (i < n && s[i] == '"') {
            next = parseString(s, i);
            if (next == -1) return false;
            i = next;
        } else if (i < n && (s[i] == '-' || isDigit(s[i]))) {
            next = parseNumber(s, i);
            if (next == -1) return false;
            i = next;
        } else if (i + 3 < n && s.substr(i, 4) == "true") {
            i += 4;
        } else if (i + 4 < n && s.substr(i,5) == "false") {
            i += 5;
        } else if (i + 3 < n && s.substr(i, 4) == "null") {
            i += 4;
        } else {
            return false;
        }
        
        skipSpaces(s,i);
        
        if (i < n && s[i] == ',') {
            i++;
            skipSpaces(s, i);
            
            if (i >= n) return false;
            continue;
        } else if (i < n && s[i] == '}') {
            i++;
            skipSpaces(s,i);
            return i == n;
        } else {
            return false;
        }
    }
    return false;
}
int main() {
    string s;
    if (!getline(cin, s)) return 0;
    cout << (validateObject(s) ? "Valid" : "Invalid") << "\n";
    
    return 0;
}