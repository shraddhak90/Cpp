#include <iostream>
#include <C:\Users\sgurulin\Documents\C++\Cpp\Data Structures\Tree\BinaryTreeNode.h>
using namespace std;

bool isIdenticalTree(Node* r1, Node* r2)
{
    if (r1 == nullptr && r2 == nullptr)
    {
        return true;
    }

    if (r1 == nullptr || r2 == nullptr)
    {
        return false;
    }

    return  (r1->data == r2->data) &&
            isIdenticalTree(r1->left, r2->left) && 
            isIdenticalTree(r1->right, r2->right);
}

int main()
{
    Node *root1 = new Node(12);
    root1->left = new Node(8);
    root1->right = new Node(18);
    root1->left->left = new Node(5);
    root1->left->right = new Node(11);


    Node *root2 = new Node(12);
    root2->left = new Node(8);
    root2->right = new Node(18);
    root2->left->left = new Node(5);
    root2->left->right = new Node(11);

    Node *root3 = new Node(12);

    if (isIdenticalTree(root1, root2))
    {
        cout << "Tress are identical" <<endl;
    }
    else
    {
        cout << "Tress are not identical" <<endl;
    }
    return 0;
}