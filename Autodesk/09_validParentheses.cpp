#include <bits/stdc++.h>
using namespace std;

bool isValidParentheses(const string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch ==']') {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if (ch == ')' && top != '(') return false;
            if (ch == '}' && top != '{') return false;
            if (ch == ']' && top != '[') return false;
        } else {
            continue;
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter the string to validate: ";
    getline(cin, s);

    bool valid = isValidParentheses(s);
    if (valid)
        cout << "The string is VALID (balanced parentheses)." << "\n";
    else
        cout << "The string is INVALID (unbalanced parentheses)." << "\n";
        
    return 0;
}