#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), left(NULL), right(NULL) {}
};

void kthSmallestUtil(Node* root, int& count, int k, int& result) {
    if (root) {
        kthSmallestUtil(root->left, count, k, result);

        count++;
        if (count == k) {
            result = root->key;
            return;
        }

        kthSmallestUtil(root->right, count, k, result);
    }
}

int kthSmallest(Node* root, int k) {
    int count = 0;
    int result = -1;
    kthSmallestUtil(root, count, k, result);
    return result;
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        root = insert(root, key);
    }

    int k = 3;
    int kthElement = kthSmallest(root, k);

    if (kthElement != -1) {
        cout << "The " << k << "th smallest element in the BST: " << kthElement << endl;
    } else {
        cout << "BST is empty or k is out of bounds." << endl;
    }

    return 0;
}
