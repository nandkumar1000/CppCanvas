#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void fillingWater(vector<int> &v, int x, int y)
  {
    for (int i = 0; i < x; i++)
    {
      v.push_back(x);
    }

    for (int i = 0; i < y; i++)
    {
      v.push_back(y);
    }
  }

  bool canMeasureWater(int x, int y, int target)
  {
    if (target > x + y)
      return false;

    return (target % gcd(x, y) == 0);
  }
};

int main()
{
  Solution sol;
  int X = 3, Y = 5, Z = 4;

  if (sol.canMeasureWater(X, Y, Z))
    cout << "Solution exists\n";
  else
    cout << "No solution possible\n";

  return 0;
}
