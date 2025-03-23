#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
  bool checkPalindrome(const vector<int> &arr)
  {
    int s = 0, e = arr.size() - 1;
    while (s < e)
    {
      if (arr[s] != arr[e])
      {
        return false;
      }
      s++;
      e--;
    }
    return true;
  }

public:
  bool isPalindrome(ListNode *head)
  {
    vector<int> arr;
    ListNode *temp = head;
    while (temp != nullptr)
    {
      arr.push_back(temp->val);
      temp = temp->next;
    }
    return checkPalindrome(arr);
  }
};

void insert(ListNode *&head, int val)
{
  if (head == nullptr)
  {
    head = new ListNode(val);
    return;
  }
  ListNode *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = new ListNode(val);
}

void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main()
{
  ListNode *head = nullptr;
  insert(head, 1);
  insert(head, 2);
  insert(head, 2);
  insert(head, 1);

  cout << "Linked List: ";
  printList(head);

  Solution sol;
  if (sol.isPalindrome(head))
  {
    cout << "The linked list is a palindrome.\n";
  }
  else
  {
    cout << "The linked list is NOT a palindrome.\n";
  }

  return 0;
}
