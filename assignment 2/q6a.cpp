#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int n; 
    cout<<"Enter number of non-zero elements: ";
    cin>>n;

    Element A[20], B[20]; // triplets
    cout<<"Enter row col value for each element:\n";
    for(int i=0;i<n;i++) cin>>A[i].row>>A[i].col>>A[i].val;

    // Transpose: swap row <-> col
    for(int i=0;i<n;i++) {
        B[i].row = A[i].col;
        B[i].col = A[i].row;
        B[i].val = A[i].val;
    }

    cout<<"\nTranspose (triplet form):\n";
    for(int i=0;i<n;i++)
        cout<<B[i].row<<" "<<B[i].col<<" "<<B[i].val<<endl;
}
