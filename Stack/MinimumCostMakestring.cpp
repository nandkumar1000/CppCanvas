#include <iostream>
#include <string>
#include <stack>
using namespace std;

int MinCost(string s)
{

  if (s.length() % 2 == 1)
    return -1;

  stack<char> st;
  int open = 0, close = 0;

  for (char ch : s)
  {
    if (ch == '(')
    {
      st.push(ch);
    }
    else
    {
      if (!st.empty() && st.top() == '(')
      {
        st.pop();
      }
      else
      {
        close++;
      }
    }
  }

  open = st.size();

  return (open + 1) / 2 + (close + 1) / 2;
}

int main()
{
  string expression;
  cin >> expression;

  int cost = MinCost(expression);
  cout << "Minimum cost to balance the string: " << cost << endl;

  return 0;
}
