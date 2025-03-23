#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
private:
  ListNode *ansHead = nullptr;
  ListNode *ansTail = nullptr;

  // Function to insert a node at the end of the linked list
  void insertAtTail(ListNode *&head, ListNode *&tail, int val)
  {
    ListNode *temp = new ListNode(val);
    if (!head)
    {
      head = temp;
      tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0;

    while (l1 || l2 || carry)
    {
      int sum = carry;
      if (l1)
      {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2)
      {
        sum += l2->val;
        l2 = l2->next;
      }

      int digit = sum % 10;
      carry = sum / 10;

      insertAtTail(ansHead, ansTail, digit);
    }

    return ansHead;
  }
};

// Function to print a linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

// Helper function to create a linked list from an array
ListNode *createLinkedList(int arr[], int size)
{
  ListNode *head = nullptr, *tail = nullptr;
  for (int i = 0; i < size; i++)
  {
    ListNode *temp = new ListNode(arr[i]);
    if (!head)
    {
      head = temp;
      tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }
  return head;
}

int main()
{
  int arr1[] = {2, 4, 3};
  int arr2[] = {5, 6, 4};

  ListNode *l1 = createLinkedList(arr1, 3);
  ListNode *l2 = createLinkedList(arr2, 3);

  Solution sol;
  ListNode *result = sol.addTwoNumbers(l1, l2);

  cout << "Result: ";
  printList(result);

  return 0;
}
