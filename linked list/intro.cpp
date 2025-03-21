#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int val)
  {
    data = val;
    next = NULL;
  }
};
class List
{
  Node *head;
  Node *tail;

public:
  List()
  {
    head = NULL;
    tail = NULL;
  }
  void push_front(int val)
  {
    Node *new_node = new Node(val);
    if (head == NULL)
    {
      head = tail = new_node;
      return;
    }
    else
    {
      new_node->next = head;
      head = new_node;
    }
  }
  void pop_front()
  {
    if (head == NULL)
    {
      cout << "linkedlist is empty" << endl;
      return;
    }
    else
    {
      Node *temp = head;
      head = head->next;
      temp->next = NULL;
      delete temp;
    }
  }
  void push_back()
  {
    Node *new_node = new Node(val);
    if (head == NULL)
    {
      head = tail = new_node;
      return;
    }
    else
    {
      tail->next = new_node;
      tail = new_node;
    }
  }
  void pop_back()
  {
    if (head == NULL)
    {
      cout << "linkedlist is empty" << endl;
      return;
    }
    else if (head->next == NULL)
    {
      delete head;
      head = tail = NULL;
    }
    else
    {
      Node *temp = head;
      while (temp->next != tail)
      {
        temp = temp->next;
      }
      delete tail;
      tail = temp;
      temp->next = NULL;
    }
  }
  void printall()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};
int main()
{
  List l1;
  l1.push_front(1);
  l1.push_front(2);
  l1.push_front(7);
  l1.push_front(9);
  // l1.push_back(8);
  l1.pop_front();
  l1.pop_back();
  l1.printall();
  l1.pop_front();
  l1.printall();
  l1.pop_back();
  l1.printall();
  return 0;
}