#include "QueueClass.h"

QueueClass::QueueClass()
{
    size = 10;
    front = rear = -1;
}

QueueClass::QueueClass(int s)
{
    size = s;
    front = rear = -1;
}

bool QueueClass::isEmpty()
{
    return rear==front;
}

bool QueueClass::isFull()
{
    return rear == size-1;
}

void QueueClass::insert(int data)
{
    if (!isFull())
    {
        arr[++rear] = data;
    }
    else
        std::cout<<"QueueClass is full"<<std::endl;
}

int QueueClass::remove()
{
    if (!isEmpty())
    {
        return arr[++front];
    }
    else
    {
        std::cout <<"QueueClass is empty"<<std::endl;
        return -1;
    }
}

int QueueClass::getfront()
{
   if (!isEmpty())
   {
    return arr[front + 1];
   }
   else
   {
     return -1;
   }
}