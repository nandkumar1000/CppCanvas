#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left, *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

// Function to calculate height of the tree
int height(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

// Function to print nodes at a given level
void nthLevel(Node *root, int curr, int level)
{
  if (root == NULL)
    return;
  if (curr == level)
  {
    cout << root->data << " ";
    return;
  }
  nthLevel(root->left, curr + 1, level);
  nthLevel(root->right, curr + 1, level);
}

// Function to print level order traversal
void levelorder(Node *root)
{
  int h = height(root);
  for (int i = 1; i <= h; i++)
  {
    nthLevel(root, 1, i);
    cout << endl;
  }
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

  cout << "Level Order Traversal:\n";
  levelorder(a);

  cout << "\nNodes at Level 2:\n";
  nthLevel(a, 1, 2);

  return 0;
}
