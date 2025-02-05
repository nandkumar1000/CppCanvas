#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int pivotIndex(vector<int> &arr)
  {
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
      int mid = start + (end - start) / 2;
      if (arr[mid] >= arr[0])
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
};