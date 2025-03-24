#include <iostream>
using namespace std;

// Definition for a binary tree node
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == nullptr && q == nullptr)
      return true;
    if (p == nullptr || q == nullptr || p->val != q->val)
      return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main()
{
  // Creating tree 1
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

  // Creating tree 2 (identical to tree 1)
  TreeNode *x = new TreeNode(1);
  TreeNode *y = new TreeNode(34);
  TreeNode *z = new TreeNode(2);
  TreeNode *w = new TreeNode(4);
  TreeNode *v = new TreeNode(5);
  TreeNode *u = new TreeNode(6);
  TreeNode *t = new TreeNode(7);

  x->left = y;
  x->right = z;
  y->left = w;
  y->right = v;
  z->left = u;
  z->right = t;

  // Testing isSameTree()
  Solution sol;
  if (sol.isSameTree(a, x))
    cout << "Both trees are the same.\n";
  else
    cout << "Trees are different.\n";

  // Free allocated memory (avoid memory leaks)
  delete a, b, c, d, e, f, g;
  delete x, y, z, w, v, u, t;

  return 0;
}
