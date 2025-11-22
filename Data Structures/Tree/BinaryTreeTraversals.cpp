#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void preOrderTraverse(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    cout <<node->data <<" ";

    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}

void inOrderTraverse(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    inOrderTraverse(node->left);

    cout <<node->data << " ";

    inOrderTraverse(node->right);
}

void postOrderTraverse(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    postOrderTraverse(node->left);

    postOrderTraverse(node->right);

    cout <<node->data<<" ";
}

int main()
{
    Node* root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    cout <<"PreOrder Traversal: "<<endl;
    preOrderTraverse(root);

    cout <<endl<<"InOrder Traversal: "<<endl;
    inOrderTraverse(root);

    cout <<endl<<"PostOrder Traversal: "<<endl;
    postOrderTraverse(root);
}
