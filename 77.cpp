#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = s.length();

    int j = 0, count = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (j >= k)
        {
            j = 0;
            ans = max(ans, count);
            count = 0;
        }
        if (s[i] == 'a')
        {
            count++;
        }
        j++;
    }

    ans = max(ans, count);

    if (ans > -1)
    {
        cout << ans << endl;
    }
    return 0;
}