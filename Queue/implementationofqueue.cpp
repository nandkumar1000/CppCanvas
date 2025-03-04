#include <iostream>
using namespace std;

class Queue
{
  int *arr;
  int size;
  int front;
  int rear;

public:
  // Constructor
  Queue(int n)
  {
    size = n;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  // Check if queue is empty
  bool isEmpty()
  {
    return (rear == front);
  }

  // Enqueue operation
  void enqueue(int data)
  {
    if (rear == size)
    {
      cout << "Queue is full" << endl;
      return;
    }
    arr[rear] = data;
    rear++;
  }

  // Dequeue operation
  int dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty" << endl;
      return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
    front++;

    // Reset queue when empty
    if (front == rear)
    {
      front = 0;
      rear = 0;
    }
    return ans;
  }

  // Get front element
  int getFront()
  {
    if (isEmpty())
    {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return arr[front];
  }

  // Destructor to free memory
  ~Queue()
  {
    delete[] arr;
  }
};

// Main function
int main()
{
  Queue q(6);

  q.enqueue(12);
  q.enqueue(34);
  q.enqueue(5667);
  q.enqueue(78);
  q.enqueue(546);

  cout << "Front element: " << q.getFront() << endl;
  cout << "Dequeued: " << q.dequeue() << endl;
  cout << "Dequeued: " << q.dequeue() << endl;
  cout << "Front element after dequeue: " << q.getFront() << endl;

  return 0;
}
