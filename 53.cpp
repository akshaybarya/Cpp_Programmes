// Cycle Detection Using DSU
// O(N)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

int sz[N];
int parent[N];

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
        if (sz[a] > sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    bool b = false;
    for (auto i : edges)
    {
        int x = i[0];
        int y = i[1];
        int u = findSet(x);
        int v = findSet(y);

        if (u == v)
        {
            b = true;
        }
        else
        {
            unionSet(u, v);
        }
    }

    if (b)
        cout << "Cycle Present";
    else
    {
        cout << "No cycle Present";
    }
    return 0;
}