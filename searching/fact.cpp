#include <iostream>
using namespace std;
int fact(int n)
{
  int fact = 1;
  while (n > 1)
  {
    fact = fact * n;
    n--;
  }
  cout << fact;
}
int main()
{
  int a;
  cout << "enter a number";
  cin >> a;
  int fun = fact(a);
}
