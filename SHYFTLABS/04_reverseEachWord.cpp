#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string reverseWordsInSentence(const string& sentence) {
    stringstream ss(sentence);
    string word, result;
    while (ss >> word) {
        reverse(word.begin(), word.end());
        result += word + " ";
    }
    // Remove trailing space 
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}
int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string reversed = reverseWordsInSentence(sentence);
    cout << "Output: " << reversed << "\n";

    return 0;
}