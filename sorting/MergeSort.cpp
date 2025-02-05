#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
  int n1 = mid - start + 1, n2 = end - mid, i = 0, j = 0, k = start;
  int left[n1], right[n2];

  for (; i < n1; i++)
    left[i] = arr[start + i];
  for (; j < n2; j++)
    right[j] = arr[mid + 1 + j];

  i = j = 0;
  while (i < n1 && j < n2)
    arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
  while (i < n1)
    arr[k++] = left[i++];
  while (j < n2)
    arr[k++] = right[j++];
}

void mergesort(int arr[], int start, int end)
{
  if (start >= end)
    return;
  int mid = start + (end - start) / 2;
  mergesort(arr, start, mid);
  mergesort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int arr[] = {12, 3456, 67, 4357, 78, 3, 6, 7, 23}, n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original: ";
  printArray(arr, n);
  mergesort(arr, 0, n - 1);
  cout << "Sorted: ";
  printArray(arr, n);

  return 0;
}
