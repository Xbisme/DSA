#include<iostream>
using namespace std;
  
class Node {
    public:
        int val;
        Node* next;
        Node()
        {
            val = 0;
            this->next = NULL;
        }
        Node (int val)
        {
            this->val = val;
            this->next = NULL;
        }
};

class LinkedList
{
    Node* head;
    Node* tail;
    int size;
    public:

        LinkedList() 
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void addHead(int val)
        {
            if (head == NULL) head = tail = new Node(val);
            else 
            {
                Node* newNode = new Node(val);
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void addTail(int val)
        {
            if (head == NULL) addHead(val);
            else
            {
                Node* newNode = new Node(val);
                tail->next = newNode;
                tail = newNode;
                size++;
            }
        }

        void insert(int val, int pos)
        {
            if (pos < 0 || pos > size) return;
            else if (pos == 0) addHead(val);
            else if (pos == size) addTail(val);
            else 
            {
                Node *temp = head;
                int count = 0;
                while(count < pos - 1)
                {
                    temp = temp->next;
                    count++;
                }
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                size++;
            }
        }
        
        void removeHead()
        {
            if (head == NULL) return;
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }

        void removeTail()
        {
            if(head == NULL) return;
            Node* temp = head;
            while(temp->next != tail ) temp = temp->next;
            delete tail;
            tail = temp;
            tail -> next = NULL;
            size--;
        }

        void remove(int val)
        {
            if (head->val == val) removeHead();
            else if (tail->val == val) removeTail();
            else
            {
                Node* temp = head;
                while(temp->val != val)
                {
                    temp = temp->next;
                }
                Node *deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
                size--;
            }
        }
        void removePos(int pos)
        {
            if (pos < 0 || pos > size) return;
            else if (pos == 0) removeHead();
            else if (pos == size) removeTail();
            else 
            {
                Node *temp = head;
                int count = 0;
                while(count < pos - 1)
                {
                    temp = temp->next;
                    count++;
                }
                Node *deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
                size--;
            }
        }
        int search(int val)
        {
            int pos = 0;
            Node* temp = head;
            while(temp != NULL)
            {
                if(temp->val == val) return pos;
                pos++;
                temp = temp->next;
            }
            return -1;
        }
        void display()
        {
            Node *temp = head;
            while(temp != NULL)
            {
                cout << temp->val << " ";
                temp = temp->next;
            }
        }

};

int main ()
{
    LinkedList list;
    list.addHead(5);
    list.addHead(10);
    list.addTail(15);
    list.addTail(20);
    list.insert(25, 2);
    // list.removeHead();
    // list.removeTail();
    // list.remove(15);
    list.display();
    list.removePos(1);
    cout << endl;
    list.display();
    // cout << list.search(5) << endl;
    return 0;
}