#include <iostream>
#include <set>
using namespace std;
int main()
{
  set<int> s;
  s.insert(23);
  s.insert(45);
  s.insert(2334);
  s.insert(34);
  s.insert(234);

  cout << s.size() << endl;
  s.erase(34);
  for (int elem : s)
  {
    cout << elem << endl;
  }

  return 0;
}