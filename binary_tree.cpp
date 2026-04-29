#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = NULL; 
        right = NULL;
    }
};

Node* buildTree() {
    int val;
    cin >> val;

    if (val == -1) {
        return NULL;
    }

    Node* newNode = new Node(val);

    cout << "Enter left child of " << val << " (-1 for none): ";
    newNode->left = buildTree();

    cout << "Enter right child of " << val << " (-1 for none): ";
    newNode->right = buildTree();

    return newNode;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << " Enter root value: ";
    Node* root = buildTree();

    
    
    cout << "Pre-order:  ";
    preorder(root);
    cout << endl;

    cout << "In-order:   ";
    inorder(root);
    cout << endl;

    cout << "Post-order: ";
    postorder(root);
    cout << endl;

    return 0;
}
