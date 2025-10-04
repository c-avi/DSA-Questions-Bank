#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string s1, string s2) {
    vector<int> freq(256, 0);

    for (char c: s1) 
        if (c != ' ') freq[tolower(c)]++;
    
    for (char c : s2)
        if (c != ' ') freq[tolower(c)]--;

    for (int count : freq)
        if (count != 0) return false;

    return true;

}

int main() {
    string s1 = "Listen";
    string s2 = "Silent";

    cout << (areAnagrams(s1, s2) ? "Anagrams" : "Not Anagrams") << "\n";
    return 0;
}