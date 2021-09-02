// Disjoin Set Union without Optimisation
// O(N)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int parent[N];

void make(int v)
{
    parent[v] = v;
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
        parent[b] = a;
    }
}

int main()
{
    return 0;
}