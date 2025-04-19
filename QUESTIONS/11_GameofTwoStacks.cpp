/*Alexa has two stacks of non-negative integers, stack  and stack  where index  denotes the top of the stack. Alexa challenges Nick to play the following game:

In each move, Nick can remove one integer from the top of either stack  or stack .
Nick keeps a running sum of the integers he removes from the two stacks.
Nick is disqualified from the game if, at any point, his running sum becomes greater than some integer  given at the beginning of the game.
Nick's final score is the total number of integers he has removed from the two stacks.
Given , , and  for  games, find the maximum possible score Nick can achieve.

Example


The maximum number of values Nick can remove is . There are two sets of choices with this result.

Remove  from  with a sum of .
Remove  from  and  from  with a sum of .
Function Description
Complete the twoStacks function in the editor below.

twoStacks has the following parameters: - int maxSum: the maximum allowed sum
- int a[n]: the first stack
- int b[m]: the second stack

Returns
- int: the maximum number of selections Nick can make

Input Format

The first line contains an integer,  (the number of games). The  subsequent lines describe each game in the following format:

The first line contains three space-separated integers describing the respective values of  (the number of integers in stack ),  (the number of integers in stack ), and  (the number that the sum of the integers removed from the two stacks cannot exceed).
The second line contains  space-separated integers, the respective values of .
The third line contains  space-separated integers, the respective values of .
Constraints

Subtasks

 for  of the maximum score.
Sample Input 0

1
5 4 10
4 2 4 6 1
2 1 8 5
Sample Output 0

4
Explanation 0

The two stacks initially look like this:

image

The image below depicts the integers Nick should choose to remove from the stacks. We print  as our answer, because that is the maximum number of integers that can be removed from the two stacks without the sum exceeding .

image

(There can be multiple ways to remove the integers from the stack, the image shows just one of them.)*/

#include <bits/stdc++.h>
using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int sum = 0, count = 0, i = 0, j = 0;

    // Take elements from stack 'a' as long as sum is within limit
    while (i < a.size() && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }
    count = i; // Initial max count using only stack 'a'

    // Now try adding elements from stack 'b'
    while (j < b.size() && i >= 0) {
        sum += b[j];
        j++;

        // If sum exceeds maxSum, remove elements from 'a'
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        // Update max count
        if (sum <= maxSum)
            count = max(count, i + j);
    }

    return count;
}

int main() {
    int g;
    cin >> g; // Number of games

    while (g--) {
        int n, m, maxSum;
        cin >> n >> m >> maxSum;
        
        vector<int> a(n), b(m);
        
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        cout << twoStacks(maxSum, a, b) << endl;
    }

    return 0;
}
