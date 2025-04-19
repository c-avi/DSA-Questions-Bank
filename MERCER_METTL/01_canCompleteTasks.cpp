#include <iostream>
#include <cmath>
using namespace std;

string canCompleteTasks(int N, int n, int d, int d2, int D) {
    // Calculate number of batches required
    int batches = (ceil)((double)N/n);

    // Total time required: batches x (2d + 2 + d2)
    int total_time = batches * (2 * d + 2 + d2);
 
    if (total_time <= D) {
        return "Yes " + to_string(total_time);
    } else {
        return "No " + to_string(total_time - D);
    }
}

int main() {
    // Sample input 
    int N, n, d, d2, D;

    cout << "Enter taks(N), n (developers per group), d, d2, D(max days): ";
    cin >> N >> n >> d >> d2 >> D;

    string result = canCompleteTasks(N, n, d, d2, D);
    cout << result << endl;

    return 0;
}