#include<iostream>
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
Node* findMax(Node* node) 
{
    while (node->right!=nullptr)
    node=node->right;

    return node;
}

Node* findPredecessor(Node* root, Node* x) 
{
    if (x->left!=nullptr)
    return findMax(x->left);

    Node* pred=nullptr;
    while (root!=nullptr) 
    {
        if (x->data > root->data) 
        {
            pred=root;          
            root=root->right;
        }
        else if (x->data<root->data)
        root=root->left;
        else
        break;
    }
    return pred;
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

    Node *x=b;
    cout<<"The predecessor of node is "<<findPredecessor(root,x)->data;
    return 0;
}