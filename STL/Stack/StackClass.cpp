#include "StackClass.h"

StackClass::StackClass()
{
    size = 5;
    top = -1;
}

StackClass::StackClass(int s)
{
    size = s;
    top = -1;
}

bool StackClass::isFull()
{
  if (top = size -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool StackClass::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void StackClass::push(int data)
{
    if (!isFull())
    {
        arr[++top] = data;
    }
    else
    {
        std::cout<<"Stack is full\n";
    }
}

int StackClass::pop()
{
    if (!isEmpty())
    {
        return arr[top--];
    }
    else
    {
        return -1;
    }
}

int StackClass::peek()
{
    if(!isEmpty())
    {
        int elem = arr[top];
        return elem;
    }
    else
    {
        return 0;
    }
}