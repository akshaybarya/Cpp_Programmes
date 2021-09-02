#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &a, int start, int end)
{
    int mid = (start + end) / 2;
    if ((mid == 0 || a[mid] > a[mid - 1]) && (mid == a.size() || a[mid] > a[mid + 1]))
    {
        return mid;
    }
    else if (mid > 0 && a[mid - 1] > a[mid])
    {
        return search(a, start, mid - 1);
    }
    else
    {
        return search(a, mid + 1, end);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    cout << search(a, 0, n) << endl;
    return 0;
}