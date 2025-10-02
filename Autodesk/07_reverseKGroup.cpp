#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    while (cur->next) {
        cur = cur->next;
        count++;
    }

    while (count >= k) {
        cur = pre->next;
        nex = cur->next;

        for (int i = 1; i < k; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    int n, k;
    cout << "enter number of nodes: ";
    cin >> n;

    cout << "Enter list elements: ";
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);
    
    return 0;
}