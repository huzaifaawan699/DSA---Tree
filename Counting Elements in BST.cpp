#include<iostream>
using namespace std;

struct Node {
    int key;
    int count; 
    Node* left, *right;
    Node(int v) : key(v), count(1), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key == root->key) {
        root->count++;
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->key << " (Count: " << root->count << ") ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 50, 30, 70, 50, 30};

    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "Elements in the BST with counts: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
