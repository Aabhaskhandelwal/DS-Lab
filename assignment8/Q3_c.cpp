#include <iostream>
#include <algorithm>
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
int maxDepth(Node *root)
{
    if (root==nullptr || root->left==nullptr && root->right==nullptr)
    return 0;           

    return (1+max(maxDepth(root->left),maxDepth(root->right)));
}
int main() 
{
    Node *root=new Node(3);
    Node *a=new Node(2);
    Node *b=new Node(6);
    Node *c=new Node(1);
    Node *d=new Node(4);
    Node *e=new Node(7);

    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;

    cout<<"Maximum Depth: "<<maxDepth(root);
    return 0;
}