#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector<int>> &a, int x, int y, int n)
{
    for (int i = x; i > -1; i--)
    {
        if (a[i][y] == 1)
            return false;
    }
    int row = x, col = y;
    while (row > -1 and col > -1)
    {
        if (a[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = x;
    col = y;
    while (row > -1 and col < n)
    {
        if (a[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool N_Queen(vector<vector<int>> &a, int x, int n)
{
    if (x == n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (canPlace(a, x, i, n))
        {
            a[x][i] = 1;
            if (N_Queen(a, x + 1, n))
            {
                return true;
            }
            a[x][i] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));

    if (N_Queen(a, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
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