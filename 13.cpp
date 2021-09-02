#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 7, 3, 6, 5, 6};
    int n = 6;
    int sum = 0, curr = 0;
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
    int pivot = -1;
    for (int i = 0; i < n; i++)
    {
        int left = curr;
        int right = sum - left - a[i];
        cout << left << " " << right << endl;
        if (left == right)
        {
            pivot = i;
        }
        curr += a[i];
    }
    cout << pivot << endl;
    return 0;
}