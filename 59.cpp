//Floyd Warshal
// Gives min dist b/w two vertex

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main()
{
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    int n = graph.size();
    vector<vector<int>> dp = graph;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == INF)
                cout << "INF ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}