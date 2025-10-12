#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pass = 0, fail = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "PASS" || s == "pass") pass++;
        else fail++;
    }
    cout << "Total: " << n << "\n";
    cout << "Passed: " << pass << "\n";
    cout << "Failed: " << fail << "\n";
    cout << "Pass%: " << (pass * 100 / n);
    return 0;
}