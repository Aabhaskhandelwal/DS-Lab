#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    stack<int> s;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch(ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    cout << "Result: " << s.top() << endl;

    return 0;
}

