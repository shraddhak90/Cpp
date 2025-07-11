#include <iostream>

class QueueClass
{
  private:
  int arr[100];
  int size;
  int rear;
  int front;

  public:
    QueueClass();
    QueueClass(int s);
    bool isEmpty();
    bool isFull();
    void insert(int data);
    int remove();
    int getfront();
};