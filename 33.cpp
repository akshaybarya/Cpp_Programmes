#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> val(n);
    for (auto &i : val)
    {
        cin >> i;
    }

    vector<int> wt(n);
    for (auto &i : wt)
    {
        cin >> i;
    }

    vector<int> dp(W + 1, 0);

    for (int j = 0; j <= W; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j - wt[i] >= 0)
            {
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            }
        }
    }
    cout << dp[W] << endl;
    return 0;
}