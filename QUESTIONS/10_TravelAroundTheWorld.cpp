/*There are N cities and N directed roads in Steven's world. The cities are numbered from 0 to N - 1. Steven can travel from city i to city (i + 1)
% N, ( 0-> 1 -> 2 -> .... -> N - 1 -> 0). Steven wants to travel around the world by car. The capacity of his car's fuel tank is C gallons. There
are a[i] gallons he can use at the beginning of city i and the car takes b[i] gallons to travel from city i to (i + 1) % N. How many cities can 
Steven start his car from so that he can travel around the world and reach the same city he started? Note The fuel tank is initially empty.
Input:
3 3
3 1 2
2 2 2

Output:
2*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
  
typedef long long lld;
  
lld travelAroundTheWorld(int N, lld C, int* a, int* b) {
    //Write your code here

    // Step 1: extend city information
    // Since roads form the circular path we duplicate the a[] and b[] arrays to simulate linear traversal for easier calculations.
    int* need = (int*)malloc(2 * N * sizeof(int));
    int* extended_a = (int*)malloc(2 * N * sizeof(int));
    int* extended_b = (int*)malloc(2 * N * sizeof(int));

    for (int i = 0; i < N; i++){
        extended_a[i] = extended_a[i + N] = a[i];
        extended_b[i] = extended_b[i + N] = b[i];
    }
    // This allows us to traverse twice the size of original cycle and handle wraparounds easily. 

    // Step 2: Find the first possible starting point
    // we simulate the travel while keeping the track of the fuel
    int s = 0;
    lld tank = 0;
    for (int i = 0; i < 2 * N; ++i){
        tank += extended_a[i]; // refuel at city i
        tank = (tank < C) ? tank : C; // Cap the tank to C gallons
        tank -= extended_b[i]; // Travel to the next city

        if (tank < 0){
            // If we ran out of fuel we cannot start from any of the past cities
            tank = 0;
            s = i + 1;
        }
    }
    // If s>=N then non valid starting cities exist, so return 0;
    if (s >= N) return 0;

    // Step 3: Count valid starting cities
    // We traverse backwards from s+N-1 to s and calculate the minimum required fuel
    lld ans = 1;
    need[s + N] = 0;
    for (int i = 1; i < N; ++i){
        int id = s + N - 1;
        need[id] = (need[id + 1] + extended_b[id] - (extended_a[id] < C ? extended_a[id] : C)) > 0
        ? (need[id + 1] + extended_b[id] - (extended_a[id] < C ? extended_a[id] : C))
        : 0;
        if (need[id] == 0) ans++;
    }
    // need[id] keeps the track of minimum fuel required at a given city
    // if need[id]==0 that means Steven can start from that city, so we increase ans

    // Step 4: Release memory and return ans
    free(need);
    free(extended_a);
    free(extended_b);
    return ans;


}
  
//Do not edit this part of code
int main() {
int N;
lld C;
scanf("%d %lld", &N, &C);
  
int* a = (int*)malloc(N * sizeof(int));
int* b = (int*)malloc(N * sizeof(int));
  
for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
for (int i = 0; i < N; ++i) scanf("%d", &b[i]);
  
lld result = travelAroundTheWorld(N, C, a, b);
printf("%lld\n", result);
  
free(a);
free(b);
  
return 0;
}