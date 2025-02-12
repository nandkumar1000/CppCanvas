#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool IsIsomorphic(string s1, string s2)
{
  if (s1.length() != s2.length())
  {
    return false;
  }
  vector<int> v1(128, -1);
  vector<int> v2(128, -1);
  for (int i = 0; i < s1.size(); i++)
  {
    if (v1[s1[i]] != v2[s2[i]])
    {
      return false;
    }
    v1[s1[i]] = v2[s2[i]] = i;
  }
  return true;
}
int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  if (IsIsomorphic(s1, s2))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}