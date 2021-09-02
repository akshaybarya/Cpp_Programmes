#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N];

int solve(vector<int> &a, int i, int j)
{
    if (i == j)
    {
        return a[i];
    }

    if (i > j)
        return 0;

    if (dp[i][j] == -1)
    {

        int choice1 = a[i] + min(solve(a, i + 2, j), solve(a, i + 1, j - 1));
        int choice2 = a[j] + min(solve(a, i + 1, j - 1), solve(a, i, j - 2));

        dp[i][j] = max(choice1, choice2);
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

    cout << solve(a, 0, n - 1) << endl;
    return 0;
}