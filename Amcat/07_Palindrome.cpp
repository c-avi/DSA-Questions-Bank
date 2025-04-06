#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter string or number : ";
    cin >>  str;

    string original = str;
    int n = str.length();

    // Reverse the string
    for (int i = 0; i < n / 2; i++) {
        swap (original[i], original[n - i - 1]);
    }
    
    if (str == original) {
        cout << str  << " is a Palindrome!\n";
    } else {
        cout << str << " is NOT a Palindrome!\n"; 
    }
    return 0;
}