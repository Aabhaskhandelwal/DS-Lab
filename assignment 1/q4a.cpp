#include<iostream>
using namespace std;

void reverse(int arr[], int n){
    for (int i = 0; i < n/2; i++)
    {
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    
}

int main(){
    int n;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    int arr[100];
    cout<<"Enter elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    reverse(arr,n);
    cout<<"The reversed array is"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}