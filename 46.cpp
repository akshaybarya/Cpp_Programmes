#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r)
{
    vector<int> a, b;
    for (int i = l; i <= mid; i++)
    {
        a.push_back(arr[i]);
    }

    for (int i = mid + 1; i < r; i++)
    {
        b.push_back(arr[i]);
    }

    int i = 0, j = 0, n1 = a.size(), n2 = b.size();
    int k = l;
    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = a[i++];
    }

    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
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

    mergeSort(a, 0, n);

    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}