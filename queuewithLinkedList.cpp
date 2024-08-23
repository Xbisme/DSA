#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Queue {
    Node *front;
    Node *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int x) {
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if(front == NULL && rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        if(front == rear) {
            front = rear = NULL;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    int peek() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return front == NULL;
    }
};

int main () {
    Queue q;
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