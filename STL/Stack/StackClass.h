#include <iostream>
#define MAXSIZE 50

class StackClass
{
    private:
    int arr[MAXSIZE];
    int top;
    int size;

    public:
    StackClass();
    StackClas(int size);
    void push(int data);
    int pop();
    //int top();
    int peek();
    bool isEmpty();
    bool isFull();
}