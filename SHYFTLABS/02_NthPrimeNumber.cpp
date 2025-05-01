#include <bits/stdc++.h>
using namespace std;

// Initialzing the max_value
#define MAX_SIZE 1000005

// Function to generate N prime numbers using Sieve of Eratosthenes
void sieveOfEratosthenes(vector<int>& primes) {
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));

    for (int p = 2; p * p < MAX_SIZE; p++) {
        if (IsPrime[p] == true) {
            for (int i = p * p; i < MAX_SIZE; i += p)
                IsPrime[i] = false;
        }
    }
    // Store all prime numbers
    for (int p = 2; p < MAX_SIZE; p++)
        if (IsPrime[p])
            primes.push_back(p);
}

int main() {
    // to store all the primes
    vector<int> primes;

    sieveOfEratosthenes(primes);

    cout << "5th prime number is " << primes[4] << "\n";
    return 0;
}