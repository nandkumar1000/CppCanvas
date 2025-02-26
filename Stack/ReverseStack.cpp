#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int elem)
{
  if (s.empty())
  {
    s.push(elem);
    return;
  }
  int top = s.top();
  s.pop();
  insertAtBottom(s, elem);
  s.push(top);
}

void reverseStack(stack<int> &s)
{
  if (s.empty())
    return;
  int top = s.top();
  s.pop();
  reverseStack(s);
  insertAtBottom(s, top);
}

int main()
{
  stack<int> s;
  int n, elem;
  cin >> n;
  while (n--)
  {
    cin >> elem;
    s.push(elem);
  }

  reverseStack(s);

  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  } 
}
