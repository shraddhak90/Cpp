#include<iostream>
#include "Node.h"

class SinglyLinkedList
{
  private:
    Node* head;
  
  public:
  SinglyLinkedList() 
  {
    head = NULL;
  }

  void insertAtBegin(int data);
  void insertAtEnd(int data);
  void insertAtPos(int data, int pos);
  void removefrmBegin();
  void removefrmEnd();
  void removefrmPos(int pos);
  void display();
  void reverseLL();
  bool detectCycle();
  void insertInAsc(int data);
  void deleteDuplicate();
  void deleteDuplicateFromSorted();
  void deleteDuplicateFromUnSorted();
  void printReverse();
  void printReverse(Node *);
};

void SinglyLinkedList::insertAtBegin(int data)
{
    Node* newNode = new Node();
    newNode->setNext(nullptr);
    newNode->setData(data);

    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->setNext(head);
        head = newNode;
    }
}

void SinglyLinkedList::insertAtEnd(int data)
{
    Node* trav = head;
    Node* newNode = new Node();
    newNode->setNext(nullptr);
    newNode->setData(data);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        while(trav->getNext() != nullptr)
        {
            trav = trav->getNext();
        }
        trav->setNext(newNode);
    }
}
 
//pos = 2  1
  //  head -> 1 -> 2 -> 3 -> 4 -> nullptr
void SinglyLinkedList::insertAtPos(int data, int pos)
{
    int i =0;
    Node* trav = head;
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(nullptr);

    if (head == nullptr || pos == 0)
    {
        newNode->setNext(head);
        head = newNode;
    }
    else
    {
        while (trav != nullptr && i < pos-1)
        {
            trav = trav->getNext();
            i++;
        }
        newNode->setNext(trav->getNext());
        trav->setNext(newNode);
    }
}

void SinglyLinkedList::removefrmBegin()
{
    if (head == nullptr)
    {
      return;
    }

    Node* trav = head;
    head = head->getNext();
    trav->setNext(nullptr);
    delete trav;
}

void SinglyLinkedList::removefrmEnd()
{
    if (head == nullptr)
    {
      return;
    }

    if (head->getNext() == nullptr)
    {
      delete head;
      head = nullptr;
      return;
    }

    Node* trav = head;
    while( trav->getNext()->getNext() != nullptr)
    {
        trav = trav->getNext();
    }
    delete (trav->getNext());
    trav->setNext(nullptr);
}

void SinglyLinkedList::removefrmPos(int pos)
{
    Node* trav = head;
    Node* temp = nullptr;

    for(int i =0 ;i< pos-1; i++)
    {
      temp = trav;
      trav = trav->getNext();
    }
    //delete trav;
    temp->setNext(trav->getNext());
    delete trav;
}

void SinglyLinkedList::reverseLL()
{
    Node* curr = head;
    Node* next=nullptr;
    Node* prev=nullptr;

    while (curr!=nullptr)
    {
        next = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool SinglyLinkedList::detectCycle()
{
    Node* slow = head;
    Node* fast = head;

    while (fast!=nullptr && fast->getNext() !=nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();

        if (slow == fast)
        {
          return true;
        }
    }
    return false;
}

void SinglyLinkedList::display()
{
    Node* temp = head;
    while(temp !=nullptr)
    {
        std::cout<< temp->getData()<<" ";
        temp = temp->getNext();
    }
    std::cout<<"\n-----------------------------------------\n";
}

int main()
{
    SinglyLinkedList s1;
    s1.insertAtBegin(10);
    s1.display();

    s1.insertAtEnd(30);
    s1.insertAtEnd(40);
    s1.insertAtEnd(50);
    s1.display();

    s1.insertAtPos(20, 1);
    s1.display();

    s1.removefrmBegin();
    s1.display();

    s1.removefrmEnd();
    s1.display();

    s1.insertAtEnd(50);
    s1.insertAtEnd(60);
    s1.display();

    s1.removefrmPos(3);
    s1.display();

    s1.reverseLL();
    s1.display();
    return 0;
}