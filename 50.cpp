#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

bool vis[N];
int indeg[N];
vector<int> adj[N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
        indeg[i] = 0;
    }
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        cnt++;
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return 0;
}