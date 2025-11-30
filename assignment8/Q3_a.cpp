#include <iostream>
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

Node* insert(Node* root, int key) 
{
    if (root==nullptr)
    return new Node(key);

    if (key < root->data)
    root->left=insert(root->left, key);

    else if(key>root->data)
    root->right = insert(root->right, key);

    return root;
}

void inorder(Node* root) 
{
    if (root==nullptr) 
    return;

    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
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

    cout<<"Tree before insertion : ";
    inorder(root);

    int x=5;
    root=insert(root,x);

    cout<<"\nTree after insertion : ";
    inorder(root);
    return 0;
}