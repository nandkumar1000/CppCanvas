#include <iostream>
using namespace std;
int peak(int arr[], int size)
{
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  while (start < end)
  {
    if (arr[mid] < arr[mid + 1])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;
    }
    mid = start + (end - mid) / 2;
  }
  return start;
}

int main()
{
  int arr[3] = {1, 2, 1};
  int fun = peak(arr, 3);
  cout << "Peak element is " << fun;
}