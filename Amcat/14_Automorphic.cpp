/*🔢 What is an Automorphic Number?
A number is Automorphic if its square ends with the same digits as the number itself.

Examples:

5 → 5² = 25 → ends with 5 ✅

76 → 76² = 5776 → ends with 76 ✅*/
#include <iostream>
#include <cmath>
using namespace std;

bool isAutomorphic(int num) {
    int square = num * num;

    // Count number of digits in num
    int digits = 0;
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Get last digits of the squared number
    int lastDigits = square % (int)pow(10,digits);

    return lastDigits == num;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isAutomorphic(num)) cout << num << " is AUTOMPORPHIC!\n";
    else cout << num << " is NOT AUTOMPORPHIC!\n";
    return 0;
}