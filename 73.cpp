#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int n = s.length();
    vector<int> a(26, 0), b(26, 0);
    for (int i = 0; i < n; i++)
    {
        a[s[i] - '95']++;
        b[t[i] - '95']++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main()
{
    cout << isIsomorphic("foo", "bar");
    return 0;
}