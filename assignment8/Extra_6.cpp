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

Node* helper(int postorder[],int postlow,int posthigh,int inorder[],int inlow,int inhigh)
{
    if(postlow>posthigh)
    return nullptr;
        
    Node* root=new Node(postorder[posthigh]);

    int i=inlow;
    while(inorder[i]!=postorder[posthigh])
    i++;

    int left=i-inlow;
    root->left=helper(postorder,postlow,postlow+left-1,inorder,inlow,i-1);
    root->right=helper(postorder,posthigh-inhigh+i,posthigh-1,inorder,i+1,inhigh);

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
    int postorder[]={9,15,7,20,3};
    int inorder[]={9,3,15,20,7};

    int n=5;

    Node *root=helper(postorder,0,n-1,inorder,0,n-1);

    cout<<"Original Tree: \n";
    display(root);
    return 0;
}