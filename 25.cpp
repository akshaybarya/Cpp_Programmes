#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N];

vector<int> val;

int knapsack(int n, int wt, vector<int> &W)
{
    if (n <= 0 || wt <= 0)
        return 0;

    if (dp[n][wt] > 0)
        return dp[n][wt];
    if (W[n - 1] > wt)
    {
        return knapsack(n - 1, wt, W);
    }

    return dp[n][wt] = max(knapsack(n - 1, wt, W), val[n - 1] + knapsack(n - 1, wt - W[n - 1], W));
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            dp[i][j] = 0;
    }
    int n, wt;
    cin >> n >> wt;
    val.resize(n);
    vector<int> W(n);
    for (auto &i : W)
    {
        cin >> i;
    }
    for (auto &i : val)
    {
        cin >> i;
    }
    cout << knapsack(n, wt, W);
    return 0;
}