#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX], top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull())
        cout << "Stack is FULL!\n";
    else {
        stack[++top] = value;
        cout << value << " pushed\n";
    }
}

void pop() {
    if (isEmpty())
        cout << "Stack is EMPTY!\n";
    else
        cout << stack[top--] << " popped\n";
}

void display() {
    if (isEmpty())
        cout << "Stack is EMPTY!\n";
    else {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (isEmpty())
        cout << "Stack is EMPTY!\n";
    else
        cout << "Top element: " << stack[top] << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1.Push  2.Pop  3.isEmpty  4.isFull  5.Display  6.Peek  7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            cout << (isEmpty() ? "Stack is EMPTY\n" : "Stack is NOT empty\n");
            break;
        case 4:
            cout << (isFull() ? "Stack is FULL\n" : "Stack is NOT full\n");
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

