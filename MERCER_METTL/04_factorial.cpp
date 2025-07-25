#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);

}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers.";
    else 
        cout << "Factorial of " << num << " is " << factorial(num);
    return 0;
}