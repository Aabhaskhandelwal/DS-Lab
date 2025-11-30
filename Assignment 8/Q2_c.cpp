#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node *right;
    Node(int val) 
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
Node* findMin(Node* root) 
{
    if (root==nullptr)
    return nullptr;

    if (root->left==nullptr)
    return root;

    return findMin(root->left);
}

int main()
{
    Node *root=new Node(3);
    Node *a=new Node(2);
    Node *b=new Node(5);
    Node *c=new Node(1);
    Node *d=new Node(4);
    Node *e=new Node(6);

    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;

    cout<<"Minimum value of tree: "<<findMin(root)->data;
    return 0;
}