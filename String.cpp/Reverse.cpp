#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s = "nand";
  // performing reverse
  // reverse(s.begin(), s.end());
  string rev = s;
  for (int i = s.length() - 1; i >= 0; i--)
  {
    rev = rev + s[i];
  }
  cout << rev << endl;
  return 0;
}