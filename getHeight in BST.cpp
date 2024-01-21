#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), right(NULL), left(NULL) {}
};
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        root = insert(root, key);
    }

    int result = getHeight(root);

    if (result > 0) {
        cout << "Height: " << result << endl;
    } else {
        cout << "BST is Empty." << endl;
    }

    return 0;
}
