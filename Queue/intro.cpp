#include <iostream>
#include <queue>
using namespace std;
int main()
{
  queue<int> q;
  q.push(34);
  q.push(45);
  q.push(56);
  cout << "front of queue is : " << q.front() << endl;
  cout << "the size of queue is : " << q.size() << endl;
  q.pop();
  cout << "front of queue is : " << q.front() << endl;
  cout << "the size of queue is : " << q.size() << endl;

  if (q.empty())
  {
    cout << "queue is empty" << endl;
  }
  else
  {
    cout << "queue is not empty" << endl;
  }

  return 0;
}