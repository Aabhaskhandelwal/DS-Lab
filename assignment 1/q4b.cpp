#include<iostream>
using namespace std;

const int MAX=100;

void matrixMul(int Matrix1[MAX][MAX],int Matrix2[MAX][MAX],int row1,int column1,int row2,int column2){
    int result[MAX][MAX]={0};
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < column1; k++) {
                result[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int row1,column1,row2,column2;
    cout<<"enter number of rows in 1st matrix"<<endl;
    cin>>row1;
    cout<<"enter number of columns in 1st matrix"<<endl;
    cin>>column1;
    cout<<"enter number of rows in 2nd matrix"<<endl;
    cin>>row2;
    cout<<"enter number of columns in 2nd matrix"<<endl;
    cin>>column2;

    int matrix1[MAX][MAX];
    int matrix2[MAX][MAX];
    if(column1!=row2){
        cout<<"multiplication not possible";
        return 0;
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            cout<<"enter matrix 1"<<" "<<i<<" "<<j<<endl;
            cin>>matrix1[i][j];
        }
        
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            cout<<"enter matrix 2"<<" "<<i<<" "<<j<<endl;
            cin>>matrix2[i][j];
        }
        
    }
    
    matrixMul(matrix1,matrix2,row1,column1,row2,column2);

    return 0;
}