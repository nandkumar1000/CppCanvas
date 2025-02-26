 #include <iostream>
using namespace std;

class twostack
{
public:
  int top1, top2;
  int *arr;
  int size;

  // Constructor
  twostack(int size)
  {
    this->size = size;
    top1 = -1;
    top2 = size;
    arr = new int[size];
  }

  // Destructor
  ~twostack()
  {
    delete[] arr;
  }

  // Push in stack 1
  void push1(int data)
  {
    if (top2 - top1 > 1)
    { // Fixing the condition
      top1++;
      arr[top1] = data;
    }
    else
    {
      cout << "Stack Overflow\n";
    }
  }

  // Push in stack 2
  void push2(int data)
  {
    if (top2 - top1 > 1)
    {
      top2--;
      arr[top2] = data;
    }
    else
    {
      cout << "Stack Overflow\n";
    }
  }

  // Pop from stack 1
  int pop1()
  { 
    if (top1 >= 0)
    {
      int ans = arr[top1];
      top1--;
      return ans;
    }
    else
    {
      cout << "Stack Underflow\n";
      return -1;
    }
  }

  // Pop from stack 2
  int pop2()
  { 
    if (top2 < size)
    {
      int ans = arr[top2];
      top2++;
      return ans;
    }
    else
    {
      cout << "Stack Underflow\n";
      return -1;
    }
  }

  // Peek function (Example for stack 1)
  int peek1()
  {
    if (top1 >= 0)
    {
      return arr[top1];
    }
    else
    {
      cout << "Stack is empty\n";
      return -1;
    }
  }

  // Peek function (Example for stack 2)
  int peek2()
  {
    if (top2 < size)
    {
      return arr[top2];
    }
    else
    {
      cout << "Stack is empty\n";
      return -1;
    }
  }
};

int main()
{
  twostack t(5);
  t.push1(1);
  t.push2(342);

  cout << "Top of Stack 1: " << t.peek1() << endl;
  cout << "Top of Stack 2: " << t.peek2() << endl;

  return 0;
}
