#include <bits//stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> A(n);
    vector<long long> P(n);
    
    cout << "enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    P[0] = A[0];
    for (int i = 1; i < n; i++) {
        P[i] = P[i - 1] + A[i];
    }
    
    int L, R;
    cout << "Enter range L and R (0-indexed): ";
    cin >> L >> R;
    
    long long rangeSum = (L == 0) ? P[R] : P[R] - P[L - 1];
    
    cout << "Sum of elements from index " << L << " to " << R << " is: " << rangeSum << "\n";
    
    return 0;
}