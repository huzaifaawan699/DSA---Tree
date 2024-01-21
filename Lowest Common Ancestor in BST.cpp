#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), left(NULL), right(NULL) {}
};

Node* lowestCommonAncestor(Node* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    if (p < root->key && q < root->key) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (p > root->key && q > root->key) {
        return lowestCommonAncestor(root->right, p, q);
    }
    else {
        return root;
    }
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        root = insert(root, key);
    }

    int p = 30, q = 60;

    Node* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->key << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
