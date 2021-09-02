// Disjoin Set Union with Optimisation
// O(N)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[1];
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
        if (size[a] > size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    return 0;
}