//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        int MAX = 1e6 + 1;
        vector<bool> isPrime(MAX, true);
        isPrime[0] = isPrime[1] = false;
        
        
        // Sieve of Eratosthenes
        for (int i = 2; i * i < MAX; ++i) {
            if (isPrime[i]) {
                for (int  j  = i * i; j < MAX; j += i)
                    isPrime[j] = false;
            }
        }
        
        // Step 2: store square of primes
        vector<long long> squares;
        for (int i = 2; i < MAX; ++i) {
            if (isPrime[i]) {
                squares.push_back(1LL * i * i);
            }
        }
        
        // Step 3: for each query, count how many squares <= n
        vector<int> result;
        for (int i = 0; i < q; ++i) {
            long long n = query[i];
            // upper_bound gives the first index with value > n
            int count = upper_bound(squares.begin(), squares.end(), n) - squares.begin();
            result.push_back(count);
        }
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends