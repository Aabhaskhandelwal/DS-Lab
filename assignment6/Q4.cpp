#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *prev;
    Node *next;

    Node(char val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    Node *tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    while (head != tail)
    {
        if (head->data != tail->data)
            return false;

        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main()
{
    // List 1: level
    Node *head1 = new Node('l');
    head1->next = new Node('e');
    head1->next->prev = head1;

    head1->next->next = new Node('v');
    head1->next->next->prev = head1->next;

    head1->next->next->next = new Node('e');
    head1->next->next->next->prev = head1->next->next;

    head1->next->next->next->next = new Node('l');
    head1->next->next->next->next->prev = head1->next->next->next;

    cout << "List 1 is ";
    if (isPalindrome(head1))
        cout << "Is Palindrome\n";
    else
        cout << "Not Palindrome\n";

    // List 2: hello
    Node *head2 = new Node('h');
    head2->next = new Node('e');
    head2->next->prev = head2;

    head2->next->next = new Node('l');
    head2->next->next->prev = head2->next;

    head2->next->next->next = new Node('l');
    head2->next->next->next->prev = head2->next->next;

    head2->next->next->next->next = new Node('o');
    head2->next->next->next->next->prev = head2->next->next->next;

    cout << "List 2 is ";
    if (isPalindrome(head2))
        cout << "Is Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
