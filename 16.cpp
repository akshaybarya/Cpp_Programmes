#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 6;
vector<int> Parent(N);
vector<int> sz(N);

void makeSet(int i)
{
    Parent[i] = i;
    sz[i] = 1;
}

int find_set(int v)
{
    if (Parent[v] == v)
        return v;
    return Parent[v] = find_set(Parent[v]);
}

void unionSet(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        Parent[b] = a;
        sz[a] += sz[b];
    }
}

signed main()
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
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    bool cycle = false;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
        {
            cycle = true;
        }
        else
        {
            unionSet(u, v);
        }
    }
    cout << "Cycle Found" << cycle << endl;
    return 0;
}