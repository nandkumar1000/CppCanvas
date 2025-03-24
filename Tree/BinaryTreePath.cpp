#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  void sol(TreeNode *root, string s, vector<string> &ans)
  {
    if (root == nullptr)
      return;
    string a = to_string(root->val);

    if (root->left == nullptr && root->right == nullptr)
    {
      s += a;
      ans.push_back(s);
      return;
    }

    sol(root->left, s + a + "->", ans);
    sol(root->right, s + a + "->", ans);
  }

  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;
    sol(root, "", ans);
    return ans;
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

  return 0;
}
