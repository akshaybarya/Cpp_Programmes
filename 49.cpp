#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    vis[node] = 1;
    cout << node << endl;

    vector<int>::iterator it;

    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!vis[*it])
        {
            dfs(*it);
        }
    }
}

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //dfs(1);
    bfs();

    return 0;
}