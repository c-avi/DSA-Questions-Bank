#include <iostream>
#include <vector>
using namespace std;

vector<long long> processQueries(const vector<int>& A, const vector<pair<long long, long long>>& queries) {
    int N = A.size();
    vector<long long> prefix(N + 1, 0);

    // Build prefix sum
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    long long totaSum = prefix[N];
    vector<long long> results;

    for (const auto query : queries) {
        long long L = query.first;
        long long R = query.second;
        // convert to 0-based indexing
        L--, R--;

        long long startIndex = L % N;
        long long endIndex = R % N;
        long long fullStart = L / N;
        long long fullEnd = R / N;

        long long sum = 0;
        if (fullStart == fullEnd) {
            // Both in the same repetition
            sum = prefix[endIndex + 1] - prefix[startIndex];
        } else {
            long long part1 = prefix[N] - prefix[startIndex];
            long long part2 = (fullEnd - fullStart - 1) * totaSum; // full A's in between
            long long part3 = prefix[endIndex + 1];
            sum = part1 + part2 + part3;
        }
        results.push_back(sum);
    }
    return results;
}

int main() {

    vector<int> A = {1,2,3};
    vector<pair<long long, long long>> queries = {
        {1,3},
        {4,6},
        {2,7}
    };

    vector<long long> result = processQueries(A, queries);

    for (long long sum : result) {
        cout << sum << "\n";
    }
    return 0;
}