#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head || k == 1) return head;

    Node dummy(0);
    dummy.next = head;
    Node* prevGroupEnd = &dummy;

    while (true) {
        Node* kth = prevGroupEnd;
        for (int i = 0; i < k && kth; i++) kth = kth->next;
        if (!kth) break;

        Node* groupStart = prevGroupEnd->next;
        Node* nextGroupStart = kth->next;

        Node* prev = nextGroupStart;
        Node* curr = groupStart;
        while (curr != nextGroupStart) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        prevGroupEnd->next = kth;
        prevGroupEnd = groupStart;

    }

    return dummy.next;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;
    head = reverseKGroup(head, k);
    printList(head);
    
    return 0;
}