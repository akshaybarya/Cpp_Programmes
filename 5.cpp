#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &a, int k, int x, int n)
{
    int i = 0;
    int start = 0;
    int sum = 0, mx = INT_MIN;
    while (i < k)
    {
        sum += a[i];
        i++;
    }
    mx = sum;
    while (i < n)
    {
        sum += a[i];
        sum -= a[start];
        if (sum < x)
        {
            mx = max(sum, mx);
        }
        start++;
        i++;
    }
    return mx;
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

    int x;
    cin >> x;

    cout << max_sum(a, k, x, n) << endl;
    return 0;
}