#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 2;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> a[n];
    vector<bool> vis(N, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    //cout << "BFS" << endl;

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        vector<int>::iterator it;
        for (it = a[node].begin(); it != a[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}