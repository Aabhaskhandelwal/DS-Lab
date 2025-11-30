#include <iostream>
#include <climits> 
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node(int val) 
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
bool isBST(Node* root, int minVal,int maxVal)
{
    if (root==nullptr)
    return true;

    if (root->data<=minVal||root->data>=maxVal)
    return false;

    return (isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal));
}

int main() 
{
    Node* root=new Node(3);
    Node* a=new Node(2);
    Node* b=new Node(6);
    Node* c=new Node(1);
    Node* d=new Node(4);
    Node* e = new Node(7);

    //Example 1:
    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;

    if (isBST(root,INT_MIN,INT_MAX))
    cout<<"The tree 1 is a BST!\n";

    else
    cout<<"The tree 1 is NOT a BST!Q5.\n";


    //Example 2:
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=e;

    if (isBST(root,INT_MIN,INT_MAX))
    cout<<"The tree 2 is a BST!\n";

    else
    cout<<"The tree 2 is NOT a BST!\n";

    return 0;
}
