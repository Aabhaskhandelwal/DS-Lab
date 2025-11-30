#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node *head=nullptr;
void insertAtBegin(int val)
{
    Node* temp=new Node;
    if(head==nullptr)
    {
        cout<<"Empty Linked List\n";
        return;
    }
    temp->data=val;
    temp->next=head;
    head=temp;
    cout<<"Inserted at start\n";
}
void insertAtEnd(int val)
{
    Node* temp=new Node;
    temp->data=val;
    temp->next=nullptr;
    if(head==nullptr)
    head=temp;

    else
    {
        Node* curr=head;
        while(curr->next!=nullptr)
        curr=curr->next;

        curr->next=temp;
    }
    cout<<"Inserted at end\n";
}
void insert(int pos,int val)
{
    if(pos==1)
    {
        insertAtBegin(val);
        return;
    }
    Node* temp=new Node;
    temp->data=val;
    Node*curr=head;
    for(int i=0;i<pos-1;i++)
    {
        if(curr!=nullptr)
        curr=curr->next;
    }
    if(curr==nullptr)
    {
        cout<<"Invalid Position\n";
        delete temp;
        return;
    }
    temp->next=curr->next;
    curr->next=temp; 
    cout<<"Inserted in the position you mentioned\n";
}
void deleteBeginning()
{
    if(head==nullptr)
    {
        cout<<"List is already empty\n";
        return;
    }
    Node*temp=head;
    head=head->next;
    delete temp;
    cout<<"Deleted from start\n";
}
void deleteEnd()
{
    if(head==nullptr)
    {
        cout<<"List is already empty\n";
        return;
    }
    if(head->next==nullptr)
    {
        head=nullptr;
        cout<<"Deleted from end\n";
        return;
    }
    Node*temp=head;
    while(temp->next->next!=nullptr)
    temp=temp->next;

    delete temp->next;
    temp->next=nullptr;
    cout<<"Deleted from end\n";
}
void deleteNode(int pos)
{
    if(head==nullptr)
    {
        cout<<"List is already empty\n";
        return;
    }
    if(pos==1)
    {
        deleteBeginning();
        return;
    }
    Node* curr=head;
    for(int i=0;i<pos-1;i++)
    {
        if(curr!=nullptr)
        curr=curr->next;
    }
    if(curr==nullptr || curr->next==nullptr)
    {
        cout<<"Invalid Position\n";
        return;
    }
    Node* temp=curr->next;
    curr->next=temp->next;
    cout<<"Deleted\n";
    delete temp;
}
void search(int val)
{
    Node* curr=head;
    int pos=1;
    while(curr!=nullptr)
    {
        if(curr->data==val)
        {
            cout<<"Ellement found at "<<pos<<" index\n";
            return;
        }
        curr=curr->next;
        pos++;
    }
    cout<<"Ellement not found\n";
    return;
}
void display()
{
    if(head==nullptr)
    {
        cout<<"List is Empty\n";
        return;
    }
    Node* curr=head;
    cout<<"Linked List: ";
    while(curr!=nullptr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main()
{
    int choice;
    cout<<"Enter choice according to the menu:\n";
    cout<<"1. Add at the begining\n2.Insertion at end\n3.Insertion in between\n4.Deletion from begining\n5.Deletion from end\n6.Deletion of a specific node\n7.Search for a node and dispaly its position from head.\n8.Display all the nodes\n";
    do
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        int pos,val;
        switch(choice)
        {
            case 1:
            cout<<"Enter the value: ";
            cin>>val;
            insertAtBegin(val);
            break;

            case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;

            case 3:
            cout << "Enter position value: ";
            cin >> pos;
            cout << "Enter new value: ";
            cin >> val;
            insert(pos, val);
            break;

            case 4:
            deleteBeginning();
            break;

            case 5:
            deleteEnd();
            break;

            case 6:
            cout << "Enter node position to delete: ";
            cin >> pos;
            deleteNode(pos);
            break;

            case 7:
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
            break;

            case 8:
            display();
            break;

            default:
            cout << "Exiting...\n";
        }
    }while(choice<=8);
    return 0;
}
