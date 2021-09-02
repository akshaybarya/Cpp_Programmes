#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int dp[N];

int main()
{
    int n;
    cin >> n;

    int c2 = 1, c3 = 1, c5 = 1;
    dp[1] = 2;
    dp[2] = 3;
    dp[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = min({dp[c2] * 2, dp[c3] * 3, dp[c5] * 5});
        if (dp[i] == dp[c2] * 2)
        {
            c2++;
        }
        if (dp[i] == dp[c3] * 3)
        {
            c3++;
        }
        if (dp[i] == dp[c5] * 5)
        {
            c5++;
        }
    }
    cout << dp[n] << endl;
    return 0;
}