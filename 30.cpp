#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;
int dp[N][N];

int memoize(vector<int> &a, int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = MOD;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], memoize(a, i, k) + memoize(a, k + 1, j) + a[i - 1] * a[k] * a[j]);
    }

    return dp[i][j];
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }

    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    cout << memoize(a, 1, n - 1) << endl;
    return 0;
}