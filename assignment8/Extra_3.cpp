#include<iostream>
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
int maxDepth(Node *root) 
{
    if (root==nullptr)
    return 0;  

    if(root->left==nullptr && root->right==nullptr)
    return 1;
        
    return (1+max(maxDepth(root->left),maxDepth(root->right)));
}
int main()
{
    Node *root=new Node(1);
    Node *a=new Node(2);
    Node *b=new Node(3);
    Node *c=new Node(4);
    Node *d=new Node(5);
    Node *e=new Node(6);
    Node *f=new Node(7);
    Node *g=new Node(8);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    d->left=f;
    e->left=g;

    cout<<"Max depth: "<<maxDepth(root);

    return 0;
}