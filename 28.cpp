#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N];

int LCS(string &a, int i, string &b, int j)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + LCS(a, i - 1, b, j - 1);
    }
    return dp[i][j] = max(LCS(a, i - 1, b, j), LCS(a, i, b, j - 1));
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
    string a, b;
    cin >> a >> b;

    cout << LCS(a, a.size() - 1, b, b.size() - 1) << endl;
    return 0;
}