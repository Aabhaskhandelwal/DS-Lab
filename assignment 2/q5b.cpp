#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of tri-diagonal matrix: ";
    cin>>n;
    int tri[3*n-2];

    cout<<"Enter elements row by row (3n-2 values): ";
    for(int i=0;i<3*n-2;i++) cin>>tri[i];

    cout<<"Matrix:\n";
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j==1 || i==j || j-i==1) cout<<tri[k++]<<" ";
            else cout<<0<<" ";
        }
        cout<<"\n";
    }
}

