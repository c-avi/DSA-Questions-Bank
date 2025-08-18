#include <iostream>
#include <unordered_map>
using namespace std;

void countCharacters(const string& str) {
    unordered_map<char, int> freq;

    for (char c: str) {
        freq[c]++;
    }

    cout << "Character frequencies:\n";
    for (auto pair : freq) {
        cout << pair.first << " -> " << pair.second << "\n";
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    countCharacters(input);

    return 0;
}
