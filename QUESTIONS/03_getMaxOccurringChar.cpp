/*Question:
Given string str. The task is to find the maximum occurring character in the string str. simple without unordered map
Input :
abcdaabcaba

Output:
a*/
#include <iostream>
using namespace std;

char getMaxOccurringChar(string str) {
    int freq[256] = {0}; // Freq array for all ASCII characters

    // Count frequency of each character
    for (char ch : str){
        freq[ch]++;
    }

    // Find the character with maximum frequency
    int maxFreq = 0;
    char maxChar = str[0]; // Initialise with the first character
    for (int i = 0; i < 256; i++){
        if(freq[i] > maxFreq){
            maxFreq = freq[i];
            maxChar = char(i);
        }
    }
    return maxChar;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Maximum occurring character: " << getMaxOccurringChar(str) << endl;
    return 0;
}
