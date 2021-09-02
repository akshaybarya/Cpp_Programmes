#include <bits/stdc++.h>
using namespace std;

int min_subarray(vector<int> &a, int k, int n)
{
    int sum = 0, start = 0, ans = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum >= k)
        {
            sum -= a[start++];
            if (sum >= k)
            {
                ans = i - start + 1;
                mn = min(ans, mn);
            }
        }
    }
    return mn;
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

    cout << min_subarray(a, k, n) << endl;
    return 0;
}