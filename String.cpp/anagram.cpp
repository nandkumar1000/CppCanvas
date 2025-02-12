#include <iostream>
#include <string>
using namespace std;
bool isAnagram(string s1, string s2)
{
  if (s1.length() != s2.length())
  {
    return false;
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  return s1 == s2 ? true : false;
}
int main()
{
  string s1, s2;
  cout << "Enter first string: ";
  cin >> s1;
  cout << "Enter second string: ";
  cin >> s2;
  if (isAnagram(s1, s2))
  {
    cout << "The strings are anagrams of each other.";
  }
  else
  {
    cout << "The strings are not anagrams of each other.";
  }
  return 0;
}