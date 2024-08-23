#include<iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int *arr;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    void push(int x) {
        if(top == size-1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s(5);
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