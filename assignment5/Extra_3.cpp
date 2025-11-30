#include<iostream>
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

void removeLoop(Node* head)
{
    if(head==nullptr || head->next==nullptr)
    return;

    Node* slow=head;
    Node* fast=head; 
    while(fast!=nullptr || fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    if(fast==nullptr || fast->next==nullptr)
    return;

    slow=head;
    Node* prev=nullptr;
    while(slow!=fast)
    {
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=nullptr;
    return;
}
int main()
{
    //Example 1
    Node* first1= new Node(1);
    Node* second1= new Node(7);
    Node* third1= new Node(3);
    Node* fourth1= new Node(6);

    first1->next=second1;
    second1->next=third1;
    third1->next=fourth1;
    fourth1->next=second1;

    removeLoop(first1);

    cout<<"Updated Linked List 1: ";
    Node* temp=first1;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    //Example 2:
    Node* first2= new Node(1);
    Node* second2= new Node(2);
    Node* third2= new Node(3);
    Node* fourth2= new Node(4);

    first2->next=second2;
    second2->next=third2;
    third2->next=fourth2;
    fourth2->next=nullptr;

    removeLoop(first2);

    cout<<"Updated Linked List 2: ";
    temp=first2;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}
