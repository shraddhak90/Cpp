#include <iostream>
#include "Node.h"

class DoublyLinkedList
{
    private:
    Node* head;

    public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtBegin(int data)
    {
        Node* newNode = new Node();
        newNode->setData(data);
        newNode->setNext(nullptr);
        newNode->setPrev(nullptr);
        
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node* newnode = new Node();
        newnode->setData(data);
        newnode->setNext(nullptr);
        newnode->setPrev(nullptr);

        if (head == nullptr)
        {
            head= newnode;
        }
        else
        {
            Node* trav = head;
            while (trav->getNext() != nullptr)
            {
                trav = trav->getNext(); 
            }
            trav->setNext(newnode);
            newnode->setPrev(trav);
        }
    }
// 10 -> 20 -> 30 -> 40 -> 50
    void insertAtPos(int data, int pos)
    {
        Node* newnode = new Node();
        newnode->setData(data);
        newnode->setPrev(nullptr);
        newnode->setNext(nullptr);

        int index =0;
        Node* trav = head;
        while (trav->getNext() != nullptr && index < pos -1)
        {
            trav = trav->getNext();
            index++;
        }
        newnode->setNext(trav->getNext());
        newnode->setPrev(trav);
        trav->setNext(newnode);
    }

    void removeFrmEnd()
    {
        if (head == nullptr)
        return;

        Node* trav = head;
        while(trav->getNext()->getNext()!=nullptr)
        {
            trav =trav->getNext();
        }
        delete(trav->getNext()); 
        trav->setNext(nullptr);       
    }

    void removeFrmBegin()
    {
        if (head == nullptr)
        return;

        Node* trav = head;

        head = trav->getNext();
        head->setPrev(nullptr);
        delete(trav);
    }

    void removeFrmPos(int pos)
    {
        Node* trav = head;
        Node* temp;

        if (head == nullptr || pos == 0)
        return;

        for(int i =0 ; i< pos-1 ;i++)
        {
            temp = trav;
            trav = trav->getNext();
        }

        trav->getNext()->setPrev(temp);
        temp->setNext(trav->getNext());
        delete (trav);
    }

    void display()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->getData() << " -> ";
            temp = temp->getNext();
        }
    }
}

