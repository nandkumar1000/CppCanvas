#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &s, int elem)
{
  if (s.empty())
  {
    s.push(elem);
    return;
  }
  int temp = s.top();
  s.pop();
  insertAtBottom(s, elem);
  s.push(temp);
}

// Function to sort the stack using recursion
void sortstack(stack<int> &s)
{
  if (s.empty())
  {
    return;
  }
  int num = s.top();
  s.pop();
  sortstack(s);
  insertAtBottom(s, num);
}

int main()
{
  stack<int> s;
  int n, val;

  cout << "Enter the number of elements: ";
  cin >> n;

  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    s.push(val);
  }

  sortstack(s);

  cout << "Sorted stack (from top to bottom): ";
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;

  return 0;
}
