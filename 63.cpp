#include <bits/stdc++.h>
using namespace std;

string solve(string &s)
{
    if (s.length() <= 1)
    {
        return s;
    }
    int n = s.length();
    string ans;
    for (int i = 1; i < n; i++)
    {
        if ((s[i] - '0') > (s[i - 1] - '0'))
        {
            ans.push_back(s[i] + '26');
        }
        else if ((s[i] - '0') < (s[i - 1] - '0'))
        {
            ans.
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}