#include <iostream>
#include <string>
using namespace std;
int main()
{
  // finding sub string
  string str = "nandkumar";

  cout << "The sub string of this string" << "=" << str.substr(0, 3) << endl;
  cout << "The sub string of this string" << "=" << str.substr(2) << endl;
  // concateation
  string s1 = "nand";
  string s2 = "kumar";
  s1 += s2;
  cout << "The string after concateation" << "=" << s1 << endl;
  // strcat for character array
  char ch[23] = "andslkdjf";
  char ch2[23] = "lasdjfkl";
  // strcat(ch, ch2);
  cout << "The string after concateation" << "=" << ch << endl;
  string n = "sd";
  char sd = 'e';
  n.push_back(sd);
  cout << "The string after push_back" << "=" << n << endl;
  // for finding size
  cout << "The size of string" << "=" << n.size() << n.length() << endl;
  // for converting num into strint by the use of to_string
  int num = 12345;
  cout << "The string after converting num into string" << "=" << to_string(num) << endl;
  string s4 = to_string(num);
  s4 += "1342";
  cout << "The string after converting num into string" << "=" << s4 << endl;
}