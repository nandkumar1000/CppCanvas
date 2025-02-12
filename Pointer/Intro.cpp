#include <iostream>
using namespace std;
int main()
{
  int nums = 909;
  int *ptr = &nums;
  cout << nums << endl;
  cout << &nums << endl;
  cout << ptr << endl;
  cout << *ptr << endl;
  int arr[10] = {12, 34};
  int *p = &arr[10];
  cout << sizeof(*p) << endl;
  cout << sizeof(arr[10]) << endl;
  cout << sizeof(p) << endl;
  cout << sizeof(p[0]) << endl;
  cout << sizeof(&arr) << endl;
  cout << *p << endl;
  cout << *(p + 1) << endl;
  cout << arr << endl;
  cout << &arr[0] << endl;
  cout << *arr << endl;
  cout << *arr + 1 << endl;
  cout << *(arr + 1) << endl;
  cout << *(arr) + 1 << endl;
  char ch[14] = "asdf";
  char *a = &ch[14];
  cout << ch[0] << endl;
  cout << &ch[14] << endl;
  return 0;
}