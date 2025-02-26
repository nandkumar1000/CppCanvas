#include <iostream>
using namespace std;

int maxProfit(int arr[], int size)
{
  int minPrice = arr[0];
  int maxProfit = 0;

  for (int i = 1; i < size; i++)
  {

    if (arr[i] < minPrice)
    {
      minPrice = arr[i];
    }

    else
    {
      int profit = arr[i] - minPrice;
      maxProfit = max(maxProfit, profit);
    }
  }
  return maxProfit;
}

int main()
{
  int arr[] = {7, 1, 5, 3, 6, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << "Maximum Profit: " << maxProfit(arr, size) << endl;
  return 0;
}
