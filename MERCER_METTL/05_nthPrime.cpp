#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num == 2) 
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int nthPrime(int n) {
    int count = 0;
    int num = 2;

    while (true) {
        if (isPrime(num)) {
            count++;
            if (count == n)
                return num;
        }
        num++;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "The " << n << "th prime number is: " << nthPrime(n) << "\n";
    return 0;
}