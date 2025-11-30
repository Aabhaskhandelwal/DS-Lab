#include<iostream>
using namespace std;
void sort(int arr[],int size)
{
    int st=0,end=size-1;
    while(st<end)
    {
        int min=st;
        int max=end;

        //find minimum and maximum
        for(int i=st;i<=end;i++)
        {
            if(arr[i]<arr[min])
            min=i;

            if(arr[i]>arr[max])
            max=i;
        }

        //swap min with start
        if(min!=st)//avoid unnecesary steps
        {
            int temp=arr[st];
            arr[st]=arr[min];
            arr[min]=temp;
        }
        
        if(max==st)//if ellement at max was at start it went to min after swap
        max=min;

        //swap max with end
        if(max!=end)
        {
            int temp=arr[end];
            arr[end]=arr[max];
            arr[max]=temp;
        }
        st++;
        end--;
    }
    return;
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the ellemnts: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];

    sort(arr,size);

    cout<<"Sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}