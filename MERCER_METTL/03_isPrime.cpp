#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true; // 2 is the only even prime no
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    cout << "enter a number: ";
    cin >> num;
    if (isPrime(num)) {
        cout << num << " is a prime number." << "\n";
    } else {
        cout << num << " is not a prime number." << "\n";
    }
    return 0;
}