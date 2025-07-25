#include <iostream>
using namespace std;

int maxDifference(int arr[], int n) {
    int maxDiff = arr[1] - arr[0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int diff = arr[j] - arr[i];
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
    }

    return maxDiff;
}

int main() {
    int arr[] = {2,3,10,6,4,8,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximium Difference: " << maxDifference(arr, n) << " ";
    return 0;
}