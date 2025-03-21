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

  // Destructor
  ~Node()
  {
    cout << "Deleting Node with data: " << data << endl;
  }
};

// Function to insert a node at the end
void insertAtEnd(Node *&head, int data)
{
  Node *newNode = new Node(data);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to delete a node at a specific position
void deleteNode(Node *&head, int position)
{
  if (head == NULL)
  {
    cout << "List is empty, nothing to delete!" << endl;
    return;
  }

  Node *temp = head;

  // If deleting the head node
  if (position == 1)
  {
    head = head->next;
    delete temp;
    return;
  }

  Node *prev = NULL;
  int count = 1;

  // Traverse to the node before the position
  while (temp != NULL && count < position)
  {
    prev = temp;
    temp = temp->next;
    count++;
  }

  // If position is beyond the list length
  if (temp == NULL)
  {
    cout << "Position out of bounds!" << endl;
    return;
  }

  prev->next = temp->next; // Bypass the node to be deleted
  delete temp;
}

// Function to print the linked list
void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  Node *head = NULL;

  // Insert some nodes
  insertAtEnd(head, 10);
  insertAtEnd(head, 20);
  insertAtEnd(head, 30);
  insertAtEnd(head, 40);

  cout << "Original List: ";
  printList(head);

  // Delete node at position 2
  deleteNode(head, 2);
  cout << "After Deletion at Position 2: ";
  printList(head);

  return 0;
}
