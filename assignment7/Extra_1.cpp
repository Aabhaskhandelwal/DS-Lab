#include<iostream>
using namespace std;

void Count_sort(int arr[],int len)
{
    int out[len];
    int maxnum=arr[0];
    for(int i=0;i<len;i++)
    {
        if(arr[i]>maxnum)
        maxnum=arr[i];
    }

    int freq[maxnum+1]={0};
    for(int i=0;i<len;i++)
    freq[arr[i]]++;

    for(int i=1;i<maxnum+1;i++)
    freq[i]+=freq[i-1];

    for(int i=len-1;i>=0;i--)
    {
        int indx=freq[arr[i]]-1;
        out[indx]=arr[i];
        freq[arr[i]]--;
    }
    for(int i=0;i<len;i++)
    arr[i]=out[i];

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

    Count_sort(arr,size);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}