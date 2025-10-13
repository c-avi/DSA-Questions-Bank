#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    
    int n;
    cin >> s >> n;
    
    string full = s;
    for (int i = 1; i < n; i++) {
        full += s;
    }
    
    bool fromStart = true;
    while (full.size() > 1) {
        string temp = "";
        if (fromStart) {
            for (int i = 1; i < full.size(); i+=2) {
                temp+= full[i];
            }
        } else {
            for (int i = full.size() - 2; i >= 0; i -=2) {
                temp = full[i] + temp;
            }
        }
        full = temp;
        fromStart = !fromStart;
    }
    
    cout << full << "\n";
    return 0;
}