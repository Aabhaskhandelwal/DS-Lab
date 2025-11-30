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
Node* findMin(Node* node) 
{
    while (node->left!=nullptr)
    node=node->left;

    return node;
}

Node* findSuccessor(Node* root, Node* x) 
{
    if (x->right!=nullptr)
    return findMin(x->right);

    Node* succ=nullptr;
    while (root!=nullptr) 
    {
        if (x->data<root->data) 
        {
            succ=root;  
            root=root->left;
        }
        else if (x->data>root->data)
        root=root->right;

        else
        break;
    }
    return succ;
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

    Node *x=c;
    cout<<"The succesor of node is "<<findSuccessor(root,x)->data;
    return 0;
}