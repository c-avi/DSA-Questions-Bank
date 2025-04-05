#include <iostream>
using namespace std;

// Function to calculate gcd using Eucledian algorithm
int findGcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate lcm using formula: (a * b)/gcd
int findLcm(int a, int b) {
    return (a * b) / findGcd(a, b);
}

int main(){
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int gcd = findGcd(num1, num2);
    int lcm = findLcm(num1, num2);

    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;
    
    return 0;
}