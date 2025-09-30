#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);

            if ((int)cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};

int main() {
    int cap;
    cout << "Enter cache capacity: ";
    cin >> cap;
    LRUCache lru(cap);

    string command;
    while (true) {
        cout << "Enter command (put key value / get key / exit): ";
        cin >> command;

        if (command == "put") {
            int key, value;
            cin >> key >> value;
            lru.put(key, value);
            cout << "Inserted (" << key << ", " << value << ")\n";
        } else if (command == "get") {
            int key;
            cin >> key;
            cout << "Value: " << lru.get(key) << endl;
        } else if (command == "exit") {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid command!\n";
        }
    }

    return 0;
}
