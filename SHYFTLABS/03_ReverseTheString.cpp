#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string reverseString(string str) {
            int left = 0, right = str.length() - 1;
            while (left < right) {
                swap(str[left], str[right]);
                left++;
                right--;
            }
            return str;
        }
};

int main() {
    int T;
    cin >> T;
    cin.ignore(); // to ignore the newLine after T

    Solution obj;
    while (T--) {
        string str;
        getline(cin, str);
        cout << obj.reverseString(str) << "\n";
    }
    return 0;
}