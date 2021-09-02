#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int w = sqrt(a[i]);
        if (w * w == a[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}