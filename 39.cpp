#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N];

// dp[i][j] = dp[i-1][j] + dp[i][j-1];

void solve(vector<vector<int>> &a, int n)
{
    if (a[0][0] == 0)
    {
        return;
    }
    bool b = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
        {
            b = true;
        }

        if (b)
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = 1;
        }
    }

    b = false;
    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == 0)
        {
            b = true;
        }

        if (b)
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[10];
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    solve(a, n);
    cout << dp[n - 1][n - 1];
    return 0;
}

/*
Ecommerce
user{
    id
    name string
    phone number string
    email unique
    image text
    password 
    role  = user/seller
}

product {
    id
    category id
    product name
    price
    rating
    seller id
}

category{
    id   
}
*/