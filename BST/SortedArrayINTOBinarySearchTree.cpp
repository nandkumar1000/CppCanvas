#include <iostream>
using namespace std;
class solution
{
public:
  int data;
  solution *left;
  solution *right;
  solution(int d)
  {
    this->data = d;
    this->left = nullptr;
    this->right = nullptr;
  }
  // dispay
  void display(solution *root)
  {
    if (root != NULL)
    {
      cout << root->data << endl;
      cout << root->left->data << endl;
      cout << root->right->data << endl;
    }
    cout << data << " ";
  }
};
int main()
{
  solution *root = new solution(5);
  root->left = new solution(4);
  root->right = new solution(6);
  root->left->left = new solution(2);
  root->left->right = new solution(3);
  //  for calling display function
  root->display(root);

  return 0;
}