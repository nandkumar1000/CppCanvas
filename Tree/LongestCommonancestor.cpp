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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == nullptr || root == p || root == q)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
      return root;
    return (left != nullptr) ? left : right;
  }
};

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

  Solution sol;
  TreeNode *lca = sol.lowestCommonAncestor(a, d, e);
  cout << "Lowest Common Ancestor: " << (lca ? lca->val : -1) << endl;

  return 0;
}
