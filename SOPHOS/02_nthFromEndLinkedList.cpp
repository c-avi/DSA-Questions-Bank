#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* findNthFromEnd(Node* head, int n) {
    if (head == nullptr) return nullptr;
    
    Node* fast = head;
    Node* slow = head;
    
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            cout << "Error: List is shorter than " << n << " nodes." << "\n";
        }
        fast = fast->next;
    }
    
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

Node* buildList() {
    int val;
    cout << "Enter values (enter -1 to stop): ";
    Node *head = nullptr, *tail = nullptr;
    
    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    Node* head = buildList();
    
    int n;
    cout << "Enter the value of N (position from end): ";
    cin >> n;
    
    Node* result = findNthFromEnd(head, n);
    
    if (result != nullptr) {
        cout << "The " << n << "th node from the end is: " << result->data << "\n";
    }

    return 0;
}