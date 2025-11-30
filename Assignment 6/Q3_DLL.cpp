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
int getSize(Node* head) 
{
    if (head == nullptr)
    return 0;

    int count = 0;
    Node* temp = head;
    do 
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}
int main() 
{
    Node* head = new Node(20);
    Node* second = new Node(100);
    Node* third = new Node(40);
    Node* fourth = new Node(80);
    Node* fifth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    head->prev=fifth;
    second->prev=head;
    third->prev=second;
    fourth->prev=third;
    fifth->prev=fourth;

    int size= getSize(head); 
    cout <<"Size="<<size << endl;
    return 0;
}