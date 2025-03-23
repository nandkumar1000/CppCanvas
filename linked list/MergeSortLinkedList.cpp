#include <iostream>
using namespace std;

// Node structure for Linked List
class Node
{
public:
  int data;
  Node *next;

  Node(int d)
  {
    data = d;
    next = NULL;
  }
};

// Function to insert a node at the end of the linked list
void insertAtTail(Node *&head, int data)
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

// Function to print the linked list
void printList(Node *head)
{
  while (head != NULL)
  {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// Function to find the middle node of the linked list
Node *findMid(Node *head)
{
  if (head == NULL)
    return NULL;

  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Function to merge two sorted linked lists
Node *merge(Node *left, Node *right)
{
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;

  Node *dummy = new Node(-1);
  Node *temp = dummy;

  while (left != NULL && right != NULL)
  {
    if (left->data < right->data)
    {
      temp->next = left;
      left = left->next;
    }
    else
    {
      temp->next = right;
      right = right->next;
    }
    temp = temp->next;
  }

  // Attach remaining elements
  if (left != NULL)
    temp->next = left;
  if (right != NULL)
    temp->next = right;

  Node *sortedList = dummy->next;
  delete dummy;
  return sortedList;
}

// Merge Sort function for linked list
Node *mergeSort(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  // Split the list into two halves
  Node *mid = findMid(head);
  Node *left = head;
  Node *right = mid->next;
  mid->next = NULL;

  // Recursively sort both halves
  left = mergeSort(left);
  right = mergeSort(right);

  // Merge the sorted halves
  return merge(left, right);
}

// Driver code
int main()
{
  Node *head = NULL;

  // Insert elements into the linked list
  insertAtTail(head, 10);
  insertAtTail(head, 3);
  insertAtTail(head, 7);
  insertAtTail(head, 15);
  insertAtTail(head, 2);

  cout << "Original Linked List:" << endl;
  printList(head);

  // merge sort
  head = mergeSort(head);

  cout << "Sorted Linked List:" << endl;
  printList(head);

  return 0;
}
