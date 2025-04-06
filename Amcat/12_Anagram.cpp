/*💡 What is an Anagram?
Two strings are anagrams if they contain the same characters with the same frequency, just in a different order.*/
#include <iostream>
#include <algorithm>
#include <cctype> // for tolower and is alpha
using namespace std;

// Function to clean and normalize a string
string normalize(string str) {
    string result = "";
    
    for (char ch: str) {
        if (isalpha(ch)) {
            result += tolower(ch); // convert to lowercase
        }
    }

    sort(result.begin(), result.end()); // sort characters
    return result;
}
bool areAnagrams(string str1, string str2) {
    // If lengths are not equal they can't be anagrams
    if (str1.length() != str2.length()) return false;

    return normalize(str1) == normalize(str2);
}

int main() {
    string st1, st2;

    cout << "Enter first string: ";
    getline(cin, st1); // use getline to allow spaces
    
    cout << "Enter second string: ";
    getline(cin, st2);

    if (areAnagrams(st1, st2))
        cout << "Strings are ANAGRAMS!\n";
    else
        cout << "Strings are NOT ANAGRAMS!\n";
    return 0;
}