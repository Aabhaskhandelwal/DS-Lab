#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertAtEnd(Node *&head,int val)
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
Node* getNode(Node* h1,Node* h2) 
{
	Node* first=h1;
	while (first!=nullptr) 
    {
		Node *second=h2;
		while (second!=nullptr) 
        {
			if (first->data==second->data)
			return first;

			second=second->next;
		}
		first= first->next;
	}
	return nullptr;
}
int main()
{
    Node *head1=nullptr,*head2=nullptr;
    int size,val;
    cout<<"Enter size of first list: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(head1,val);
    }

    cout<<"Enter size of second list: ";
    cin>>size;
    cout<<"Enter elements: ";
    for (int i=0;i<size;i++)
    {
        cin>>val;
        insertAtEnd(head2,val);
    }

    Node* common=getNode(head1,head2);
    if(common!=nullptr)
    cout<<"The intersecting node is "<<common->data<<endl;

    else
    cout<<"There is no intersecting point\n";
    return 0;
}
