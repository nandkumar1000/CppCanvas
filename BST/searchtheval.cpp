#include <iostream>
using namespace std;

class searchtheval {
public:
    int data;
    searchtheval* left;
    searchtheval* right;

    // Constructor
    searchtheval(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Function to search for a value in BST
    searchtheval* searchBST(searchtheval* root, int val) {
        if (root == nullptr || root->data == val) {
            return root;
        } 
        if (root->data > val) {
            return searchBST(root->left, val);
        } 
        return searchBST(root->right, val);
    }

    // Function to display the BST (inorder traversal)
    void display(searchtheval* node) {
        if (node != nullptr) {
            display(node->left);
            cout << node->data << " ";
            display(node->right);
        }
    }
};

int main() {
    searchtheval* root = new searchtheval(10);
    root->left = new searchtheval(5);
    root->right = new searchtheval(15);
    root->left->left = new searchtheval(3);
    root->left->right = new searchtheval(7);
    root->right->right = new searchtheval(20);

    cout << "BST Inorder Traversal: ";
    root->display(root);
    cout << endl;

    int searchValue = 7;
    searchtheval* result = root->searchBST(root, searchValue);
    if (result) {
        cout << "Value " << searchValue << " found in BST." << endl;
    } else {
        cout << "Value " << searchValue << " not found in BST." << endl;
    }

    return 0;
}
