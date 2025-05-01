#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<string> arr = {"banana", "apple", "cherry", "date"};

    // Sort the array
    sort(arr.begin(), arr.end());

    // Print the sorted array
    cout << "Sorted array of strings:\n";
    for (const string& str : arr) {
        cout << str << " ";
    }

    return 0;
}