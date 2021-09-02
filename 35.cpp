#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<int>> &a, int i, int j, int n)
{
    if (i < n and j < n and a[i][j] == 0)
    {
        return true;
    }
    return false;
}

bool rat_in_a_maze(vector<vector<int>> &a, vector<vector<int>> &ans, int i, int j, int n)
{

    if (i >= n || j >= n)
    {
        return false;
    }
    if (i == n - 1 and j == n - 1)
    {
        ans[i][j] = 1;
        return true;
    }
    if (canPlace(a, i, j, n))
    {
        ans[i][j] = 1;
        if (rat_in_a_maze(a, ans, i + 1, j, n))
        {
            return true;
        }
        if (rat_in_a_maze(a, ans, i, j + 1, n))
        {
            return true;
        }
        ans[i][j] = 0;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));

    if (rat_in_a_maze(a, ans, 0, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "NO possible Solution" << endl;
    }
    return 0;
}