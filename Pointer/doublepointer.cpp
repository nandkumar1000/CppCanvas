#include <iostream>
using namespace std;
void update(int **ptr)
{
  **ptr = 20;
}
int main()
{
  int a = 10;
  int *p = &a;
  update(&p);
  cout << a; 
}
