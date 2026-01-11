#include <iostream>
#include <C:\Users\sgurulin\Documents\C++\Cpp\Data Structures\Tree\BinaryTreeNode.h>
using namespace std;


//Maximum height / depth of binary tree
int height(Node* root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) +1;
}

int findParent(Node* root, int target, int parent)
{
    if (root == nullptr)
    {
      return -1;
    }

    // if target is root node only
    if (root->data == target)
    {
      return parent;
    }

    int leftSearch = findParent(root->left, target, root->data);

    if (leftSearch != -1)
    {
      return leftSearch;
    }

    return findParent(root->right, target, root->data);
  }

int main()
{
    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    cout << "Height of Binary Tree: "<< height(root) <<endl;

    cout<<"\n Find parent:: "<<findParent(root, 8, -1)<<endl;
    return 0;
}