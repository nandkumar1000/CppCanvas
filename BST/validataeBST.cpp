#include <iostream>
#include <climits>

using namespace std;

class validateBST
{
public:
  int data;
  validateBST *left;
  validateBST *right;

  validateBST(int d)
  {
    this->data = d;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class Solution
{
public:
  int maximum(validateBST *root)
  {
    if (root == nullptr)
      return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
  }

  int minimum(validateBST *root)
  {
    if (root == nullptr)
      return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
  }

  bool isValidBST(validateBST *root)
  {
    if (root == nullptr)
      return true;
    if (root->data <= maximum(root->left) || root->data >= minimum(root->right))
      return false;
    return isValidBST(root->left) && isValidBST(root->right);
  }
};

void display(validateBST *root)
{
  if (root == nullptr)
    return;
  display(root->left);
  cout << root->data << " ";
  display(root->right);
}

int main()
{
  validateBST *root = new validateBST(43);
  root->left = new validateBST(20);
  root->right = new validateBST(60);
  root->left->left = new validateBST(10);
  root->left->right = new validateBST(30);
  root->right->left = new validateBST(50);
  root->right->right = new validateBST(70);

  Solution sol;
  display(root);
  cout << endl;

  if (sol.isValidBST(root))
  {
    cout << "Valid BST" << endl;
  }
  else
  {
    cout << "Invalid BST" << endl;
  }

  return 0;
}
