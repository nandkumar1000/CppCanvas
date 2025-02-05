#include <iostream>
using namespace std;

void selectionsort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int min_index = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min_index])
      {
        min_index = j;
      }
    }

    int temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
  }
}

void printarray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[9] = {23, 435, 45, 56, 564, 67, 789, 34, 56};

  selectionsort(arr, 9);
  cout << "Sorted array is: ";
  printarray(arr, 9);

  return 0;
}
