#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
  int pivot = arr[start], i = start + 1, j = end;

  while (i <= j)
  {
    while (i <= end && arr[i] <= pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[start], arr[j]);
  return j; 
}

void quicksort(int arr[], int start, int end)
{
  if (start >= end)
    return;
  int p = partition(arr, start, end);
  quicksort(arr, start, p - 1);
  quicksort(arr, p + 1, end);
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int arr[] = {1, 2, 345, 56, 6, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original: ";
  printArray(arr, n);

  quicksort(arr, 0, n - 1);

  cout << "Sorted: ";
  printArray(arr, n);

  return 0;
}
