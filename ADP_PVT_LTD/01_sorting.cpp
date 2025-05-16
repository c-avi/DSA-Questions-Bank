#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;

    // Get the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Print the sorted array
    cout << "Sorted arrat:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout <<"\n";

    return 0;
}