#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head = nullptr;

void insertAtBeginning(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
    cout << "Inserted at beginning.\n";
}

void insertAtEnd(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;
        cout << "\nInserted at end.\n";
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    cout << "Inserted at end.\n";
}

void insertAfter(int key, int val)
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }
    Node *temp = head;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr)
    {
        cout << "Node " << key << " not found!\n";
        return;
    }
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
    cout << val << " inserted after " << key << endl;
}

void deleteNode(int key)
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;

    if (temp->data == key) // for head
    {
        head = temp->next;
        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
        cout << "Node " << key << " deleted.\n";
        return;
    }

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr)
    {
        cout << "Node " << key << " not found!\n";
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Node " << key << " deleted.\n";
}

void search(int val)
{
    Node *temp = head;
    int pos = 1;

    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            cout << "Node " << val << " found at position " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    }
    cout << "Node " << val << " not found!\n";
}

void display()
{
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    cout << "List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int choice, val, key;
    cout << "Doubly Linked List Menu\n";
    cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Delete Node\n5. Search\n6. Display Forward\n0. Exit\n";

    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            insertAtBeginning(val);
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> val;
            insertAtEnd(val);
            break;

        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            insertAfter(key, val);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteNode(val);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
            break;

        case 6:
            display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    return 0;
}