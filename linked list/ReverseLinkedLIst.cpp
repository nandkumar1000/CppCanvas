#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int d)
  {
    this->data = d;
    this->next = nullptr;
  }

  Node *ReverseLinklist()
  {
    Node *prev = nullptr;
    Node *current = this;
    Node *next = nullptr;

    while (current != nullptr)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    return prev;
  }
};

void printList(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  cout << "Original Linked List: ";
  printList(head);

  head = head->ReverseLinklist();

  cout << "Reversed Linked List: ";
  printList(head);

  return 0;
}
