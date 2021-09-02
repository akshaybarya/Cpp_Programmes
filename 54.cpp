// Kruskals Algorithm
// cost of Spanning Tree
// O(N)
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
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);

    if (a != b)
    {
        if (sz[a] > sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        makeSet(i);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int w, u, v;
        cin >> u >> v >> w;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto it : edges)
    {
        int w = it[0];
        int u = it[1];
        int v = it[2];

        u = findSet(u);
        v = findSet(v);

        if (u == v)
        {
            continue;
        }
        else
        {
            cout << u << " " << v << endl;
            cost += w;
            unionSet(u, v);
        }
    }
    cout << cost << endl;
    return 0;
}