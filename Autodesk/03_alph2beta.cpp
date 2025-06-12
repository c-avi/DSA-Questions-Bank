#include <iostream>
#include <vector>
using namespace std;

// Function to find the earliest available shuttle after currentTime
int findNextShuttle(const vector<int>& schedule, int currentTime) {
    for (int t : schedule) {
        if (t >= currentTime) {
            return t;
        }
    }
    // This shouldn't happen as per problem guarantees
    return -1;
}

int solution(vector<int> alpha2beta, vector<int> beta2alpha, int missions) {
    int currentTime = 0;

    for (int i = 0; i < missions; i++) {
        // Step 1: From Alpha to Beta
        int depAlpha = findNextShuttle(alpha2beta, currentTime);
        int arriveBeta = depAlpha + 100;

        // Step 2: From Beta to Alpha
        int depBeta = findNextShuttle(beta2alpha, arriveBeta);
        currentTime = depBeta + 100;
    }

    return currentTime;
}

// Example usage
int main() {
    vector<int> alpha2beta1 = {0, 200, 500};
    vector<int> beta2alpha1 = {99, 210, 450};
    cout << "Test 1: " << solution(alpha2beta1, beta2alpha1, 1) << endl; // 310

    vector<int> alpha2beta2 = {109, 200, 500};
    vector<int> beta2alpha2 = {99, 210, 600};
    cout << "Test 2: " << solution(alpha2beta2, beta2alpha2, 2) << endl; // 700

    vector<int> alpha2beta3 = {5, 206};
    vector<int> beta2alpha3 = {105, 306};
    cout << "Test 3: " << solution(alpha2beta3, beta2alpha3, 2) << endl; // 406

    return 0;
}