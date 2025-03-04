#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the first k elements of a queue
queue<int> KReverse(queue<int> &q, int k)
{
  if (k > q.size() || k <= 0)
  {
    return q;
  }

  stack<int> s;

  // Step 1: Push first k elements into stack
  for (int i = 0; i < k; i++)
  {
    int val = q.front();
    q.pop();
    s.push(val);
  }

  // Step 2: Pop from stack and push back into queue
  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
  }

  // Step 3: Move the remaining elements (n-k) to the back
  int t = q.size() - k;
  while (t--)
  {
    q.push(q.front());
    q.pop();
  }

  return q;
}

int main()
{
  int n, k;
  cout << "Enter the number of elements in the queue: ";
  cin >> n;

  queue<int> q;
  cout << "Enter the elements of the queue: ";
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    q.push(x);
  }

  cout << "Enter the value of k: ";
  cin >> k;

  queue<int> reversedQueue = KReverse(q, k);

  // Output the modified queue
  cout << "Queue after reversing first " << k << " elements: ";
  while (!reversedQueue.empty())
  {
    cout << reversedQueue.front() << " ";
    reversedQueue.pop();
  }
  cout << endl;

  return 0;
}
