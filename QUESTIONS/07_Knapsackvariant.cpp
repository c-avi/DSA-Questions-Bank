/*Question No. - 2 
Mr. Dorsey Dawson recently stole X grams of gold from ACME Jewellers. He is now on a train back home. To avoid getting caught by the police, he has
 to convert all the gold he has into paper money. He turns into a salesman and starts selling the gold in the train. There are N passengers who 
 have shown interest in buying the gold. The i(th) passenger agrees to buy a[i] grams of gold by paying v[i] dollars. Dawson wants to escape from 
 the police and also maximize the profit. Can you help him maximize the profit? Note: The i(th) passenger would buy exactly a[i] grams if the 
 transaction is successful.
 Input:
 4 10
 460 4
 590 6
 550 5
 590 5
 
 Output:
 1140*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_X 5000
#define INF LLONG_MIN // A very small value to indicate invalid states
typedef long long ll;

struct Passenger{
    int weight, value;
};

// Comparator to sort passengers in descending order of value
bool compare(Passenger a, Passenger b){
    return a.value > b.value; // Sorting in decreasing order of value
}

int main(){
    int N, X;
    cin >> N >> X;

    vector<Passenger> passengers(N);
    for (int i = 0; i < N; i++){
        cin >> passengers[i].value >> passengers[i].weight;
    }

    // Sorting passengers based on value in decreasing order
    sort(passengers.begin(), passengers.end(), compare);

    // DP array: dp[i] stores the max profit for exactly i grams
    vector<ll> dp(X+1, INF);
    dp[0] = 0; // Base case: 0 grams sold = 0 profit

    // Knapsack DP: Process each passengers offer
    for (auto p : passengers){
        int wt = p.weight, val = p.value;
        for (int j = X; j >= wt; j--){ // Reverse to prevent reusing the same offer
            if (dp[j - wt] != INF){
                dp[j] = max(dp[j], dp[j - wt] + val);
            }
        }
    }

    // If selling exactly x grams is possible, print max profit; otherwise print "got caught!"
    if (dp[X] != INF){
        cout << dp[X] << endl;
    } else{
        cout << "Got caught!" << endl;
    }

    return 0;
}
