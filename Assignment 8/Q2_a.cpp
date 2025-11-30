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
Node* searchRecursive(Node* root,int key) 
{
    if (root==nullptr || root->data==key)
    return root;

    if (key<root->data)
    return searchRecursive(root->left, key);
    else
    return searchRecursive(root->right, key);
}
Node* searchIterative(Node* root,int key) 
{
    while (root!=nullptr) 
    {
        if (root->data==key)
        return root;
        else if (key<root->data)
        root=root->left;
        else
        root=root->right;
    }
    return nullptr;
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
    b->left=d;
    b->right=e;

    int num;
    cout<<"Enter the number to be searched: ";
    cin>>num;
    Node* found=searchRecursive(root,num);
    if(found)
    cout<<"Ellement found!\n";
    else
    cout<<"Ellement not found!\n";

    found=searchIterative(root,num);
    if(found)
    cout<<"Ellement found!\n";
    else
    cout<<"Ellement not found!\n";

    return 0;
}