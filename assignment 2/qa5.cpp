#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Traverse from right to left to shift elements and duplicate 2s
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 2)
        {
            // Shift elements right to make space for duplicate 2
            for (int j = n - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            // Duplicate the 2 at the next position
            if (i + 1 < n)
            {
                arr[i + 1] = 2;
            }
            i--; // Skip the next index since we just duplicated 2 there
        }
    }

    cout << "Modified array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
