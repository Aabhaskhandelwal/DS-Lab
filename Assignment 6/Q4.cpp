#include <iostream>
using namespace std;

struct Node 
{
    char data;
    Node* prev;
    Node* next;
    Node(char val)
    {
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};

void insertAtEnd(Node*& head, char val)
{
    Node*newNode=new Node(val);

    if(head==nullptr)
    {
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    temp = temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

bool isPalindrome(Node* head)
{
    if (head==nullptr || head->next==nullptr)
    return true; // Empty or single-node list is palindrome

    Node* tail=head;
    while (tail->next!=nullptr)
    tail=tail->next;

    while (head!=tail && tail->next!=head)
    {
        if (head->data!=tail->data)
        return false;

        head=head->next;
        tail=tail->prev;
    }
    return true;
}

int main()
{
    Node* head1=nullptr;

    //Example 1
    insertAtEnd(head1,'l');
    insertAtEnd(head1,'e');
    insertAtEnd(head1,'v');
    insertAtEnd(head1,'e');
    insertAtEnd(head1,'l');

    cout<<"List 1 is ";
    if(isPalindrome(head1))
    cout<<"Is Palindrome\n";

    else
    cout<<"Not Palindrome\n";

    // Example 2
    Node* head2=nullptr;
    insertAtEnd(head2,'h');
    insertAtEnd(head2,'e');
    insertAtEnd(head2,'l');
    insertAtEnd(head2,'l');
    insertAtEnd(head2,'o');

    cout<<"List 2 is ";
    if(isPalindrome(head2))
    cout<<"Is Palindrome\n";

    else
    cout<<"Not Palindrome\n";
    return 0;
}
