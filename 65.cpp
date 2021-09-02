// Krushkals Algorithm
// Min Spanning Tree
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int parent[N];
int sz[N];

void makeSet(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int findSet(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        makeSet(i);
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    int ans = 0;

    for (auto it : edges)
    {
        int u = it[1];
        int v = it[2];
        int w = it[0];

        int a = findSet(u);
        int b = findSet(v);

        if (a == b)
            continue;
        else
        {
            unionSet(u, v);
            ans += w;
        }
    }
    cout << ans << endl;
    return 0;
}