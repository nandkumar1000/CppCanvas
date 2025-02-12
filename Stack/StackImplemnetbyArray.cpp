// by using array
#include <iostream>
using namespace std;
class stack
{
public:
  int top;
  int size;
  int *arr;
  stack(int n);

}

int main()
{
  stack s(5);
  s.top = -1;
  s.size = 5;
  return 0;
}