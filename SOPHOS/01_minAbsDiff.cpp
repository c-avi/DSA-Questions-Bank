#include <bits/stdc++.h>

using namespace std;

int minSwapsForMinDiff(string s, string t) {
    if (s.length() != t.length()) {
        cerr << "Error: Input strings must have the same length." << "\n";
        return -1;
    }
    
    int N = s.length();
    
    if (N > 18) {
        return -1;
    }
    
    long long min_diff = -1;
    int min_swaps = N + 1;
    
    function<void(int, int, string, string)> solve = [&](int index, int swaps_count, string current_s, string current_t) {
        if (index == N) {
            long long s_val = stoll(current_s);
            long long t_val = stoll(current_t);
            long long diff = abs(s_val - t_val);
            
            if (min_diff == -1 || diff < min_diff) {
                min_diff = diff;
                min_swaps = swaps_count;
            } else if (diff == min_diff) {
                min_swaps = min(min_swaps, swaps_count);
            }
            return;
        }
        
        solve(index + 1, swaps_count, current_s, current_t);
        
        swap(current_s[index], current_t[index]);
        solve(index + 1, swaps_count + 1, current_s, current_t);
        swap(current_s[index], current_t[index]);
    };
    
    solve(0, 0, s, t);
    
    return min_swaps;
}

int main() {
    cout << "Enter the first string of digits (s): ";
    string s;
    cin >> s;
    
    cout << "enter the second string of digits (t): ";
    string t;
    cin >> t;
    
    auto is_digit_string = [](const string& str) {
        return all_of(str.begin(), str.end(), ::isdigit);
    };
    
    if (!is_digit_string(s) || !is_digit_string(t) || s.length() != t.length()) {
        cerr << "Invalid input: Please ensure both inputs are strings of digits and have the same length." << "\n";
        return 1;
    }
    
    int result = minSwapsForMinDiff(s, t);
    
    if (result != -1) {
        cout << "\nMinimum number of swaps required to minimize absolute difference: " << result << endl;
    } else {
        cout << "\nThe problem could not be solved efficiently due to large input size or complex constraints." << endl;
    }

    return 0;
}