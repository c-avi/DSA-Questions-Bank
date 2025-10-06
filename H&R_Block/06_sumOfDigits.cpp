#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int x;
    cin >> x;

    while(true) {
        if (sumOfDigits(x) % 4 == 0) {
            cout << x << "\n";
            break;
        }
        x++;
    }

    return 0;
}
