#include <iostream>
using namespace std;

int main() {
    int num, i;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> num;

    if (num <= 1) {
        isPrime = false;
    } else {
        for (i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        cout << num << " is a PRIME number.\n";
    } else{
        cout << num << " is a NON PRIME number.\n";
    }
    return 0;
}