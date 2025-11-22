#include <iostream>
#include <vector>
using namespace std;

class Node
{
  public:
  int data;
  vector<Node*> children;

  Node(int d)
  {
    data = d;
  }
};

// Function to add a child to a node
  void addChild( Node* parent, Node* node)
  {
    parent->children.push_back(node);
  }


  // Function to print parents of each node
  void printParents(Node* node, Node* parent)
  {
    if (parent== nullptr)
    {
        cout << node->data << "--> NULL"<<endl; 
        //return;
    }
    else
    {
        cout << node->data << "--> "<< parent->data <<endl;
    }

    for (auto child : node->children)
    {
        printParents(child, node);
    }
  }

  // Function to print children of each node
  void printChildren(Node* node)
  {
    cout << node->data << "--> ";
    for (auto child : node->children)
    {
        cout << child->data << " ";
    }
    cout <<endl;

    for (auto child : node->children)
    {
        printChildren(child);
    }
  } 

  // Function to print leaf nodes
  void printLeafNodes(Node* node)
  {
    if (node->children.empty())
    {
        cout<< node->data <<endl;
        return;
    }
    for (auto child: node->children)
    {
        printLeafNodes(child);
    }
  }

// Function to print degrees of each node
  void printDegrees(Node* node, Node* parent)
  {
    int degree = node->children.size();
    if (parent != nullptr)
    {
        degree++;
    }
    cout << node->data << " Degree --> " << degree<< endl;
    
    for (auto child : node->children)
    {
        printDegrees(child, node);
    }
  }

int main()
{
    cout << "SK" << endl;
    Node* root = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);

    addChild( root, n1);
    addChild(root, n2);
    addChild(n2, n3);
    addChild(n2, n4);

     cout << "Parents of each node:" << endl;
    printParents(root, nullptr);

    cout << "\nChildren of each node:" << endl;
    printChildren(root);

    cout <<"\nPrint leaf nodes: "<<endl;
    printLeafNodes(root);

    cout <<"\n Print Degrees: "<<endl;
    printDegrees(root, nullptr);

    return 0;
}