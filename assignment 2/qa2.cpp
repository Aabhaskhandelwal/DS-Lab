#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string small, string big)
{
    return big.find(small) != string::npos;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int n = s.size();
    bool possible = false;

    // try every split into 3 parts
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string p1 = s.substr(0, i);
            string p2 = s.substr(i, j - i);
            string p3 = s.substr(j);

            if (isSubstring(p1, p2) && isSubstring(p1, p3))
                possible = true;
            if (isSubstring(p2, p1) && isSubstring(p2, p3))
                possible = true;
            if (isSubstring(p3, p1) && isSubstring(p3, p2))
                possible = true;

            if (possible)
                break;
        }
        if (possible)
            break;
    }

    if (possible)
        cout << "Possible to split the string" << endl;
    else
        cout << "Not possible to split the string" << endl;

    return 0;
}
