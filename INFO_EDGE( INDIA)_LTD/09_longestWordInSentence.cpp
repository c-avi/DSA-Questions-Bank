#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    string word, longest = "";
    while (ss >> word) {
        if (word.size() > longest.size()) longest = word;
    }
    cout << "Longest word: " << longest << "\n";
    cout << "Length: " << longest.size() << "\n";
    return 0;
}