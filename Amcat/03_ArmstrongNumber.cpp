#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, originalNum, remainder, n = 0;
    double result = 0.0;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;

    // Count number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;

    // Calculate the sum of nth power of its digit
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow (remainder, n);
        originalNum /= 10;
    }

    // Check if the number is armstrong
    if (static_cast<int>(result) == num) {
        cout << num << " is an armstrong number." << endl;
    } else {
        cout << num << " is not an armstrong number." << endl;
    }
    return 0;
}