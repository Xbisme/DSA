#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

// Binary Search Tree with C++
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node** root, int val) {
    if (*root == NULL) {
        (*root) = new Node(val);
    }
    else if (val <= (*root)->data) {
        insert(&(*root)->left, val);
    } else {
        insert(&(*root)->right, val);
    }
}

void remove (Node** root, int val)
{
    if (*root == NULL) {
        return;
    }
    if (val < (*root)->data) {
        remove(&(*root)->left, val);
    } else if (val > (*root)->data) {
        remove(&(*root)->right, val);
    } else {
        if ((*root)->left == NULL) {
            Node* temp = (*root)->right;
            delete *root;
            *root = temp;
        } else if ((*root)->right == NULL) {
            Node* temp = (*root)->left;
            delete *root;
            *root = temp;
        } else {
            Node* temp = (*root)->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            remove(&(*root)->right, temp->data);
        }
    }
}

void display(Node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

bool search(Node* root, int val) {
    if (root == NULL) {
        return false;
    }
    else if (root->data == val) {
        return true;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

int main() {
    Node* root = NULL;
    insert(&root, 9);
    insert(&root, 6);
    insert(&root, 16);
    insert(&root, 22);
    insert(&root, 2);
    insert(&root, 35);
    insert(&root, 10);
    insert(&root, 25);
    insert(&root, 12);
    display(root);
    remove(&root,16);
    cout << endl;
    display(root);
    return 0;
}