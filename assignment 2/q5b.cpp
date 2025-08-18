#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int tri[3*n - 2];
    cout << "Enter elements (lower, diagonal, upper):\n";

    for (int i = 0; i < 3*n - 2; i++) cin >> tri[i];

    cout << "\nTri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << tri[i] << " "; 
            else if (i == j+1) cout << tri[n + j] << " ";   
            else if (j == i+1) cout << tri[2*n - 1 + i] << " "; 
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
