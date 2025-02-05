#include <iostream>
using namespace std;
int sqrt(int a)
{
  int start = 0;
  int end = a;
  while (start <= end)
  {
    int mid = start + (end - start) / 2;
    if (mid * mid == a)
    {
      return mid;
    }
    if (mid * mid < a)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}
int main()
{
  int n;
  cin >> n;
  int fun = sqrt(n);
  cout << fun << endl;
}