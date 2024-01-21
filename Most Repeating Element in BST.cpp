#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), left(NULL), right(NULL) {}
};

int currentElement = -1;
int currentCount = 0;

void updateMostRepeating(Node* root) {
    if (root) {
        updateMostRepeating(root->left);

        if (root->key == currentElement) {
            currentCount++;
        } else {
            currentElement = root->key;
            currentCount = 1;
        }

        updateMostRepeating(root->right);
    }
}

int findMostRepeating(Node* root) {
    updateMostRepeating(root);

    if (currentElement != -1) {
        cout << "Most Repeating Element in the BST: " << currentElement << " (Frequency: " << currentCount << ")" << endl;
    } else {
        cout << "BST is empty." << endl;
    }

    return currentElement;
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 50, 30, 70, 50, 30};

    for (int key : keys) {
        root = insert(root, key);
    }

    findMostRepeating(root);

    return 0;
}
