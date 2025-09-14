#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
bool isEmpty() { return top == -1; }

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    string infix, postfix = "";
    cout << "Enter Infix expression: ";
    cin >> infix;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If (
        else if (ch == '(') {
            push(ch);
        }
        // If )
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix += pop();
            }
            pop(); // remove '('
        }
        // If operator
        else {
            while (!isEmpty() && prec(peek()) >= prec(ch)) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop remaining
    while (!isEmpty()) {
        postfix += pop();
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}

