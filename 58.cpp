//Bellmen Ford

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int source;
    cin >> source;

    vector<int> dist(n, INF);
    dist[source] = 0;

    for (int iter = 0; iter < n - 1; iter++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for (auto it : dist)
    {
        if (it < INF)
            cout << it << " ";
        else
            cout << "-1 ";
    }

    return 0;
}