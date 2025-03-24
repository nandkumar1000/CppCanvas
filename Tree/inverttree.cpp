#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  void sol(TreeNode *root)
  {
    if (root == nullptr)
      return;
    TreeNode *Temp = root->left;
    root->left = root->right;
    root->right = Temp;
    sol(root->left);
    sol(root->right);
  }

  TreeNode *invertTree(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;
    sol(root);
    return root;
  }
};

void printTree(TreeNode *root)
{
  if (root == nullptr)
    return;
  cout << root->val << " ";
  printTree(root->left);
  printTree(root->right);
}

int main()
{
  TreeNode *a = new TreeNode(1);
  TreeNode *b = new TreeNode(34);
  TreeNode *c = new TreeNode(2);
  TreeNode *d = new TreeNode(4);
  TreeNode *e = new TreeNode(5);
  TreeNode *f = new TreeNode(6);
  TreeNode *g = new TreeNode(7);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;

  Solution solution;
  cout << "Original Tree: ";
  printTree(a);
  cout << endl;

  a = solution.invertTree(a);

  cout << "Inverted Tree: ";
  printTree(a);
  cout << endl;

  return 0;
}
