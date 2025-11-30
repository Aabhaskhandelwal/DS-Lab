#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};
Node* head=nullptr;
void insertAtBeginning(int val) 
{
    Node* newNode = new Node();
    newNode->data = val;
    if (head == nullptr) 
    {
        head = newNode;
        newNode->next = head;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next != head)
        temp = temp->next;
    
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void insertAtEnd(int val) 
{
    Node* newNode = new Node();
    newNode->data = val;
    if (head == NULL) 
    {
        head = newNode;
        newNode->next = head;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next != head)
        temp = temp->next;
        
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAfter(int key, int val) 
{
    Node* temp = head;
    if (head == NULL) 
    return;

    do 
    {
        if (temp->data == key) 
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } 
    while (temp != head);
    cout << "Node " << key << " not found!\n";
}
void deleteNode(int key) 
{
    if (head == NULL) 
    return;
    
    Node* temp = head;
    Node* prev = NULL;

    if (head->data == key) 
    {
        while (temp->next != head)
        temp = temp->next;

        if (head->next == head) 
        {
            delete head;
            head = NULL;
            return;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    // Search for node
    prev = head;
    temp = head->next;
    while (temp != head) 
    {
        if (temp->data == key) 
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Node " << key << " not found!\n";
}
void search(int val) 
{
    if (head == NULL) 
    return;

    int pos=1;
    Node* temp = head;
    do 
    {
        if (temp->data == val) 
        {
            cout << "Node " << val << " found at "<<pos<<" position\n";
            return;
        }
        pos++;
        temp = temp->next;
    } 
    while (temp != head);
    cout << "Node " << val << " not found!\n";
}
void display() 
{
    if (head == NULL)
    return;

    Node* temp = head;
    do 
    {
        cout << temp->data << " ";
        temp = temp->next;
    } 
    while (temp != head);
    cout << endl;
}
int main() 
{
    int choice,val,pos;
    cout<<"Circular Linked List Menu\n";
    cout<<"1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Delete Node\n5. Search\n6. Display\n0. Exit\n";
    do 
    {
        cout<<"Enter choice: ";
        cin>> choice;
        switch (choice) 
        {
            case 1:
            cout<<"Enter value to be inserted: "; 
            cin>>val; 
            insertAtBeginning(val); 
            break;

            case 2: 
            cout<<"Enter value to insert: "; 
            cin >> val; 
            insertAtEnd(val); 
            break;

            case 3: 
            cout << "Enter postion and value: "; 
            cin >> pos >> val; 
            insertAfter(pos, val); 
            break;

            case 4: 
            cout << "Enter value to delete: "; 
            cin >> val; 
            deleteNode(val); 
            break;

            case 5: 
            cout << "Enter value to search: "; 
            cin >>val; 
            search(val); 
            break;

            case 6: 
            display(); 
            break;
        }
    } while (choice != 0);

    return 0;
}
