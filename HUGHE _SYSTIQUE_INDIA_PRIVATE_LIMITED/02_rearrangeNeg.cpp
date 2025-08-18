#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        if (arr[left] < 0) {
            left++;
        } else {
            swap(arr[left], arr[right]);
            right--;
        }
    }
}

int main() {
    vector<int> arr = {1, -2, 3, -4, 5, -6};
    rearrange(arr);
    for (int num : arr) 
        cout << num << " ";
    cout << "\n";

    return 0;
}