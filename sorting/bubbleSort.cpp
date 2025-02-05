#include <iostream>
using namespace std;
int bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void prin(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[9] = {12, 34, 56, 7, 889, 4, 51, 2, 32};
    bubblesort(arr, 9);
    cout << "sorted array is " << "" << endl;
    prin(arr, 9);
    return 0;
}