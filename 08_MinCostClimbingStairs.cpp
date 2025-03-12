/*Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.

Examples:

Input: cost[] = [10, 15, 20]
Output: 15
Explanation: Cheapest option is to start at cost[1], pay that cost, and go to the top.



Input: cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest option is to start on cost[0], and only step on 1s, skipping cost[3].


Constraints:
2 ≤ cost.size() ≤ 105
0 ≤ cost[i] ≤ 999

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0], prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        
        return min(prev1, prev2);
    }
};

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    if (n < 2) {
        cout << "Number of steps must be at least 2." << endl;
        return 0;
    }

    vector<int> cost(n);
    cout << "Enter the cost of each step: ";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    Solution solution;
    int result = solution.minCostClimbingStairs(cost);

    cout << "Minimum cost to reach the top: " << result << endl;

    return 0;
}
