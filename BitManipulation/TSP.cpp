#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int N = 4;
int grid[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};
int dp[N][(1 << N)];

int tsp(int curr, int mask)
{
  if (mask == (1 << N) - 1)
  {
    return grid[curr][0];
  }

  if (dp[curr][mask] != -1)
  {
    return dp[curr][mask];
  }

  int ans = INT_MAX;

  for (int next = 0; next < N; next++)
  {
    if ((mask & (1 << next)) == 0)
    {
      int newCost = grid[curr][next] + tsp(next, mask | (1 << next));
      ans = min(ans, newCost);
    }
  }

  return dp[curr][mask] = ans;
}

int main()
{
  memset(dp, -1, sizeof(dp));
  cout << tsp(0, 1) << endl;
  return 0;
}
