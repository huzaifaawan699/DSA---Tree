#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), left(NULL), right(NULL) {}
};

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
    if (root == NULL) {
        return true; 
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        root = insert(root, key);
    }

    if (isBalanced(root)) {
        cout << "BST is balanced." << endl;
    } else {
        cout << "BST is not balanced." << endl;
    }

    return 0;
}
