#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int LargestRectangle(vector<int> &v)
{
  stack<int> s;
}
int main()
{
  int n;
  cin >> n; 
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    cout << "inserted height :" << v[i] << endl;
  }
  LargestRectangle(v);
  return 0;
}