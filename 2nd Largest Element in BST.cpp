#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), left(NULL), right(NULL) {}
};

Node* findMax(Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

int findSecondLargest(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        cout << "BST does not have a second largest value." << endl;
        return -1; 
    }

    if (root->left != NULL && root->right == NULL) {
        return findMax(root->left)->key;
    }

    if (root->right != NULL && root->right->left == NULL && root->right->right == NULL) {
        return root->key;
    }

    return findSecondLargest(root->right);
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        root = insert(root, key);
    }

    int secondLargest = findSecondLargest(root);

    if (secondLargest != -1) {
        cout << "Second Largest Value in the BST: " << secondLargest << endl;
    }

    return 0;
}
