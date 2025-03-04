#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the queue
queue<int> rev(queue<int> q)
{
  stack<int> s;
  while (!q.empty())
  {
    int element = q.front();
    q.pop();
    s.push(element);
  }
  while (!s.empty())
  {
    int element = s.top();
    s.pop();
    q.push(element);
  }
  return q;
}

int main()
{
  // For reverse of queue
  queue<int> q;
  int n;

  cout << "Enter the number of elements in queue: ";
  cin >> n;

  cout << "Enter the elements in queue: ";
  for (int i = 0; i < n; i++)
  {
    int element;
    cin >> element;
    q.push(element); 
  }

  q = rev(q); 

  cout << "Reversed Queue: ";
  while (!q.empty())
  {
    cout << q.front() << " "; 
    q.pop();
  }
  cout << endl;

  return 0;
}
