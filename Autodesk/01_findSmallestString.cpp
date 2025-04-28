#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string findSmallestString(string word) {
    string smallest = word;
    int n = word.length();
    
    for (int k = 1; k <= n; ++k) {
        // Reverse first k characters
        string temp1 = word;
        reverse(temp1.begin(), temp1.begin() + k);
        if (temp1 < smallest) {
            smallest = temp1;
        }
        
        // Reverse last k characters
        string temp2 = word;
        reverse(temp2.end() - k, temp2.end());
        if (temp2 < smallest) {
            smallest = temp2;
        }
    }
    
    return smallest;
}

int main() {
    string word = "cbad";
    cout << findSmallestString(word) << endl;
    return 0;
}
