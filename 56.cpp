// DP No of Palindromic Substring
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    int dp[n][n];

    memset(dp, 0, sizeof(dp));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        count++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dp[i][j - 1] == 1 || dp[i][j - 2] == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}