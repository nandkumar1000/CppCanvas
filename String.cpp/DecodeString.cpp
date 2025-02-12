#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string decodeString(string s)
{
  string result = "";
  if (s.empty())
  {
    return "";
  }
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != ']')
    {
      result.push_back(s[i]);
    }
    else
    {
      string str = "";
      while (!result.empty() && result.back() != '[')
      {
        str.push_back(result.back());
        result.pop_back();
      }
      reverse(str.begin(), str.end());
      result.pop_back();

      string num = "";
      while (!result.empty() && isdigit(result.back()))
      {
        num.push_back(result.back());
        result.pop_back();
      }
      reverse(num.begin(), num.end());

      int int_num = (num.empty()) ? 1 : stoi(num);
      while (int_num--)
      {
        result += str;
      }
    }
  }
  return result;
}

int main()
{
  string s;
  cin >> s;
  cout << decodeString(s) << endl;
  return 0;
}
