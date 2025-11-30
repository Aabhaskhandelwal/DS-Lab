#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
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
Node* reverse(Node* head)
{
    Node* prev=nullptr;
    Node* temp=head;
    while(temp!=nullptr)
    {
        Node* nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;  
    }
    head=prev;
    return head;
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
    head=reverse(head);
    cout<<"Reversed List: ";
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"null\n";
    return 0;
}
