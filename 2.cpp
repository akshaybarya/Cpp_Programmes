#include <bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int> &a, int n, int mid, int m)
{
    int csum = 0, ele = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            return false;
        }
        if (csum + a[i] > mid)
        {
            ele++;
            csum = 0;
            if (ele > m)
            {
                return false;
            }
        }
        csum += a[i];
    }
    return true;
}

int minimum_pages(vector<int> &a, int n, int m)
{
    if (m > n)
        return 0;
    sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int start = 0;
    int end = sum;
    int ans = sum;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (isFeasible(a, n, mid, m))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
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

    cout << minimum_pages(a, n, m) << endl;

    return 0;
}