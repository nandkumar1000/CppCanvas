#include <iostream>
using namespace std;

void Insertionsort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

void printarray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[9] = {2, 34, 56, 778, 12, 34, 1245, 23, 45};

  Insertionsort(arr, 9);

  cout << "Sorted array is: ";
  printarray(arr, 9);

  return 0;
}
