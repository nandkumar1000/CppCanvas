#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

// Insert at head
void insertAthead(Node *&head, int d)
{
  Node *temp = new Node(d);
  temp->next = head;
  head = temp;
}

// Insert at tail
void insertAttail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

// Insert at a specific position
void insertAtposition(Node *&head, Node *&tail, int position, int data)
{
  if (position == 1)
  {
    insertAthead(head, data);
    return;
  }

  Node *temp = head;
  int cnt = 1;

  while (cnt < position - 1 && temp->next != NULL)
  {
    temp = temp->next;
    cnt++;
  }

  if (temp->next == NULL)
  {
    insertAttail(tail, data);
    return;
  }

  // Creating a node for insertion
  Node *newnode = new Node(data);
  newnode->next = temp->next;
  temp->next = newnode;
}

// Print linked list
void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *node1 = new Node(10);
  cout << "Initial Node: " << node1->data << endl;

  // Head and tail pointer
  Node *head = node1;
  Node *tail = node1;

  print(head);

  insertAthead(head, 12);
  print(head);

  insertAttail(tail, 15);
  print(head);

  insertAtposition(head, tail, 3, 35);
  print(head);

  return 0;
}
