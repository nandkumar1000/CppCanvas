#include <iostream>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  int maxDiameter = 0; 

  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
      return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Update the max diameter at this node
    maxDiameter = max(maxDiameter, leftDepth + rightDepth);

    // Return the height of this subtree
    return 1 + max(leftDepth, rightDepth);
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    maxDepth(root);
    return maxDiameter;
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

  // Building the tree structure
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;

  Solution solution;
  cout << "Diameter of Binary Tree: " << solution.diameterOfBinaryTree(a) << endl;

  return 0;
}
