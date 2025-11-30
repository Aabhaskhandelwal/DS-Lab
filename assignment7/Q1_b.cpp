#include<iostream>
using namespace std;
void insertion_sort(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i;j>0 && arr[j]<arr[j-1];j--)
        {
            //swap
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
    }
    return;  
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the ellements of the array: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];

    insertion_sort(arr,size);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}