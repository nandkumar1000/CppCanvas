#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  // Constructor
  Node(int data)
  {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
};

// Function to insert at head
void insertAtHead(Node *&head, Node *&tail, int data)
{
  Node *newNode = new Node(data);
  if (head == NULL)
  {
    head = tail = newNode;
    return;
  }
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

// Function to insert at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
  Node *newNode = new Node(data);
  if (tail == NULL)
  {
    head = tail = newNode;
    return;
  }
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

// Function to insert at any position
void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
  if (position == 1)
  {
    insertAtHead(head, tail, data);
    return;
  }

  Node *temp = head;
  int count = 1;

  while (temp != NULL && count < position - 1)
  {
    temp = temp->next;
    count++;
  }

  if (temp == NULL)
  {
    cout << "Position out of range!" << endl;
    return;
  }

  if (temp->next == NULL)
  {
    insertAtTail(head, tail, data);
    return;
  }

  // Insert in the middle
  Node *newNode = new Node(data);
  newNode->next = temp->next;
  newNode->prev = temp;
  temp->next->prev = newNode;
  temp->next = newNode;
}

// Function to print the list (forward)
void printForward(Node *head)
{
  Node *temp = head;
  cout << "Forward: ";
  while (temp != NULL)
  {
    cout << temp->data << " <-> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

// Function to print the list (reverse)
void printReverse(Node *tail)
{
  Node *temp = tail;
  cout << "Reverse: ";
  while (temp != NULL)
  {
    cout << temp->data << " <-> ";
    temp = temp->prev;
  }
  cout << "NULL" << endl;
}

int main()
{
  Node *head = NULL;
  Node *tail = NULL;

  insertAtHead(head, tail, 10);
  insertAtHead(head, tail, 20);
  insertAtTail(head, tail, 30);
  insertAtTail(head, tail, 40);
  insertAtPosition(head, tail, 3, 25);

  printForward(head);
  printReverse(tail);

  return 0;
}
