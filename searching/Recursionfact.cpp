#include <iostream>
using namespace std;
int fact(int a)
{

  if (a < 1)
  {
    return 1;
  }
  else
  {
    return a * fact(a - 1);
  }
}
int main()
{
  int x;
  cout << "enter the value" << endl;
  cin >> x;
  int fun = fact(x);
  cout << fun << endl;
}