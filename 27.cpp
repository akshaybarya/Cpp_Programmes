#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int dp[N];

int longest(vector<int> &a, int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(1 + dp[j], dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
    }
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }
    cout << longest(a, n) << endl;
    return 0;
}