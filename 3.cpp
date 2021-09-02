#include <bits/stdc++.h>
using namespace std;

bool b_search(vector<int> &a, int start, int end, int m)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == m)
            return true;
        else if (a[mid] > m)
        {
            end = mid - 1;
        }
        else
        {
            start = mid;
        }
    }
    return false;
}

bool Search(vector<int> &a, int n, int m)
{
    int pivot = 0;
    int start = 0, end = n;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (a[mid] > a[end])
        {
            pivot = mid;
            break;
        }
        else
        {
            if (a[mid] < a[start])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
    }

    return b_search(a, 0, pivot, m) ? b_search(a, 0, pivot, m) : b_search(a, pivot + 1, n, m);
}

int SearchInRotatedArray(vector<int> &a, int left, int right, int key)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (a[mid] == key)
    {
        return mid;
    }

    if (a[mid] >= a[left])
    {
        if (a[mid] >= key && a[left] <= key)
        {
            return SearchInRotatedArray(a, left, mid - 1, key);
        }
        return SearchInRotatedArray(a, mid + 1, right, key);
    }

    if (key >= a[mid] && key <= a[right])
    {
        return SearchInRotatedArray(a, mid + 1, right, key);
    }

    return SearchInRotatedArray(a, left, mid - 1, key);
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

    int m;
    cin >> m;

    cout << SearchInRotatedArray(a, 0, n, m) << endl;

    return 0;
}