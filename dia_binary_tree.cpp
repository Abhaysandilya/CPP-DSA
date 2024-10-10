#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
int height(Node* node) {

    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left),
                   height(node->right));
}
int diameter(Node* tree) {

    if (tree == nullptr)
        return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max({lheight + rheight + 1, ldiameter, rdiameter});
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << diameter(root) << endl;

    return 0;
}

