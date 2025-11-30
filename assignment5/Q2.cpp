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
int countKey(int key)
{
    int count=0;
    Node*temp=head;
    while (temp!=nullptr)
    {
        if(temp->data==key)
        count++;

        temp=temp->next;
    }
    return count;
}
void deleteKey(int key)
{
    while (head!=nullptr && head->data==key)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    Node* curr=head;
    Node* prev=nullptr;

    while (curr!=nullptr)
    {
        if (curr->data!=key)
        {
            prev=curr;
            curr=curr->next;
        }
        else
        {
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
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
    cout<<"Enter key to delete: ";
    cin>>key;
    int count=countKey(key);
    cout<<"Count: "<<count<<endl;

    deleteKey(key);
    cout<<"Updated Linked List: ";
    Node* temp = head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}
