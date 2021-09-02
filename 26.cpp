#include <bits/stdc++.h>
using namespace std;

vector<int> coins;

int coinChange1(vector<int> &coins, int n, int v)
{
    if (n < 0)
        return 0;
    if (v <= 0)
        return 1;
    if (v < coins[n - 1])
        return coinChange1(coins, n - 1, v);
    return coinChange1(coins, n - 1, v) + coinChange1(coins, n, v - coins[n - 1]);
}
const int N = 1e3 + 2;
int DP[N][N];

void coinChange2(vector<int> &coins, int n, int v)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            DP[i][j] = 0;
        }
    }
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            DP[i][j] = DP[i - 1][j];
        }
        for (int j = i; j <= v; j++)
        {
            DP[i][j] = DP[i - 1][j] + DP[i][j - coins[i - 1]];
        }
    }
    cout << DP[n][v] << endl;
}

vector<int> dp(N, 0);

void coinChange3(vector<int> &coins, int n, int v)
{
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= v; j++)
        {
            dp[j] += dp[j - coins[i - 1]];
        }
    }

    cout << dp[v] << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> temp(n);
    for (auto &i : temp)
    {
        cin >> i;
    }
    coins = temp;
    int v;
    cin >> v;
    //cout << coinChange1(coins, n, v) << endl;
    //coinChange2(coins, n, v);
    coinChange3(coins, n, v);
    return 0;
}