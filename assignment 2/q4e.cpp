#include<bits/stdc++.h>
using namespace std;
string lowercase(string &s){
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]>=65&&s[i]<=91){
            s[i]+=32;
        }
    }
    return s;  
}
int main(){
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    string ans = lowercase(s);
    cout<<"in lowercase : ";
    cout<<ans;
    return 0;
}