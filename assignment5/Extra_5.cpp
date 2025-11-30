#include <iostream>
using namespace std;
struct Node 
{
    int data;
    int power;
    Node* next;
    Node(int val,int pow)
    {
        data=val;
        power=pow;
        next=nullptr;
    }
};
void insertAtEnd(Node* &head,int val,int pow)
{
    Node*newNode=new Node(val,pow);

    if(head==nullptr)
    {
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    temp = temp->next;

    temp->next=newNode;
}
Node* addLists(Node* h1,Node* h2)
{
    if(h1==nullptr)
    return h2;

    if(h2==nullptr)
    return h1;

    if(h1->power > h2->power)
    {
        h1->next=addLists(h1->next,h2);
        return h1;
    }
    else if(h1->power < h2->power)
    {
        h2->next=addLists(h1,h2->next);
        return h2;
    }
    h1->data+=h2->data;
    h1->next=addLists(h1->next,h2->next);

    return h1;
}
int main()
{
    Node *head1=nullptr,*head2=nullptr;
    int size,val,pow;
    cout<<"Enter the size of the list 1: ";
    cin>>size;
    cout<<"Enter the ellements and then its power of list 1:\n";
    for(int i=0;i<size;i++)
    {
        cin>>val>>pow;
        insertAtEnd(head1,val,pow);
    }

    cout<<"Enter the size of the list 2: ";
    cin>>size;
    cout<<"Enter the ellements and then its power of list 2:\n";
    for(int i=0;i<size;i++)
    {
        cin>>val>>pow;
        insertAtEnd(head2,val,pow);
    }

    Node *reshead=addLists(head1,head2);
    cout<<"The output list: ";
    Node* temp=reshead;
    while(temp->next!=nullptr)
    {
        cout<<temp->data<<","<<temp->power<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data<<","<<temp->power<<endl;
    return 0;
}
