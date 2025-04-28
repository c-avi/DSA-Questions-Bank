#include <iostream>
#include <string>
using namespace std;

int countGoodTriplets(string s) {
    int count = 0;
    int n = s.length();
    
    for (int i = 0; i <= n - 3; ++i) {
        if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    string s = "xyzzaz";
    cout << countGoodTriplets(s) << endl;
    return 0;
}
