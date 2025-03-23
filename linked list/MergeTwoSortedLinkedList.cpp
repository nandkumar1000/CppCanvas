#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  ListNode *dummy = new ListNode(-1);
  ListNode *temp = dummy;

  while (list1 && list2)
  {
    if (list1->val < list2->val)
    {
      temp->next = list1;
      list1 = list1->next;
    }
    else
    {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }

  temp->next = list1 ? list1 : list2;

  return dummy->next;
}

// Function to insert a node at the end of the linked list
void insertAtTail(ListNode *&head, int val)
{
  if (!head)
  {
    head = new ListNode(val);
    return;
  }
  ListNode *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = new ListNode(val);
}

// Function to print the linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  ListNode *list1 = nullptr;
  ListNode *list2 = nullptr;

  insertAtTail(list1, 1);
  insertAtTail(list1, 3);
  insertAtTail(list1, 5);

  insertAtTail(list2, 2);
  insertAtTail(list2, 4);
  insertAtTail(list2, 6);

  cout << "List 1: ";
  printList(list1);

  cout << "List 2: ";
  printList(list2);

  ListNode *mergedList = mergeTwoLists(list1, list2);

  cout << "Merged List: ";
  printList(mergedList);

  return 0;
}
