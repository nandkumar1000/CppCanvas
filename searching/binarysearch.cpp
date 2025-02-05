#include <iostream>
using namespace std;
int binary_search(int arr[], int key, int size)
{
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      return mid;
    }
    if (key > mid)
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

int main()
{
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int fun = binary_search(arr, 2, 6);
  cout << "result of binary search" << " =" << fun << endl;
}