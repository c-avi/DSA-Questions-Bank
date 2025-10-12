#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> failed;
    for (int i = 0; i < n; i++) {
        string name, status;
        cin >> name >> status;
        if (status == "FAIL") failed.push_back(name);
    }
    sort(failed.begin(), failed.end());
    cout << "Failed Tests:\n";
    for(string &x : failed) cout << x << "\n";
    return 0;
}