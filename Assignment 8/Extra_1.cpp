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
int sumOfLeftLeaves(Node *root) 
{
    if (root==nullptr)
    return 0;

    int sum=0;
    if (root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr)
    sum+=root->left->data;

    sum+=sumOfLeftLeaves(root->left);
    sum+=sumOfLeftLeaves(root->right);

    return sum;
}
int main()
{
    Node *root=new Node(3);
    Node *a=new Node(9);
    Node *b=new Node(20);
    Node *c=new Node(15);
    Node *d=new Node(7);

    root->left=a;
    root->right=b;
    b->left=c;
    b->right=d;

    cout<<"Sum of left leaves only: "<<sumOfLeftLeaves(root);
    return 0;
}