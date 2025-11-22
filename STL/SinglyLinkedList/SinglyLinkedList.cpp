#include<iostream>
#include <unordered_set>
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

  void setHead(Node* node)
  {
    head = node;
  }

  Node* getHead()
  {
    return head;
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
  void getMiddle();
  int getLength();
  Node* mergeTwoSortedLL(Node* head1, Node* head2);
  Node* AddTwoLinkedLists(Node* head1, Node* head2);
  int nthNodeFromEnd(Node* head, int n);
  bool isPalindrome(Node* head);
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
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr = head;

    while(curr!= nullptr)
    {
        next = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = next;
    }
}

bool SinglyLinkedList::detectCycle()
{
    Node* slow = head;
    Node* fast = fast = head;

    while( slow && fast && fast->getNext())
    {
        slow= slow->getNext();
        fast = fast->getNext()->getNext();

        if (slow== fast)
        {
            return true
        }
    }
    return false;
}

void SinglyLinkedList::printReverse()
{
    printReverse(head);
}

void SinglyLinkedList::printReverse(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        printReverse(node->getNext());
        std::cout<<node->getData()<<" ";
    }
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

 // 10 -> 20 -> 20 -> 30 -> 40 ->nullptr
void SinglyLinkedList::deleteDuplicateFromSorted()
{
    Node* curr = head;

    while (curr!= nullptr && curr->getNext()!=nullptr)
    {
        if (curr->getData() == curr->getNext()->getData())
        {
            Node* temp = curr->getNext();
            curr->setNext(temp->getNext());
            delete temp;
        }
        else
        {
            curr =curr->getNext();
        }
    }
}

//20 -> 10 -> 10 -> 50 -> 30 -> nullptr

void SinglyLinkedList::deleteDuplicateFromUnSorted()
{
   Node* curr = head;
   Node* prev = nullptr;

   std::unordered_set<int> seen;

   while(curr != nullptr)
   {
     if (seen.count(curr->getData()))
     {
        prev->setNext(curr->getNext());
        delete curr;
        curr = prev->getNext();
     }
     else
     {
        seen.insert(curr->getData());
        prev = curr;
        curr= curr->getNext();
     }
   }
}

int SinglyLinkedList::getLength()
{
    int l =0;
    Node* trav = head;

    while(trav)
    {
        l++;
        trav = trav->getNext();
    }
    return l;
}

void SinglyLinkedList::getMiddle()
{
  Node* trav = head;
  int length = getLength();

  int mid = length/2;
  while (mid--)
  {
    trav = trav->getNext();
  }
  std::cout<<"Middle elementh: "<<trav->getData()<<std::endl;
}

Node* mergeTwoSortedLL(Node* head1, Node* head2)
{
    Node dummy;
    Node* tail = &dummy;

    while(head1 != nullptr && head2!=nullptr)
    {
        if (head1->getData() <= head2->getData())
        {
            tail->setNext(head1);
            head1 = head1->getNext();
        }
        else
        {
            tail->setNext(head2);
            head2 = head2->getNext();
        }
        tail = tail->getNext();
    }

    if (head1 != nullptr)
    {
        tail->setNext(head1);
    }
    if (head2 != nullptr)
    {
        tail->setNext(head2);
    }
    return dummy.getNext();
}

Node* MergeTwoSortedLists(Node* head1, Node* head2)
{
    if (head1 == nullptr) 
    {
        return head2
    }
    if (head2 == nullptr)
    {
        return head1;
    }

    if (head1->getData() <= head2->getData())
    {
        head1->setNext(MergeTwoSortedLists(head1->getNext(), head2));
        return head1;
    }
    else
    {
        head2->setNext(MergeTwoSortedLists(head2->getNext(), head1));
        return head2;
    }
}

Node* SinglyLinkedList::AddTwoLinkedLists(Node* head1, Node* head2)
{
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);
    
    Node* sum = nullptr;
    int carry =0;

    while (head1 != nullptr || head2 != nullptr || carry !=0)
    {
        int newval = carry;

        if (head1)
        {
            newval += head1->getData();
            head1 = head1->getNext();
        }

        if (head2)
        {
            newval+= head2->getData();
            head2 = head2->getNext();
        }

        carry = newval /10;

        newval = newval % 10;

        Node* newNode = new Node(newval);
        newNode->setNext(sum);
        sum = newNode;
    }

    //Remove leading zeros if any

    while (sum!= nullptr ** sum->getData()== 0)
    {
        Node* temp = sum;
        sum = sum->getNext();
        delete temp;
    }

    //if result is empty return single node with 0
    if (sum == nullptr)
    {
        return new Node(0);
    }
    return sum;
}

int SinglyLinkedList::nthNodeFromEnd(Node* head, int n)
{
    Node* mainPtr = head;
    Node* refPtr = head;

    for (int i = 1 ;i <n ;i++)
    {
        refPtr = refPtr->getNext();

        if (refPtr == nullptr)
        {
            return -1;
        }
    }

    while (refPtr->getNext != nullptr)
    {
        mainPtr = mainPtr->getNext();
        refPtr = refPtr->getNext();
    }

    return mainPtr->getData();
}

bool SinglyLinkedList::isPalindrome(Node* head)
{
    Node* curr  = head;
    std::stack<int> s;

    while (curr != nullptr)
    {
       s.push(curr->getData())
       curr = curr->getNext();
    }

    while (head ! = nullptr)
    {
        int top = s.top();
        s.pop();

        if (head->getData()!= top)
        {
            return false;
        }
        head = head->getNext();
    }
    return true;
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

    /* s1.removefrmBegin();
    s1.display();

    s1.removefrmEnd();
    s1.display();

    s1.insertAtEnd(50);
    s1.insertAtEnd(60);
    s1.display();

    s1.removefrmPos(3);
    s1.display(); */

    s1.reverseLL();
    s1.display();

    /* s1.printReverse();

    s1.reverseLL();
    s1.display();

    s1.insertAtPos(20, 1);
    s1.display();

    s1.deleteDuplicateFromSorted();
    s1.display();

    s1.insertAtBegin(20);
    s1.display();

    s1.deleteDuplicateFromUnSorted();
    s1.display();

    s1.insertAtEnd(70);

    s1.getMiddle(); */

    SinglyLinkedList s2, mergedList;
    s2.insertAtEnd(80);
    s2.insertAtEnd(90);
    s2.insertAtEnd(100);
    s2.display();


    Node* s3 = mergeTwoSortedLL(s1.getHead(), s2.getHead());
    mergedList.setHead(s3);
    mergedList.display();
    return 0;
}