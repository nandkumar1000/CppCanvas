#include <iostream>
using namespace std;

class Node
{
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

void preorder(Node *root)
{
  if (root == NULL)
    return; 
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
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

  cout << "Preorder: ";
  preorder(a);
  cout << endl;

  cout << "Inorder: ";
  inorder(a);
  cout << endl;

  cout << "Postorder: ";
  postorder(a);
  cout << endl;

  return 0;
}
