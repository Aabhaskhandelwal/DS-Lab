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

Node* findMin(Node* root) 
{
    while (root->left!=nullptr)
    root=root->left;
    return root;
}

Node* deleteNode(Node* root, int key) 
{
    if (root==nullptr)
    return root;

    if (key<root->data)
    root->left=deleteNode(root->left, key);

    else if (key>root->data)
    root->right=deleteNode(root->right, key);

    else 
    {
        if (root->left==nullptr && root->right==nullptr)//no child
        {
            delete root;
            return nullptr;
        }
        else if (root->left==NULL) //one child
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if (root->right==NULL) //one child
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else //2 child
        {
            Node* temp=findMin(root->right);//inorder successor or findMax(root->right) for inorder predecessor
            root->data=temp->data;//copy value
            root->right=deleteNode(root->right, temp->data);//delete successor
        }
    }
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
    Node *b=new Node(5);
    Node *c=new Node(1);
    Node *d=new Node(4);
    Node *e=new Node(6);

    root->left=a;
    root->right=b;
    a->left=c;
    b->left=d;
    b->right=e;

    cout<<"Tree before deletion : ";
    inorder(root);

    int x=5;
    root=deleteNode(root,x);

    cout<<"\nTree after deletion : ";
    inorder(root);
    return 0;
}