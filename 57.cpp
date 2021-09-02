// Dijkstra Algorithm
// find min to react all nodes from source node

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5 + 2, N = 1e5 + 2;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(N, inf);
    vector<vector<pair<int, int>>> edges(n);
    vector<bool> vis(N, false);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    int source;
    cin >> source;

    set<pair<int, int>> s;
    s.insert({0, source});
    vis[source] = true;

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);

        for (auto it : edges[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.first)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == inf)
        {
            cout << "-1"
                 << " ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}