#include <iostream>
#include <stack>
using namespace std;

#define N 4

// Given helper function (Example)
bool knows(int A, int B)
{
  int MATRIX[N][N] = {{0, 1, 1, 1},
                      {0, 0, 1, 1},
                      {0, 0, 0, 1},
                      {0, 0, 0, 0}};
  return MATRIX[A][B];
}

// Function to find the celebrity
int findCelebrity(int n)
{
  stack<int> s;

  // Step 1: Push all people onto the stack
  for (int i = 0; i < n; i++)
    s.push(i);

  // Step 2: Find the potential celebrity
  while (s.size() > 1)
  {
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();

    if (knows(A, B))
      s.push(B);
    else
      s.push(A);
  }

  int candidate = s.top();
  s.pop();

  // Step 3: Verify the candidate
  for (int i = 0; i < n; i++)
  {
    if (i != candidate)
    {
      if (knows(candidate, i) || !knows(i, candidate))
        return -1;
    }
  }
  return candidate;
}

int main()
{
  int celebrity = findCelebrity(N);
  if (celebrity == -1)
    cout << "No celebrity found." << endl;
  else
    cout << "Celebrity is person " << celebrity << endl;
  return 0;
}
