#include <iostream>

using namespace std;

const int imax = 100;

void transpose(int arr[][imax],int r, int c){
    int t[c][r];

    for (int i = 0; i<c; i++){
        for (int j = 0; j<r;j++){
            t[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i<c;i++){
        for (int j= 0; j<r;j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

}
void create(int arr[][imax],int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0;j < c;j++){
            cin >> arr[i][j];
            cout << " ";
        }
    }
    
}

int main(){
    int r,c;
    cout << "Enter no. of rows";
    cin >> r;

    cout << "Enter no. of columns";
    cin >> c;

    int arr[r][imax];

    create(arr,r,c);

    transpose(arr,r,c);

}