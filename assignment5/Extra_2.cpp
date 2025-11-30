#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node *head=nullptr;
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
Node* reverseK(Node* head,int k)
{
    if(head==nullptr)
    return nullptr;

    Node* curr=head; 
    Node* prev=nullptr;
    Node* next=nullptr;  
    Node* temp=head;
    int count=0;
    // Check if there are at least K nodes left 
    for (int i=0;i<k;i++)
    { 
        if (temp==nullptr) 
        return head; // less than K nodes
        temp = temp->next; 
    }
    // Reverse K nodes
    while (curr!=nullptr && count<k) 
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    // Recursively reverse the remaining list
    if (next!=nullptr)
    head->next=reverseK(next,k);

    return prev; // prev is the new head of this reversed part
}
int main()
{
    int size,val,k;
    cout<<"Enter number of elements: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(val);
    }
    cout<<"Enter the group size: ";
    cin>>k;

    if(k>size)
    {
        cout<<"Invalid group size\n";
        return 0;
    }

    head=reverseK(head,k);

    cout<<"Resultant List: ";
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"null\n";
    return 0;
}