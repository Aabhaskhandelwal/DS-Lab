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
Node* rotateK(Node* head,int k)
{
    if (!head || !head->next || k==0) 
    return head;

    Node* temp=head;
    int size=1;
    while (temp->next!=nullptr) 
    {
        temp=temp->next;
        size++;
    }
    Node* tail=temp;//last node

    k=k%size;
    if (k==0) 
    return head;

    tail->next=head;//make list circular

    Node* newTail=head;
    for (int i=1; i<k; i++)
    newTail=newTail->next;

    Node* newHead=newTail->next;

    newTail->next=nullptr;//circular list break

    return newHead;
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
    cout<<"Enter the value of k: ";
    cin>>k;

    head=rotateK(head,k);

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