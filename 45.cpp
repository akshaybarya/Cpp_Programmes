#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int l, int r)
{
    int i = l - 1, pivot = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}

void quickSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);

        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, r);
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }

    quickSort(a, 0, n - 1);

    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}