#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int val)
    {
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};
Node *head=nullptr;
void insertAtEnd(int val)
{
    Node* newNode=new Node(val);

    if (head==nullptr)
    {
        head=newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    temp = temp->next;

    temp->next=newNode;
    newNode->prev=temp;
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

    if(head->next==nullptr)
    {
        delete head;
        head=nullptr;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr)
    temp=temp->next;

    Node* last=temp->next;
    temp->next=nullptr;
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
    while(temp->next!=nullptr)
    {
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<temp->data;
    return 0;
}