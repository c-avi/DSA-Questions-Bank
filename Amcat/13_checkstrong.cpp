/*💡 What is a Strong Number?
A number is said to be a Strong Number if the sum of the factorials of its digits is equal to the number itself.

Example:
145 → 1! + 4! + 5! = 1 + 24 + 120 = 145 ✅*/

#include <iostream>
using namespace std;

// Function to calculate factorial of a digit
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to check if a number is a strong number
bool isStrong(int num) {
    int sum = 0, temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    return sum == num;
}

int main() {
    int n;
    cout << "Enter upper limit: ";
    cin >> n;

    cout << "Strong numbers between 1 to " << n << " are: ";
    for (int i = 1; i <= n; i++) {
        if (isStrong(i)) cout << i << " ";
    }
    return 0;
}