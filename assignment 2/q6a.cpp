#include <iostream>
using namespace std;

void transpose(int A[][3], int B[][3], int rows, int cols, int n) {
    B[0][0] = cols;   // rows become cols
    B[0][1] = rows;   // cols become rows
    B[0][2] = n;

    int k = 1;
    for (int c = 0; c < cols; c++) {  
        for (int i = 1; i <= n; i++) {
            if (A[i][1] == c) {  // if col matches
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols, n;
    cout << "Enter rows, cols and non-zero elements: ";
    cin >> rows >> cols >> n;

    int A[n+1][3], Tr[n+1][3];

    // header
    A[0][0] = rows;
    A[0][1] = cols;
    A[0][2] = n;

    cout << "Enter triplet (row col value):\n";
    for (int i = 1; i <= n; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    transpose(A, Tr, rows, cols, n);

    cout << "\nTranspose in triplet form:\n";
    for (int i = 0; i <= Tr[0][2]; i++)
        cout << Tr[i][0] << " " << Tr[i][1] << " " << Tr[i][2] << endl;

    return 0;
}


