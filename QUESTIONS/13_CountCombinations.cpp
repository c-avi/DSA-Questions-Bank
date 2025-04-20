/*Problem Statement:

Given two integers N and k, determine the total number of possible combinations of groups formed using adjacent elements from 1 to N, where each group size ranges from 2 to k.

Constraints & Rules:
Each element can only appear in one group at a time (i.e., once an element is used in a group, it cannot be reused in another group).
Groups must be formed using consecutive elements from the given range.
The size of each group must be between 2 and k (inclusive).
Example:
Input:
ini
Copy
Edit
N = 5, k = 3
Possible Groups:
vbnet
Copy
Edit
Single elements: 1, 2, 3, 4, 5  
Pairs: (1,2), (1,3), (1,4), (1,5), (2,3), (2,4), (2,5), (3,4), (3,5), (4,5)  
Triplets: (1,2,3), (1,2,4), (1,2,5), (1,3,4), (1,3,5), (1,4,5), (2,3,4), (2,3,5), (2,4,5), (3,4,5)  
Total Combinations = **25**
Output:
Copy
Edit
25
Example 2:
Input:
ini
Copy
Edit
N = 4, k = 2
Output:
Copy
Edit
10
*/
#include <iostream>
#include <vector>
using namespace std;

int countCombinations(int N, int k, int start, vector<bool> &used){
    if (k == 0) return 1; // Valid combination found

    int count = 0;
    for (int i = start; i <= N; i++){
        if (!used[i]){
            used[i] = true; // Mark as used
            count += countCombinations(N, k - 1, i + 1, used);
            used[i] = false; // backtrack
        }
    }
    return count;
}

int totalCombinations(int N, int k){
    int totalCount = 0;
    for (int size = 2; size <= k; size++){
        vector<bool> used(N+1, false);
        totalCount += countCombinations(N, size, 1, used);


    }
    return totalCount;
}

int main(){
    int N, k;
    cout << "Enter N and k: ";
    cin >> N >> k;

    int result = totalCombinations(N, k);
    cout << "Total valid combinations: " << result + N  << "\n";
    return 0;
}
