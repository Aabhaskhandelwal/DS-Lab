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
Node* findMax(Node* root) 
{
    if (root==nullptr)
    return nullptr;

    if (root->right==nullptr)
    return root;

    return findMax(root->right);
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

    cout<<"Max value of tree: "<<findMax(root)->data;
    return 0;
}