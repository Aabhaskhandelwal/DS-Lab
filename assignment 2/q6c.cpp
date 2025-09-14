#include <iostream>
using namespace std;

void multiply(int A[][3], int B[][3], int C[][3]) {
    if(A[0][1] != B[0][0]) {
        cout<<"Multiplication not possible!\n";
        return;
    }

    int m=A[0][0], n=A[0][1], p=B[0][1];
    C[0][0]=m; C[0][1]=p; C[0][2]=0;

    int k=1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<p;j++) {
            int sum=0;
            for(int a=1;a<=A[0][2];a++) {
                if(A[a][0]==i) {
                    for(int b=1;b<=B[0][2];b++) {
                        if(B[b][0]==A[a][1] && B[b][1]==j)
                            sum += A[a][2]*B[b][2];
                    }
                }
            }
            if(sum!=0) {
                C[k][0]=i;
                C[k][1]=j;
                C[k][2]=sum;
                k++;
            }
        }
    }
    C[0][2]=k-1;
}

int main() {
    int A[20][3], B[20][3], C[40][3];
    cout<<"Enter A (rows cols non-zeros): ";
    cin>>A[0][0]>>A[0][1]>>A[0][2];
    cout<<"Enter A triplets:\n";
    for(int i=1;i<=A[0][2];i++) cin>>A[i][0]>>A[i][1]>>A[i][2];

    cout<<"Enter B (rows cols non-zeros): ";
    cin>>B[0][0]>>B[0][1]>>B[0][2];
    cout<<"Enter B triplets:\n";
    for(int i=1;i<=B[0][2];i++) cin>>B[i][0]>>B[i][1]>>B[i][2];

    multiply(A,B,C);

    cout<<"\nMultiplication result (triplet form):\n";
    for(int i=0;i<=C[0][2];i++)
        cout<<C[i][0]<<" "<<C[i][1]<<" "<<C[i][2]<<endl;
}
