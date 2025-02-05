#include <iostream>

using namespace std;
int main()
{
  int height[6] = {3, 4, 1, 16, 8, 2};
  int totalwater = 0;
  int max_left = 0;
  int max_right = 0;
  int left = 0;
  int right = 6 - left;
  while (left <= right)
  {
    if (height[left] <= height[right])
    {
      if (height[left] >= max_left)
      {
        max_left = height[left];
      }
      else
      {
        totalwater = totalwater + max_left - height[right];
        left++;
      }
      if (height[right] >= max_right)
      {
        max_right = height[right];
      }
      else
      {
        totalwater = totalwater + max_right - height[left];
        right--;
      }
    }

    return totalwater;
  }
}
