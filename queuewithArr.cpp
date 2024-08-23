#include<iostream>
using namespace std;

class Queue {
    int front;
    int rear;
    int size;
    int *arr;
public:
    Queue(int size) {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    void enqueue(int x) {
        if(rear == size-1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }
    void dequeue() {
        if(front == rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }
    int peek() {
        if(front == rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front+1];
    }
    bool isEmpty() {
        return front == rear;
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}