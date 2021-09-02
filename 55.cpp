// Find number of Island In A Matrix

#include <bits/stdc++.h>
using namespace std;

void markIsland(vector<vector<int>> &adj, int i, int j, int n, int m)
{
    if (i < 0 or j < 0 or i >= n or j >= m or adj[i][j] != 1)
    {
        return;
    }

    adj[i][j] = 2;
    markIsland(adj, i - 1, j, n, m);
    markIsland(adj, i + 1, j, n, m);
    markIsland(adj, i, j - 1, n, m);
    markIsland(adj, i, j + 1, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    int island = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 1)
            {
                island++;
                markIsland(adj, i, j, n, m);
            }
        }
    }

    cout << island << endl;
    return 0;
}