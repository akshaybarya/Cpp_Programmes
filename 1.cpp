// 
#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &a, int n, int k, int mid)
{
    int pos = a[0];
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - pos >= mid)
        {
            pos = a[i];
            count++;
            if (count == k)
            {
                return true;
            }
        }
    }
    return false;
}

int maximise_min_dist(vector<int> &a, int n, int k)
{
    sort(a.begin(), a.end());
    int start = 1, end = a[n - 1];
    int ans = -1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (helper(a, n, k, mid))
        {
            ans = max(mid, ans);
            start = mid + 1;
        }
        else
        {
            end = mid;
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

    int k;
    cin >> k;

    cout << maximise_min_dist(a, n, k) << endl;

    return 0;
}
