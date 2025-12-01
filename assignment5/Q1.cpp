#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtBegin(int val)
    {
        Node *temp = new Node{val, head};
        head = temp;
        cout << "Inserted at start\n";
    }

    void insertAtEnd(int val)
    {
        Node *temp = new Node{val, nullptr};

        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;

            curr->next = temp;
        }
        cout << "Inserted at end\n";
    }

    void insert(int pos, int val)
    {
        if (pos == 1)
        {
            insertAtBegin(val);
            return;
        }

        Node *curr = head;

        for (int i = 1; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;

        if (curr == nullptr)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node *temp = new Node{val, curr->next};
        curr->next = temp;

        cout << "Inserted at position\n";
    }

    void deleteBeginning()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;

        cout << "Deleted from start\n";
    }

    void deleteEnd()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Deleted from end\n";
            return;
        }

        Node *curr = head;
        while (curr->next->next != nullptr)
            curr = curr->next;

        delete curr->next;
        curr->next = nullptr;

        cout << "Deleted from end\n";
    }

    void deleteNode(int pos)
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1)
        {
            deleteBeginning();
            return;
        }

        Node *curr = head;

        for (int i = 1; i < pos - 1 && curr != nullptr; i++)
            curr = curr->next;

        if (curr == nullptr || curr->next == nullptr)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;

        cout << "Deleted node\n";
    }

    void search(int val)
    {
        Node *curr = head;
        int pos = 1;

        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                cout << "Element found at position " << pos << endl;
                return;
            }
            curr = curr->next;
            pos++;
        }

        cout << "Element not found\n";
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty\n";
            return;
        }

        Node *curr = head;
        cout << "Linked List: ";
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, val, pos;

    cout << "MENU\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert at Position\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from End\n";
    cout << "6. Delete at Position\n";
    cout << "7. Search\n";
    cout << "8. Display\n";
    cout << "0. Exit\n";

    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBegin(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            list.insert(pos, val);
            break;

        case 4:
            list.deleteBeginning();
            break;

        case 5:
            list.deleteEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteNode(pos);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;

        case 8:
            list.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
