#include<iostream>
using namespace std;    
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) 
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void bstToDLL(Node *root, Node *&head)
{
    if(root==nullptr)
    return;

    bstToDLL(root->right,head);

    root->right=head;
    if(head!=nullptr)
    head->left=root;

    head=root;
    bstToDLL(root->left,head);
}
Node* merge(Node *head1,Node *head2)
{
    if(head1==nullptr)
    return head2;

    if(head2==nullptr)
    return head1;

    Node *head=nullptr;
    Node *tail=nullptr;

    if(head1->data<head2->data)
    {
        head=head1;
        tail=head1;
        head1=head1->right;
    }
    else
    {
        head=head2;
        tail=head2;
        head2=head2->right;
    }

    while(head1!=nullptr && head2!=nullptr)
    {
        if(head1->data<head2->data)
        {
            tail->right=head1;
            head1->left=tail;
            tail=head1;
            head1=head1->right;
        }
        else
        {
            tail->right=head2;
            head2->left=tail;
            tail=head2;
            head2=head2->right;
        }
    }

    if(head1!=nullptr)
    {
        tail->right=head1;
        head1->left=tail;
    }
    if(head2!=nullptr)
    {
        tail->right=head2;
        head2->left=tail;
    }
    return head;
}
int main()
{
    Node *root1=new Node(20);
    Node *a=new Node(10);
    Node *b=new Node(30);
    Node *c=new Node(25);
    Node *d=new Node(100);

    root1->left=a;
    root1->right=b;
    b->right=d;
    b->left=c;

    Node *root2=new Node(50);
    Node *p=new Node(5);
    Node *q=new Node(70);

    root2->left=p;
    root2->right=q;

    Node *head1=nullptr;
    Node *head2=nullptr;
    bstToDLL(root1,head1);
    bstToDLL(root2,head2);
    Node *ans=merge(head1,head2);//merge

    cout<<"Merged doubly Linked List: ";
    while(ans!=nullptr)
    {
        cout<<ans->data<<" <-> ";
        ans=ans->right;
    }
    cout<<"null"<<endl;
    return 0;
}