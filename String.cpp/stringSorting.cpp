#include <iostream>
#include <string>
using namespace std;
int main()
{
  // sorting of string by the use of sort inbuilt function;
  // string str = "nandkumar";
  // string sorted_str = str;
  // sort(sorted_str.begin(), sorted_str.end());
  // cout << "Sorted string is: " << sorted_str << endl;

  // sorting of string by the use of ascii value;
  string str;
  cout << "enter the string" << endl;
  cin >> str;
  string sorted_str = str;
  for (int i = 0; i < str.length(); i++)
  {
    for (int j = i + 1; j < str.length(); j++)
    {
      if (str[i] > str[j])
      {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  cout << "Sorted string is: " << str << endl;

  return 0;
}