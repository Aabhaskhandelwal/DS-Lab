#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) 
    {
        data=val;
        next=nullptr;
    }
};
Node *head=nullptr;
void insertAtEnd(int val) 
{
    Node* newNode=new Node(val);
    newNode->data=val;
    if (head==NULL) 
    {
        head=newNode;
        newNode->next=head;
    } 
    else 
    {
        Node* temp=head;
        while(temp->next!=head)
        temp=temp->next;
        
        temp->next=newNode;
        newNode->next=head;
    }
}
bool checkParity(int num)
{
    if(num<2)
    return false;

    int binary[32]={0};
    int ind=0;
    while(num>0)
    {
        binary[ind]=num%2;
        num/=2;
        ind++;
    }
    int count=0;
    for(int i=0;i<32;i++)
    {
        if(binary[i]==1)
        count++;
    }
    return(count%2==0);
}
void removeNum()
{
    if (head==nullptr)
    return;

    if(head->next==head)
    {
        delete head;
        head=nullptr;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=head)
    temp=temp->next;

    Node* last=temp->next;
    temp->next=head;
    delete last;
    return;
}
int main()
{
    int size,val;
    cout<<"Enter number of elements: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(val);
        if(checkParity(val))
        removeNum();
    }
    cout<<"Updated List: ";
    Node*temp=head;
    do
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    while(temp->next!=head);
    cout<<temp->data;
    return 0;
}