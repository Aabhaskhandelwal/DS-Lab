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

Node* helper(int preorder[],int prelow,int prehigh,int inorder[],int inlow,int inhigh)
{
    if(prelow>prehigh)
    return nullptr;
        
    Node* root=new Node(preorder[prelow]);

    int i=inlow;
    while(inorder[i]!=preorder[prelow])
    i++;

    int left=i-inlow;
    root->left=helper(preorder,prelow+1,prelow+left,inorder,inlow,i-1);
    root->right=helper(preorder,prelow+left+1,prehigh,inorder,i+1,inhigh);

    return root;
}
void display(Node* root)
{
    if(root==nullptr)
    return;

    cout<<root->data<<" -> ";

    if(root->left!=nullptr)
    cout<<root->left->data<<" ";
    else
    cout<<"null ";

    if(root->right!=nullptr)
    cout<<root->right->data;
    else
    cout<<"null ";

    cout<<endl;

    display(root->left);
    display(root->right);
}
int main()
{
    int preorder[]={3,9,20,15,7};
    int inorder[]={9,3,15,20,7};

    int n=5;

    Node *root=helper(preorder,0,n-1,inorder,0,n-1);

    cout<<"Original Tree: \n";
    display(root);
    return 0;
}