#include<iostream>
using namespace std;



int b_search(int arr[], int n, int s) {
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = high+low / 2; 

        if (arr[mid] == s) 
            return mid; 

        if (arr[mid] < s ) 
            low = mid + 1; 
        else 
            high = mid - 1; 
    }
    return -1;
    
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = b_search(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}