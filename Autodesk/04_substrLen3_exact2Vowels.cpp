#include <iostream>
#include <string>
using namespace std;

// Helper function to check if a character is a vowel
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

int solution(string text) {
    int count = 0;

    if (text.length() < 3) return 0; // Avoid invalid substring calls

    // Traverse all substrings of length 3
    for (int i = 0; i <= text.length() - 3; i++) {
        string sub = text.substr(i, 3);
        int vowelCount = 0;

        // Count vowels in substring
        for (char ch : sub) {
            if (isVowel(ch)) {
                vowelCount++;
            }
        }

        // if exactly two vowels,increment count
        if (vowelCount == 2) {
            count++;
        }
    }
    return count;
}

// Example usage 
int main() {
    string text1 = "aeiobe";
    cout << "Result for 'aeiobe': " << solution(text1) << "\n"; // Output:2

    string text2 = "banana";
    cout << "Result for 'banana': " << solution(text2) << "\n"; // Output:2

    string text3 = "";
    cout << "Result for '': " << solution(text3) << "\n"; // Output:0
    
    return 0;
}