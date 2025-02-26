#include <iostream>
#include <stack>
using namespace std;

bool hasRedundantBrackets(string expression)
{
  stack<char> s;

  for (char ch : expression)
  {
    if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
      s.push(ch);
    }
    else if (ch == ')')
    {
      if (s.top() == '(')
      {
        return true;
      }
      while (!s.empty() && s.top() != '(')
      {
        s.pop();
      }
      s.pop();
    }
  }
  return false;
}

int main()
{
  string expr;
  cout << "Enter expression: ";
  cin >> expr;

  if (hasRedundantBrackets(expr))
  {
    cout << "Redundant brackets found.\n";
  }
  else
  {
    cout << "No redundant brackets.\n";
  }

  return 0;
}
