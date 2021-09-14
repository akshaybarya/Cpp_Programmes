#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int ans = -1;

    map<int, int> mp;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        x = b + (i * a);
        y = d + ((i + 1) * c);

        if (mp[x] == 1)
        {
            ans = x;
            break;
        }
        if (mp[y] == 1)
        {
            ans = y;
            break;
        }
        mp[x]++;
        mp[y]++;
    }

    if (ans == -1)
    {
        cout << "No same amount of fuel found" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}