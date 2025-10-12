#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    int count = 0;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        string lower = line;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if(lower.find("error") != string::npos)
            count++;
    }
    cout << count;
    return 0;
}