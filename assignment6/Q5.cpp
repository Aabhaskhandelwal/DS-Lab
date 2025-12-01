#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
bool isCircular(Node *head)
{
    if (head == nullptr)
        return false; // empty list is not circular

    Node *temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}
int main()
{
    // List 1:
    Node *head1 = new Node(2);
    Node *second1 = new Node(4);
    Node *third1 = new Node(6);
    Node *fourth1 = new Node(7);
    Node *fifth1 = new Node(5);
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = head1; // circular connection

    // List 2
    Node *head2 = new Node(5);
    Node *second2 = new Node(15);
    Node *third2 = new Node(25);
    Node *fourth2 = new Node(30);
    Node *fifth2 = new Node(35);
    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = nullptr; // not circular

    cout << "List 1 is ";
    if (isCircular(head1))
        cout << "Is Circular\n";

    else
        cout << "Not Circular\n";

    cout << "List 2 is ";
    if (isCircular(head2))
        cout << "Is Circular\n";

    else
        cout << "Not Circular\n";
    return 0;
}