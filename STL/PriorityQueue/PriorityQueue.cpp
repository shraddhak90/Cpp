#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    size = 10;
    front=rear =-1;
}

PriorityQueue::PriorityQueue(int s)
{
    size = s;
    front=rear =-1;
}

void PriorityQueue::insert(Entity e)
{
    //int i;
    if (rear == -1 )
    {
        front = rear = 0;
        arr[rear] = e;
    }
    else
    {
      int i;
      for (i = rear; arr[i].getPriority() < e.getPriority() && i >= front ; i--)
      {
        arr[i+1] = arr[i];
      }
      arr[i+1] = e;
      rear++;
    }
}

Entity PriorityQueue::remove()
{
    if (!isEmpty())
    {
       Entity e = arr[front];
       front++;
       return e;
    }
    return Entity() ;
}

bool PriorityQueue::isEmpty()
{
    return front== -1 || front > rear;
}


bool PriorityQueue::isFull()
{
    return rear == size -1;
}