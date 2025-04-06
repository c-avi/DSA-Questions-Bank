#include <iostream>
using namespace std;

int main() {
    int num;
    unsigned long long factorial = 1;

    cout << "Enter a positive number: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for NEGATIVE numbers.\n";
    } else {
        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }
        cout << "Factorial of " << num << " is: " << factorial;
    }
    return 0;
}