// Merge Two Sorted Arrays Without Extra Space O(N^2)
#include <bits/stdc++.h>
#define Speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve(vector<int> &a, int n, vector<int> &b, int m)
{
    if (n == 0 || m == 0)
        return;

    int i = 0, j = 0;

    while (i < n and j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            int k = j;
            while (k < m - 1 and b[k] > b[k + 1])
            {
                swap(b[k], b[k + 1]);
                k++;
            }
        }
        i++;
    }
}

int main()
{
    Speed int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (auto &it : a)
    {
        cin >> it;
    }

    for (auto &it : b)
    {
        cin >> it;
    }

    solve(a, n, b, m);

    for (auto it : a)
    {
        cout << it << " ";
    }
    for (auto it : b)
    {
        cout << it << " ";
    }
    return 0;
}