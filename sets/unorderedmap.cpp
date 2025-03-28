// code for anagram
#include <iostream>
#include <unordered_map>
using namespace std;
bool checkanagram(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }
  unordered_map<char, int> m;
  for (int i = 0; i < s.length(); i++){
    m[s[i]]++;

  }
  for(int j=0;j<t.length();j++){
    if(m.find(t[j])!=m.end()){
      m[t[j]]--;
      }
      else{
        return false;
        }

  }

};
int main()
{
  string s = "listen";
  string t = "silent";
  checkanagram(s,t);
  if (checkanagram(s, t))
  cout << "Anagram";
  else
  cout << "Not an anagram";
  return 0;


}