#include <iostream>
using namespace std;
class Node
{
private:
  /* data */
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
void displayTree(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  displayTree(root->left);
  displayTree(root->right);
}
int sum(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int leftsum = sum(root->left);
  int rightsum = sum(root->right);
  int ans = root->data + leftsum + rightsum;
  return ans;
}
int size(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int leftsize = size(root->left);
  int rightsize = size(root->right);
  int fullsize = 1 + leftsize + rightsize;
  return fullsize;
}
int MaxInTree(Node *root)
{
  if (root == NULL)
    return 0;
  // return INT_MIN; for negative value

  int leftMax = MaxInTree(root->left);
  int rightMax = MaxInTree(root->right);
  int MaximumNode = max(root->data, max(leftMax, rightMax));
  return MaximumNode;
}
int main()
{
  Node *a = new Node(1);
  Node *b = new Node(34);
  Node *c = new Node(2);
  Node *d = new Node(4);
  Node *e = new Node(5);
  Node *f = new Node(6);
  Node *g = new Node(7);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  displayTree(a);
  cout << endl;
  cout << sum(a) << endl;
  cout << size(a) << endl;
  cout << MaxInTree(a) << endl;
  return 0;
}