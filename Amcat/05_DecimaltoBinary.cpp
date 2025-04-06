#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    int binary[32]; // array ot store binary number
    int i = 0;

    if (n == 0) {
        cout << "Binary: 0";
        return;
    }

    // Store remainders
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary in reverse
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }

} 

int main() {
    int num;

    cout << "Enter a decimal number: ";
    cin >> num;

    decimalToBinary(num);
    
    return 0;
}