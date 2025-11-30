#include<iostream>
using namespace std;
void selection_sort(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        //find min ellemnt in unsorted arra
        int minind=i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j]<arr[i])
            minind=j;
        }
        //swap cuurent ellement(arr[i]) and min ellement(arr[minind])
        int temp=arr[i];
        arr[i]=arr[minind];
        arr[minind]=temp;
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

    selection_sort(arr,size);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}
