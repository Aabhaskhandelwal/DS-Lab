#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i,bool inc) 
{
    int large=i;
    int left=2*i+1;
    int right=2*i+2;

    if (inc) 
    { 
        if (left<n && arr[left]>arr[large])
        large=left;
      
        if (right<n && arr[right]>arr[large])
        large=right;
    } 
    else 
    {
        if (left<n && arr[left]<arr[large])
        large=left;
        if (right<n && arr[right]<arr[large])
        large=right;
    }

    if (large!=i) 
    {
        int temp=arr[i];
        arr[i]=arr[large];
        arr[large]=temp;
        heapify(arr,n,large,inc);
    }
}

void heapSort(int arr[], int n, bool inc) 
{
    for (int i=n/2-1;i>=0;i--)
    heapify(arr,n,i,inc);

    for (int i=n-1;i>0;i--) 
    {    
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
      
        heapify(arr,i,0,inc);
    }
}

int main() 
{
    int arr[]={5,6,7,8,3,4};
    int n=6;

    cout<<"Original array: ";
    for (int i=0;i<n; i++) 
    cout<<arr[i]<<" ";

    bool inc=true;
    heapSort(arr,n,inc);

    cout<<"\nSorted array:";
    for (int i=0;i<n;i++) 
    cout<<arr[i]<<" ";
  
    cout<<endl;

    return 0;
}
