#include <iostream>
#include <stack>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class MinStack
{
private:
  stack<int> s;
  int mini;

public:
  MinStack()
  {
    mini = INT_MAX;
  }

  void push(int data)
  {
    if (s.empty())
    {
      mini = data;
      s.push(data);
    }
    else
    {
      if (data < mini)
      {
        s.push(2 * data - mini);
        mini = data;
      }
      else
      {
        s.push(data);
      }
    }
  }

  void pop()
  {
    if (s.empty())
    {
      cout << "Stack is empty" << endl;
      return;
    }

    int curr = s.top();
    s.pop();

    if (curr < mini)
    {
      mini = 2 * mini - curr; 
    }
  }

  int top()
  {
    if (s.empty())
      return -1;

    int curr = s.top();
    return (curr < mini) ? mini : curr;
  }

  bool isEmpty()
  {
    return s.empty();
  }

  int getMin()
  {
    return s.empty() ? -1 : mini;
  }
};

vector<int> minvalue(vector<int> &a, int n)
{
  MinStack ms;
  vector<int> result;

  for (int i = 0; i < n; i++)
  {
    ms.push(a[i]);
    result.push_back(ms.getMin());
  }

  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<int> result = minvalue(a, n);

  // Printing min values after each push
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
