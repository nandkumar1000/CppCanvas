#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NextSmaller(vector<int> &v)
{
  stack<int> s;
  s.push(-1);
  vector<int> ans(v.size());

  for (int i = v.size() - 1; i >= 0; i--)
  {
    int curr = v[i];
    while (!s.empty() && s.top() >= curr)
    {
      s.pop();
    }

    ans[i] = s.top();

    s.push(curr);
  }
  return ans;
}

int main()
{
  int n, val;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  vector<int> smaller = NextSmaller(v);

  cout << "Next smaller elements: ";
  for (int num : smaller)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
