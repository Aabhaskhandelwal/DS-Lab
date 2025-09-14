#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        bool isDistinct = true;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if(isDistinct) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Number of distinct elements = " << countDistinct(arr, n);
    return 0;
}
