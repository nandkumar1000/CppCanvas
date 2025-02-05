// by using binary search
#include <iostream>
using namespace std;
int firstOccure(int arr[], int size, int key)
{
  int ans = -1;
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      ans = mid;
      end = mid - 1;
    }
    else if (arr[mid] < key)
    {
      start = mid + 1;
    }
    else if (arr[mid] > key)
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}
int LastOcuure(int arr[], int size, int key)
{
  int ans = -1;
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    if (arr[mid] == key)
    {
      ans = mid;
      start = mid + 1;
    }
    else if (arr[mid] < key)
    {
      start = mid + 1;
    }
    else if (arr[mid] > key)
    {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}
int main()
{
  int arr[10] = {1, 2, 2, 3, 3, 3, 4, 5, 6, 7};
  int fun = firstOccure(arr, 10, 3);
  int gun = LastOcuure(arr, 10, 3);
  cout << " the first occurrence = " << fun << " " << "the last index occurence = " << gun << endl;
}