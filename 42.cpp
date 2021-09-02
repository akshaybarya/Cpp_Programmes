#include <bits/stdc++.h>
using namespace std;

int solve(map<int, int> mp, vector<int> &a, int i, int r)
{
    for (int j = i; j < i + r and j < a.size(); j++)
    {
        mp[a[j]]--;
        if (mp[a[j]] == 0)
        {
            mp.erase(a[j]);
        }
    }
    return mp.size();
}

int question_function(vector<int> &a, int r)
{
    cin.tie(NULL);
    int n = a.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    int ans = 0;
    for (int i = 0; i <= n - r; i++)
    {
        ans = max(ans, solve(mp, a, i, r));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int r;
    cin >> r;

    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }

    cout << question_function(a, r) << endl;
    return 0;
}