#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, Tmin, Tmax;
    cin >> n >> Tmin >> Tmax;

    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (temp[i] < Tmin or temp[i] > Tmax)
        {
            cout << temp[i] << " ";
        }
    }
    return 0;
}