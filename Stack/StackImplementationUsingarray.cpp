#include <iostream>
using namespace std;

class Stack
{
public:
  int top;
  int size;
  int *arr;

  // Constructor
  Stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  // Destructor to free memory
  ~Stack()
  {
    delete[] arr;
  }

  void push(int element)
  {
    if (top < size - 1)
    {
      top++;
      arr[top] = element;
    }
    else
    {
      cout << "Stack is overflow" << endl;
    }
  }

  void pop()
  {
    if (top >= 0)
    {
      top--;
    }
    else
    {
      cout << "Stack is underflow" << endl;
    }
  }

  bool ISempty()
  {
    return top == -1;
  }

  int peak()
  {
    if (top >= 0)
    {
      return arr[top];
    }
    else
    {
      cout << "Stack is empty" << endl;
      return -1;
    }
  }
};

int main()
{
  Stack s(5);
  s.push(10);
  s.push(23);
  s.push(123);

  cout << "Top element: " << s.peak() << endl;
  s.pop();
  cout << "Top element: " << s.peak() << endl;

  return 0;
}
