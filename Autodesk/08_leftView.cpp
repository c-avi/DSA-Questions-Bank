#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void leftViewUtil(Node* root, int level, int &maxLevel) {
    if (root == NULL) return;

    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}

void leftViewRecursive(Node* root) {
    int maxLevel = 0;
    leftViewUtil(root, 1, maxLevel);
}

void leftViewIterative(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int  i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();

            if (i == 0) cout << node->data << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);

    cout << "Left View (Recursive): ";
    leftViewRecursive(root);
    cout << "\n";

    cout << "Left View (Iterative): ";
    leftViewIterative(root);
    cout << "\n";

    return 0;
}