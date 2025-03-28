#include <iostream>
#include <unordered_set>

using namespace std;
int main()
{
  unordered_set<int> s;
  s.insert(23);
  s.insert(34);
  s.insert(2);
  s.insert(11);
  s.insert(232);
  s.insert(2);
  s.erase(2);
  int target = 23;
  // s.find() it searches  in the set  and if  it is not found  then ir return the last element
  if (s.find(target) != s.end())
  {
    cout << "Element is present in the set" << endl;
  }
  else
  {
    cout << "Element is not present in the set" << endl;
  }
  cout << s.size() << endl;
  for (int elem : s)
  {
    cout << elem << endl;
  }
  return 0;
}