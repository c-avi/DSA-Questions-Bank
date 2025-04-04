/*Tyler durden is a salesperson and is assigned a task to travel to sell soaps. He must travel to different countries with S states each. His manager has also provided him with an integer array of A, of length N. Array A represents a rating list which shows the past sales in a certain state. Below are a few ules for him to follow to increase the efficiency of his travel :-


tyler should begin his travel from the state which has the lowest rating
when he starts his travel in a country, he should visit all the states in that country before going to a different country
Your task is to help tyler plan his travel route and return an integer value representing the country and the rating of the state tyler will be travelling to in month M based on the rating list.


NOTE -


The rating list contains data for all the states together, so the first S ratings are for country 1, the next S ratings are for country 2 and so on.
The month count starts from 1 and if two or more countries have same lowest rating then choose the country whose states has the second lowest rating.
Input -
Input1 : An integer value N, representing the length of rating list
Input2 : An integer value S, representing the number of states in a country
Input3 : An integer value M, representing the month numbers
Input4 : An integer array A, representing the rating list


Output -
Output1 : Return the country tyler will be travelling to in month M based on the rating list
Output2 : Return the state tyler will be travelling to in month M based on the rating list


Example 1 -
Input1 : 6
Input2 : 3
Input3 : 6
Input4 : {2, 1, 9, 3, 1, 4}


Output1 : 2
Output2 : 4


Explanation - there are 6 states, and each country has 3 states.
route will be country 1 --> country 2 (since the lowest rating is same in both the countries, we look at the second lowest rating and thus tyler will start his travel with country 1)


country 1 : 1 ---> 2 ---> 9
country 2 : 1 ---> 3 ---> 4
using this tyler will be in country 2 and state 4 during the 6th month.
Example 2 -
Input1 : 12
Input2 : 3
Input3 : 7
Input4 : {4, 5, 7, 9, 3, 2, 5, 1, 3, 2, 4, 1}


Output1 : 2
Output2 : 2


Explanation - there are 12 states, and each country has 3 states.
route will be country 4 --> country 3 --> country 2 ---> country 4 (since the lowest rating is same in countries 4 and 3, we look at the second lowest rating and thus tyler will start his travel with country 4)


country 4 : 1 ---> 2 ---> 4
country 3 : 1 ---> 3 ---> 5
country 2 : 2 ---> 3 ---> 9
country 1 : 4 ---> 5 ---> 7
using this tyler will be in country 2 and state 2 during the 7th month.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Define the structure to store the result
struct Result {
    int output1;  // Country number
    int output2;  // State rating
};

// Function to determine Tyler's travel route
Result profitDevelopment(int N, int S, int M, vector<int>& A) {
    int numCountries = N / S;
    vector<vector<int>> countries(numCountries);

    // Step 1: Divide states into countries
    for (int i = 0; i < N; i++) {
        countries[i / S].push_back(A[i]);
    }

    // Step 2: Find the country with the lowest rating
    vector<pair<int, int>> minRatings;  
    vector<pair<int, int>> secondMinRatings;  

    for (int i = 0; i < numCountries; i++) {
        vector<int> &states = countries[i];
        sort(states.begin(), states.end());

        minRatings.push_back({states[0], i + 1});
        secondMinRatings.push_back({states[1], i + 1});
    }

    sort(minRatings.begin(), minRatings.end());
    int chosenCountry = minRatings[0].second;

    // If multiple countries have the same min rating, resolve by second min rating
    vector<int> candidateCountries;
    for (auto &p : minRatings) {
        if (p.first == minRatings[0].first)
            candidateCountries.push_back(p.second);
    }

    if (candidateCountries.size() > 1) {
        vector<pair<int, int>> filteredSecondMins;
        for (auto &p : secondMinRatings) {
            if (find(candidateCountries.begin(), candidateCountries.end(), p.second) != candidateCountries.end()) {
                filteredSecondMins.push_back(p);
            }
        }
        sort(filteredSecondMins.begin(), filteredSecondMins.end());
        chosenCountry = filteredSecondMins[0].second;
    }

    // Step 3: Determine travel order
    vector<int> travelSequence;
    vector<int> visitedCountries;

    while (visitedCountries.size() < numCountries) {
        int currentCountry = chosenCountry - 1;  
        vector<int> sortedStates = countries[currentCountry];
        sort(sortedStates.begin(), sortedStates.end());
        travelSequence.insert(travelSequence.end(), sortedStates.begin(), sortedStates.end());

        visitedCountries.push_back(chosenCountry);

        int nextCountry = -1;
        for (auto &p : minRatings) {
            if (find(visitedCountries.begin(), visitedCountries.end(), p.second) == visitedCountries.end()) {
                nextCountry = p.second;
                break;
            }
        }

        if (nextCountry == -1) break;
        chosenCountry = nextCountry;
    }

    // Step 4: Find Mth state
    int targetState = travelSequence[M - 1];

    return {chosenCountry, targetState};
}

// Main function for testing
int main() {
    int N, S, M;
    cin >> N >> S >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    Result res = profitDevelopment(N, S, M, A);
    cout << res.output1 << endl;
    cout << res.output2 << endl;

    return 0;
}