#include <iostream>
using namespace std;
void fun(int *ptr)
{
  cout << *ptr << endl;
}
int main()
{
  int value = 89;
  int *ptr = &value;
  fun(ptr);

  return 0;
}