#include <iostream>
using namespace std;

struct petrolpump
{
  int petrol;
  int distance;
};

class Solution
{
public:
  int tour(petrolpump p[], int n)
  {
    int deficit = 0, start = 0, balance = 0;

    for (int i = 0; i < n; i++)
    {
      balance += p[i].petrol - p[i].distance;
      if (balance < 0)
      {
        deficit += balance;
        start = i + 1;
        balance = 0;
      }
    }
    return (deficit + balance >= 0) ? start : -1;
  }
};

int main()
{
  int n;
  cin >> n;
  petrolpump p[n];

  for (int i = 0; i < n; i++)
  {
    cin >> p[i].petrol >> p[i].distance;
  }

  Solution sol;
  cout << sol.tour(p, n) << endl;

  return 0;
}
