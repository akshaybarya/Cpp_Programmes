#include <bits/stdc++.h>
using namespace std;

char solve(string &s, int n)
{
    int res = 0, i = 0;
    for (i = n; i < s.size(); i += 3)
    {
        res += (int)(s[i] - 64);
    }
    i = i % s.size();
    while (i < n)
    {
        res += (int)(s[i] - 64);
        i += 3;
    }

    res %= 26;
    return res - 1 + 'A';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, ans;
    cin >> s;

    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(solve(s, i));
    }

    cout << ans << endl;
    return 0;
}