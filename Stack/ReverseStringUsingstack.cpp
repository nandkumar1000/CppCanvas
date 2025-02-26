#include <iostream>
#include <stack>
using namespace std;

string reverseString(string input)
{
  stack<char> s;

  // Push all characters onto the stack
  for (char ch : input)
  {
    s.push(ch);
  }

  // Pop all characters to form the reversed string
  string reversed = "";
  while (!s.empty())
  {
    reversed += s.top();
    s.pop();
  }

  return reversed;
}

int main()
{
  string str = "Hello";
  cout << "Original String: " << str << endl;
  cout << "Reversed String: " << reverseString(str) << endl;
  return 0;
}
