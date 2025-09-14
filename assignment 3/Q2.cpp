#include <iostream>
using namespace std;

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    // Push all characters
    for (int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop and print reversed string
    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}

