#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return (top == -1) ? '\0' : stack[top--];
}

bool isBalanced(string exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch); // push opening bracket
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return false; // nothing to match
            
            char last = pop();
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return false; // mismatch
            }
        }
    }
    return (top == -1); // stack should be empty
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

