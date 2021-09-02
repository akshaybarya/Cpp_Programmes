#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 2, m = 1e9 + 7, p = 31;
vector<int> power(N, 0);

signed main()
{
    string t = "apnaacollegena";
    string s = "na";
    int S = s.length(), T = t.length();

    for (int i = 1; i < N; i++)
    {
        power[i] = (power[i - 1] * p) % m;
    }

    vector<int> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % m;
    }

    int h_s = 0;
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % m;
    }

    for (int i = 0; i + S - 1 < T; i++)
    {
        int curr_h = (h[i + S] - h[i] + m) % m;
        if (curr_h == (h_s * power[i]) % m)
        {
            cout << "Substring found at" << i << endl;
        }
    }

    return 0;
}