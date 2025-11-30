#include<iostream>
#include<vector>
#include<queue>
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
vector<int> rightSide(Node *root)
{
    vector<int> ans;
    if(root==nullptr)
    return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();

            if(i==size-1)
            ans.push_back(curr->data);

            if(curr->left!=nullptr)
            q.push(curr->left);

            if(curr->right!=nullptr)
            q.push(curr->right);
        }
    }
    return ans;
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

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    d->left=f;

    vector<int> view=rightSide(root);
    cout<<"Right side view: ";
    for (int i=0;i<view.size();i++)
    cout<<view[i]<<" ";

    cout<<endl;
    return 0;
}