#include <iostream>
using namespace std;

class circularqueue
{
  int *arr;
  int size;
  int front;
  int rear;

public:
  circularqueue(int n)
  {
    size = n;
    arr = new int[n];
    front = rear = -1;
  }

  // Enqueue operation
  void enqueue(int data)
  {
    if ((rear + 1) % size == front)
    {
      cout << "Queue is full" << endl;
      return;
    }
    else if (front == -1)
    {
      front = rear = 0;
    }
    else if (rear == size - 1 && front != 0)
    {
      rear = 0;
    }
    else
    {
      rear++;
    }
    arr[rear] = data;
  }

  // Dequeue operation
  int dequeue()
  {
    if (front == -1)
    {
      cout << "Queue is empty" << endl;
      return -1;
    }

    int ans = arr[front];
    arr[front] = -1;

    if (front == rear)
    {
      front = rear = -1;
    }
    else if (front == size - 1)
    {
      front = 0;
    }
    else
    {
      front++;
    }

    return ans;
  }

  // Display queue
  void display()
  {
    if (front == -1)
    {
      cout << "Queue is empty" << endl;
      return;
    }
    cout << "Queue: ";
    if (rear >= front)
    {
      for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    }
    else
    {
      for (int i = front; i < size; i++)
        cout << arr[i] << " ";
      for (int i = 0; i <= rear; i++)
        cout << arr[i] << " ";
    }
    cout << endl;
  }

  ~circularqueue()
  {
    delete[] arr;
  }
};

// Main function
int main()
{
  circularqueue q(5);

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.display();

  cout << "Dequeued: " << q.dequeue() << endl;
  q.enqueue(60);

  q.display();

  return 0;
}
