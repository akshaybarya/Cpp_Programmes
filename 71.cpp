#include <bits/stdc++.h>
using namespace std;

int maxUniqueSum(int input1, int input2, int input3[])
{
    int m = input1, n = input2;
    sort(input3, input3 + n);
    int ans = 0, canBear = m;
    int j = 0;
    for (int i = 1; i <= m; i++)
    {
        if (j <= n and input3[j] == i)
        {
            j++;
            continue;
        }
        else
        {
            if (canBear >= i)
            {
                canBear = canBear - i;
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxUniqueSum(m, n, a);
    return 0;
}