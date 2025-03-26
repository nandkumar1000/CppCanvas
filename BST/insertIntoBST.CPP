#include <iostream>
using namespace std;

class insertintbst
{
public:
  int data;
  insertintbst *left;
  insertintbst *right;

  // Constructor
  insertintbst(int d)
  {
    this->data = d;
    this->left = nullptr;
    this->right = nullptr;
  }

  // Corrected insertion function
  insertintbst *insertion(insertintbst *root, int val)
  {
    if (root == nullptr)
    {
      return new insertintbst(val);
    }

    if (val < root->data)
    {
      if (root->left == nullptr)
      {
        root->left = new insertintbst(val);
      }
      else
      {
        root->left = insertion(root->left, val);
      }
    }
    else
    {
      if (root->right == nullptr)
      {
        root->right = new insertintbst(val);
      }
      else
      {
        root->right = insertion(root->right, val);
      }
    }

    return root;
  }

  // Corrected display function (inorder traversal)
  void display(insertintbst *root)
  {
    if (root != nullptr)
    {
      display(root->left);
      cout << root->data << " ";
      display(root->right);
    }
  }
};

int main()
{
  insertintbst *root = new insertintbst(5);

  root = root->insertion(root, 10);
  root = root->insertion(root, 15);
  root = root->insertion(root, 20);
  root = root->insertion(root, 25);

  cout << "BST Inorder Traversal: ";
  root->display(root);
  cout << endl;

  return 0;
}
