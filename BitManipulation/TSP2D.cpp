#include <iostream>
#include <climits>
#include <vector>
using namespace std;

const int N = 4;
int grid[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};
vector<vector<int>> dp(N, vector<int>(N, -1));

int tsp(int curr, vector<bool> &visited, int count)
{
  if (count == N)
  {
    return grid[curr][0];
  }

  if (dp[curr][count] != -1)
  {
    return dp[curr][count];
  }

  int ans = INT_MAX;

  for (int next = 0; next < N; next++)
  {
    if (!visited[next])
    {
      visited[next] = true;
      int newCost = grid[curr][next] + tsp(next, visited, count + 1);
      ans = min(ans, newCost);
      visited[next] = false;
    }
  }

  return dp[curr][count] = ans;
}

int main()
{
  vector<bool> visited(N, false);
  visited[0] = true;
  cout << tsp(0, visited, 1) << endl;
  return 0;
}
