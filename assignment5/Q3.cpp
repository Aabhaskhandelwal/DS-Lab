#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head=nullptr;
void insertAtEnd(int val)
{
    Node* newNode=new Node;
    newNode->data=val;
    newNode->next=nullptr;

    if (head==nullptr)
    head=newNode;

    else
    {
        Node* temp=head;
        while(temp->next!=nullptr)
        temp=temp->next;

        temp->next=newNode;
    }
}
int main()
{
    int size,val,key;
    cout<<"Enter number of elements: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(val);
    }
    Node* fast=head;
    Node* slow =head;

    if(head==nullptr)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }
    else if(head->next==nullptr)
    {
        cout<<"The middle value: "<<head->data;
        return 0;
    }
    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"The middle value: "<<slow->data;
    return 0;
}
