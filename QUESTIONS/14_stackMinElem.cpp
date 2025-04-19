#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int* minArr;
    int topIndex;
    int capacity;
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        minArr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;

        if (topIndex == 0) {
            minArr[topIndex] = x;
        } else {
            minArr[topIndex] = min(x, minArr[topIndex - 1]);
        }
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    int getMin() {
        if (topIndex == -1){
            cout << "Stack is empty\n";
            return -1;
        }
        return minArr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    ~Stack() {
        delete[] arr;
        delete[] minArr;
    }
};

int main() {
    Stack s(10);
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);

    cout << "Top Elements: " << s.top() << "\n";    // 1
    cout << "Minimum: " << s.getMin() << "\n";  // 1

    s.pop();    // Remove 1
    cout << "Top Elements: " << s.top() << "\n";    // 8
    cout << "Minimum: " << s.getMin() << "\n";  // 2

    return 0;
}
