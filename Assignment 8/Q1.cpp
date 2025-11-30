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
void preorder(Node *root)
{
    if(root==nullptr)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(Node *root)
{
    if(root==nullptr)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void postorder(Node *root)
{
    if(root==nullptr)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
int main()
{
    Node *root=new Node(1);
    Node *a=new Node(2);
    Node *b=new Node(3);
    Node *c=new Node(4);
    Node *d=new Node(5);
    Node *e=new Node(6);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->right=e;

    cout<<"Preorder: ";
    preorder(root);//root left right
    cout<<"\nInorder: ";
    inorder(root);//left root right
    cout<<"\nPostorder: ";
    postorder(root);//left right root

    return 0;
}
