#include <iostream>
#include <string>
#include <vector>
using namespace std;
string LongestCommonPrefix(vector<string> &v)
{
  sort(v.begin(), v.end());
  string ans = "";
  int i = 0;
  int j = 0;
  string s1 = v[0];
  string s2 = v[v.size() - 1];
  while (i < s1.size() && j < s2.size())
  {
    if (s1[i] == s2[j])
    {
      ans += s1[i];
      i++;
      j++;
    }
    else
    {
      break;
    }
  }
  return ans;
}
int main()
{
  int n;
  cout << "Enter the no of Strings";
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  cout << "Longest common prefix" << LongestCommonPrefix(v) << endl;
  return 0;
}