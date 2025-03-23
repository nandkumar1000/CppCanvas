#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    this->data = value;
    this->next = nullptr;
  }
};

bool isCircular(Node *head)
{
  if (head == nullptr)
    return false;

  Node *slow = head;
  Node *fast = head;

  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      return true;
    }
  }

  return false;
}

int main()
{
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);

  head->next = second;
  second->next = third;
  third->next = head;

  if (isCircular(head))
  {
    cout << "The linked list is circular." << endl;
  }
  else
  {
    cout << "The linked list is not circular." << endl;
  }

  return 0;
}
