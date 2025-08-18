#include <iostream>
using namespace std;

string rev(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return s;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string ans = rev(s);
    cout << "Reversed: " << ans << endl;

    return 0;
}

