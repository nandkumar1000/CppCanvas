#include <iostream>
#include <climits>
using namespace std;
int maxSubArray(int nums[], int n)
{

  int maxsum = INT_MIN;
  int currentsum = 0;
  for (int i = 0; i < n; i++)
  {
    currentsum += nums[i];
    maxsum = max(maxsum, currentsum);
    if (currentsum < 1)
    {
      currentsum = 0;
    }
  }
  return maxsum;
}
int main()
{

  int arr[5] = {1, 2, 3, 4, 5};
  cout << maxSubArray(arr, 5);
  return 0;
}