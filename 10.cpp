#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> a, vector<int> &d, int k, int c)
{
    int n = a.size();
    for (int i = 0; i < k; i++)
    {
        a[d[i]] = INT_MAX;
    }
    sort(a.begin(), a.end());
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == INT_MAX)
            break;
        if (a[i] <= c)
        {
            c -= a[i];
            mx++;
        }
    }
    return mx;
}

vector<int> solve(vector<int> a, vector<vector<int>> &querry, int q, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int c = querry[i][0];
        int k = querry[i][1];
        vector<int> d;
        for (int j = 2; j < querry[i].size(); j++)
        {
            d.push_back(querry[i][j]);
        }

        ans.push_back(solve(a, d, k, c));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
    {
        cin >> i;
    }

    int k;
    cin >> k;

    vector<int> d(k);

    for (auto &i : d)
    {
        cin >> i;
    }

    int c;
    cin >> c;

    cout < < < < endl;

    return 0;
}