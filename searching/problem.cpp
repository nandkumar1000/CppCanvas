#include <iostream>
using namespace std;
int two_sum(int arr, int target, int size)
{
  int pair = 0;
  for (int i = 0; i <= size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (arr[i] + arr[j] == target)
      {
        cout << i << j << endl;
        pair++;
      }
    }
  }
  return -1;
}
int main()
{
  int arr[7] = {23, 45, 56, 67, 78, 89, 12};
  int fun = two_sum(arr[7], 68, 7);
  cout << "pair to two sum" << fun << endl;
}