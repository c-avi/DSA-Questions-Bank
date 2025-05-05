#include <iostream>
#include <vector>
using namespace std;

// Store the results
vector<string> result;

// Recursivefunction to generate strings
void generate(string current, int targetLength, const vector<char>& chars) {
    if (current.length() == targetLength) {
        result.push_back(current);
        return;
    }

    for (char ch : chars) {
        if (current.empty() || ch != current.back()) {
            generate(current + ch, targetLength, chars);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of characters to use (e.g., 3 for a, b, c): ";
    cin >> n;

    if (n < 1 || n > 26) {
        cout << "Invalid input. Enter between 1 and 26.\n";
        return 0;
    }

    // Create character set from 'a' to ('a' + n - 1)
    vector<char> chars;
    for (int i = 0; i < n; ++i) {
        chars.push_back('a' + i);
    }

    // Generate strings of length 1 to n
    for (int len = 1; len <= n; ++len) {
        result.clear();
        generate("", len, chars);

        cout << "Strings of length " << len << ":\n";
        for (const string&s : result) {
            cout << s << "\n";
        }
        cout << "\n";
    }
    return 0;
}