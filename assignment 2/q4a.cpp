#include<iostream>
using namespace std;

int main(){
    string s1,s2;
    cout<<"enter first"<<endl;
    getline(cin,s1);
    cout<<"enter second"<<endl;
    getline(cin,s2);
    cout<<"the combine string is"<<endl;
    cout<<s1+s2;
    return 0;
}