#include <iostream>
using namespace std;

int main() {
    int num, reversed = 0;
    cout << "Enter number: ";
    cin >> num;

    while (num != 0) {
        int digit = num % 10;
        reversed += reversed * 10 + digit;
        num = num / 10;
    }
    cout << "Reversed num: " << reversed << endl;
    return 0;
}
