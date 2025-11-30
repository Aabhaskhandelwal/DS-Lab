#include<iostream>
using namespace std;
void bubble_sort(int arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        bool check=false;
        for(int j=0;j<len-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                check=true;
            }
        }
        if(check==false)
        return;
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

    bubble_sort(arr,size);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}