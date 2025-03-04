#include <iostream>
#include <queue>
using namespace std;
int main()
{
  deque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_front(13);
  d.push_front(14);
  cout << "Size of deque: " << d.size() << endl;
  d.pop_back();
  cout << "size of deque:" << d.size() << endl;
  if (d.empty())
  {
    cout << "deque is empty" << endl;
  }
  else
  {
    cout << "deque is not empty" << endl;
  }
  return 0;
}