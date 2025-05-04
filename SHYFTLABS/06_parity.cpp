#include <iostream>
#include <vector>

using namespace std;

// function to count set bits
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to process array according to parity of set bits
vector<int> modifyByParity(const vector<int>& arr) {
    vector<int> result;
    for (int num : arr) {
        int setBits = countSetBits(num);
        if(setBits % 2 == 0) {
            result.push_back(num + 1); // Even parity -> add 1
        } else {
            result.push_back(num); // Odd parity -> keep as is
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<int> output = modifyByParity(arr);

    // Print result vector
    cout << "Modified vector: ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}