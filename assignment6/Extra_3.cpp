#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};
Node* head = nullptr;

void insertAtEnd(int val)
{
    Node* newNode=new Node();
    newNode->data=val;
    newNode->next=nullptr;

    if (head==nullptr)
    {
        newNode->prev=nullptr;
        head=newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    temp = temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}
Node* reverseK(Node* head,int k)
{
    if(head==nullptr)
    return nullptr;

    Node* curr=head;
    Node* next=nullptr;  
    Node* newHead=nullptr;
    Node*  temp=head;
    int count=0;
    
    for (int i=0;i<k;i++)
    { 
        if (temp==nullptr) 
        return head;

        temp = temp->next; 
    }

    while (curr!=nullptr && count<k) 
    {
        next=curr->next;
        curr->next=curr->prev;
        curr->prev=next;
        newHead=curr;
        curr=next;
        count++;
    }

    if (curr!=nullptr)
    {
        Node* restHead=reverseK(next,k);
        head->next=restHead;

        if(restHead!=nullptr)
        restHead->prev=head;
    }
    newHead->prev=nullptr;
    return newHead;
}
int main()
{
    int size,val,k;
    cout<<"Enter the size of the list: ";
    cin>>size;
    cout<<"Enter the value: ";
    for(int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(val);
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    head=reverseK(head,k);
    cout<<"Resultant List: ";
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data;
        if(temp->next!=nullptr)
        cout<<" <-> ";
    
        temp=temp->next;
    }
    return 0;
}