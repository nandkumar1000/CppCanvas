#include <iostream>
#include <stack>
using namespace std;
int main()
{
  stack<int> s;
  s.push(23);
  s.push(45);
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  if (s.empty())
  {
    cout << "Stack is empty" << endl;
  }
  else
  {
    cout << "Stack is not empty" << endl;
  }
  cout << "the size of stack is :" << s.size() << endl;

  return 0;
}