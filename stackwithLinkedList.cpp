#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
    Node *top;
public:
    Stack() {
        top = NULL;
    }
    void push(int x) {
        Node *temp = new Node();
        if(temp == NULL) {
            cout << "Stack Overflow" << endl;
            return;
        }
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    void pop() {
        if(top == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    int peek() {
        if(top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}