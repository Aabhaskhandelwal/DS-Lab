#include<iostream>
using namespace std;

void countSort(int arr[],int len,int place)
{
    int out[len];

    int freq[10]={0};
    for(int i=0;i<len;i++)
    {
        int digit=(arr[i]/place)%10;
        freq[digit]++;
    }
    for(int i=1;i<10;i++)
    freq[i]+=freq[i-1];

    for(int i=len-1;i>=0;i--)
    {
        int digit=(arr[i]/place)%10;
        int indx=freq[digit]-1;
        out[indx]=arr[i];
        freq[digit]--;
    }
    for(int i=0;i<len;i++)
    arr[i]=out[i];

    return;
}
void Radix_sort(int arr[],int len)
{
    int max=arr[0];
    for(int i=0;i<len;i++)
    {
        if(arr[i]>max)
        max=arr[i];

        for(int place=1;max/place>0;place*=10)
        countSort(arr,len,place);
    }
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

    Radix_sort(arr,size);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}