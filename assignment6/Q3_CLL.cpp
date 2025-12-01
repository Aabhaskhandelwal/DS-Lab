#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

int size(Node *head)
{
    if (head == NULL)
        return 0;

    int count = 1;
    Node *temp = head->next;

    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    Node *head = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);

    head->next = n2;
    n2->next = n3;
    n3->next = head; // circular

    cout << "Size of circular linked list = " << size(head) << endl;

    return 0;
}
