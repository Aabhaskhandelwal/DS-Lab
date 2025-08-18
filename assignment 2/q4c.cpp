#include <iostream>
using namespace std;

string deleteVowels(string s) {
    string result = "";
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' && ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U') {
            result += ch;  
        }
    }
    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    string ans = deleteVowels(s);
    cout << "After deleting vowels: " << ans << endl;
    return 0;
}
