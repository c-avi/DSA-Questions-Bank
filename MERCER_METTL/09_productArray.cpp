#include <iostream>
#include <vector>
using namespace std;

vector<long long> productExceptSelf(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> prefix(n, 1), suffix(n, 1), product(n);

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    for (int i = n -2; i >= 0; --i) {
        suffix[i] = suffix[i + 1] * arr[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        product[i] = prefix[i] * suffix[i];
    }

    return product;
}

int main() {
    vector<int> arr = {1,2,3,4};
    vector<long long> result = productExceptSelf(arr);

    cout << "Product array:\n";
    for (long long val : result) {
        cout << val << " ";
    }
    cout << "\n"; 
    
    return 0;
}