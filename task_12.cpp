#include <iostream>
#include <algorithm>  
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;
    Node(int val) : data(val), height(1), left(NULL), right(NULL) {}
};


int getHeight(Node* node) {
    return node ? node->height : 0;
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    
 
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}


Node* insert(Node* root, int val) {
    if (!root) return new Node(val);  // New node
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root;  
    
    // Height update
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    // Balance check
    int balance = getHeight(root->left) - getHeight(root->right);
    
    // 4 Rotation Cases:
    // 1. Left-Left (Right Rotate)
    if (balance > 1 && val < root->left->data)
        return rightRotate(root);
    
    // 2. Right-Right (Left Rotate)
    if (balance < -1 && val > root->right->data)
        return leftRotate(root);
    
    // 3. Left-Right (Left then Right Rotate)
    if (balance > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // 4. Right-Left (Right then Left Rotate)
    if (balance < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

// In-Order Traversal (Same as BST)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);  
    
    cout << "AVL Traversal (Sorted Order): ";
    inorder(root); // Output: 10 20 30
    return 0;
}