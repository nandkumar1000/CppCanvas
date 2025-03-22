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
    this->next = NULL;
  }

  // Destructor
  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete this->next;
      this->next = NULL;
    }
    cout << "Memory is free for node with data: " << value << endl;
  }
};

// Insert at Head in Circular Linked List
void insertAtHead(Node *&tail, int d)
{
  Node *newNode = new Node(d);

  if (tail == NULL)
  { // Empty List Case
    tail = newNode;
    tail->next = newNode;
  }
  else
  {
    newNode->next = tail->next;
    tail->next = newNode;
  }
}

// Insert at Tail in Circular Linked List
void insertAtTail(Node *&tail, int d)
{
  insertAtHead(tail, d);
  tail = tail->next;
}

// Insert After a Given Value in Circular Linked List
void insertAfter(Node *&tail, int target, int d)
{
  if (tail == NULL)
    return;

  Node *curr = tail;
  do
  {
    if (curr->data == target)
    {
      Node *newNode = new Node(d);
      newNode->next = curr->next;
      curr->next = newNode;

      if (curr == tail)
      {
        tail = newNode;
      }
      return;
    }
    curr = curr->next;
  } while (curr != tail);
}

// Print Circular Linked List
void print(Node *tail)
{
  if (tail == NULL)
  {
    cout << "List is empty!" << endl;
    return;
  }

  Node *temp = tail->next;
  do
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  } while (temp != tail->next);
  cout << "(Back to Head)" << endl;
}

int main()
{
  Node *tail = NULL;

  insertAtTail(tail, 10);
  insertAtTail(tail, 20);
  insertAtTail(tail, 30);
  insertAfter(tail, 20, 25);

  cout << "Circular Linked List: " << endl;
  print(tail);

  return 0;
}
