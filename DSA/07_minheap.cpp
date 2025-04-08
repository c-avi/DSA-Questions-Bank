#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min Heap using priority_queue
    
    int n, element;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> element;
        minHeap.push(element);  // Insert elements into the heap
    }

    cout << "\nElements in ascending order:\n";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";  // Print the smallest element
        minHeap.pop();  // Remove the top element
    }

    return 0;
}
