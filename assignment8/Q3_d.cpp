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
int minDepth(Node *root)
{
    if (root==nullptr || root->left==nullptr && root->right==nullptr) 
    return 0;      

    if (root->left==nullptr)
    return (1+minDepth(root->right));

    if (root->right==nullptr)
    return (1+minDepth(root->left));

    return (1+min(minDepth(root->left),minDepth(root->right)));
}
int main() 
{
    Node *root=new Node(3);
    Node *a=new Node(2);
    Node *b=new Node(6);
    Node *d=new Node(4);
    Node *e=new Node(7);

    root->left=a;
    root->right=b;
    b->left=d;
    b->right=e;

    cout<<"Minimum Depth: "<<minDepth(root);
    return 0;
}